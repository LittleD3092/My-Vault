from scapy.all import *
import threading

class FlowCollector:
    def __init__(self) -> None:
        self.is_alive = True

        self.mode = 0

        self.flow_dict = {}
        self.flow_dict_mutex = threading.Lock()
        
        self.sniff_thread = threading.Thread(target=self.sniff_loop)
        self.sniff_thread.start()
        
    def sniff_loop(self):
        sniff(iface="enp0s3", prn=self.handle_packet)

    def handle_packet(self, packet):
        if packet.haslayer(IP) and packet.haslayer(TCP):
            src_ip = packet[IP].src
            dst_ip = packet[IP].dst
            src_port = packet[TCP].sport
            dst_port = packet[TCP].dport
            if packet.haslayer(Raw):
                payload = packet[Raw].load
                key = "{},{},{},{}".format(src_ip, dst_ip, src_port, dst_port)
                
                payload = payload[:50]
                self.flow_dict_mutex.acquire()
                if key in self.flow_dict:
                    if self.mode == 0:
                        if b"HTTP" in payload:
                            self.flow_dict[key]["limit"] += 5
                    elif self.mode == 1:
                        self.flow_dict[key]["count"] += 1
                        if self.flow_dict[key]["count"] % 40 == 1:
                            self.flow_dict[key]["limit"] += 5
                    if len(self.flow_dict[key]["payload"]) < self.flow_dict[key]["limit"]:
                        self.flow_dict[key]["payload"].append(payload)
                else:
                    self.flow_dict[key] = {"limit": 0, "count": 0, "payload": [payload]}
                self.flow_dict_mutex.release()

    def command(self, in_key):
        if in_key == "show":
            self.flow_dict_mutex.acquire()
            for key in self.flow_dict:
               print("{}->".format(key))
               for payload in self.flow_dict[key]["payload"]:
                   print("   {}".format(payload))
            self.flow_dict_mutex.release()
            print("end flow_dict")
        elif in_key == "clear":
            self.flow_dict_mutex.acquire()
            self.flow_dict.clear()
            self.flow_dict_mutex.release()
            print("flow_dict has cleared")
        elif in_key == "http1":
            self.mode = 0
            print("mode has been set to http/1")
        elif in_key == "http2":
            self.mode = 1
            print("mode has been set to http/2")

if __name__ == "__main__":
    collector = FlowCollector()
    while True:
      in_key = input("command:")
      if in_key == "exit" or in_key == "close":
        break
      else:
        collector.command(in_key)