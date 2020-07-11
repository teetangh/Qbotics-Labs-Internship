In the   previous section of the documentation we had constructed the model of our differential drive. We also constructed macros for the links and the joints of the wheels and stored it in a  XACRO  file and called it macros.xacro.

In this Section of the documentation you will learn how to create a simple laser scanner as well as customising the gazebo plugin for the laser scanner so that it can interact with the environment.

Now use the following code snippet for the laser scanner and include it in your URDF file  just after the wheel link and joint macros and therefore the ending \<robot> tag.

     <!-- /////////////////////////////////////// Laser Scanner /////////////////////////////////////////////-->
    <link name="sensor_laser">
        <inertial>
            <origin xyz="0 0 0" rpy="0 0 0" />
            <mass value="1" />
            <xacro:cylinder_inertia mass="1" r="0.05" l="0.1" />
        </inertial>

        <visual>
            <origin xyz="0 0 0" rpy="0 0 0" />
            <geometry>
                <cylinder radius="0.05" length="0.1"/>
            </geometry>
        </visual>

        <collision>
            <origin xyz="0 0 0" rpy="0 0 0"/>
            <geometry>
                <cylinder radius="0.05" length="0.1"/>
            </geometry>
        </collision>
    </link>

    <joint name="joint_sensor_laser" type="fixed">
        <origin xyz="0.15 0 0.05" rpy="0 0 0"/>
        <parent link="link_chassis"/>
        <child link="sensor_laser"/>
    </joint>

