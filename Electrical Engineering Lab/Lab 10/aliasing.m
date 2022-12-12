close all; clc; clear;
%% aliasing 
% arduino adc sampling rate = 9600Hz
% fsignal = 5; signal frequency = 5Hz
t = 0:0.01:3;
fs1 = 100; %sampling frequency = 100 Hz
fs2 = 100/12; %sampling frequency = 8.33 Hz
% fs3 = 4; 
Ts1 = 1/fs1;
Ts2 = 1/fs2;
% Ts3 = 1/fs3;
t1 = 0:Ts1:3-Ts1;
t2 = 0:Ts2:3-Ts2;
% t3 = 0:Ts3:5-Ts3;

%sampling
% sampling_points=xlsread('sampling_points1.xlsx','A101:A400');
sampling_points=readmatrix('sampling_points1.xlsx', 'Range', 'A101:A400');
data1=sampling_points(:,1);
data2=sampling_points(1:12:300,1);

figure
plot(t1,data1)
hold on
plot(t2,data2)
xlabel('t'); ylabel('value'); axis([0 3 0 500])
legend('sampling frequency = 100Hz', 'sampling frequency = 8.33Hz’)

%do fast fourier transform
y1 = fft(data1);
n1 = length(data1);% number of samples
freq1 = (0:n1-1)*(fs1/n1);% frequency range
power1 = abs(y1).^2/n1;
% 
y2 = fft(data2);
n2 = length(data2);% number of samples
freq2 = (0:n2-1)*(fs2/n2);% frequency range
power2 = abs(y2).^2/n2;

%plot frequency spectrogram
figure
plot(freq1,power1)
grid on
hold on 
xlabel('frequency(Hz)')
ylabel('Power')
title('spectrum of sampling frequency = 100Hz')
figure
plot(freq2,power2)
grid on
hold on 
xlabel('frequency(Hz)')
ylabel('Power')
title('spectrum of sampling frequency = 8.33Hz')
