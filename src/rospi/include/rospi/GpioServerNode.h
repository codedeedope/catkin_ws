#ifndef GPIO_SERVER_NODE
#define GPIO_SERVER_NODE

#include "rospi/GpioManager.h"
#include "rospi/WritePin.h" ///home/rospi/catkin_ws/devel/include/rospi

#include <memory>

#include "ros/ros.h"

class GpioServerNode
{
	public:
	GpioServerNode(int argc, char **argv);
	void start();
	
	private:
	std::unique_ptr<ros::NodeHandle> node;
	static std::unique_ptr<GpioManager> gpio;
	static bool writePin(rospi::WritePin::Request& req, rospi::WritePin::Response& res);
};

#endif


