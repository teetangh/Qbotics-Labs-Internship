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

### Chassis Link for the Differential Drive
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

 the folder hierarchy should be as  per the diagram given below:

    diff_drive_gazebo:
        m2wr_description
            urdf
                m2wr.xacro

### Explaination for the above snippet

Now let us look at the explanation for the above code snippet. here we are creating a link for the  chassis  part of our differential drive which consists of the following components ,i.e. :inertial 
collision and visual components.

 The collision properties define how the robot is going to collide with the other obstacles in Environment.  the visual properties define your model will look like. Finally the inertial properties  inertia properties talk about About the mass and  as well as the inertial components of the object about various axes in 3 x 3 inertial matrix.In  most cases the visual and connection parameters remain the same.

 As you can see in the above code snippet we have constructed the  chassis link,  given it inertial, visual and collision parameters as well as constructed a front caster wheel to help the differential drive maintain its balance. We have defined the sphere radius of the front caster wheel as well as the coefficient of friction and slip as required. You can set them to your desired values.

### The Wheel joints for the differential drive.

Now when constructing URDFs via XML code, it is strongly advised to clean up the code using the package which can help you  modularise your code. Using the XACRO package, you can define macros, simple constants, properties,simple math and include files.


Here we shall not write the xml code for the wheel  links and joints rather include it via a XACRO file  as demonstrated below:
Please attach this code just above the ending tag of the \<robot>.

    <!-- WHEELS -->
    <xacro:link_wheel name="link_right_wheel"/>
    <xacro:joint_wheel name="joint_right_wheel" child="link_right_wheel" origin_xyz="-0.05 0.15 0"/>

    <xacro:link_wheel name="link_left_wheel"/>
    <xacro:joint_wheel name="joint_left_wheel" child="link_left_wheel" origin_xyz="-0.05 -0.15 0"/>



  Let's create a XACRO file ( call it macros.xacro)  for defining macros  for  the wheel  links and wheel joints.Your again we define the wheel inertial collision and visual properties as per the  our choice. You can set them to your own desired values. Also in the  macro of the wheel  joint between the parent link to be the link chassis  since all the components are going to be attached to this and the child link or to be an arbitrary argument ${child}  show that  our desired  child component can be attached to this macro. Also we set the damping and friction parameters as per the common law of Physics. 

		<?xml version="1.0"?>
        <robot>
            <!-- LINK_WHEEL MACRO -->
            <macro name="link_wheel" params="name">
                <link name="${name}">
                    <inertial>
                        <mass value="0.2"/>
                        <origin rpy="0 1.5707 1.5707" xyz="0 0 0"/>
                        <inertia ixx="0.000526666666667" ixy="0" ixz="0" iyy="0.000526666666667" iyz="0" izz="0.001"/>
                    </inertial>
                    <collision name="${name}_collision">
                        <origin rpy="0 1.5707 1.5707" xyz="0 0 0"/>
                        <geometry>
                            <cylinder length="0.04" radius="0.1"/>
                        </geometry>
                    </collision>
                    <visual name="${name}_visual">
                        <origin rpy="0 1.5707 1.5707" xyz="0 0 0"/>
                        <geometry>
                            <cylinder length="0.04" radius="0.1"/>
                        </geometry>
                    </visual>
                </link>
            </macro>
            <!-- JOINT_WHEEL MACRO -->
            <macro name="joint_wheel" params="name child origin_xyz">
                <joint name="${name}" type="continuous">
                    <origin rpy="0 0 0" xyz="${origin_xyz}"/>
                    <child link="${child}"/>
                    <parent link="link_chassis"/>
                    <axis rpy="0 0 0" xyz="0 1 0"/>
                    <limit effort="10000" velocity="1000"/>
                    <joint_properties damping="1.0" friction="1.0"/>
                </joint>
        </macro>

        <macro name="cylinder_inertia" params="mass r l">
            <inertia ixx ="${mass*(3*r*r+l*l)/12}" ixy = "0" ixz="0"
                    iyy ="${mass*(3*r*r+l*l)/12}" iyz="0"
                    izz ="${mass*(3*r*r+l*l)/12}" />
        </macro>
    </robot>

 the folder hierarchy should be as  per the diagram given below:

    diff_drive_gazebo:
        m2wr_description
            urdf
                m2wr.xacro
                macros.xacro

 this is our recommended folder hierarchy but you can  create your own folder hierarchy. it is strongly recommended that you maintain and all small case naming separated by underscores. also remember to create  create the package using catkin_create_package command  followed by the name and the dependencies of the package  rather than just creating a simple folder.
