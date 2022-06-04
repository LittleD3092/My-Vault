標籤: #ROS 

---

這個指令可以建立 package，後面要加上名字和 depend

```bash
cd /content/catkin_ws/src
source /content/environment.sh
catkin_create_pkg rospackage_first_example roscpp rospy
```

- `rospackage_first_example`: package name
- `roscpp`: depend1
- `rospy`: depend2

---

參考資料:

機器人系統

---

link:

[[Create Catkin Workspace]]
[[Catkin Workspace]]