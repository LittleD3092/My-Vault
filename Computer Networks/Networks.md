標籤: #computer-networks #list 

---

[TOC]

---

# Types of Networks

## Access Networks

### Cable-Based Access

![[Pasted image 20221023202019.png]]

- As illustrated in figure above, fiber optics connect the cable head end to neighborhood-level junctions, from which traditional coaxial cable is then used to reach individual houses and apartments.
- Each junction typically supports 500 to 5,000 homes.
- Because both fiber and coaxial cable are employed in this system, it is often referred to as hybrid fiber coas (HFC).
- At the cable head end, the cable modem termination system (CMTS) serves a similar function as the [[#Digital Subscriber Line (DSL)]] network's DSLAM. 
- Cable modems divide the HFC network into two channels, a upstream channel and a down stream channel.

![[cable based access - computer network basics.png]]

The cable-based access is usually established using the television cable. DIfferent homes shares a cable, therefore one's internet bandwidth is dependent on whether others is using the cable too.

One cable can be splitted to different channels by frequency. In this way, the bandwidth will be larger. This technology is called "frequency division multiplexing", "FDM".

### Digital Subscriber Line (DSL)

![[digital subscriber line - computer network basics.png|400]]

The DSL access is usually established using telephone cables. Each house has a dedicated cable, therefore your bandwidth does not share with other houses.

The residential telephone line carries both data and triditional telephone signals simultaneously, which are encoded at different frequencies:

- A high-speed downstream channel, in the $50\text{ kHz}$ to $1\text{ MHz}$ band.
- A medium-speed upstream channel, in the $4\text{ kHz}$ to $50 \text{ kHz}$ band.
- An ordinary two-way telephone channel, in the $0$ to $4\text{ kHz}$ band.

Due to this, the speed for downstream and upstream is different, which we called ==asymmetric==.

### Fiber to the Home (FTTH)

Although [[#Digital Subscriber Line (DSL)]] and [[#Cable-Based Access]] represent the majority of residential broadband access, an up-and-coming technology that provides even higher speeds is ==fiber to the home (FTTH)==.

The FTTH concept is simple: provide an optical fiber path from the CO directly to the home. Each fiber leaving the central office is actually shared by many homes.


There are two competing optical-distribution network architectures that perform the splitting at the optical splitter:

- active optical networks (AONs)
- [[#Passive Optical Networks (PONs)]]

#### Passive Optical Networks (PONs)

![[Pasted image 20221023203404.png|500]]

- Each home has an optical network terminator (ONT).
- The splitter combines a number of homes (typically less than 100) on to a single, shared optical fiber, which connect to an optical line terminator (OLT) in the telco's CO.

### 5G Fixed Wireless

5G fixed wireless is a new way of network access. It not only promises high-speed residential access, but will do so without installing costly and failure-prone cabling from the telco's CO to the home.

Data is sent wirelessly from a provider's base station to the modem in the home. A WiFi wireless router is connected to the modem, similar to how a WiFi wireless router is connected to a cable or DSL modem.

### Home Networks

![[home networks - computer networks basics.png|400]]

### Enterprise Networks

![[enterprise networks - computer networks basics.png|400]]

This kind of networks is used in companies and universities, places that need both wireless and wired access, also have a wide range.

Enterprise networks are mixed of wired, wireless link technologies, and connects a mix of switches and routes.

## Wireless Access Networks

### Wireless Local Area Networks (WLANs)

![[wireless local area networks - computer networks basics.png|300]]

Wifi is this type of networks. This network has a very short range, but the speed is better than [[#Wide-Area Cellular Access Networks]].

### Wide-Area Cellular Access Networks

![[wide-area cellular access networks.png|300]]

This kind of networks is provided by mobile or cellular network operator. 4G cellular networks is this type of network.

Wide-area cellular access networks have higher range than [[#Wireless Local Area Networks WLANs]], however the bandwidth is smaller.

# Core of Network

The core of network is the approaches to moving data through a network of links and switches. There are two fundamental approaches:

- [[#Packet Switching]]
- [[#Circuit Switching]]

## Packet Switching

![[Packet Switching]]

## Circuit Switching

![[Circuit Switching]]

# Network of Networks

As we see in [[#Types of Networks]], we know that end systems connect into the Internet via an access ISP. But to acheive a world-wide Internet, the access ISPs themselves must be interconnected. This is done by creating a ==network of networks==.

- There may be a ==regional ISP== to which the access ISPs in the region connect.
- Each regional ISP connects to ==tier-1 ISPs==. Note that no tier-1 ISP cover every city in the world.
- Providers provide a group of one or more routers (at the same location) for customers to directly connect. The group of routers is called ==Points of Presence (PoP)==.
- In case of a higher tier failure, a access ISP may connect to multiple regional ISPs, or even tier-1 ISPs. This is called ==multi-home==.
- To reduce the cost that a customer ISP pays a provider ISP, customer ISPs can ==peer==. 
	- This means that they directly connect their networks together so that all the traffic between them passes over the direct connection.
- A third-party company can create an ==Internet Exchange Point (IXP)==, which is a meeting point where multiple ISPs can peer together.
- Content providers build its own networks, ==content-provider networks==, to reduce the cost of paying ISPs.
	- Google has its private network, which spans the entire globe.

---

參考資料:

Computer Networking, A Top-Down Approach, 8th edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.