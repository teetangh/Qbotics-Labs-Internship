 in the section of the documentation we shall be constructing in the URDF/XACRO model for Velodyne VLP-16 lidar. The meshes/collada dae files/gazebo files are bundled into a nice little package and is available as a GIT repository.  The reference to the same has been given below:

https://github.com/lmark1/velodyne_simulator

Redirect yourself to the src folder and git clone the above package. 

Now open the m2wr.xacro file and append the following code snippet just before the closing \<robot> tag

    <!-- /////////////////////////////////////// Inertial Measurement Unit /////////////////////////////////////////////-->

    <!-- joint between the link_chassis and the IMU -->
    <joint name="link_chassis_IMU_joint" type="fixed">
        <parent link="link_chassis"/>
        <child link="imu_sensor"/>
        <origin xyz="0.0 0.0 0.05" rpy="0.0 0.0 0.0"/>
        <!-- <axis xyz="0.0 0.0 0.0"/>
        <limit lower="0.0" upper="0.0" effort="0.0" velocity="0.0"/> -->
    </joint>

    <!-- IMU Sensor Link -->
    <xacro:property name="imu_height" value="0.05"/>
    <xacro:property name="imu_width" value="0.05"/>

    <link name="imu_sensor">
        <inertial>
            <origin xyz="0.0 0.0 1" rpy="0.0 0.0 0.0"/>
            <mass value="1.0"/>
            <inertia ixx="1.0" ixy="0.0" ixz="0.0" iyy="1.0" iyz="0.0" izz="1.0"/>
        </inertial>

        <visual>
            <!-- <origin xyz="0.0 0.0 ${imu_height}" rpy="0.0 0.0 0.0"/> -->
            <origin xyz="0.0 0.0 0.0" rpy="0.0 0.0 0.0"/>
            <geometry>
                <box size="${imu_width} ${imu_width} ${imu_height}"/>
            </geometry>
            <!-- <material>
                <color rgba="28 152 230 1.0"/>
                <texture filename=""/>
            </material> -->
        </visual>

        <collision>
            <origin xyz="0.0 0.0 0.0" rpy="0.0 0.0 0.0"/>
            <geometry>
                <box size="${imu_width} ${imu_width} ${imu_height}"/>
            </geometry>
        </collision>
    </link>


### Explanation




Add the snippet just after the <\link> tag and before the \ <robot>


    <!-- ROS Built-in Gazebo IMU Plugin Reference -->
    <gazebo>
        <plugin name="imu_plugin" filename="libgazebo_ros_imu.so">
            <alwaysOn>true</alwaysOn>
            <bodyName>imu_sensor</bodyName>
            <topicName>imu_topic</topicName>
            <serviceName>imu_service</serviceName>
            <gaussianNoise>0.0</gaussianNoise>
            <updateRate>20</updateRate>
        </plugin>
    </gazebo>

In the next section of the documentation we shall see how to integrate the inertial measurement unit with the differential drive robot which is used to estimate the linear and angular velocities and acculations in X,Y,Z coordinate frames.

