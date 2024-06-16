import random

class Setting:
    """
    This class represents the settings for a network simulation.

    Attributes:
        host_num (int): host 總數量
        total_time (int): 模擬時間總長，以 1 為最小時間單位
        packet_num (int): 每個 host 要送出的封包數量
        packet_time (int): 完成一個封包 (包含送 packet 和收 ack 的 link delay) 所需的總時間, 也等於 slotted aloha 的 slot size。 (假設 ack 的等待時間等於 link delay)
        max_collision_wait_time (int): 重送封包的最大等待時間，ALOHA, CSMA, CSMA/CD 的 maximum random backoff time
        p_resend (float): slotted aloha 每個 slot 開始時，重送封包的機率
        link_delay (int): link delay
        seed (int): 用來產生一系列隨機數的 seed，若使用相同 seed 則會有一樣的模擬結果，若使用不同的seed，模擬結果則會不同

    Methods:
        gen_packets(): 產生各個 host 的所有待傳送封包的產生時間點
    """

    def __init__(
        self,
        host_num=3,
        total_time=10000,
        packet_num=500,
        packet_size=5,
        max_collision_wait_time=None,
        p_resend=None,
        coefficient=8,
        link_delay=1,
        seed=None,
    ) -> None:

        self.host_num = host_num
        self.total_time = total_time
        self.packet_num = packet_num
        self.packet_time = packet_size + 2 * link_delay
        self.link_delay = link_delay

        if max_collision_wait_time is None:
            self.max_collision_wait_time = coefficient * self.host_num * self.packet_time  # TODO: this is not complete, change this (hint: add two parameters)
        else:
            self.max_collision_wait_time = max_collision_wait_time

        if p_resend is None:
            self.p_resend = 1 / (coefficient * self.host_num)  # TODO: this is not complete, change this (hint: add one parameters)
        else:
            self.p_resend = p_resend

        if seed is None:
            self.seed = random.randint(1, 10000)
        else:
            self.seed = seed

    """
    format:
    e.g.
       [[10, 20, 30],  - host 0
        [20, 30, 50],  - host 1
        [30, 50, 60]]  - host 2
    """
    def gen_packets(self):
        random.seed(self.seed)
        packets = [[] for i in range(self.host_num)]
        for i in range(self.host_num):
            packets[i] = random.sample(
                range(1, self.total_time - self.packet_time), self.packet_num
            )
            packets[i].sort()
        return packets
