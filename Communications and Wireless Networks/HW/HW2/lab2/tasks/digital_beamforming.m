function [rx1_SNR_dbm, rx2_SNR_dbm, rx1_noW_SNR_dbm, rx2_noW_SNR_dbm, constant, error_dBm] = digital_beamforming(P_tx_dBm, N0_dBm, tx_location, rx1_location, rx2_location, tx_nums, rx_nums)
addpath ./ewa_function;

% Calculate P_rx
% Hint: Use friis equation
freq = 2.4e9;
PL1_dBm = friis_equation(freq, 1, 1, norm(rx1_location - tx_location));
PL2_dBm = friis_equation(freq, 1, 1, norm(rx2_location - tx_location));
P_rx1_dBm = P_tx_dBm + PL1_dBm;
P_rx2_dBm = P_tx_dBm + PL2_dBm;

P_rx1_mWatt = 10^((P_rx1_dBm)/10);
P_rx2_mWatt = 10^((P_rx2_dBm)/10);

% Generate random channel h~N(0,1)
H = (randn(rx_nums, tx_nums) + randn(rx_nums, tx_nums) * 1i) ./ sqrt(2) .* sqrt([P_rx1_mWatt; P_rx2_mWatt]);

% TODO1: Generate precoded weight W (h')
% Hint1: You can reference the equation for calculating W on page 35 of PPT L9
% Hint2: Or you can just use the MATLAB api to get inverse matrix of H
W = pinv(H);

% TODO2: Scaled W into unit power (power = 1)
W = W ./ sqrt(sum(abs(W).^2, 'all'));

% Hint: Uncomment the equation below to verify if W is converted to unit power (W_power = 1)
% W_power = sum(abs(W).^2, 'all');
% fprintf('W_power: %f\n', W_power);

% Generate random transmitted signals
num_data = 1000;
x = randn(rx_nums, num_data);

% Generate random noises
N0_mWatt = 10^((N0_dBm)/10); % Convert noise power to mW
n = (randn(rx_nums, num_data) + randn(rx_nums, num_data) * 1i) ./ sqrt(2) * sqrt(N0_mWatt);

% Generate receive signals 
y_noW = H * x + n; % without precoding
y = H * W * x + n; % with precoding

% TODO3: Calculate H_eq with & without ZFBF
% Hint: without ZFBF: summmation one rx channel by all tx channel. H_eq = sum H_rx,i i=tx
% Hint: with ZFBF: H * W = I * constant. Please calculate the constant (H_eq)
H_eq_noW = sum(H, 2);
H_eq = H * W;
I_dot_constant = diag(H_eq);
constant = real(mean(I_dot_constant));
H_eq = constant * eye(rx_nums);

% % size of H_eq_noW
% [m, n] = size(H_eq_noW);
% fprintf('H_eq_noW size: %d x %d\n', m, n);

% % size of H
% [m, n] = size(H);
% fprintf('H size: %d x %d\n', m, n);

% TODO4: Decode signal with both with & without ZFBF H_eq
% Hint: Estimate x_hat based on the received signal y
x_hat_noW = y_noW ./ H_eq_noW;
x_hat = H_eq \ y;

% % size of x_hat_noW
% [m, n] = size(x_hat_noW);
% fprintf('x_hat_noW size: %d x %d\n', m, n);

% % size of x
% [m, n] = size(x);
% fprintf('x size: %d x %d\n', m, n);

% TODO5: Calculate deoding errors and SNR (|x|/|x-x'|)
% Hint: The difference between the transmitted and estimated signals
error_power_noW = sum(abs(x - x_hat_noW).^2, 2);
error_power = sum(abs(x - x_hat).^2, 2);
signal_power = sum(abs(x).^2, 2);

error_dBm_noW = 10 .* log10(error_power_noW);
error_dBm = 10 .* log10(error_power);
signal_dBm = 10 .* log10(signal_power);

rx1_SNR_dbm = signal_dBm(1) - error_dBm(1);
rx2_SNR_dbm = signal_dBm(2) - error_dBm(2);

rx1_noW_SNR_dbm = signal_dBm(1) - error_dBm_noW(1);
rx2_noW_SNR_dbm = signal_dBm(2) - error_dBm_noW(2);

end

