Tag: #ROS 
Previous: 
Link: 

[TOC]

---

Robostack is a bundle of ROS that can run on any OS that has conda package manager, such as Linux, Mac and Windows. This note includes install steps of robostack.

# Installation

## Step 0: If you installed ROS before

- If you installed ROS before, make sure not to source it. It will conflict with robostack.
	- TIPS: If you are going to install multiple versions of ROS, it is recommended that you install all of them using robostack. It is easier to remember rather than installing them using different methods.
- Make sure not to install ROS in `base` environment in the following steps.
- Make sure not to install `conda` in `ros_env` in the following steps.

## Step 1: Check whether miniforge is installed

If not installed, install miniforge: [[Miniforge]]

## Step 2: Install mamba

If you don't have mamba yet, you need to install it. Note that if you use `mambaforge`, `mamba` is already installed.

```bash
conda install mamba -c conda-forge
```

## Step 3: Create environment for ROS installation

```bash
# For ROS 2 Humble
mamba create -n ros-humble-env python=3.10 -c conda-forge
# For ROS 1 Noetic
mamba create -n ros-noetic-env python=3.9 -c conda-forge

conda activate <your-env>
```

Make sure you are in the right environment. In the terminal you should see your environment name before your user name, like so:

```bash
(ros-humble-env) littled3092@littled3092-Latitude-7390:~$ 
```

## Step 4: Customize channels

```bash
# this adds the conda-forge channel to the new created environment configuration 
conda config --env --add channels conda-forge
# and the robostack channel
conda config --env --add channels robostack-staging
# remove the defaults channel just in case, this might return an error if it is not in the list which is ok
conda config --env --remove channels defaults
```

## Step 5: Install ROS and other packages

```bash
# Install the version of ROS you are interested in:
mamba install ros-humble-desktop  # (or "mamba install ros-noetic-desktop" or "mamba install ros-galactic-desktop")

# optionally, install some compiler packages if you want to e.g. build packages in a colcon_ws:
mamba install compilers cmake pkg-config make ninja colcon-common-extensions

# on Linux and osx (but not Windows) for ROS1 you might want to:
mamba install catkin_tools

# on Windows, install Visual Studio 2017 or 2019 with C++ support 
# see https://docs.microsoft.com/en-us/cpp/build/vscpp-step-0-installation?view=msvc-160

# on Windows, install the Visual Studio command prompt:
mamba install vs2019_win-64

# note that in this case, you should also install the necessary dependencies with conda/mamba, if possible

# reload environment to activate required scripts before running anything
# on Windows, please restart the Anaconda Prompt / Command Prompt!
conda deactivate
conda activate ros-humble-env # or ros-noetic-env

# if you want to use rosdep, also do:
mamba install rosdep
rosdep init  # note: do not use sudo!
rosdep update
```

---

# Reference

[robostack official site](https://robostack.github.io/)

---

# Note

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.