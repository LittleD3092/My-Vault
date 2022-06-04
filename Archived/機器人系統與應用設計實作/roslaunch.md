標籤: #ROS 

---

這是一個好用的工具，可以用一行指令執行多個檔案，譬如同時開啟 talker 和 listener 的 python 檔案

# launch file 內容

from [[example ROS package]]
```bash
cat /content/catkin_ws/src/rospackage_example/launch/launch_package.launch
```

```html
<launch> 

	<node name="talker" pkg="rospackage_example" type="talker.py" />
	<node name="listener" pkg="rospackage_example" type="listener.py" /> 

</launch>
```

# launch 使用

```bash
# terminal 1
source /opt/ros/noetic/setup.bash
roscore
```

```bash
# terminal 2
source /content/environment.sh
roslaunch rospackage_example launch_package.launch
```

---

參考資料:

機器人系統

---

link:

[[ROS]]
[[source]]
[[ros setup.bash]]
[[roscore]]
[[Create Catkin Workspace]]