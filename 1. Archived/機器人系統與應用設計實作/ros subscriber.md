標籤: #ROS #linux 

---

從[[ros publisher]]取得資料

```python
import sys
import rospy
from std_msgs.msg import String

def callback(data):
  	rospy.loginfo(rospy.get_caller_id() + "I heard %s", data.data)

def main(args):
  	rospy.init_node('listener')
  	rospy.Subscriber("greeting", String, callback)
  	rospy.spin()

if __name__ == '__main__':
  	main(sys.argv)
```

---

參考資料:

機器人系統與應用設計實做

---

link:

[[ROS]]
[[rosnode list]]
[[rospy.spin()]]