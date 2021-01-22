# Readme

```
sudo apt install ros-melodic-teleop-twist-keyboard
sudo apt install ros-$ROS_DISTRO-cartographer*
```

To Launch all the files

```
rm -rf build/ devel/
catkin_make
source devel/setup.bash

roslaunch m2wr_worlds second_world.launch
roslaunch m2wr_description spawn.launch
rosrun teleop_twist_keyboard teleop_twist_keyboard.py
rosrun rqt_graph rqt_graph
roslaunch m2wr_cartographer diff_drive_cartographer_2d_demo.launch
```
