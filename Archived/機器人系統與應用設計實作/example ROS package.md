標籤: #ROS 

---

在 github 上面有範例程式可以測試

# 安裝

```bash
cd /content/catkin_ws/src/
git clone https://github.com/Sensing-Intelligent-System/rospackage_example.git
```

[[catkin make]]
```bash
cd /content/catkin_ws
source /content/environment.sh
catkin_make
```

確認有沒有裝好（[[rospack find]]）
```bash
cd /content/catkin_ws
source /content/environment.sh
rospack find rospackage_example
```

---

參考資料:

機器人系統

---

link:

[[catkin create pkg]]