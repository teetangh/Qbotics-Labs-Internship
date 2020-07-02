# Documentation:

## References:
    Robot Ignite Academy(The Construct)
    https://www.theconstructsim.com/
    wiki.ros.org
    other youtube channels

## Introduction:
Lets build a 2 wheeled differential drive robot.We shall start by modelling the robot and using URDFs/XACROs.

Create a a new workspace in your root directory and name it "simulation_ws".
Also create a source folder inside it 

    mkdir -p ~/simulation_ws/src
    cd ~/simulation_ws/src

Lets create a catkin package which depends on urdf

    catkin_create_pkg m2wr_description urdf
    
Once inside create two folders namely launch and urdf

     cd ~/simulation_ws/src/m2wr_description/
     mkdir launch urdf
    
inside the urdf folder we shall make the components of the differential drive.Make a file called "m2wr.xacro" inside the urdf folder and in the xacro file paste the code from the file "spawn.launch"

## Rviz Visualization
Before we can visualize our robot through Rviz we need to install the MoveIt!,a motion planning framework for robotics applications and other relevant ROS and catkin libraries
This can be done through the following commands

    rosdep update
    sudo apt-get update
    sudo apt-get dist-upgrade
    sudo apt-get install ros-melodic-catkin python-catkin-tools

## 