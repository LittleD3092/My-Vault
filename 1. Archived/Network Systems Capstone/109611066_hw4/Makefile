all: generate-tabs-file run clean

generate-tabs-file:
	echo 'title: router1;; command: python ospf.py 1' >> tabs.txt
	echo 'title: router2;; command: python ospf.py 2' >> tabs.txt
	echo 'title: router3;; command: python ospf.py 3' >> tabs.txt
	echo 'title: router4;; command: python ospf.py 4' >> tabs.txt
	echo 'title: router5;; command: python ospf.py 5' >> tabs.txt
	echo 'title: router6;; command: python ospf.py 6' >> tabs.txt

run:
	konsole --tabs-from-file tabs.txt --hold

clean:
	rm -f tabs.txt

zip:
	zip 109611066_hw4 ospf.py