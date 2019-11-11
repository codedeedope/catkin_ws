#!/bin/bash

#Starten mit:
#sudo ./rospi_launch.bash

cd /home/rospi/catkin_ws
source devel/setup.bash
roslaunch rospi rospi.launch

