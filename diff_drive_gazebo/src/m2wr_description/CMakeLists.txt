cmake_minimum_required(VERSION 3.0.2)
project(m2wr_description)

find_package(catkin REQUIRED COMPONENTS
  urdf
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

# add_library(laz_sensor_plugin plugins/PLUGINFILE.cc)
# target_link_libraries(laz_sensor_plugin ${catkin_LIBRARIES} ${GAZEBO_LIBRARIES} ${roscpp_LIBRARIES} RayPlugin)