cmake_minimum_required(VERSION 2.8.3)
project(serial_example)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  serial
  std_msgs
)

catkin_package(
  CATKIN_DEPENDS
    serial
    std_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(serial_example_node src/serial_example_node.cpp)
add_executable(serial_example_node2 src/serial_example_node2.cpp)
add_executable(ser_subscriber src/ser_subscriber.cpp)
target_link_libraries(serial_example_node
  ${catkin_LIBRARIES}
)
target_link_libraries(serial_example_node2
  ${catkin_LIBRARIES}
)
target_link_libraries(ser_subscriber
  ${catkin_LIBRARIES}
)

