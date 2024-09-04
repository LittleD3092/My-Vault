function  pathloss_dbm = friis_equation(freq, tx_gain, rx_gain, tx_rx_distance)
    wave_length = 3e8/freq;
    M1 = (4 * pi * tx_rx_distance) / wave_length;
    pathloss_dbm = 10*log10(tx_gain) + 10*log10(rx_gain) - 20*log10(M1);
end