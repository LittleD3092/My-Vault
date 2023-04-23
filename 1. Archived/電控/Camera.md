Tag: #slam #ROS 
Previous: 
Link: 

---

[TOC]

---

# Pinhole Camera

[[Pinhole Camera]]

# Setup camera in ROS

## Step 1: Download necessary packages

```bash
mkdir -p ~/ros2_ws/src && cd ~/ros2_ws/src  
git clone --branch humble https://gitlab.com/boldhearts/ros2_v4l2_camera.git  
git clone --branch humble https://github.com/ros-perception/vision_opencv.git  
git clone --branch humble https://github.com/ros-perception/image_common.git  
git clone --branch humble https://github.com/ros-perception/image_transport_plugins.git  
cd ..  
rosdep install --from-paths src -r -y
```

If your workspace is a git repository, you should use `git submodule` to clone these things. Use the following bash commands:

```bash
cd ros2_ws/src
git submodule add --branch humble
git submodule add --branch humble https://gitlab.com/boldhearts/ros2_v4l2_camera.git  
git submodule add --branch humble https://github.com/ros-perception/vision_opencv.git  
git submodule add --branch humble https://github.com/ros-perception/image_common.git  
git submodule add --branch humble https://github.com/ros-perception/image_transport_plugins.git  
cd ..  
rosdep install --from-paths src -r -y
```

## Step 2: Build packages

```bash
cd ros2_ws
colcon build
source install/setup.bash
```

When building the `ros2_v4l2_camera` package, you may encounter the error that looks like the following:

```bash
--- stderr: v4l2_camera
In file included from /home/littled3092/Documents/turbo-turret/src/ros2_v4l2_camera/src/v4l2_camera.cpp:17:
/home/littled3092/Documents/turbo-turret/install/cv_bridge/include/cv_bridge/cv_bridge/cv_bridge.h:42:2: error: #warning This header is obsolete, please include cv_bridge/cv_bridge.hpp instead [-Werror=cpp]
   42 | #warning This header is obsolete, please include cv_bridge/cv_bridge.hpp instead
      |  ^~~~~~~
cc1plus: all warnings being treated as errors
gmake[2]: *** [CMakeFiles/v4l2_camera.dir/build.make:76: CMakeFiles/v4l2_camera.dir/src/v4l2_camera.cpp.o] Error 1
gmake[1]: *** [CMakeFiles/Makefile2:141: CMakeFiles/v4l2_camera.dir/all] Error 2
gmake: *** [Makefile:146: all] Error 2
---
Failed   <<< v4l2_camera [15.4s, exited with code 2]
```

If this is the case, you should follow the instruction and change `turbo-turret/src/ros2_v4l2_camera/src/v4l2_camera.cpp:17`:

```cpp
// #include <cv_bridge/cv_bridge.h> // chnage this
#include <cv_bridge/cv_bridge.hpp>  // to this
```

## Step 3: Run camera node

```bash
ros2 run v4l2_camera v4l2_camera_node
```

You can see the result by using `rqt_image_view`:

```bash
ros2 run rqt_image_view rqt_image_view
```

---

參考資料:

視覺SLAM十四講 從理論到實踐
[ROS2 camera tutorial - medium](https://medium.com/swlh/raspberry-pi-ros-2-camera-eef8f8b94304)

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.