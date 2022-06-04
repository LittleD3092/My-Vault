標籤: #機器人 #linux 

---

# 硬體規格

![[LoCoBot 硬體規格.png]]

# 連接方式

1. 開啟機器人後機器人會開啟熱點，可以用電腦連接
SSID: `locobot-4`
password: `locobot-4`

2. 查看機器人 ip
`arp -a`

3. 使用 SSH 進行遠端操作
```bash
ssh locobot@<IP>
```

4. 輸入 `py` 開啟機器人的 python

5. 寫 python 之後執行

```python
# position control

from pyrobot import Robot

# 選擇控制演算法
base_config_dict = {'base_controller': 'ilqr'}

# 宣告pyrobot物件並輸入參數
robot = Robot('locobot', base_config = base_config_dict)

# set target position
target_position = [1, 1, 0.5]

# go to absolute position
robot.base.go_to_absolute(target_position)

# go to relative position
# robot.base.go_to_relative(target_position)
```

```python
from pyrobot import Robot

robot = Robot('locobot')

linear_velocity = 0.1
rotational_velocity = 0.1
execution_time = 4

robot.base.set_vel(fwd_speed = linear_velocity,
				   turn_speed = rotational_velocity,
				   exe_time = execution_time)

robot.base.stop()
```

---

參考資料:

機器人系統與應用設計實作

---

link:

[[機器人系統與應用設計實作時間表]]
[[arp]]
[[vim]]
[[vi]]
[[linux 文字編輯器]]