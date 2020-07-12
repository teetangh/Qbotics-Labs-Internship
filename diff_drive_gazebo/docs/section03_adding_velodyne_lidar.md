 in the section of the documentation we shall be constructing in the URDF/XACRO model for an inertial measurement unit.Although there are meshes,urdfs and xacros available for IMUs online we shall make our very own imu from scratch and use a readily available gazebo plugin to implement its functionality

Now open the m2wr.xacro file and append the following code snippet just before the closing \<robot> tag

    <!-- /////////////////////////////////////// Veloddyne Lidar /////////////////////////////////////////////-->

    <xacro:property name="VLP_16_base_radius" value="0.05"/>
    <xacro:property name="VLP_16_base_height" value="0.5"/>


    <!-- Constructing a fake base_link -->
    <joint name="chassis_base_link_joint" type="fixed">
        <parent link="link_chassis"/>
        <child link="base_link"/>
        <origin xyz="-0.15 0 0.05" rpy="0 0 0"/>
    </joint>

    <link name="base_link">
        <inertial>
            <mass value="0.1"/>
            <inertia ixx="${(1/12) * 0.1 * (3 * VLP_16_base_radius * VLP_16_base_radius + VLP_16_base_height * VLP_16_base_height)}" ixy="0" ixz="0" iyy="${(1/12) * 0.1 * (3 * VLP_16_base_radius * VLP_16_base_radius + VLP_16_base_height * VLP_16_base_height)}" iyz="0" izz="${(1/2) * 0.1 * VLP_16_base_radius * VLP_16_base_radius}"/>
        </inertial>
        <visual>
            <origin xyz="0.0 0.0 0.20" rpy="0.0 0.0 0.0"/>
            <geometry>
                <cylinder radius="${VLP_16_base_radius}" length="${VLP_16_base_height}"/>
            </geometry>
        </visual>
        <collision>
            <origin xyz="0.0 0.0 0.20" rpy="0.0 0.0 0.0"/>
            <geometry>
                <cylinder radius="${VLP_16_base_radius}" length="${VLP_16_base_height}"/>
            </geometry>
        </collision>
    </link>

### Explanation
As usual, although the code is pretty self-explanatory it would help if you searched the web for images of Velodyne vlp-16 lidar.  Here we also create a height extender(with joints on both sides - chassis and thelidar)  to hold the lidar in place and name it base_link.

The URDF/XACRO file for the VLP16 has been written by Velodyne and can be referenced using the below XML snippet which consider our height extender as the base_link and publishes point_cloud data onto /velodyne_points at the rate of 10 hertz frequency and takes about 440 samples.Also, if you have gpu drivers in installed,you can set the gpu to true. 

Add the snippet just after the <\link> tag and before the \ <robot>


    <xacro:arg name="gpu" default="false"/>
    <xacro:property name="gpu" value="$(arg gpu)" />
    <xacro:include filename="$(find velodyne_description)/urdf/VLP-16.urdf.xacro"/>
    <VLP-16 parent="base_link" name="velodyne" topic="/velodyne_points" hz="10" samples="440" gpu="${gpu}">
        <origin xyz="0 0 0.4" rpy="0 0 0" />
    </VLP-16>

In the next section of the documentation we shall see how to integrate the inertial measurement unit with the differential drive robot which is used to estimate the linear and angular velocities and acculations in X,Y,Z coordinate frames.

