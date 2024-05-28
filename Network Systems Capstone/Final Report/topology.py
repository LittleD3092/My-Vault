from mininet.topo import Topo
from mininet.net import Mininet
from mininet.node import RemoteController
from mininet.cli import CLI
from mininet.log import setLogLevel, info
import time
import threading

class MyTopo(Topo):
    def build(self):
        h1 = self.addHost('h1', ip='10.0.0.1', mac='00:00:00:00:00:01')
        h2 = self.addHost('h2', ip='10.0.0.2', mac='00:00:00:00:00:02')
        h3 = self.addHost('h3', ip='10.0.0.3', mac='00:00:00:00:00:03')
        h4 = self.addHost('h4', ip='10.0.0.4', mac='00:00:00:00:00:04')
        h5 = self.addHost('h5', ip='10.0.0.10', mac = '00:00:00:00:00:10')

        s1 = self.addSwitch('s1')

        self.addLink(h1, s1)
        self.addLink(h2, s1)
        self.addLink(h3, s1)
        self.addLink(h4, s1)
        self.addLink(h5, s1)

def run_scripts_on_hosts(net):
    h1 = net.get('h1')
    h2 = net.get('h2')
    h3 = net.get('h3')
    h4 = net.get('h4')
    h5 = net.get('h5')

    h1.cmd('python3 sender.py &')
    h2.cmd('python3 sender.py &')
    h3.cmd('python3 sender.py &')
    h4.cmd('python3 sender.py &')
    h5.cmd('python3 receiver.py &')

def count_down(duration = 60):
    def countdown_thread():
        time.sleep(duration)
        info(f'Countdown finished after {duration} seconds\n')
    
    thread = threading.Thread(target=countdown_thread)
    thread.start()

def rename_interfaces(net):
    hosts = ['h1', 'h2', 'h3', 'h4', 'h5']
    for host_name in hosts:
        host = net.get(host_name)
        for intf in host.intfList():
            host.cmd(f'ip link set {intf} down')
            host.cmd(f'ip link set {intf} name eth0')
            host.cmd(f'ip link set eth0 up')

def main():
    setLogLevel('info')

    topo = MyTopo()
    net = Mininet(topo=topo, controller=RemoteController, autoSetMacs=True)
    net.start()

    info('*** Starting the network\n')
    rename_interfaces(net)
    run_scripts_on_hosts(net)
    count_down()
    info('*** Scripts are running on all hosts\n')

    CLI(net)
    info('*** Stopping the network\n')
    net.stop()

if __name__ == '__main__':
    main()