#!/bin/bash

#Starten mit:
#sudo ./_start.bash

cd /home/rospi/catkin_ws
source devel/setup.bash
catkin_make && roslaunch rospi rospi.launch

