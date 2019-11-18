#ifndef GPIO_CLIENT_NODE
#define GPIO_CLIENT_NODE

#include "rospi/WritePin.h" ///home/rospi/catkin_ws/devel/include/rospi

#include <memory>

#include "ros/ros.h"

class GpioClientNode
{
	public:
	GpioClientNode(int argc, char **argv);
	void writePin(rospi::WritePin::Request::_pin_type pin, rospi::WritePin::Request::_high_type high);
	void testBlink();
	
	private:
	std::unique_ptr<ros::NodeHandle> node;
	std::unique_ptr<ros::ServiceClient> client;
};

#endif


