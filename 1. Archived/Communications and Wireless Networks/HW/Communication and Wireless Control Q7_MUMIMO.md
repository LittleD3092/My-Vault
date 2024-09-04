# 1. What is “Multiplexing gain”?

Multiplexing gain is to transmit different data streams over each antenna, increasing the overall data rate.

# 2. What is "Diversity gain"?

Diversity gain is to transmit the same data stream over each antenna to increase the SNR of the single stream.

# 3. What is the (1) Degree of Freedom (DoF) and (2) Diversity of a 4x2 MIMO system?

1. **Degree of freedom**: The maximum number of streams that can be transmitted at the same time. For a $4 \times 2$ MIMO system, the degree of freedom is $2$.
2. **Maximum diversity**: The number of paths that exists among transmitter and receiver. For a $4 \times 2$ MIMO system, the maximum diversity is $8$.

# 4. Why should the antennas of a MIMO node should be separated by at least half wavelength?

The antenna should be separated by at least half wavelength because we need to ensure the channel dependency. When antennas are separated by a half wavelength, we ensure that the channels are not correlated to each other.

# 5. What does mmWave mean?

"mmWave", or millimeter-wave, refers to 24-100GHz. This frequency range has a huge amount of available bandwidth, but has small wavelength that leads to large path loss.

# 6. List two key properties of mmWave communications.

- The frequencies have a larger available bandwidth.
- The path loss of this communication is larger.

# 7. Why antenna array (device with a large number of anttena elements) is only practical for mmWave, instead of conventional cmWave spectrum?

The smaller wavelengths of mmWave allow the distance between two MIMO antennas to be smaller, allowing for a more compact design of antenna arrays.

# 8. Define what is “transmit beamforming” and “receive beamforming”, respectively.

Transmit beamforming is a technique that the phases and the relative amplitudes of each transmitting signal are modified to create a pattern of constructive interference in a specific direction.

Receive beamforming is a technique that the receiving signals of each antenna are combined with slightly different delay to make a constructive interference in a specific receiving direction.

# 9. Explain what does “beam scanning” mean.

Beam scanning is a technique to steer the direction of the beam of signals to find the optimal angle of transmitting and receiving. Beam scanning allows the AP and the client to know each others position, and finds the optimal direction to form the beam.

# 10. Compare a 16-antenna and 64-antenna array. Which one can generate a narrower beam?

64-antenna array. More antennas mean that the spatial resolution can be higher, so a narrower beam can be generated.

# 11. Describe what is “digital beamforming” and “analog beamforming”.

Digital beamforming is a technique that each stream is precoded using a calculated wave vector to nullify the interference.

Analog beamforming is a technique to use the antenna array to focus the power along one direction.

# 12. If a transmitter has 2 RF chains and is equipped with a 16-antnena array.

## 12.1. What is the maximum number of parallel streams it can send?

The maximum number of parallel streams is limited by the number of RF chains. Therefore the maximum number of parallel streams is 2.

## 12.2. What are the dimensions of the received signal y, the channel matrix H and precoders Frf and Fbb?

**Digital precoder** $F_{\rm bb}$ maps the data streams to the RF chains, therefore:

$$N_{RF} \times N_s = 2 \times 2$$

**Analog precoder** $F_{\rm rf}$ maps the RF chains to the transmit antennas, therefore:

$$N_t\times N_{RF} = 16 \times 2$$

The receiver has an 8-antenna array, so the dimension of the **received signals** $y$ is:

$$
8 \times 1
$$

Given that the receiver has an 8-antenna array, and the transmitter has a 16-antenna array. The **channel** $H$ maps the transmitting signals to the receiving signals, therefore $H$ has a dimension:

$$
8 \times 16
$$