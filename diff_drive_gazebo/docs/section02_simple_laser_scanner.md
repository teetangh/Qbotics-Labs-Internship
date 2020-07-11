In the   previous section of the documentation we had constructed the model of our differential drive. We also constructed macros for the links and the joints of the wheels and stored it in a  XACRO  file and called it macros.xacro.

In this Section of the documentation you will learn how to create a simple laser scanner as well as customising the gazebo plugin for the laser scanner so that it can interact with the environment.


## Laser Scanner URDF snippet
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

### Explanation

In the above code sample,The  sensor_laser is the scanner in the form of a cylinder and  we are giving it appropriate radius and height and as usual giving it similar visual and  collision parameters. We are also setting the mass to be one unit.  Since the  laser scanner is mounted on the chassis link of the differential drive,  the parent link is obviously the chassis of the differential drive  and child link is the sensor itself

## Developing the code for the Laser Sensor Gazebo plugin

Make a gazebo file (with .gazebo extension and very similar to urdf,xacro files) and call it m2wr.gazebo .The Final folder heirarchy must look like as demonstrated below:
    
    diff_drive_gazebo:
        m2wr_description
            urdf
                m2wr.gazebo
                m2wr.xacro
                macros.xacro

We now proceed on to developing the code for the Laser Sensor Gazebo plugin.The following code snippet will demonstrate how a simple gazebo plugin can be implemented: 

    <?xml version="1.0"?>
    <robot>
        <!-- Laser Scanner -->
        <gazebo reference="sensor_laser">
            <sensor type="ray" name="head_hokuyo_sensor">
                <pose>0 0 0 0 0 0</pose>
                <visualize>false</visualize>
                <update_rate>20</update_rate>
                <ray>
                    <scan>
                        <horizontal>
                            <samples>720</samples>
                            <resolution>1</resolution>
                            <min_angle>-1.57079632679</min_angle>
                            <max_angle>1.57079632679</max_angle>
                        </horizontal>
                    </scan>
                    <range>
                        <min>0.10</min>
                        <max>10.0</max>
                        <resolution>1</resolution>
                    </range>
                    <noise>
                        <type>gaussian</type>
                        <mean>0.0</mean>
                        <stddev>0.01</stddev>
                    </noise>
                </ray>

                <plugin name="gazebo_ros_head_hokuyo_controller" filename="libgazebo_ros_laser.so">
                    <topicName>/m2wr/laser/scan</topicName>
                    <frameName>sensor_laser</frameName>
                </plugin>
            </sensor>
        </gazebo>
    <robot>

### Explanation

Most of the properties are self-explanatory,but we’ll look at some of them.

 The scan range property  allows the laser to scan from -90 degrees to +90 degrees. we have to set the number of samples taken to be 720 and  resolution to be unity.

 you also said the minimum and maximum range of the scanner to be  0.1 and 10 respectively with the resolution of unity. we also introduce a Gaussian noise  which follows a normal distribution having mean 0 and standard deviation of 0.01.

 We now  connect this with the gazebo plugin of the laser sensor which publishes on the topic /m2wr/laser/scan and and has a frame named sensor_laser

Rememeber all of this is in the m2wr.gazebo file and NOT the m2wr.xacro file.

In the next section of the  documentation,  we shall proceed onto creating the Velodyne VLP-16 Lidar URDF/XACRO and also its plugin.




