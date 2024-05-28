from ryu.base import app_manager
from ryu.controller import ofp_event
from ryu.controller.handler import CONFIG_DISPATCHER, MAIN_DISPATCHER
from ryu.controller.handler import set_ev_cls
from ryu.ofproto import ofproto_v1_3
from ryu.lib.packet import packet
from ryu.lib.packet import ethernet, ipv4, arp, ipv6
from ryu.lib import hub
from collections import defaultdict, Counter, deque
import time
import math
from enum import Enum

class AlgorithmType(Enum):
    BASIC = 1
    CUMULATIVE = 2
    TIME_BASED = 3

algo_type = AlgorithmType.TIME_BASED

class SimpleSwitch13(app_manager.RyuApp):
    OFP_VERSIONS = [ofproto_v1_3.OFP_VERSION]

    def __init__(self, *args, **kwargs):
        super(SimpleSwitch13, self).__init__(*args, **kwargs)
        # 新增一個儲存 Host MAC 的資料結構，類別為 dict(字典)
        self.mac_to_port = {}
        self.packet_count = defaultdict(Counter)

        # Keep track of previous packet count
        self.prev_packet_count = defaultdict(Counter)

        # Keep track of all datapaths to send flow stats requests
        self.datapaths = {}
        
        # Start a thread that periodically sends stats request
        self.monitor_thread = hub.spawn(self._monitor)

        self.start_time = time.time()

        # Parameters for cumulative entropy calculation
        self.prev_y = 0

        # Parameters for time-based DDoS detection
        self.n_elements = 10
        self.t_interval = 1
        self.time_based_vector = deque([-1] * self.n_elements, maxlen=self.n_elements)

        # If the file already exists, clear its contents
        open('entropy.txt', 'w').close()

    @set_ev_cls(ofp_event.EventOFPSwitchFeatures, CONFIG_DISPATCHER)
    def switch_features_handler(self, ev):
        # 一開始 Switch 連上 Controller 時的初始設定 Function
        datapath = ev.msg.datapath          # 接收 OpenFlow 交換器實例
        ofproto = datapath.ofproto          # OpenFlow 交換器使用的 OF 協定版本
        parser = datapath.ofproto_parser    # 處理 OF 協定的 parser

        # 以下片段用於設定 Table-Miss FlowEntry
        # 首先新增一個空的 match，也就是能夠 match 任何封包的 match rule
        match = parser.OFPMatch()
        # 指定這一條 Table-Miss FlowEntry 的對應行為
        # 把所有不知道如何處理的封包都送到 Controller
        actions = [parser.OFPActionOutput(ofproto.OFPP_CONTROLLER,
                                          ofproto.OFPCML_NO_BUFFER)]
        # 把 Table-Miss FlowEntry 設定至 Switch，並指定優先權為 0 (最低)
        self.add_flow(datapath, 0, match, actions)

    def add_flow(self, datapath, priority, match, actions):
        # 取得與 Switch 使用的 IF 版本 對應的 OF 協定及 parser
        ofproto = datapath.ofproto
        parser = datapath.ofproto_parser

        # Instruction 是定義當封包滿足 match 時，所要執行的動作
        # 因此把 action 以 OFPInstructionActions 包裝起來
        inst = [parser.OFPInstructionActions(ofproto.OFPIT_APPLY_ACTIONS,
                                             actions)]

        # FlowMod Function 可以讓我們對 Switch 寫入由我們所定義的 Flow Entry
        mod = parser.OFPFlowMod(datapath=datapath, priority=priority,
                                match=match, instructions=inst)
        # 把定義好的 FlowEntry 送給 Switch
        datapath.send_msg(mod)

    @set_ev_cls(ofp_event.EventOFPPacketIn, MAIN_DISPATCHER)
    def _packet_in_handler(self, ev):
        # 收到來自 Switch 不知如何處理的封包（Match 到 Table-Miss FlowEntry）
        msg = ev.msg
        datapath = msg.datapath
        ofproto = datapath.ofproto
        parser = datapath.ofproto_parser
        # in_port 相當於封包從 Switch 的哪個 port 進到 Switch 中
        # 同時也代表 source Host MAC 要往 in_port 送，才能送達
        in_port = msg.match['in_port']

        pkt = packet.Packet(msg.data)
        eth = pkt.get_protocols(ethernet.ethernet)[0]

        dst = eth.dst            # 得到封包目的端 MAC address
        src = eth.src            # 得到封包來源端 MAC address

        if pkt.get_protocols(ethernet.ethernet)[0].ethertype == 0x0800:
            ipv4_src = pkt.get_protocols(ipv4.ipv4)[0].src
        else:
            ipv4_src = None

        dpid = datapath.id       # Switch 的 datapath id (獨一無二的 ID)
        
        # 如果 MAC 表內不曾儲存過這個 Switch 的 MAC，則幫他新增一個預設值
        # ex. mac_to_port = {'1': {'AA:BB:CC:DD:EE:FF': 2}}
        #     但是目前 dpid 為 2 不存在，執行後 mac_to_port 會變成
        #     mac_to_port = {'1': {'AA:BB:CC:DD:EE:FF': 2}, '2': {}}
        self.mac_to_port.setdefault(dpid, {})

        # self.logger.info("packet in %s %s %s %s", dpid, src, dst, in_port)

        # 我們擁有來源端 MAC 與 in_port 了，因此可以學習到 src MAC 要往 in_port 送
        self.mac_to_port[dpid][src] = in_port

        # 如果 目的端 MAC 在 mac_to_port 表中的話，就直接告訴 Switch 送到 out_port
        # 否則就請 Switch 用 Flooding 送出去
        if dst in self.mac_to_port[dpid]:
            out_port = self.mac_to_port[dpid][dst]
        else:
            out_port = ofproto.OFPP_FLOOD

        # 把剛剛的 out_port 作成這次封包的處理動作
        actions = [parser.OFPActionOutput(out_port)]

        if ipv4_src is not None:
            match = parser.OFPMatch(in_port=in_port, eth_dst=dst, ipv4_src=ipv4_src, eth_type=0x0800)
            self.add_flow(datapath, 2, match, actions)

        data = None
        if msg.buffer_id == ofproto.OFP_NO_BUFFER:
            data = msg.data

        # 把要 Switch 執行的動作包裝成 Packet_out，並讓 Switch 執行動作
        out = parser.OFPPacketOut(datapath=datapath, buffer_id=msg.buffer_id,
                                  in_port=in_port, actions=actions, data=data)
        datapath.send_msg(out)

    # Keep track of all datapaths that are connected or disconnected
    @set_ev_cls(ofp_event.EventOFPStateChange, [MAIN_DISPATCHER, CONFIG_DISPATCHER])
    def _state_change_handler(self, ev):
        datapath = ev.datapath
        if ev.state == MAIN_DISPATCHER:
            self.datapaths[datapath.id] = datapath
        elif ev.state == CONFIG_DISPATCHER:
            if datapath.id in self.datapaths:
                del self.datapaths[datapath.id]

    # Periodically send stats request to all datapaths
    def _monitor(self):
        while True:
            for dp in self.datapaths.values():
                self._request_stats(dp)
            hub.sleep(self.t_interval)

    # Send stats request to datapath
    def _request_stats(self, datapath):
        self.logger.info('send stats request: %016x', datapath.id)
        ofproto = datapath.ofproto
        parser = datapath.ofproto_parser

        req = parser.OFPFlowStatsRequest(datapath)
        datapath.send_msg(req)

    # Handle flow stats reply
    @set_ev_cls(ofp_event.EventOFPFlowStatsReply, MAIN_DISPATCHER)
    def _flow_stats_reply_handler(self, ev):
        body = ev.msg.body
        dpid = ev.msg.datapath.id

        # Initialize or reset packet count for current switch
        current_packet_count = Counter()

        for stat in sorted(
            [flow for flow in body if flow.priority == 2],
            key=lambda flow: (
                flow.match['in_port'], 
                flow.match['eth_dst'],
                flow.match['ipv4_src']
            )
        ):
            if 'ipv4_src' not in stat.match:
                continue
            ipv4_src = stat.match['ipv4_src']
            current_packet_count[ipv4_src] += stat.packet_count

        # Calculate the difference in packet count
        for src, count in current_packet_count.items():
            # Skip ip address of the server
            if src == '10.0.0.10':
                continue
            previous_count = self.prev_packet_count[dpid][src]
            self.packet_count[dpid][src] += count - previous_count

        # Update previous packet count
        self.prev_packet_count[dpid] = current_packet_count

        # Call DDoS detection function after updating packet count
        self.detect_ddos(ev.msg.datapath)

    # DDoS detection function
    def detect_ddos(self, datapath):
        current_time = time.time()
        self.logger.info('------------------------------------')
        self.logger.info('Current time: %f', time.time())
        if current_time - self.start_time >= self.t_interval:
            self.start_time = current_time
            for dpid in self.packet_count:
                if algo_type == AlgorithmType.BASIC:
                    entropy = self.calculate_basic_entropy(self.packet_count[dpid])
                    self.logger.info('Entropy of switch %d: %f', dpid, entropy)
                    self.write_entropy(current_time, entropy)
                elif algo_type == AlgorithmType.CUMULATIVE:
                    entropy = self.calculate_cumulative_entropy(self.packet_count[dpid])
                    self.logger.info('Cumulative entropy of switch %d: %f', dpid, entropy)
                    self.write_entropy(current_time, entropy)
                elif algo_type == AlgorithmType.TIME_BASED:
                    summation = self.detect_time_based_ddos(self.packet_count[dpid])
                    self.logger.info('Summation of switch %d: %f', dpid, summation)
                    self.write_entropy(current_time, summation)
            # Reset packet count after detecting DDoS
            self.packet_count = defaultdict(Counter)

    # Calculate entropy of packet count
    def calculate_basic_entropy(self, packet_count):
        total_packets = sum(packet_count.values())
        if total_packets == 0:
            return 0
        
        entropy = 0
        for count in packet_count.values():
            probability = count / total_packets
            print(f'Probability: {probability}')
            if probability == 0:
                entropy += 0
            else:
                entropy += -probability * math.log2(probability)
        return entropy
    
    # Calculate cumulative entropy of packet count
    def calculate_cumulative_entropy(self, packet_count):
        alpha = 2
        X = self.calculate_basic_entropy(packet_count)
        Z = X - 2 * alpha
        y = max(self.prev_y + Z, 0)
        self.prev_y = y
        return y
    
    # Detect DDoS attack based on time
    def detect_time_based_ddos(self, packet_count):
        alpha = 2
        entropy = self.calculate_basic_entropy(packet_count)
        z_value = entropy - 2 * alpha
        self.update_time_based_vector(z_value)

        return sum(self.time_based_vector)
    
    # Update time-based vector
    def update_time_based_vector(self, z_value):
        if z_value > 0:
            self.time_based_vector.append(1)
        elif z_value < 0:
            self.time_based_vector.append(-1)
        else:
            self.time_based_vector.append(
                self.time_based_vector[-1]
            )

    # Write the entropy value to a file
    def write_entropy(self, time, entropy):
        with open('entropy.txt', 'a') as f:
            f.write('%f %f\n' % (time, entropy))
            f.close()