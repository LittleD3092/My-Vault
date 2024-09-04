close all; clear; clc;
addpath ./tasks;

rng(1);

% Environment Configurations
tx_node_number = 1;          % Number of Tx users
rx_node_number = 2;          % Number of Rx users
analog_antenna_number = 16;  % Number of Tx antennas of analog
digital_antenna_number = 2;  % Number of Tx antennas of digital
rx_antenna_number = 1;       % Number of Rx antennas

% Generate receivers with beam direction and distances
% [x y] = rand_rx_location_list(tx_beam_direction_idx)
rand_rx_location_list = [];
for tx_beam = 0:10:180
    tmp = [];
    for d = 50:50:500
        offset = -5 + 10 * rand();       % -5~5 degrees
        x = d * cosd(tx_beam + offset);  % Add a small random offset
        y = d * sind(tx_beam + offset);  % Add a small random offset
        tmp = [tmp x y];
    end
    rand_rx_location_list = [rand_rx_location_list; tmp];
end

% Define coordination and power for transmitter
origin = [0, 0];
tx_location = origin;
P_tx_dBm = 10;          % Transmission power of Tx (dBm)
N0_dBm = -95;           % Assume noise power is -90 dBm

% Randomly select receiver's coordination at d=200
rand_idx = randperm(numel(0:10:180), 2);
rx1_location = rand_rx_location_list(rand_idx(1), (7:8));
rx2_location = rand_rx_location_list(rand_idx(2), (7:8));

% TODO: Implement Analog Beamforming functions in /tasks
% Hint: you can adjust input/output for reports
[rx1_SNR_dbm, rx2_INR_dbm] = analog_beamforming(P_tx_dBm, N0_dBm, tx_location, rx1_location, rx2_location, analog_antenna_number, 19);

fprintf('Task1: SNR Calculation\n');
fprintf('Receiver1\tSNR: %f dBm\tReceiver2 INR: %f dBm\n', rx1_SNR_dbm, rx2_INR_dbm);

% Plot SNR and INR for different distances
antenna_n_SNR_dBm_d = []; % 2d matrix, with dimension (antenna_number, distance) and value of SNR (dBm)
antenna_n_INR_dBm_d = []; % 2d matrix, with dimension (antenna_number, distance) and value of INR (dBm)
for analog_antenna_number = [8, 16]
    SNR_dBm_d = []; % list to store SNR for different distances
    INR_dBm_d = []; % list to store INR for different distances
    for d = 50:50:500
        sum_SNR_dBm = 0;
        sum_INR_dBm = 0;
        for i = 1:10
            rand_idx = randperm(numel(0:10:180), 2);
            distance_idx = (d / 50) * 2 - 1;
            rx1_location = rand_rx_location_list(rand_idx(1), (distance_idx:distance_idx+1));
            rx2_location = rand_rx_location_list(rand_idx(2), (distance_idx:distance_idx+1));
            [rx1_SNR_dbm, rx2_INR_dbm] = analog_beamforming(P_tx_dBm, N0_dBm, tx_location, rx1_location, rx2_location, analog_antenna_number, 19);
            sum_SNR_dBm = sum_SNR_dBm + rx1_SNR_dbm;
            sum_INR_dBm = sum_INR_dBm + rx2_INR_dbm;
        end
        avg_SNR_dBm = sum_SNR_dBm / 10;
        avg_INR_dBm = sum_INR_dBm / 10;
        SNR_dBm_d = [SNR_dBm_d avg_SNR_dBm];
        INR_dBm_d = [INR_dBm_d avg_INR_dBm];
    end
    antenna_n_SNR_dBm_d = [antenna_n_SNR_dBm_d; SNR_dBm_d];
    antenna_n_INR_dBm_d = [antenna_n_INR_dBm_d; INR_dBm_d];
end
% plot SNR and INR for different distances, for antenna number 8 and 16
tmp_plot = figure('Visible', 'off');
plot(50:50:500, antenna_n_SNR_dBm_d(1, :), 'r', 50:50:500, antenna_n_INR_dBm_d(1, :), 'b');
xlabel('Distance (m)');
ylabel('Power (dBm)');
title('SNR and INR for different distances (8 antennas)');
legend('SNR', 'INR');
saveas(tmp_plot, 'pics/SNR_INR_8_antennas.png');
close(tmp_plot);

tmp_plot = figure('Visible', 'off');
plot(50:50:500, antenna_n_SNR_dBm_d(2, :), 'r', 50:50:500, antenna_n_INR_dBm_d(2, :), 'b');
xlabel('Distance (m)');
ylabel('Power (dBm)');
title('SNR and INR for different distances (16 antennas)');
legend('SNR', 'INR');
saveas(tmp_plot, 'pics/SNR_INR_16_antennas.png');
close(tmp_plot);

% Plot SNR and INR for 10 topologies when analog_antenna_number = 16 and distance = 200
SNR_dBm_list = [];
INR_dBm_list = [];
for i = 1:10
    rand_idx = randperm(numel(0:10:180), 2);
    rx1_location = rand_rx_location_list(rand_idx(1), (7:8));
    rx2_location = rand_rx_location_list(rand_idx(2), (7:8));
    [rx1_SNR_dbm, rx2_INR_dbm] = analog_beamforming(P_tx_dBm, N0_dBm, tx_location, rx1_location, rx2_location, 16, 19);
    SNR_dBm_list = [SNR_dBm_list rx1_SNR_dbm];
    INR_dBm_list = [INR_dBm_list rx2_INR_dbm];
end
tmp_plot = figure('Visible', 'off');
plot(1:10, SNR_dBm_list, 'r', 1:10, INR_dBm_list, 'b');
xlabel('Topology Index');
ylabel('Power (dBm)');
title('SNR and INR for 10 topologies (16 antennas, 200m)');
legend('SNR', 'INR');
saveas(tmp_plot, 'pics/SNR_INR_16_antennas_200m.png');
close(tmp_plot);

% Prx_1_dBm of 10 topologies for various codebook sizes 
% when d=200m and there are 16 antennas

% 2d matrix, with dimension (codebook_size, topology_index) 
% and value of Prx_1_dBm (dBm)
Prx_1_dBm_matrix = [];
for codebook_size = [19, 37, 73]
    Prx_1_dBm_list = [];
    for i = 1:10
        rand_idx = randperm(numel(0:10:180), 2);
        rx1_location = rand_rx_location_list(rand_idx(1), (7:8));
        rx2_location = rand_rx_location_list(rand_idx(2), (7:8));
        [~, ~, P_rx1_dBm] = analog_beamforming(P_tx_dBm, N0_dBm, tx_location, rx1_location, rx2_location, 16, codebook_size);
        Prx_1_dBm_list = [Prx_1_dBm_list P_rx1_dBm];
    end
    Prx_1_dBm_matrix = [Prx_1_dBm_matrix; Prx_1_dBm_list];
end
tmp_plot = figure('Visible', 'off');
plot(1:10, Prx_1_dBm_matrix(1, :), 'r', 1:10, Prx_1_dBm_matrix(2, :), 'b', 1:10, Prx_1_dBm_matrix(3, :), 'g');
xlabel('Topology Index');
ylabel('Power (dBm)');
title('Prx_1_dBm for 10 topologies (16 antennas, 200m)');
legend('Codebook Size 19', 'Codebook Size 37', 'Codebook Size 73');
saveas(tmp_plot, 'pics/Prx_1_dBm_16_antennas_200m.png');
close(tmp_plot);

% TODO: Implement Digital Beamforming functions in /tasks
% Hint: you can adjust input/output for reports
[rx1_SNR_dbm, rx2_SNR_dbm, ori_rx1_SNR_dbm, ori_rx2_SNR_dbm] = digital_beamforming(P_tx_dBm, N0_dBm, tx_location, rx1_location, rx2_location, tx_node_number*digital_antenna_number, rx_node_number*rx_antenna_number);

fprintf('Task2: SNR Calculation\n');
fprintf('Receiver1\tSNR: %f dBm\t without precoding SNR: %f dBm\n', rx1_SNR_dbm, ori_rx1_SNR_dbm);
fprintf('Receiver2\tSNR: %f dBm\t without precoding SNR: %f dBm\n', rx2_SNR_dbm, ori_rx2_SNR_dbm);

% SNR of two users with and without ZFBF for d=[50:50:500]m
rx1_SNR_dbm_list = [];
rx2_SNR_dbm_list = [];
rx1_noW_SNR_dbm_list = [];
rx2_noW_SNR_dbm_list = [];
for d = 50:50:500
    sum_rx1_SNR_dbm = 0;
    sum_rx2_SNR_dbm = 0;
    sum_rx1_noW_SNR_dbm = 0;
    sum_rx2_noW_SNR_dbm = 0;
    for i = 1:10
        rand_idx = randperm(numel(0:10:180), 2);
        distance_idx = (d / 50) * 2 - 1;
        rx1_location = rand_rx_location_list(rand_idx(1), (distance_idx:distance_idx+1));
        rx2_location = rand_rx_location_list(rand_idx(2), (distance_idx:distance_idx+1));
        [rx1_SNR_dbm, rx2_SNR_dbm, ori_rx1_SNR_dbm, ori_rx2_SNR_dbm] = digital_beamforming(P_tx_dBm, N0_dBm, tx_location, rx1_location, rx2_location, tx_node_number*digital_antenna_number, rx_node_number*rx_antenna_number);
        sum_rx1_SNR_dbm = sum_rx1_SNR_dbm + rx1_SNR_dbm;
        sum_rx2_SNR_dbm = sum_rx2_SNR_dbm + rx2_SNR_dbm;
        sum_rx1_noW_SNR_dbm = sum_rx1_noW_SNR_dbm + ori_rx1_SNR_dbm;
        sum_rx2_noW_SNR_dbm = sum_rx2_noW_SNR_dbm + ori_rx2_SNR_dbm;
    end
    avg_rx1_SNR_dbm = sum_rx1_SNR_dbm / 10;
    avg_rx2_SNR_dbm = sum_rx2_SNR_dbm / 10;
    avg_rx1_noW_SNR_dbm = sum_rx1_noW_SNR_dbm / 10;
    avg_rx2_noW_SNR_dbm = sum_rx2_noW_SNR_dbm / 10;
    rx1_SNR_dbm_list = [rx1_SNR_dbm_list avg_rx1_SNR_dbm];
    rx2_SNR_dbm_list = [rx2_SNR_dbm_list avg_rx2_SNR_dbm];
    rx1_noW_SNR_dbm_list = [rx1_noW_SNR_dbm_list avg_rx1_noW_SNR_dbm];
    rx2_noW_SNR_dbm_list = [rx2_noW_SNR_dbm_list avg_rx2_noW_SNR_dbm];
end
% plot SNR for different distances
tmp_plot = figure('Visible', 'off');
plot(50:50:500, rx1_SNR_dbm_list, 'r', 50:50:500, rx2_SNR_dbm_list, 'b', 50:50:500, rx1_noW_SNR_dbm_list, 'g', 50:50:500, rx2_noW_SNR_dbm_list, 'y');
xlabel('Distance (m)');
ylabel('Power (dBm)');
title('SNR for different distances');
legend('Receiver1 with ZFBF', 'Receiver2 with ZFBF', 'Receiver1 without ZFBF', 'Receiver2 without ZFBF');
saveas(tmp_plot, 'pics/digital_SNR.png');
close(tmp_plot);

% heq, error(in dBm) of rx1 with ZFBF when d=200m
heq_rx1_list = [];
error_rx1_list = [];
for i = 1:10
    rand_idx = randperm(numel(0:10:180), 2);
    rx1_location = rand_rx_location_list(rand_idx(1), (7:8));
    rx2_location = rand_rx_location_list(rand_idx(2), (7:8));
    [~, ~, ~, ~, H_eq, error_dBm] = digital_beamforming(P_tx_dBm, N0_dBm, tx_location, rx1_location, rx2_location, tx_node_number*digital_antenna_number, rx_node_number*rx_antenna_number);
    heq_rx1_list = [heq_rx1_list H_eq];
    error_rx1_list = [error_rx1_list error_dBm(1)];
end
tmp_plot = figure('Visible', 'off');
subplot(2, 1, 1);
plot(1:10, heq_rx1_list, 'r');
ylabel('heq');
title('heq for 10 topologies (Receiver1, 200m)');
legend('heq');

subplot(2, 1, 2);
plot(1:10, error_rx1_list, 'b');
xlabel('Topology Index');
ylabel('Error (dBm)');
title('Error for 10 topologies (Receiver1, 200m)');
legend('Error');

saveas(tmp_plot, 'pics/heq_error_rx1.png');
close(tmp_plot);
