#!/bin/bash

#Starten mit:
#sudo ./_server.bash

echo "sudo nicht vergessen?"
echo "---------------------"
cd /home/rospi/catkin_ws
source devel/setup.bash
roslaunch rospi gpioServer.launch

