標籤: #ROS 

---

# 初始化

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

# 使用 package

像是 [[ros setup.bash]] 一樣，[[Catkin Workspace]] 也有自己的 `setup.bash`，路徑如下

```bash
source /content/catkin_ws/devel/setup.bash
```

這樣每次都需要 setup 兩次，一次是 [[ROS]] 的，一次是 [[Catkin Workspace]] 的，這樣很麻煩，因此我們會寫一個 `environment.sh` 方便設定環境

```bash
# /content/environment.sh
source /opt/ros/noetic/setup.bash
source /content/catkin_ws/devel/setup.bash
```

如此一來只需要 [[source]] 這個檔案就可以設定好環境

```bash
source /content/environment.sh
```

---

參考資料:

機器人系統

---

link:

[[ros setup.bash]]
[[source]]
[[catkin make]]