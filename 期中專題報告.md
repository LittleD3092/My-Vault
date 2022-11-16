一開始的預想

- 我們要做turtlebot 的研究
	- slam
		- 包括lidar的建圖
		- 馬達的控制
		- 利用gmapping
- 目的：做到[FIRA比賽](http://humanoid.nkust.edu.tw/RoboSports2022/Autorace.php) 的功能

---

# 實際執行情況

- Lidar
	- 因為我們覺得原本的lidar效能不足，因此換了ydlidar G4
- SBC
	- 原本的raspberry pi 3停產了
	- 換成upsquared pro，效能也較佳
- 底層控制
	- opencr 電池供電有問題
	- usb功能正常
	- 目前市面上買不到可以替換的板子
- 了解turtlebot 基本的配置與架構

---

# 成果

up squared 可以與lidar 連接，並且建圖

!圖

---

# 失敗因素

1. 我們沒有辦法確定替換配備之間的相容性
2. 根據官方manual ，官方提供的軟體都需要相對應的硬體做匹配
3. 以我們的能力無法修改最底層的程式
	- turtlebot 使用tcp/udp port 11311 通訊，並非使用ssh 通訊協定，我們無法修改
	- 官方提供的軟體僅支援raspberry pi，經過實測無法裝到up squared 上

---

# 未來規劃

加入另一邊