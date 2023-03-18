close all; clc; clear;

osc_voltage_resolution = 1; %單位:V 
osc_time_resolution = 0.5; %單位:sec(固定不變，為了跟Arduino一樣取5sec的資料)
frequency = 7;

A_arduino = 5/1023;
A_oscilloscope = (10*osc_voltage_resolution)/255;

sampling_points=xlsread('DS0001.csv', 'A29:A10028');
arduino_sampling_points=xlsread('sampling_points2.xlsx', 'A101:A500');
% sampling_points=readmatrix('DS0004.csv', 'Range', 'A29:A10028');
% arduino_sampling_points=readmatrix('sampling_points2.xlsx', 'Range', 'A101:A500');
data1=sampling_points(:,1);
data2=arduino_sampling_points(:,1);

fs = 100; Ts = 1/fs; %arduino sampling freq.
t_arduino = 0:Ts:4-Ts;

t_range = 5; %5秒
t1 = 0:t_range/10000:t_range-t_range/10000; %示波器輸出資料10000筆

% figure;
% plot(t1, A_oscilloscope*data1);
% figure;
% plot(t_arduino, A_arduino*data2);

data1_sampling = data1(1:20:10000); %將資料從10000變成500筆

%對位，調整oscilloscope_displacement.Arduino_displacement
oscilloscope_displacement = 10; 
osc_bias = 0.008;
Arduino_displacement = 2;
Arduino_bias = -0.007;
t = 0:Ts:3;
ideal_sin = sin(2*pi*frequency*t - (pi/2) )+1 % ideal sin

data3 = A_oscilloscope*data1_sampling(oscilloscope_displacement:1:300+oscilloscope_displacement) + osc_bias; %將示波器資料平移
data4 = A_arduino*data2(Arduino_displacement:1:300+Arduino_displacement) + Arduino_bias; %將Arduino資料平移
ideal_sin = ideal_sin'; %ideal_sin 轉置

%figure;                                  %41~48
%plot(t, ideal_sin);
%grid on; hold on; 
%plot(t, data3); 
%figure;
%plot(t, ideal_sin);
%grid on; hold on; 
%plot(t, data4);

%plot the osc quantization error                     50~72
osc_err = ideal_sin - data3;
osc_STD_err = std(osc_err);
% max(abs(osc_err))
figure;
plot(t, osc_err, 'x');
hold on; grid on;
plot(t, t*0+osc_STD_err);
hold on; grid on;
plot(t, t*0+A_oscilloscope);
legend('quantization error value', 'osc standard deviation', 'osc resolution');
xlabel('t'); ylabel('value'); title('示波器');

%plot the Arduino quantization error
arduino_err = ideal_sin - data4;
arduino_STD_err = std(arduino_err);
% max(abs(arduino_err))
figure;
plot(t, arduino_err, 'x');
hold on; grid on;
plot(t, t*0+arduino_STD_err);
hold on; grid on;
plot(t, t*0+A_arduino);
legend('quantization error value', 'Arduino standard deviation', 'Arduino resolution');
xlabel('t'); ylabel('value'); title('Arduino');
