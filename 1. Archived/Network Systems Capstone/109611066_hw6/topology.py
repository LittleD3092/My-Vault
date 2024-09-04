from mininet.topo import Topo
from mininet.node import Host

class MyTopo_vm1(Topo):
    def build(self):
        h1 = self.addHost('h1', ip='10.0.0.1')
        h2 = self.addHost('h2', ip='10.0.0.2')
        h3 = self.addHost('h3', ip='10.0.0.3')
        h4 = self.addHost('h4', ip='10.0.0.4')
        
        s1 = self.addSwitch('s1')

        self.addLink(h1, s1)
        self.addLink(h2, s1)
        self.addLink(h3, s1)
        self.addLink(h4, s1)

class MyTopo_vm2(Topo):
    def build(self):
        h5 = self.addHost('h5', ip='10.0.0.5')
        h6 = self.addHost('h6', ip='10.0.0.6')
        h7 = self.addHost('h7', ip='10.0.0.7')
        h8 = self.addHost('h8', ip='10.0.0.8')

        s2 = self.addSwitch('s2')

        self.addLink(h5, s2)
        self.addLink(h6, s2)
        self.addLink(h7, s2)
        self.addLink(h8, s2)

topos = {'mytopo_vm1': (lambda: MyTopo_vm1()), 'mytopo_vm2': (lambda: MyTopo_vm2())}
