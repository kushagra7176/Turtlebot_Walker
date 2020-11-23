/**
 *@file       main.cpp
 *@author     Kushagra Agrawal
 *@copyright  MIT License 2020
 *@brief      Main file for running the node.
 */

#include "Walker.hpp"
#include <ros/ros.h>

int main(int argc, char** argv) {
    ros::init(argc, argv, "walker");
    ros::NodeHandle node;
    Walker walker(node);
}
