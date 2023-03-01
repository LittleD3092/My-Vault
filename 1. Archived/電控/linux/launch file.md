標籤: #ROS 

---

The contents of a launch file must be contained between a pair of launch tags.

```xml
<launch> ... </launch>
```

---

To actually start a node, the `<node>` tags are used.
The `pkg`, `type`, `name`.

```xml
<launch>
	<node pkg="..." type="..." name="..." respawn=true ns="..."/>
</launch>
```

- `pkg`: The package associated with the node that is to be launched.
- `type`: The name of the node executable file.
- `name`: To overwrite the name of node. This will take priority over the name given to the node in the code.
- `respawn`/`required`: Optional, but important. 
If `respawn = true`, then the node will be restarted if for some reason it closed.
If `required = true`, it will shut down all nodes associated with a launch file if this particular node comes down.
- `ns`: Launch a node inside a namespace. This is useful when using multiple instances of the same node.

---

Sometimes it is necessary to use a local variable in launch files using `<arg>`.

```xml
<launch>
	<node pkg="..." type="..." name="..." respawn=true ns="..."/>
	<arg name="..." value="..."/>
</launch>
```

---

參考資料:

[ros launch file - blog](http://www.clearpathrobotics.com/assets/guides/kinetic/ros/Launch%20Files.html)

---

link:

[[XML]]
[[roslaunch]]