109611066 吳典謀

## 1. What does Medium Access Control (MAC) mean?

Medium access control is a layer that controls the network card (hardware). (<u>1</u>)

## 2. What is the MAC method used by a cellular network (4G, LTE, 5G)?

Orthogonal frequency-division multiplexing (OFDM) (<u>2</u>). It is a random access method for dynamically assign the bandwidth.

## 3. What is the MAC method used by WiFi (802.11)?

Carrier sense multiple access with collision avoidance (CSMA/CA) (<u>3</u>). It is a random access method for dynamically manage the wireless medium.

## 4. What are the pros and cons of MAC protocols based on fixed assignment?

- Pros: Fixed assignment can guarantee bandwidth for real-time communication.
- Cons: If a device has little data to transmit, the slot allocated is wasted, causing the resources underutilized.

## 5. What are the pros and cons of MAC protocols based on Random access?

- Pros: Easy to allocate resources dynamically.
- Cons: Devices that try to transmit data can cause collisions, and the performance of the protocol is more unpredictable.

## 6. What does half-duplex mean?

Half-duplex means that two devices can transmit data in either directions, but not simultaneously. The communication is one direction at a time. (<u>4</u>)

## 7. What does a collision mean?

When two or more devices try to access the same network resource, a collision happens. In this case, data streams interfere each other.

## 8. What does collision avoidance mean? Why don't we eliminate collisions completely?

Collision avoidance means that we wait for a random period of time if there is another device transmitting data currently.

Methods that eliminate collisions completely will lose the benefit of better resource utilization.

## 9. What does the hidden terminal problem mean?

Hidden terminal problem occurs when a listening device is in the range of two transmitting devices, and both transmitting devices don't know the presence of each other. (<u>5</u>)

This problem causes two data streams from two transmitting devices interfere each other.

## Reference

1. “Medium access control,” Wikipedia. Jan. 27, 2024. Accessed: Mar. 05, 2024. [Online]. Available: https://en.wikipedia.org/w/index.php?title=Medium_access_control&oldid=1199429241
2. “Orthogonal frequency-division multiplexing,” Wikipedia. Feb. 12, 2024. Accessed: Mar. 05, 2024. [Online]. Available: https://en.wikipedia.org/w/index.php?title=Orthogonal_frequency-division_multiplexing&oldid=1206391364
3. P. Brenner, “A Technical Tutorial on the IEEE 802.11 Protocol,” 1996.
4. “Duplex (telecommunications),” Wikipedia. Dec. 09, 2023. Accessed: Mar. 05, 2024. [Online]. Available: https://en.wikipedia.org/w/index.php?title=Duplex_(telecommunications)&oldid=1189125500
5. “Hidden node problem,” Wikipedia. Sep. 07, 2022. Accessed: Mar. 05, 2024. [Online]. Available: https://en.wikipedia.org/w/index.php?title=Hidden_node_problem&oldid=1109046656