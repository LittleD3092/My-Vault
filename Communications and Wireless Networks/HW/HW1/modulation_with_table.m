function [P_rx_W, P_rx_dBm] = ...
    calculate_received_power(d)
    % Constants
    c = 3e8; % Speed of light (m/s)

    % Tx Parameters
    f = 2.4e9; % Frequency (Hz)
    P_tx_dBm = 10; % Transmit power (dBm)
    P_tx = 10^(P_tx_dBm / 10) * 1e-3; % Transmit power (W)
    G_tx = 1; % Transmit antenna gain

    % Rx Parameters
    G_rx = 1; % Receive antenna gain

    % Calculate the wavelength
    lambda = c / f;

    % Received Power (dBm)
    P_rx_dBm = P_tx_dBm + 10 * log10(G_tx) + ...
        10 * log10(G_rx) + ...
        20 * log10(lambda / (4 * pi * d));

    % Convert dBm to Watts
    P_rx_W = 10^(P_rx_dBm / 10) * 1e-3;
end

function [best_scheme] = best_modulation_scheme(d, l)
    % d: distance in meters
    % l: packet length in bits
    % best_scheme: best modulation scheme

    load('SNR_BER.mat');

    [P_rx_W, P_rx_dBm] = calculate_received_power(d);
    noise_power_dBm = -90;
    noise_power_W = 10^(noise_power_dBm/10) * 1e-3;
    SNR = P_rx_W / noise_power_W;
    
    if SNR > 31
        BER = [0; 0; 0; 0];
    else
        SNR_floor = floor(SNR);
        delta = SNR - SNR_floor;
        BER = SNR_BER(:, SNR_floor) * (1 - delta) + SNR_BER(:, SNR_floor + 1) * delta;
    end

    PDR = (1 - BER) .^ l;

    sample_duration_s = 3.2e-6;
    throughput = [1; 2; 4; 6] .* PDR / sample_duration_s;
    [best_throughput, best_scheme_index] = max(throughput);
    modulation_schemes = ["BPSK", "QPSK", "16-QAM", "64-QAM"];
    best_scheme = modulation_schemes(best_scheme_index);
end

fprintf('| Distance (m) / Packet Length (bits) | 500 | 1000 | 2000 | 4000 | 8000 |\n');
fprintf('| --- | --- | --- | --- | --- | --- |\n');
for d = 50:50:600
    fprintf('| %d |', d);
    for l = [500, 1000, 2000, 4000, 8000]
        best_scheme = best_modulation_scheme(d, l);
        fprintf(' %s |', best_scheme);
    end
    fprintf('\n');
end