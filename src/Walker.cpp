/**
 *@file       Walker.cpp
 *@author     Kushagra Agrawal
 *@copyright  MIT License 2020
 *@brief      Describes Walker class functions.
 */

#include "Walker.hpp"
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sensor_msgs/LaserScan.h>
#include "geometry_msgs/Twist.h"

void Walker::callback(const sensor_msgs::LaserScan::ConstPtr& data) {
    double minDistance = 0.2;
    for (int i = 0; i < data->ranges.size(); i++) {
        if (data->ranges[i] > minDistance) {
            minDistance = data->ranges[i];
        }
    }
    distance = minDistance;
}

Walker::Walker(ros::NodeHandle node) {
    // ROS LaserScan Subscriber
    ros::Subscriber laserSubscriber =
            node.subscribe("/scan", 1000, &Walker::callback, this);

    // ROS Publisher
    ros::Publisher velocityPublisher =
            node.advertise<geometry_msgs::Twist>("/mobile_base/commands/velocity", 1);

    ros::Rate loopRate(4);
    while (ros::ok()) {
        // Declare and initialize twist
        geometry_msgs::Twist twist;
        twist.linear.x = 0.0;
        twist.linear.y = 0.0;
        twist.linear.z = 0.0;
        twist.angular.x = 0.0;
        twist.angular.y = 0.0;
        twist.angular.z = 0.0;

        if (distance > 0.77) {
            ROS_INFO_STREAM("Moving Forward!");
            twist.linear.x = 0.12;
        } else {
            ROS_INFO_STREAM("Rotating!");
            twist.angular.z = 1.7;
        }
        velocityPublisher.publish(twist);
        ros::spinOnce();
        loopRate.sleep();
    }
}
