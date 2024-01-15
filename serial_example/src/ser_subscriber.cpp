#include <ros/ros.h>
#include <serial/serial.h>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>

#include <std_msgs/UInt32.h>
#include <iostream>
#include <string>
#include <typeinfo>

std::string temp;

void msgCallback(const std_msgs::String::ConstPtr& msg){
  temp.clear();
  temp = msg->data;
  ROS_INFO_STREAM("tca1 " << temp.substr(0,4));
  ROS_INFO_STREAM("tca2 " << temp.substr(4,4));
  // ROS_INFO_STREAM("recieve = " << msg->data);
  // ROS_INFO_STREAM("size " << sizeof(msg->data));
  ROS_INFO_STREAM("");
}

int main(int argc, char **argv){
  // 노드 메인 함수
  ros::init(argc, argv, "ser_subscriber");// 노드명 초기화
  ros::NodeHandle nh; // ROS 시스템과 통신을 위한 노드핸들 선언

  // 서브스크라이버 선언, ros_tutorials_topic 패키지의 MsgTutorial 메시지 파일을 이용한
  // 서브스크라이버 ros_tutorial_sub를 작성한다. 토픽명은 "ros_tutorial_msg" 이며,
  // 서브스크라이버큐(queue) 사이즈를 100개로 설정한다는 것이다
  ros::Subscriber ser_sub= nh.subscribe("read", 100, msgCallback);

  // 콜백 함수 호출을 위한 함수로써, 메시지가 수신되기를 대기,
  // 수신되었을 경우 콜백함수를 실행한다
  ros::spin();
  return 0;
}