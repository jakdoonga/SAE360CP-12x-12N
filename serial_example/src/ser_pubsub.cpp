#include <ros/ros.h>
#include <serial/serial.h>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>

#include <std_msgs/Int16.h>
#include <iostream>
#include <string>
#include <typeinfo>

std::string temp;
int16_t temp2;

void msgCallback(const std_msgs::String::ConstPtr& msg){
  temp.clear();
  temp = msg->data;
  temp2 = std::stoi(temp.substr(0,4));
  ROS_INFO_STREAM("tca1 " << temp.substr(0,4));
  // ROS_INFO_STREAM("tca1 " << temp2);
  // ROS_INFO_STREAM("recieve = " << msg->data);
  // ROS_INFO_STREAM("size " << sizeof(msg->data));
  ROS_INFO_STREAM("");
}

int main (int argc, char** argv)
{
  ros::init(argc, argv, "ser_subscriber");
  ros::NodeHandle nh;

  ros::Subscriber ser_sub= nh.subscribe("read", 100, msgCallback);
  ros::Publisher read_pub = nh.advertise<std_msgs::Int16>("raw", 1000);

  ros::Rate loop_rate(5);
  while(ros::ok())
  {
    ros::spinOnce();
    std_msgs::Int16 raw;
    raw.data = temp2;
    read_pub.publish(raw);

    loop_rate.sleep();
  }

  return 0;
}
