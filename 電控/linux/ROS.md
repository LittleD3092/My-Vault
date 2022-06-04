標籤: #ROS 

---

ROS(Robot Operating System) 是一個平台，為了避免重複研發同一個東西而出現，這上面有許多開源的程式碼可以重複利用，加快開發的速度。

它的版本順序由第一個字母排列。

裡面包含 ROS 1 和 [[ROS 2]] 兩種版本，兩種差別不大

在 ROS 中，最基本的單位是 Node ，譬如 master ， talker 和 listener

通常 user 手動創造的連接埠是 11311

---

# 安裝

## Neuron Startup Menu

同時叫做 ROS menu

ROS 的安裝與開啟過程繁瑣，因此通常使用這個工具

開終端機時會跳出選單提供選擇

[github](https://github.com/Adlink-ROS/ros_menu)

> config設定：
> `~/ros_menu/config.yaml`

---

## 測試ROS 1

在一個終端機開啟roscore
```bash
roscore
```

在另一個終端機跑turtlesim
```bash
rosrun turtlesim turtlesim_node
```

在第三個終端機跑按鍵輸入
```bash
rosrun turtlesim turtle_teleop_key
```
用方向鍵測試看看烏龜會不會動

---

## 測試[[ROS 2]]

和 ROS 1 的流程一樣，只是少了開啟core

```bash
ros2 run turtlesim turtlesim_node
ros2 run turtlesim turtle_teleop_key
```

---

## ROS bridge 測試

在終端機開啟 ROS1 ，並開啟 roscore
```bash
roscore
```

在另一個終端機開 ROS1 ，並開啟聆聽
```bash
rosrun rospy_tutorials listener
```

在第三個終端機開啟 ROS2 ，開啟 talker
```bash
ros2 run demo_nodes_py talker
```

在第四個終端機開啟 bridge ，注意在開啟 bridge 後通常不用輸入下面的指令就會把 ROS1 和 ROS2 接起來
```bash
ros2 run ros1_bridge dynamic_bridge
```

---

# 通訊功能

ROS 的通訊分成四種，可以視情況挑需要的

---

## Topic

這是單向的，因此不會有回覆，所以也不同步
有兩種 Node ， `Publisher` 和 `Subscriber`

`Publisher`: 發送端
`Subscriber`: 接收端

---

## Service

這是雙向並且同步的，有兩種 Node ，分成 `Server` 和 `Client`

`Server`: 收到 request 後回傳 response
`Client`: 主動發送 request

---

### request, response 資料型態

request 和 response 的資料型態在 `.srv` 檔案中設定，以 `---` 分隔 request 和 response

例如(`std_srvs/Trigger.srv`)：
```bash
---
bool success
string message
```
橫線上方是 request ，下方是 response

---

## Action

這是雙向並且不同步的，有兩種 Node ，分成 `Server` 和 `Client`，比起 Server 多加了一個 feedback ，因此適合需要較長時間的動作，譬如機器手臂移動至定點可以定期回傳距離目標的距離

通訊如下：
Server / Client

<-Action Goal
Action Feedback->
Action Result->

> 更多詳細功能:
> <-Goal
> <-Cancel
> Status->
> Feedback->
> Result->

---

### goal, feedback, result 資料型態

在 `.action` 檔案中設定，如下

```bash
Goal
---
Result
---
Feedback
```

---

## Parameter Server

像是一片黑板上面寫滿變數，大家有共用的變數空間

---

# debug

## rostopic publish

可以用手動的方式上傳東西給接收端，分成三種模式

1. Latching mode
2. Once mode
3. Rate mode

Latching mode 可以讓上傳的東西留在網路中，就算發送端消失了，在之後新加入的 Node 也可以聽的到

Once mode 相較 Latching mode 不會讓上傳的東西留在網路中（三秒後自動消失）

Rate mode 會以一個設定的頻率持續發送資訊

---

## rosbag

執行時可以選擇的產生紀錄，在執行完可以用來 debug

---

# 編譯

用終端機在 package 的資料夾中使用以下指令，會自動產生 build 和 devel 資料夾

```bash
catkin
```

---

參考資料:

[專業課程 ROS 1 簡介 1](https://youtu.be/FX8HAkR7SFw)
[[ROS暑期課程播放清單]]