all:
	echo "usage: make [a|b]"

a:
	make add-port
	python3 player_a.py
	make remove-port

b:
	make add-port
	python3 player_b.py
	make remove-port

FIREWALL_CMD := $(shell which firewall-cmd 2> /dev/null)
UFW := $(shell which ufw 2> /dev/null)

add-port:
	@if [ -n "$(FIREWALL_CMD)" ]; then \
		echo "Using firewall-cmd to add ports"; \
		sudo firewall-cmd --add-port=11066/tcp --permanent; \
		sudo firewall-cmd --add-port=11067/tcp --permanent; \
		sudo firewall-cmd --add-port=11066/udp --permanent; \
		sudo firewall-cmd --add-port=11067/udp --permanent; \
		sudo firewall-cmd --reload; \
	elif [ -n "$(UFW)" ]; then \
		echo "Using ufw to add ports"; \
		sudo ufw allow 11066/tcp; \
		sudo ufw allow 11067/tcp; \
		sudo ufw allow 11066/udp; \
		sudo ufw allow 11067/udp; \
	else \
		echo "No firewall management tool detected (firewall-cmd or ufw). Skipping..."; \
	fi

remove-port:
	@if [ -n "$(FIREWALL_CMD)" ]; then \
		echo "Using firewall-cmd to remove ports"; \
		sudo firewall-cmd --remove-port=11066/tcp --permanent; \
		sudo firewall-cmd --remove-port=11067/tcp --permanent; \
		sudo firewall-cmd --remove-port=11066/udp --permanent; \
		sudo firewall-cmd --remove-port=11067/udp --permanent; \
		sudo firewall-cmd --reload; \
	elif [ -n "$(UFW)" ]; then \
		echo "Using ufw to remove ports"; \
		sudo ufw delete allow 11066/tcp; \
		sudo ufw delete allow 11067/tcp; \
		sudo ufw delete allow 11066/udp; \
		sudo ufw delete allow 11067/udp; \
	else \
		echo "No firewall management tool detected (firewall-cmd or ufw). Skipping..."; \
	fi