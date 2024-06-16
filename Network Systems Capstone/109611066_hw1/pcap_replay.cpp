#include <arpa/inet.h> // inet_addr
#include <cstring>     // memcpy
#include <iostream>
#include <netinet/ether.h> // ethernet header struct
#include <netinet/ip.h>    // ip header struct
#include <netinet/udp.h>   // udp header struct
#include <pcap.h>          // pcap libary
#include <unistd.h>

#define MAX_PACKET_SIZE 65535

/* some useful identifiers:
 * - ETH_ALEN = 6   (ethernet address length)
 * - ETH_HLEN = 14	(ethernet header length)
*/

// TODO 5
void modify_mac_address(struct ether_header *eth_header) {
    // struct ether_header reference:
    // https://sites.uclouvain.be/SystInfo/usr/include/net/ethernet.h.html
    uint8_t newSrcMac[ETH_ALEN] = {0x08, 0x00, 0x12, 0x34, 0x56, 0x78};
    uint8_t newDstMac[ETH_ALEN] = {0x08, 0x00, 0x12, 0x34, 0xac, 0xc2};

    memcpy(eth_header->ether_shost, newSrcMac, ETH_ALEN);
    memcpy(eth_header->ether_dhost, newDstMac, ETH_ALEN);
}

// TODO 6
void modify_ip_address(struct ip *ip_header) {
    in_addr_t newSrcIp = inet_addr("10.1.1.3");
    in_addr_t newDstIp = inet_addr("10.1.1.4");

    ip_header->ip_src.s_addr = newSrcIp;
    ip_header->ip_dst.s_addr = newDstIp;
}

int main() {

    // TODO 1: Open the pcap file
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *pcapFile = pcap_open_offline("custom_packets.pcap", errbuf);
    if (pcapFile == NULL) {
        std::cerr << "Error: " << errbuf << std::endl;
        return 1;
    }

    // TODO 2: Open session with loopback interface "lo"
    pcap_t *loopInterface = pcap_open_live("lo", MAX_PACKET_SIZE, 1, 1000, errbuf);
    if (loopInterface == NULL) {
        std::cerr << "Error: " << errbuf << std::endl;
        return 1;
    }

    struct pcap_pkthdr *header;
    const u_char *packet;

    // TODO 8: Variables to store the time difference between each packet
    struct timeval prevPacketTime = {0, 0};

    // TODO 3: Loop through each packet in the pcap file
    while (pcap_next_ex(pcapFile, &header, &packet) == 1) {

        // TODO 4: Send the original packet
        std::cout << "Sending original packet at time: " << header->ts.tv_sec << " sec"<< std::endl;
        pcap_inject(loopInterface, packet, header->len);

        // TODO 5: Modify mac address (function up above)
        struct ether_header *eth_header = (struct ether_header *)packet;
        modify_mac_address(eth_header);

        // TODO 6: Modify ip address if it is a IP packet (hint: ether_type)
        if (eth_header->ether_type == htons(ETHERTYPE_IP)) {
            // Assuming Ethernet headers
            struct ip *ip_header = (struct ip *)(packet + ETH_HLEN);
            modify_ip_address(ip_header);   // modify function up above
        }

        // TODO 8: Calculate the time difference between the current and the
        // previous packet and sleep. (hint: usleep)
        struct timeval currentTime = header->ts;
        if (prevPacketTime.tv_sec == 0)
            prevPacketTime = currentTime;
        usleep(
            (currentTime.tv_sec - prevPacketTime.tv_sec) * 1000000 +
            (currentTime.tv_usec - prevPacketTime.tv_usec)
        );

        // TODO 7: Send the modified packet
        std::cout << "Sending modified packet at time: " << header->ts.tv_sec << " sec" << std::endl;
        pcap_inject(loopInterface, packet, header->len);

        // TODO 8: Update the previous packet time
        prevPacketTime = currentTime;
    }

    // Close the pcap file
    pcap_close(pcapFile);
    pcap_close(loopInterface);
    
    return 0;
}