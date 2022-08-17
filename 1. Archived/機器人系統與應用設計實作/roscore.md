標籤: #ROS #python 

---

啟動ros的基本程式

下面這是用python與[[get_ipython().system_raw]]啟動roscore的例子
```python
import time
get_ipython().system_raw('source /opt/ros/noetic/setup.bash && roscore &')
```

---

參考資料:

機器人系統與應用設計實做

---

link:

[[ROS]]
[[time]]
[[time.sleep()]]
[[ros setup.bash]]