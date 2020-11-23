/**
 *@file       Walker.hpp
 *@author     Kushagra Agrawal
 *@copyright  MIT License 2020
 *@brief      Header file for Walker class.
 */

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sensor_msgs/LaserScan.h>

class Walker {
private:
    /**
      * @ brief    Variable to store distance.
     */
    double distance;
public:
    /**
      * @brief      Constructs the Walker object.
      * @param      node  ros::NodeHandle.
    */
     explicit Walker(ros::NodeHandle node);
     /**
      * @brief      Callback for subscriber.
      * @param      data  sensor_msgs::LaserScan::ConstPtr.
     */
     void callback(const sensor_msgs::LaserScan::ConstPtr& data);
};
