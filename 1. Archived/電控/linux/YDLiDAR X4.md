標籤: #ROS #機器人 

---

# Overview

一個 2D 360 度的 LiDAR

- 馬達轉速：6~12Hz
- 採樣速率：up to 5KHz

## Dimensions

![[ydlidar x4 dimension.png]]

## Specs

### Performance Parameter

| Item              | Min                  | Typical              | Max                   | Unit | Remarks                                  |
| ----------------- | -------------------- | -------------------- | --------------------- | ---- | ---------------------------------------- |
| Ranging frequency | /                    | 5000                 | /                     | Hz   | Ranging 5000 times per second            |
| Motor frequency   | 6                    | /                    | 12                    | Hz   | PWM or voltage speed regulation          |
| Ranging distance  | 0.12                 | /                    | 10                    | m    | Indoor encironment with 80% Reflectivity |
| Field of view     | /                    | 0~360                | /                     | Deg  | /                                        |
| Systematic error  | /                    | 2                    | /                     | cm   | Range $\leq$ 1m                          |
| Relative error    | /                    | 3.5%                 | /                     | /    | 1m $\leq$ Range $\leq$ 6m                |
| Tilt angle        | 0.25                 | 1                    | 1.75                  | Deg  | /                                        |
| Angle resolution  | 0.43 (frequency@6Hz) | 0.50 (frequency@7Hz) | 0.86 (frequency@12Hz) | Deg  | Different motor frequency                | 

### Electrical Parameter

| Item            | Min  | Typical | Max | Unit | Remarks                                                                      |
| --------------- | ---- | ------- | --- | ---- | ---------------------------------------------------------------------------- |
| Supply voltage  | 4.8  | 5       | 5.2 | V    | Excessive voltage might damage the Lidar while low affect normal performance |
| Supply current  | 1000 | /       | /   | mA   | Instantaneous peak current at start-up                                       |
| Working current | /    | 350     | 500 | mA   | System work, motor rotation speed=7Hz                                        | 

### Interface

![[ydlidar x4 interface.png]]

| Pin    | Type         | Description                     | Defaults | Range    | Remarks                                          |
| ------ | ------------ | ------------------------------- | -------- | -------- | ------------------------------------------------ |
| VCC    | Power supply | Positive                        | 5V       | 4.8~5.2V | /                                                |
| Tx     | Output       | System serial port output       | /        | /        | Data stream: LiDAR $\rightarrow$ Peripherals     |
| Rx     | Input        | System serial port input        | /        | /        | Data stream: Peripherals $\rightarrow$ LiDAR     |
| GND    | Power supply | Negative                        | 0V       | 0V       | /                                                |
| M_EN   | Input        | Motor enables control terminal  | 3.3V     | 0V~3.3V  | High level enables                               |
| DEV_EN | Input        | Ranging enable control terminal | 3.3V     | 0V~3.3V  | High level enables                               |
| M_SCTR | Input        | Motor speed control terminal    | 1.8V     | 0V~3.3V  | Voltage speed regulation or PWM speed regulation |
| NC     | /            | Reserve pin                     | /        | /        | /                                                | 

### Lidar Communication

The communication protocol are as follows:

- Baud rate: 128000 (8-bit data bit, 1 stop bit, no parity)
- High signal level: 2.4 ~ 3.5V
- Low signal level: 0 ~ 0.6V

### Motor Control

- M_EN: enable signal of the motor, high-level enable
- M_SCTR: motor speed control signal, PWM. 
	- 0% PWM 為最高轉速
	- PWM frequency: 10kHz
	- Duty cycle range: 50% ~ 100%, typical 85%

### Coordinate Definition

![[ydlidar x4 coordinate definition.png]]

# Usage

可以直接接電腦，如果電腦的電流不夠可以用 micro-usb 外接電源 (5V)

## ROS Operation

1. 安裝 ydlidar-SDK library

clone 以下網址的程式碼，使用 cmake 編譯並安裝

[ydlidar-SDK library - github](https://github.com/YDLIDAR/YDLidar-SDK)

```bash
$ git clone https://github.com/YDLIDAR/YDLidar-SDK
$ cd YDLidar-SDK
$ cmake ..
$ make
$ sudo make install
```

2. 安裝 ROS package

```bash
$ git clone https://github.com/YDLIDAR/ydlidar_ros_driver.git ydlidar_ws/src/ydlidar_ros_driver
$ cd ydlidar_ws
$ catkin_make
```

3. environment setting

```bash
$ source ./devel/setup.sh
```

> 如果不想要每次使用都 source 一次，可以把 `setup.sh` 加入 `~/.bashrc`
> ```bash
> $ echo "source ~/ydlidar_ws/devel/setup.bash" >> ~/.bashrc 
> $ source ~/.bashrc
> ```

4. 檢查 ros package path ，看有沒有設定好

```bash
$ echo $ROS_PACKAGE_PATH
```

你應該會看到類似以下資訊：

`/home/tony/ydlidar_ws/src:/opt/ros/melodic/share`

5. 設定 serial port

```bash
$ chmod 777 src/ydlidar_ros_driver/startup/* 
$ sudo sh src/ydlidar_ros_driver/startup/initenv.sh
```

6. Run ros driver with roslaunch

```bash
$ roslaunch ydlidar_ros_driver X4.launch
```

7. RVIZ view scan results

```bash
$ roslaunch ydlidar_ros_driver lidar_view.launch
```

> 注意，記得改 launch file 裡面的檔名
> ![[launch file of ydlidar x4.png]]
> 譬如本篇的 lidar 是 X4 ，要把圖中的地方改成 `X4.launch`

> 這裡觀看結果會使用到 `rviz` ，如果沒裝過要記得裝
> ```bash
> $ sudo apt-get install ros-noetic-rviz
> ```
> 上面的 noetic 可以改成自己裝的 ros 版本

### 更改參數

如果需要更改如掃描角度等的參數，可以在 `X4.launch` 裡面找到

更多資訊：
[ydlidar configuration - github](https://github.com/YDLIDAR/ydlidar_ros_driver#configure-ydlidar_ros_driver-internalparameter)

---

參考資料:

[[YDLIDAR X4 Data sheet V1.1(211230).pdf]]

---

link:

[[chmod]]
[[Hector Slam]]