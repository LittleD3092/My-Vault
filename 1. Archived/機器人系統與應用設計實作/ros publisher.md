標籤: #ROS #python 

---

底下這段程式碼會推送一次`hello world`

```python
import rospy
from std_msgs.msg import String

pub = rospy.Publisher('topic_name', String, queue_size=10)
rospy.init_node('node_name')
pub.publish('hello world')
```

# publish std_msgs and geometry_msgs

```python
import rospy
from std_msgs.msg import String
from geometry_msgs.msg import Twist

pub = rospy.Publisher('greeting', String, queue_size=10)
pub_cmd = rospy.Publisher('commands', Twist, queue_size=10)

rospy.init_node('talker')
rate = rospy.Rate(10) # 10hz

cmd_msg = Twist()
cmd_msg.linear.x = 1
cmd_msg.linear.y = 0
cmd_msg.linear.z = 0
cmd_msg.angular.x = 0
cmd_msg.angular.y = 0
cmd_msg.angular.z = 2

while not rospy.is_shutdown():
	hello_str = "hello world"
	pub.publish(hello_str)
	pub_cmd.publish(cmd_msg)
	rate.sleep()
```

---

參考資料:

機器人系統與應用設計實做

---

link:

[[ROS]]