#!/bin/bash

#Starten mit:
#sudo ./_client.bash

echo "sudo nicht vergessen?"
echo "---------------------"
cd /home/rospi/catkin_ws
source devel/setup.bash
roslaunch rospi gpioClient.launch

