# Documentation:


## Introduction:
Lets build a 2 wheeled differential drive robot.We shall start by modelling the robot and using URDFs/XACROs.

Create a a new workspace in your root directory and name it "diff_drive_gazebo".
Also create a source folder inside it 

    mkdir -p ~/diff_drive_gazebo/src
    cd ~/diff_drive_gazebo/src

Just to avoid sourcing the bashrc file everytime,please add to the ~/.bashrc file

    echo "source ~/diff_drive_gazebo/devel/setup.bash" >> ~/.bashrc


Lets create a catkin package which depends on urdf

    catkin_create_pkg m2wr_description urdf
    
Once inside create two folders namely launch and urdf

     cd ~/diff_drive_gazebo/src/m2wr_description/
     mkdir launch urdf
    

## Constructing the main skeleton urdf

inside the urdf folder we shall make the components of the differential drive.Make a file called "m2wr.xacro" inside the urdf folder and in the xacro file paste the following code:

    <?xml version="1.0" ?>
    <robot name="m2wr" 
        xmlns:xacro="https://www.ros.org/wiki/xacro">

    <!-- /////////////////////////////////////// Main Body /////////////////////////////////////////////-->
        <!-- CHASSIS -->
        <link name="link_chassis">
            <!-- pose and inertial -->
            <pose>0 0 0.1 0 0 0</pose>
            <inertial name="chassis_inertial">
                <mass value="5"/>
                <origin rpy="0 0 0" xyz="0 0 0.1"/>
                <inertia ixx="0.0395416666667" ixy="0" ixz="0" iyy="0.106208333333" iyz="0" izz="0.106208333333"/>
            </inertial>
            <!-- body -->
            <collision name="collision_chassis">
                <geometry>
                    <box size="0.5 0.3 0.07"/>
                </geometry>
            </collision>
            <!-- Naming the visual defaults to white colour -->
            <!-- <visual name="chassis_visual"> -->
            <visual>
                <origin rpy="0 0 0" xyz="0 0 0"/>
                <geometry>
                    <box size="0.5 0.3 0.07"/>
                </geometry>
            </visual>
            <!-- FRONT CASTER WHEEL -->
            <inertial name="caster_front_inertial">
                <origin rpy=" 0 0 0" xyz="0.35 0 -0.05"/>
                <mass value="10.0"/>
                <inertia ixx="0.0" ixy="0.0" ixz="0.0" iyy="0.0" iyz="0.0" izz="0.0"/>
            </inertial>
            <collision name="caster_front_collision">
                <origin rpy=" 0 0 0" xyz="0.35 0 -0.05"/>
                <geometry>
                    <sphere radius="0.05"/>
                </geometry>
                <surface>
                    <friction>
                        <ode>
                            <mu>0</mu>
                            <mu2>0</mu2>
                            <slip1>1.0</slip1>
                            <slip2>1.0</slip2>
                        </ode>
                    </friction>
                </surface>
            </collision>
            <visual name="caster_front_visual">
                <origin rpy=" 0 0 0" xyz="0.2 0 -0.05"/>
                <geometry>
                    <sphere radius="0.05"/>
                </geometry>
            </visual>
        </link>
    </robot>

### Explaination

Now let us look at the explanation for the above code snippet. here we are creating a link for the  chassis  part of our differential drive which consists of the following components ,i.e. :inertial 
collision and visual components.

 The collision properties define how the robot is going to collide with the other obstacles in Environment.  the visual properties define your model will look like. Finally the inertial properties  inertia properties talk about About the mass and  as well as the inertial components of the object about various axes in 3 x 3 inertial matrix.In  most cases the visual and connection parameters remain the same.

 As you can see in the above code snippet we have constructed the  chassis link,  given it inertial, visual and collision parameters as well as constructed a front caster wheel to help the differential drive maintain its balance. We have defined the sphere radius of the front caster wheel as well as the coefficient of friction and slip as required. You can set them to your desired values.


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


okay


## References:
    Robot Ignite Academy(The Construct)
    https://www.theconstructsim.com/
    wiki.ros.org
    other youtube channels
