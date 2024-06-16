CONTROLLER_CODE = controller.py
TOPOLOGY_CODE = topology.py
TOPOLOGY_NAME_VM1 = mytopo_vm1
TOPOLOGY_NAME_VM2 = mytopo_vm2
CONTROLLER_IP = 10.0.2.4

controller:
	ryu-manager $(CONTROLLER_CODE) --verbose

mininet-vm1:
	sudo mn --custom $(TOPOLOGY_CODE) --topo $(TOPOLOGY_NAME_VM1) --controller=remote,ip=$(CONTROLLER_IP)

mininet-vm2:
	sudo mn --custom $(TOPOLOGY_CODE) --topo $(TOPOLOGY_NAME_VM2) --controller=remote,ip=$(CONTROLLER_IP)

ls:
	sudo ovs-vsctl -- --columns=name,ofport list Interface

gre-tunnel-vm1:
	sudo ovs-vsctl add-port s1 s1-gre1 -- set interface s1-gre1 type=gre options:remote_ip=10.0.2.5
	sudo ip link set s1-gre1 up

gre-tunnel-vm2:
	sudo ovs-vsctl add-port s2 s2-gre1 -- set interface s2-gre1 type=gre options:remote_ip=10.0.2.4
	sudo ip link set s2-gre1 up

clean:
	sudo mn -c

# --- Tutorial ---
try:
	ryu-manager tutorial/first-app.py