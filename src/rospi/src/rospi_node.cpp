#include "ros/ros.h"
#include "std_msgs/String.h"

#include "rospi/GpioManager.h"

#include <sstream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "theRospi");
  ros::NodeHandle n;

  ros::Rate loop_rate(2);

	GpioManager gpio;
	bool an = true;

  while (ros::ok())
	{
		ROS_INFO("SPIN");
		
    gpio.writePin(3, an);
    gpio.writePin(2, !an);		
		an = !an;
		
		ros::spinOnce();
		loop_rate.sleep();
	}


  return 0;
}


