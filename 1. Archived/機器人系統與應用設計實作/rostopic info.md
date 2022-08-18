標籤: #ROS #linux 

---

可以看到其中一個topic的細項

# 例子

假設有兩個topic: `greeting`, `commands`

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

```bash
rostopic info /greeting
```

> ```bash
> Type: std_msgs/String 
> 
> Publishers:
>  * /talker (http://c54314501637:39905/) 
>  
> Subscribers: None
> ```

```bash
rostopic info /commands
```

> ```bash
> Type: geometry_msgs/Twist
> 
> Publishers: 
>  * /talker (http://c54314501637:39905/)
> 
> Subscribers: None
> ```

---

參考資料:

機器人系統與應用設計實做

---

link:

[[rostopic list]]
[[ros publisher]]
[[ROS]]