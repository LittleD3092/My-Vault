標籤: #ROS #python 

---

阻止python停止，直到ros節點停止為止

```python
def main(args):
	rospy.init_node('listener')
	rospy.Subcriber("greeting", String, callback)
	rospy.spin()
```

---

參考資料:

機器人系統與應用設計實做

---

link:

[[ROS]]