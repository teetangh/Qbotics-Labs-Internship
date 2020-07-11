## Rviz Visualization

### Install Related Dependencies
Before we can visualize our robot through Rviz we need to install the MoveIt!,a motion planning framework for robotics applications and other relevant ROS and catkin libraries
This can be done through the following commands

    rosdep update
    sudo apt-get update
    sudo apt-get dist-upgrade
    sudo apt-get install ros-melodic-catkin python-catkin-tools
    
### Creating the launch file to visualize the temporary model.
Inside the launch folder create a launch file used to launch the diff_drive and name it "rviz.launch".Now,paste the code from the repository link

### Acutally visualizing the model.
Now we can visualize the model using the given command:

    roslaunch m2wr_description rviz.launch 

Now Rviz pops up and given the fact that we installed MoveIt.Select Transform model.Click the Add button and select the Robot State from the menu and the diff_drive will be visible on Rviz.

## Simulating the model in Gazebo
For this you need to have Gazebo installed on your system.Follow the link to install Gazebo depending upon your current system configuration

    http://gazebosim.org/tutorials?tut=install_ubuntu&cat=install

### Gazebo Code snippet already in the m2wr.xacro

    <gazebo reference="link_chassis">
        <material>Gazebo/Orange</material>
    </gazebo>
    <gazebo reference="link_left_wheel">
        <material>Gazebo/Blue</material>
    </gazebo>
    <gazebo reference="link_right_wheel">
        <material>Gazebo/Blue</material>
    </gazebo>
    

### Spawning the model
Inside the launch folder create another launch file called "spawn.launch" and paste the code from the repository.

### Launching Gazebo in the right order
Now if we launched gazebo and spawned the model,the model wouldn't load.That is probably because the gazebo isn't interfaced with the ROS ecosystem.The right way to do it would be to 

    roslaunch gazebo_ros empty_world.launch
    roslaunch m2wr_description spawn.launch 

### Installing the teleop_twist_keyboard to control the differential drive
We can also install the Teleop_twist keyboard and control the differential drive robot using the keyboard commands through a terminal
    
    sudo apt-get install ros-melodic-teleop-twist-keyboard 
    rosrun teleop_twist_keyboard teleop_twist_keyboard.py


okay


## References:
    Robot Ignite Academy(The Construct)
    https://www.theconstructsim.com/
    wiki.ros.org
    other youtube channels
