CXX = g++
CXXFLAGS = -std=c++14

all: pcap_replay
pcap_replay: pcap_replay.cpp
	$(CXX) $(CXXFLAGS) $^ \
	-lpcap \
	-o $@
clean:
	rm -f pcap_replay