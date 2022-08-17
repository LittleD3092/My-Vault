標籤: #python 

---

讓python可以在bash中輸入指令

```python
import time

get_ipython().system_raw('source /opt/ros/melodic/setup.bash && roscore &')

time.sleep(3)
```

上面這個指令是在啟動 roscore

---

參考資料:

機器人系統與應用設計實做

---

link:

[[time]]
[[time.sleep()]]
[[roscore]]
[[ros setup.bash]]