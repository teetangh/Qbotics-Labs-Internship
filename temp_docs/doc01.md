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

Just to avoid sourcing the bashrc file everytime,please add to the ~/.bashrc file

    echo "source ~/simulation_ws/devel/setup.bash" >> ~/.bashrc


Lets create a catkin package which depends on urdf

    catkin_create_pkg m2wr_description urdf
    
Once inside create two folders namely launch and urdf

     cd ~/simulation_ws/src/m2wr_description/
     mkdir launch urdf
    
inside the urdf folder we shall make the components of the differential drive.Make a file called "m2wr.xacro" inside the urdf folder and in the xacro file paste the code from the repository link:

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
    
    <gazebo>
        <plugin filename="libgazebo_ros_diff_drive.so" name="differential_drive_controller">
        <legacyMode>false</legacyMode>
        <alwaysOn>true</alwaysOn>
        <updateRate>20</updateRate>
        <leftJoint>joint_left_wheel</leftJoint>
        <rightJoint>joint_right_wheel</rightJoint>
        <wheelSeparation>0.2</wheelSeparation>
        <wheelDiameter>0.2</wheelDiameter>
        <torque>0.1</torque>
        <commandTopic>cmd_vel</commandTopic>
        <odometryTopic>odom</odometryTopic>
        <odometryFrame>odom</odometryFrame>
        <robotBaseFrame>link_chassis</robotBaseFrame>
        </plugin>
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



