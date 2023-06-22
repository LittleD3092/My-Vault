標籤: #ROS 

---

[TOC]

---

- ROS(Robot Operating System) 是一個平台，為了避免重複研發同一個東西而出現，這上面有許多開源的程式碼可以重複利用，加快開發的速度。
- 它的版本順序由第一個字母排列。
- 裡面包含 ROS 1 和 [[ROS 2]] 兩種版本，兩種差別不大
- 在 ROS 中，最基本的單位是 Node ，譬如 master ， talker 和 listener
- 通常 user 手動創造的連接埠是 11311

# 安裝

## Neuron Startup Menu

- 同時叫做 ROS menu
- ROS 的安裝與開啟過程繁瑣，因此通常使用這個工具
- 開終端機時會跳出選單提供選擇
- [ros_menu - github](https://github.com/Adlink-ROS/ros_menu)

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

# Catkin

## Catkin Workspace

- catkin workspace 是一種可以快速編譯與執行的 workspace 管理工具，因此可以幫我們整理 packages。
- 他不僅可以像一般的 [[cmake]] 一樣管理單個 project，也引入了 workspace 的概念，用來管理多個 package。
- catkin workspace 使用了 [[cmake]] 來編譯整個 workspace。

### Create Catkin Workspace

要創造 catkin workspace 包含了三個步驟

包含三個步驟
1. 建立 `./content/catkin_ws/src` 的目錄
2. 移動到 `./content/catkin_ws` 目錄
3. 使用 `catkin_make` 指令初始化

如下：
```bash
mkdir -p /content/catkin_ws/src
cd /content/catkin_ws
source /opt/ros/melodic/setup.bash
catkin_make
```

## Initialize

每次要使用 catkin workspace 編譯或做任何事情前，都需要使用 `setup.bash` 。ROS 有自己的 `setup.bash` ，catkin 也有。以下是 ROS 的 `setup.bash`:

```bash
source /opt/ros/noetic/setup.bash
```

還有以下是 catkin workspace 的 `setup.bash`:

```bash
source /content/catkin_ws/devel/setup.bash
```

兩個都需要執行才可以做其他與 ROS 和 catkin workspace 有關的事。

### environment.sh

因為每次要跑那兩行指令很麻煩，並且如果之後你的 package 需要其他設定環境的流程，一一跑指令很容易漏掉，因此我們習慣將設定環境的部份寫成一個 script ，並且把他放在 catkin workspace 資料夾的上一層。裡面至少包含 [[#Initialize]] 中的兩行指令：

```bash
# /content/environment.sh
source /opt/ros/noetic/setup.bash
source /content/catkin_ws/devel/setup.bash
```

如果你的專案需要安裝其他的 package 才可以使用，建議把那些安裝流程也一併寫入這個 script ，方便其他接手的人可以迅速的架起測試與開發的環境。

如此一來，就可以利用單一行的 `source` 來設定好環境：

```bash
source /content/environment.sh
```

## Create Pkg

這個指令可以建立 package，後面要加上名字和 depend

```bash
cd /content/catkin_ws/src
source /content/environment.sh
catkin_create_pkg rospackage_first_example roscpp rospy
```

- `rospackage_first_example`: package name
- `roscpp`: depend1
- `rospy`: depend2

## Make

可以編譯（或初始化）[[#Catkin Workspace]]

```bash
cd /content/catkin_ws/src
source /content/environment.sh
catkin_make
```

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

![[Parameter Server]]

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

# 工具

## Gazebo

- 模擬環境的工具
- 通常用在機器人領域，可以模擬動力學
- 跟ROS整合的不錯

> [[Gazebo]]

---

參考資料:

[專業課程 ROS 1 簡介 1](https://youtu.be/FX8HAkR7SFw)
[[ROS暑期課程播放清單]]
機器人系統

---

link:

