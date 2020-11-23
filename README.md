## Software Development for Robotics (ENPM 808X) ROS and Gazebo Exercise

## Dependencies 
 1. ROS Melodic
 2. Ubuntu 18.04 LTS
 3. Catkin

## Standard Install via Command Line

```
cd ~/catkin_ws/src
git clone --recursive https://github.com/kushagra7176/Turtlebot_Walker
cd ..
catkin_make
```
Open the following terminals and run the following commands:

Terminal 1:
```
roscore
```
Terminal 2:
```
cd catkin_ws
source ./devel/setup.bash
roslaunch turtlebot_walker turtlebot_walker.launch record:=true
```
## Printing information in a bag file
Terminal 1:
```
cd catkin_ws
source ./devel/setup.bash
cd src/Turtlebot_Walker/results/
rosbag info turtlebot_walker.bag
```
## Playing a Ros Bag file
Terminal 1:
```
roscore
```
Terminal 2:
```
cd catkin_ws
source ./devel/setup.bash
rosbag play src/Turtlebot_Walker/results/turtlebot_walker.bag
```

