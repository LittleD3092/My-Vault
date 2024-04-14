rng(0);


% ####################
% ### Task 1: P_rx ###
% ####################
fprintf('####################\n');
fprintf('### Task 1: P_rx ###\n');
fprintf('####################\n\n');

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

d = 100; % Distance in meters
[P_rx_W, P_rx_dBm] = calculate_received_power(d);
fprintf('At a distance of %f meters, the received power is %e W (%f dBm).\n\n', d, P_rx_W, P_rx_dBm);

% ##################################
% ### Task 2: Channel Generation ###
% ##################################
fprintf('##################################\n');
fprintf('### Task 2: Channel Generation ###\n');
fprintf('##################################\n\n');
function [h] = generate_channel()
    % get a, b from a Gaussian normal distribution
    a = randn;
    b = randn;

    % generate h
    h = a + 1i * b;
end
function [h_scaled] = generate_scaled_channel(P_rx_W)
    h = generate_channel();
    scale_factor = sqrt(P_rx_W / abs(h)^2);
    h_scaled = h * scale_factor;
end
h_scaled = generate_scaled_channel(P_rx_W);
fprintf('The scaled channel is: %e + %ei.\n\n', real(h_scaled), imag(h_scaled));

% ##########################
% ### Task 3: Modulation ###
% ##########################
fprintf('##########################\n');
fprintf('### Task 3: Modulation ###\n');
fprintf('##########################\n\n');
function [random_bits] = generate_random_bits(N)
    random_bits = randi([0, 1], 1, N);
end

function [symbols] = BPSK_modulate(bits)
    symbols = 2 * bits - 1;

    % Normalize symbols
    expected_power = abs(-1)^2 * 0.5 + abs(1)^2 * 0.5;
    symbols = symbols / sqrt(expected_power);
end

function [symbols] = QPSK_modulate(bits)
    N = length(bits);
    symbols = zeros(1, N/2);
    for i = 1:2:N
        if bits(i) == 0 && bits(i+1) == 0
            symbols((i+1)/2) = 1 + 1i;
        elseif bits(i) == 0 && bits(i+1) == 1
            symbols((i+1)/2) = -1 + 1i;
        elseif bits(i) == 1 && bits(i+1) == 0
            symbols((i+1)/2) = 1 - 1i;
        else
            symbols((i+1)/2) = -1 - 1i;
        end
    end

    % Normalize symbols
    expected_power = abs(1 + 1i)^2;
    symbols = symbols / sqrt(expected_power);
end

function [symbols] = QAM16_modulate(bits)
    N = length(bits);
    symbols = zeros(1, N/4);
    
    for i = 1:4:N
        % Initialize real and imaginary parts
        real_part = 0;
        imag_part = 0;

        % Determine real part
        if bits(i) == 0 && bits(i+1) == 0
            real_part = -3;
        elseif bits(i) == 0 && bits(i+1) == 1
            real_part = -1;
        elseif bits(i) == 1 && bits(i+1) == 1
            real_part = 1;
        else % bits(i) == 1 && bits(i+1) == 0
            real_part = 3;
        end

        % Determine imaginary part
        if bits(i+2) == 0 && bits(i+3) == 0
            imag_part = 3;
        elseif bits(i+2) == 0 && bits(i+3) == 1
            imag_part = 1;
        elseif bits(i+2) == 1 && bits(i+3) == 1
            imag_part = -1;
        else % bits(i+2) == 1 && bits(i+3) == 0
            imag_part = -3;
        end

        % Store symbol
        symbols((i+3)/4) = real_part + 1i * imag_part;
    end

    % Normalize symbols
    expected_power = ( ...
        abs(-3 + 3i)^2 * 4 + ...
        abs(-3 + 1i)^2 * 8 + ...
        abs(-1 + 1i)^2 * 4 ...
    ) / 16;
    symbols = symbols / sqrt(expected_power);
end

function [symbols] = QAM64_modulate(bits)
    N = length(bits);
    symbols = zeros(1, N/6);

    for i=1:6:N
        % Initialize real and imaginary parts
        real_part = 0;
        imag_part = 0;

        % Determine real part
        if bits(i:i+2) == [0 0 0]
            real_part = -7;
        elseif bits(i:i+2) == [0 0 1]
            real_part = -5;
        elseif bits(i:i+2) == [0 1 1]
            real_part = -3;
        elseif bits(i:i+2) == [0 1 0]
            real_part = -1;
        elseif bits(i:i+2) == [1 1 0]
            real_part = 1;
        elseif bits(i:i+2) == [1 1 1]
            real_part = 3;
        elseif bits(i:i+2) == [1 0 1]
            real_part = 5;
        else % bits(i:i+2) == [1 0 0]
            real_part = 7;
        end

        % Determine imaginary part
        if bits(i+3:i+5) == [0 0 0]
            imag_part = 7;
        elseif bits(i+3:i+5) == [0 0 1]
            imag_part = 5;
        elseif bits(i+3:i+5) == [0 1 1]
            imag_part = 3;
        elseif bits(i+3:i+5) == [0 1 0]
            imag_part = 1;
        elseif bits(i+3:i+5) == [1 1 0]
            imag_part = -1;
        elseif bits(i+3:i+5) == [1 1 1]
            imag_part = -3;
        elseif bits(i+3:i+5) == [1 0 1]
            imag_part = -5;
        else % bits(i+3:i+5) == [1 0 0]
            imag_part = -7;
        end

        % Store symbol
        symbols((i+5)/6) = real_part + 1i * imag_part;
    end

    % Normalize symbols
    sample_symbols = zeros(1, 64);
    for i = 1:8
        for j = 1:8
            sample_symbols((i-1)*8 + j) = (2*i - 9) + 1i * (2*j - 9);
        end
    end
    expected_power = sum(abs(sample_symbols).^2) / 64;
    symbols = symbols / sqrt(expected_power);
end

function [average_power] = calculate_average_power(symbols)
    average_power = mean(abs(symbols).^2);
end

N = 300000; % Number of bits
bits = generate_random_bits(N);
symbols_BPSK = BPSK_modulate(bits);
symbols_QPSK = QPSK_modulate(bits);
symbols_QAM16 = QAM16_modulate(bits);
symbols_QAM64 = QAM64_modulate(bits);

fprintf('First 12 bits of the random bits: %s\n', num2str(bits(1:12)));
fprintf('First 12 BPSK symbols: %s\n', num2str(symbols_BPSK(1:12)));
fprintf('First 6 QPSK symbols: %s\n', num2str(symbols_QPSK(1:6)));
fprintf('First 3 QAM16 symbols: %s\n', num2str(symbols_QAM16(1:3)));
fprintf('First 2 QAM64 symbols: %s\n\n', num2str(symbols_QAM64(1:2)));

average_power_BPSK = calculate_average_power(symbols_BPSK);
average_power_QPSK = calculate_average_power(symbols_QPSK);
average_power_QAM16 = calculate_average_power(symbols_QAM16);
average_power_QAM64 = calculate_average_power(symbols_QAM64);

% #####################################
% ### Task 4: Transmit over the Air ###
% #####################################
fprintf('#####################################\n');
fprintf('### Task 4: Transmit over the Air ###\n');
fprintf('#####################################\n\n');
function [noise] = generate_noise(N, noise_power_dBm)
    noise_power_W = 10^(noise_power_dBm / 10) * 1e-3;
    noise = zeros(1, N);
    for i = 1:N
        a = randn * sqrt(noise_power_W / 2);
        b = randn * sqrt(noise_power_W / 2);
        noise(i) = a + 1i * b;
    end
end

function [received_symbols] = transmit_symbol(symbols, h, noise)
    K = length(symbols);
    received_symbols = h * symbols + noise(1:K);
end

noise_power_dBm = -90; % Noise power in dBm
noise_power_W = 10^(noise_power_dBm / 10) * 1e-3;
noise = generate_noise(N, noise_power_dBm);

received_symbols_BPSK = transmit_symbol(symbols_BPSK, h_scaled, noise);
received_symbols_QPSK = transmit_symbol(symbols_QPSK, h_scaled, noise);
received_symbols_QAM16 = transmit_symbol(symbols_QAM16, h_scaled, noise);
received_symbols_QAM64 = transmit_symbol(symbols_QAM64, h_scaled, noise);

fprintf('First 3 received BPSK symbols: %s\n', num2str(received_symbols_BPSK(1:3)));
fprintf('First 3 received QPSK symbols: %s\n', num2str(received_symbols_QPSK(1:3)));
fprintf('First 3 received QAM16 symbols: %s\n', num2str(received_symbols_QAM16(1:3)));
fprintf('First 3 received QAM64 symbols: %s\n\n', num2str(received_symbols_QAM64(1:3)));

% #######################################
% ### Task 5: Decode and Demodulation ###
% #######################################
fprintf('#######################################\n');
fprintf('### Task 5: Decode and Demodulation ###\n');
fprintf('#######################################\n\n');
function [bits, symbols] = BPSK_demodulate(received_symbols, h)
    symbols = received_symbols / h;
    bits = symbols > 0;
end

function [bits, symbols] = QPSK_demodulate(received_symbols, h)
    symbols = received_symbols / h;
    bits = zeros(1, 2 * length(symbols));
    for i = 1:length(symbols)
        if imag(symbols(i)) > 0
            bits(2*i - 1) = 0;
        else
            bits(2*i - 1) = 1;
        end

        if real(symbols(i)) > 0
            bits(2*i) = 0;
        else
            bits(2*i) = 1;
        end
    end
end

function [bits, symbols] = QAM16_demodulate(received_symbols, h)
    symbols = received_symbols / h;
    constellations = [ ...
        -3+3i, -1+3i, 1+3i, 3+3i, ...
        -3+1i, -1+1i, 1+1i, 3+1i, ...
        -3-1i, -1-1i, 1-1i, 3-1i, ...
        -3-3i, -1-3i, 1-3i, 3-3i ...
    ];
    normalized_constellations = constellations / sqrt(mean(abs(constellations).^2));
    bits_of_constellations = [ ...
        0 0 0 0; 0 1 0 0; 1 1 0 0; 1 0 0 0; ...
        0 0 0 1; 0 1 0 1; 1 1 0 1; 1 0 0 1; ...
        0 0 1 1; 0 1 1 1; 1 1 1 1; 1 0 1 1; ...
        0 0 1 0; 0 1 1 0; 1 1 1 0; 1 0 1 0 ...
    ];
    bits = zeros(1, 4 * length(symbols));
    for i = 1:length(symbols)
        distances = abs(symbols(i) - normalized_constellations);
        [~, index] = min(distances);
        bits((i-1)*4 + 1:i*4) = bits_of_constellations(index, :);
    end
end

function [bits, symbols] = QAM64_demodulate(received_symbols, h)
    symbols = received_symbols / h;
    constellations = zeros(1, 64);
    for i = 1:8
        for j = 1:8
            constellations((i-1)*8 + j) = (2*i - 9) + 1i * (-2*j + 9);
        end
    end
    normalized_constellations = constellations / sqrt(mean(abs(constellations).^2));
    bits_of_constellations = zeros(64, 6);
    gray_code = [0 0 0; 0 0 1; 0 1 1; 0 1 0; 1 1 0; 1 1 1; 1 0 1; 1 0 0];
    for i = 1:8
        for j = 1:8
            bitsI = gray_code(i, :);
            bitsQ = gray_code(j, :);
            bits_of_constellations((i-1)*8 + j, :) = [bitsI bitsQ];
        end
    end
    bits = zeros(1, 6 * length(symbols));
    for i = 1:length(symbols)
        distances = abs(symbols(i) - normalized_constellations);
        [~, index] = min(distances);
        bits((i-1)*6 + 1:i*6) = bits_of_constellations(index, :);
    end
end

[bits_BPSK, symbols_BPSK_prime] = BPSK_demodulate(received_symbols_BPSK, h_scaled);
[bits_QPSK, symbols_QPSK_prime] = QPSK_demodulate(received_symbols_QPSK, h_scaled);
[bits_QAM16, symbols_QAM16_prime] = QAM16_demodulate(received_symbols_QAM16, h_scaled);
[bits_QAM64, symbols_QAM64_prime] = QAM64_demodulate(received_symbols_QAM64, h_scaled);

fprintf('First 10 demodulated BPSK bits: %s\n', num2str(bits_BPSK(1:10)));
fprintf('First 10 demodulated QPSK bits: %s\n', num2str(bits_QPSK(1:10)));
fprintf('First 10 demodulated QAM16 bits: %s\n', num2str(bits_QAM16(1:10)));
fprintf('First 10 demodulated QAM64 bits: %s\n\n', num2str(bits_QAM64(1:10)));

% #############################
% ### Task 6: Calculate SNR ###
% #############################
fprintf('#############################\n');
fprintf('### Task 6: Calculate SNR ###\n');
fprintf('#############################\n\n');
empirical_noise_BPSK = symbols_BPSK_prime - symbols_BPSK;
empirical_noise_QPSK = symbols_QPSK_prime - symbols_QPSK;
empirical_noise_QAM16 = symbols_QAM16_prime - symbols_QAM16;
empirical_noise_QAM64 = symbols_QAM64_prime - symbols_QAM64;

average_power_empirical_noise_BPSK_W = mean(abs(empirical_noise_BPSK).^2);
average_power_empirical_noise_QPSK_W = mean(abs(empirical_noise_QPSK).^2);
average_power_empirical_noise_QAM16_W = mean(abs(empirical_noise_QAM16).^2);
average_power_empirical_noise_QAM64_W = mean(abs(empirical_noise_QAM64).^2);
fprintf('Average power of BPSK empirical noise: %e W.\n', average_power_empirical_noise_BPSK_W);
fprintf('Average power of QPSK empirical noise: %e W.\n', average_power_empirical_noise_QPSK_W);
fprintf('Average power of QAM16 empirical noise: %e W.\n', average_power_empirical_noise_QAM16_W);
fprintf('Average power of QAM64 empirical noise: %e W.\n\n', average_power_empirical_noise_QAM64_W);

average_power_empirical_noise_BPSK_dBm = 10 * log10(average_power_empirical_noise_BPSK_W * 1e3);
average_power_empirical_noise_QPSK_dBm = 10 * log10(average_power_empirical_noise_QPSK_W * 1e3);
average_power_empirical_noise_QAM16_dBm = 10 * log10(average_power_empirical_noise_QAM16_W * 1e3);
average_power_empirical_noise_QAM64_dBm = 10 * log10(average_power_empirical_noise_QAM64_W * 1e3);
fprintf('Average power of BPSK empirical noise: %f dBm.\n', average_power_empirical_noise_BPSK_dBm);
fprintf('Average power of QPSK empirical noise: %f dBm.\n', average_power_empirical_noise_QPSK_dBm);
fprintf('Average power of QAM16 empirical noise: %f dBm.\n', average_power_empirical_noise_QAM16_dBm);
fprintf('Average power of QAM64 empirical noise: %f dBm.\n\n', average_power_empirical_noise_QAM64_dBm);

SNR_BPSK_W = average_power_BPSK / average_power_empirical_noise_BPSK_W;
SNR_QPSK_W = average_power_QPSK / average_power_empirical_noise_QPSK_W;
SNR_QAM16_W = average_power_QAM16 / average_power_empirical_noise_QAM16_W;
SNR_QAM64_W = average_power_QAM64 / average_power_empirical_noise_QAM64_W;
fprintf('SNR of BPSK: %f.\n', SNR_BPSK_W);
fprintf('SNR of QPSK: %f.\n', SNR_QPSK_W);
fprintf('SNR of QAM16: %f.\n', SNR_QAM16_W);
fprintf('SNR of QAM64: %f.\n\n', SNR_QAM64_W);

SNR_BPSK_dB = 10 * log10(SNR_BPSK_W);
SNR_QPSK_dB = 10 * log10(SNR_QPSK_W);
SNR_QAM16_dB = 10 * log10(SNR_QAM16_W);
SNR_QAM64_dB = 10 * log10(SNR_QAM64_W);
fprintf('SNR of BPSK: %f dB.\n', SNR_BPSK_dB);
fprintf('SNR of QPSK: %f dB.\n', SNR_QPSK_dB);
fprintf('SNR of QAM16: %f dB.\n', SNR_QAM16_dB);
fprintf('SNR of QAM64: %f dB.\n\n', SNR_QAM64_dB);

theoretical_SNR_W = P_rx_W - noise_power_W;
theoretical_SNR_dB = 10 * log10(theoretical_SNR_W);
fprintf('Theoretical SNR: %e W (%f dB).\n\n', theoretical_SNR_W, theoretical_SNR_dB);

% ####################################
% ### Task 7: Calculate Throughput ###
% ####################################
fprintf('####################################\n');
fprintf('### Task 7: Calculate Throughput ###\n');
fprintf('####################################\n\n');
function [PDR] = calculate_PDR(bits, bits_prime, pkt_size_bit)
    N = length(bits);
    errors = bits ~= bits_prime;
    success_pkt = 0;
    for i = 1:pkt_size_bit:N
        if sum(errors(i:i+pkt_size_bit-1)) == 0
            success_pkt = success_pkt + 1;
        end
    end
    PDR = success_pkt / (N / pkt_size_bit);
end

sample_duration_s = 3.2e-6;
pkt_size_byte = 500;
pkt_size_bit = pkt_size_byte * 8;
empirical_bit_err_rate_BPSK = sum(bits_BPSK ~= bits) / N;
empirical_bit_err_rate_QPSK = sum(bits_QPSK ~= bits) / N;
empirical_bit_err_rate_QAM16 = sum(bits_QAM16 ~= bits) / N;
empirical_bit_err_rate_QAM64 = sum(bits_QAM64 ~= bits) / N;
fprintf('Empirical bit error rate of BPSK: %e.\n', empirical_bit_err_rate_BPSK);
fprintf('Empirical bit error rate of QPSK: %e.\n', empirical_bit_err_rate_QPSK);
fprintf('Empirical bit error rate of QAM16: %e.\n', empirical_bit_err_rate_QAM16);
fprintf('Empirical bit error rate of QAM64: %e.\n\n', empirical_bit_err_rate_QAM64);

theoretical_PDR_BPSK = (1 - empirical_bit_err_rate_BPSK) ^ pkt_size_bit;
theoretical_PDR_QPSK = (1 - empirical_bit_err_rate_QPSK) ^ pkt_size_bit;
theoretical_PDR_QAM16 = (1 - empirical_bit_err_rate_QAM16) ^ pkt_size_bit;
theoretical_PDR_QAM64 = (1 - empirical_bit_err_rate_QAM64) ^ pkt_size_bit;
fprintf('Theoretical packet delivery rate of BPSK: %e.\n', theoretical_PDR_BPSK);
fprintf('Theoretical packet delivery rate of QPSK: %e.\n', theoretical_PDR_QPSK);
fprintf('Theoretical packet delivery rate of QAM16: %e.\n', theoretical_PDR_QAM16);
fprintf('Theoretical packet delivery rate of QAM64: %e.\n\n', theoretical_PDR_QAM64);

empirical_PDR_BPSK = calculate_PDR(bits, bits_BPSK, pkt_size_bit);
empirical_PDR_QPSK = calculate_PDR(bits, bits_QPSK, pkt_size_bit);
empirical_PDR_QAM16 = calculate_PDR(bits, bits_QAM16, pkt_size_bit);
empirical_PDR_QAM64 = calculate_PDR(bits, bits_QAM64, pkt_size_bit);
fprintf('Empirical packet delivery rate of BPSK: %f.\n', empirical_PDR_BPSK);
fprintf('Empirical packet delivery rate of QPSK: %f.\n', empirical_PDR_QPSK);
fprintf('Empirical packet delivery rate of QAM16: %f.\n', empirical_PDR_QAM16);
fprintf('Empirical packet delivery rate of QAM64: %f.\n\n', empirical_PDR_QAM64);

% total_bits_transferred = N * theoretical_PDR;
% total_time_s = sample_duration_s * (N / bits_per_sample);
% throughput = total_bits_transferred / total_time_s;
%            = N * theoretical_PDR / (sample_duration_s * (N / bits_per_sample));
%            = theoretical_PDR * bits_per_sample / sample_duration_s;
theoretical_throughput_BPSK = theoretical_PDR_BPSK * 1 / sample_duration_s;
theoretical_throughput_QPSK = theoretical_PDR_QPSK * 2 / sample_duration_s;
theoretical_throughput_QAM16 = theoretical_PDR_QAM16 * 4 / sample_duration_s;
theoretical_throughput_QAM64 = theoretical_PDR_QAM64 * 6 / sample_duration_s;
fprintf('Theoretical throughput of BPSK: %e bps.\n', theoretical_throughput_BPSK);
fprintf('Theoretical throughput of QPSK: %e bps.\n', theoretical_throughput_QPSK);
fprintf('Theoretical throughput of QAM16: %e bps.\n', theoretical_throughput_QAM16);
fprintf('Theoretical throughput of QAM64: %e bps.\n\n', theoretical_throughput_QAM64);

empirical_throughput_BPSK = empirical_PDR_BPSK * 1 / sample_duration_s;
empirical_throughput_QPSK = empirical_PDR_QPSK * 2 / sample_duration_s;
empirical_throughput_QAM16 = empirical_PDR_QAM16 * 4 / sample_duration_s;
empirical_throughput_QAM64 = empirical_PDR_QAM64 * 6 / sample_duration_s;
fprintf('Empirical throughput of BPSK: %e bps.\n', empirical_throughput_BPSK);
fprintf('Empirical throughput of QPSK: %e bps.\n', empirical_throughput_QPSK);
fprintf('Empirical throughput of QAM16: %e bps.\n', empirical_throughput_QAM16);
fprintf('Empirical throughput of QAM64: %e bps.\n\n', empirical_throughput_QAM64);

modulation_schemes = {'BPSK', 'QPSK', 'QAM16', 'QAM64'};
empirical_throughputs = [empirical_throughput_BPSK, empirical_throughput_QPSK, empirical_throughput_QAM16, empirical_throughput_QAM64];
[best_throughput, best_scheme_index] = max(empirical_throughputs);
best_scheme = modulation_schemes{best_scheme_index};
fprintf('Given a distance of %f meters, the best modulation scheme is %s with an empirical throughput of %e bps.\n\n', d, best_scheme, best_throughput);

% ############################
% ### Task 8: Plot Figures ###
% ############################
fprintf('############################\n');
fprintf('### Task 8: Plot Figures ###\n');
fprintf('############################\n\n');
function plot_constellation(symbols, title_str)
    figure;
    sc = scatter(real(symbols), imag(symbols), 'filled');
    sc.SizeData = 10;
    title(title_str);
    xlabel('Real');
    ylabel('Imaginary');
    grid on;
    axis equal;
    saveas(gcf, sprintf('pics/%s.png', strrep(title_str, ' ', '_')));
    fprintf('The plot has been saved as "pics/%s.png".\n', strrep(title_str, ' ', '_'));
end

% BPSK with 40m
d = 40;
[P_rx_W, ~] = calculate_received_power(d);
h_scaled = generate_scaled_channel(P_rx_W);
received_symbols_BPSK = transmit_symbol(symbols_BPSK, h_scaled, noise);
[bits_BPSK, symbols_BPSK_prime] = BPSK_demodulate(received_symbols_BPSK, h_scaled);
plot_constellation(symbols_BPSK_prime, 'BPSK Constellation with 40m');

% QPSK with 20m
d = 20;
[P_rx_W, ~] = calculate_received_power(d);
h_scaled = generate_scaled_channel(P_rx_W);
received_symbols_QPSK = transmit_symbol(symbols_QPSK, h_scaled, noise);
[bits_QPSK, symbols_QPSK_prime] = QPSK_demodulate(received_symbols_QPSK, h_scaled);
plot_constellation(symbols_QPSK_prime, 'QPSK Constellation with 20m');

% QAM16 with 10m
d = 10;
[P_rx_W, ~] = calculate_received_power(d);
h_scaled = generate_scaled_channel(P_rx_W);
received_symbols_QAM16 = transmit_symbol(symbols_QAM16, h_scaled, noise);
[bits_QAM16, symbols_QAM16_prime] = QAM16_demodulate(received_symbols_QAM16, h_scaled);
plot_constellation(symbols_QAM16_prime, 'QAM16 Constellation with 10m');

% QAM64 with 5m
d = 5;
[P_rx_W, ~] = calculate_received_power(d);
h_scaled = generate_scaled_channel(P_rx_W);
received_symbols_QAM64 = transmit_symbol(symbols_QAM64, h_scaled, noise);
[bits_QAM64, symbols_QAM64_prime] = QAM64_demodulate(received_symbols_QAM64, h_scaled);
plot_constellation(symbols_QAM64_prime, 'QAM64 Constellation with 5m');

% Throughput vs. Distance
function plot_throughput_vs_distance( ...
    BPSK_distance_vs_throughput, ...
    QPSK_distance_vs_throughput, ...
    QAM16_distance_vs_throughput, ...
    QAM64_distance_vs_throughput ...
)
    figure;
    hold on;
    plot(BPSK_distance_vs_throughput(:, 1), BPSK_distance_vs_throughput(:, 2), 'r', 'DisplayName', 'BPSK');
    plot(QPSK_distance_vs_throughput(:, 1), QPSK_distance_vs_throughput(:, 2), 'g', 'DisplayName', 'QPSK');
    plot(QAM16_distance_vs_throughput(:, 1), QAM16_distance_vs_throughput(:, 2), 'b', 'DisplayName', 'QAM16');
    plot(QAM64_distance_vs_throughput(:, 1), QAM64_distance_vs_throughput(:, 2), 'm', 'DisplayName', 'QAM64');
    hold off;
    title('Throughput vs. Distance');
    xlabel('Distance (m)');
    ylabel('Throughput (bps)');
    legend;
    grid on;
    saveas(gcf, 'pics/throughput_vs_distance.png');
    fprintf('The plot has been saved as "pics/throughput_vs_distance.png".\n');
end

BPSK_distance_vs_throughput = zeros(12, 2);
QPSK_distance_vs_throughput = zeros(12, 2);
QAM16_distance_vs_throughput = zeros(12, 2);
QAM64_distance_vs_throughput = zeros(12, 2);

for d = 50:50:600
    [P_rx_W, ~] = calculate_received_power(d);
    h_scaled = generate_scaled_channel(P_rx_W);

    received_symbols_BPSK = transmit_symbol(symbols_BPSK, h_scaled, noise);
    [bits_BPSK, symbols_BPSK_prime] = BPSK_demodulate(received_symbols_BPSK, h_scaled);
    empirical_PDR_BPSK = calculate_PDR(bits, bits_BPSK, pkt_size_bit);
    empirical_throughput_BPSK = empirical_PDR_BPSK * 1 / sample_duration_s;
    BPSK_distance_vs_throughput(d/50, :) = [d, empirical_throughput_BPSK];

    received_symbols_QPSK = transmit_symbol(symbols_QPSK, h_scaled, noise);
    [bits_QPSK, symbols_QPSK_prime] = QPSK_demodulate(received_symbols_QPSK, h_scaled);
    empirical_PDR_QPSK = calculate_PDR(bits, bits_QPSK, pkt_size_bit);
    empirical_throughput_QPSK = empirical_PDR_QPSK * 2 / sample_duration_s;
    QPSK_distance_vs_throughput(d/50, :) = [d, empirical_throughput_QPSK];

    received_symbols_QAM16 = transmit_symbol(symbols_QAM16, h_scaled, noise);
    [bits_QAM16, symbols_QAM16_prime] = QAM16_demodulate(received_symbols_QAM16, h_scaled);
    empirical_PDR_QAM16 = calculate_PDR(bits, bits_QAM16, pkt_size_bit);
    empirical_throughput_QAM16 = empirical_PDR_QAM16 * 4 / sample_duration_s;
    QAM16_distance_vs_throughput(d/50, :) = [d, empirical_throughput_QAM16];

    received_symbols_QAM64 = transmit_symbol(symbols_QAM64, h_scaled, noise);
    [bits_QAM64, symbols_QAM64_prime] = QAM64_demodulate(received_symbols_QAM64, h_scaled);
    empirical_PDR_QAM64 = calculate_PDR(bits, bits_QAM64, pkt_size_bit);
    empirical_throughput_QAM64 = empirical_PDR_QAM64 * 6 / sample_duration_s;
    QAM64_distance_vs_throughput(d/50, :) = [d, empirical_throughput_QAM64];
end

plot_throughput_vs_distance( ...
    BPSK_distance_vs_throughput, ...
    QPSK_distance_vs_throughput, ...
    QAM16_distance_vs_throughput, ...
    QAM64_distance_vs_throughput ...
);