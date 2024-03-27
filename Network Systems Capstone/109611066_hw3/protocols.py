import random

# A class to store hosts' information
# Usage:
#     hosts = Hosts(10) # create 10 hosts
#     hosts[0] # get the first host
#     hosts[0]["status"] # get the status of the first host
# Fields in each host:
#    id: host id, start from 0 and end at num-1
#    status: 
#        0: standby, 1: send, 2: resend
#    action_to_do: 
#        0: standby, 1: send, 2: resend, 3: stop sending
#    packet_num: the number of remaining packets to send
#    remain_length: the remaining time to send the current packet
#    wait_time: the time to wait to send the next packet
#    collision: whether the host has a collision
#    success_num: the number of successful transmissions
#    collision_num: the number of collisions
#    history: the history of host's actions
#    pending_packets: the packets to send
class Hosts:
    # A class for a sequence of packets, with time to send
    class Packets:
        # Preconditions:
        #    timestamps: a list of integers representing 
        #                the time to send
        # Postconditions:
        #    Initialize the packets with the time to send
        def __init__(self, timestamps = []):
            self.timestamps = timestamps

        # A [] operator to get the packet by index
        # Preconditions:
        #    key: an integer
        # Postconditions:
        #    Return the packet with the given index key
        def __getitem__(self, key):
            return self.timestamps[key]
        
        # Set the timestamps
        # Preconditions:
        #    timestamps: a list of integers representing
        #                the time to send
        # Postconditions:
        #    The timestamps are set to the given timestamps
        def set_timestamps(self, timestamps):
            self.timestamps = timestamps
        
        # Get the time of the next packet
        # Postconditions:
        #    Return the time of the next packet
        def time_of_next_packet(self):
            return self.timestamps[0]
        
        # Pop the first packet
        # Postconditions:
        #    The first packet is removed
        def pop(self):
            self.timestamps.pop(0)

        # Check if the pending packets list is empty
        # Postconditions:
        #    Return True if the list is empty, False otherwise
        def is_empty(self):
            return len(self.timestamps) == 0
    
    # A class for a single host
    class Host:
        # Preconditions:
        #    id: an integer
        # Postconditions:
        #    Initialize the host with the given id
        def __init__(self, id):
            self.id = id
            self.status = 0
            self.action_to_do = 0
            self.packet_num = 0
            self.remain_length = 0
            self.wait_time = 0
            self.collision = False
            self.success_num = 0
            self.collision_num = 0
            self.history = ""
            self.pending_packets = self.Packets()

        # Preconditions:
        #    index: a string representing the field name
        # Postconditions:
        #    Return the value of the field with the given index
        def __getitem__(self, index):
            return getattr(self, index)

        # Wait for the random time
        # Postconditions:
        #    The host is waiting for the random time
        def wait(self):
            if self.wait_time > 0:
                self.wait_time -= 1
        
        # Plan to send the packet
        # Postconditions:
        #    The host plans to send the packet
        def plan_to_send(self):
            self.action_to_do = 1
            self.remain_length = self.setting.packet_length
        
    # Preconditions:
    #    setting: a Setting object
    # Postconditions:
    #    Initialize the hosts with setting.host_num hosts
    def __init__(self, setting):
        self.hosts = [
            {
                "id": i,
                "status": 0,         # 0: standby, 1: send, 2: resend
                "action_to_do": 0,   # 0: standby, 1: send, 2: resend, 3: stop sending
                "packet_num": 0,   
                "remain_length": 0,  # remain time to sending
                "wait_time": 0,      # time wait to send
                "collision": False,
                "success_num": 0,
                "collision_num": 0,
                "history": "",       # record history of host's actions
                "pending_packets": self.Packets()
            }
            for i in range(setting.host_num)
        ]
        self.setting = setting
        timestamps_for_all_hosts = setting.gen_packets()
        for i in range(setting.host_num):
            self.hosts[i]["pending_packets"].set_timestamps(timestamps_for_all_hosts[i])

    # A [] operator to get the host by index
    # Preconditions:
    #    key: an integer
    # Postconditions:
    #    Return the host with the given index key
    def __getitem__(self, key):
        return self.hosts[key]
    
    # Check whether there are any collisions among the hosts
    # Postconditions:
    #    Return True if there are any collisions, False otherwise
    #    Also set the collision field of each sending host to True 
    #    if there is a collision
    def check_collision(self):
        sending_hosts = [h for h in self.hosts if h["status"] == 1]
        if len(sending_hosts) > 1:
            for h in sending_hosts:
                h["collision"] = True
            return True
        return False

def aloha(setting, show_history=False):
    hosts = Hosts(setting)
    total_idle_time = 0

    # Iterate through the time
    for t in range(setting.time):
        # put due packets in the queue
        hosts.update()

        # determine the action
        for h in hosts:
            if h["status"] == 0:
                if h["wait_time"] > 0:
                    h.wait()
                elif h["packet_num"] > 0:
                    h.plan_to_send()

        hosts.apply()

        # check collision
        hosts.check_collision()
        if hosts.is_idle():
            total_idle_time += 1

        # 

def slotted_aloha(setting, show_history=False):
    # TODO: implement slotted aloha
    pass

def csma(setting, one_persistent=False, show_history=False):
    # TODO: implement csma
    pass

def csma_cd(setting, one_persistent=False, show_history=False):
    # TODO: implement csma_cd
    pass