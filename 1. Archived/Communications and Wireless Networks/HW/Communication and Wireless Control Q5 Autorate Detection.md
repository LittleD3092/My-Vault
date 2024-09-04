109611066 吳典謀

## 1. What does MCS stand for?

MCS stands for modulation and coding scheme. It is the definition of how many bits can be transmitted per RE (resource element). (<u>1</u>)

## 2. What does the “order” of a modulation scheme mean?

Modulation order is the number of different symbols that can be transmitted using the corresponding modulation scheme. (<u>2</u>)

## 3. What is the pros and cons of a high-order modulation scheme?

- **Pros**: More information bits can be conveyed. (<u>3</u>)
- **Cons**: Requires a higher signal to noise ratio. (<u>4</u>)

## 4. The statement “A high-order modulation scheme can always produce a higher throughput.” is truth or false? Give your reason.

False. A high-order modulation scheme requires a higher signal to noise ratio. If it is not satisfied, data loss and re-transmission will occur which produces a lower throughput.

## 5. Why do we need a rate adaptation algorithm?

Rate adaption algorithms choose the best MCS depending on the channel state. (<u>5</u>) It is crucial that we need a rate adaptation algorithm to dynamically adapt the current state of the channel.

## 6. The goal of a rate adaptation algorithm is trying to maximize which performance metric?

It uses the bit rate and/or bit error rates as the performance metric to maximize performance. (<u>6</u>)

## 7. What could be the challenges of a rate-adaptation algorithm? (just guess)

There might be a delay between the detection of the network condition and the adaptation action taken by the algorithm. This delay can result in mismatches between the available bandwidth and the rate of transmission, causing reduced quality.

## 8. “Packet detection” is the function of capturing the start of a packet. Do you think “packet detection” is hard when the SNR is high or low? Why?

When the signal-to-noise ratio is low, it means that there are more noise. More noise will mean more errors, so packet detection is hard when the SNR is low.

## 9. What is the preamble of a WiFi frame? Why do we need a preamble for packet detection?

The preamble of a WiFi frame is a beginning section that is used to support frame detection, synchronization, and channel estimation. (<u>7</u>)

A preamble can indicate the start of a packet and make packet detection easier.

## Reference

1. “LTE Modulation and Coding Scheme (MCS).” Accessed March 21, 2024. http://anisimoff.org/eng/lte_mcs.html.
2. “Modulation Order.” In Wikipedia, July 5, 2023. https://en.wikipedia.org/w/index.php?title=Modulation_order&oldid=1163507401.
3. Chapman, Thomas, Erik Larsson, Peter von Wrycza, Erik Dahlman, Stefan Parkvall, and Johan Sköld. “Chapter 10 - Higher-Order Modulation.” In HSPA Evolution, edited by Thomas Chapman, Erik Larsson, Peter von Wrycza, Erik Dahlman, Stefan Parkvall, and Johan Sköld, 219–33. Oxford: Academic Press, 2015. https://doi.org/10.1016/B978-0-08-099969-2.00010-7.
4. Parker, Michael. “Chapter 17 - Orthogonal Frequency Division Multiple Access Wireless Communications.” In Digital Signal Processing 101 (Second Edition), edited by Michael Parker, 209–30. Newnes, 2017. https://doi.org/10.1016/B978-0-12-811453-7.00017-2.
5. Sammour, Ibrahim, and Gerard Chalhoub. “Evaluation of Rate Adaptation Algorithms in IEEE 802.11 Networks.” Electronics 9, no. 9 (September 2020): 1436. https://doi.org/10.3390/electronics9091436.
6. “Link Adaptation.” In Wikipedia, July 24, 2022. https://en.wikipedia.org/w/index.php?title=Link_adaptation&oldid=1100051421.
7. Zhang, Zhengguang, and Marwan Krunz. “Preamble Injection and Spoofing Attacks in Wi-Fi Networks.” In 2021 IEEE Global Communications Conference (GLOBECOM), 1–6, 2021. https://doi.org/10.1109/GLOBECOM46510.2021.9685461.