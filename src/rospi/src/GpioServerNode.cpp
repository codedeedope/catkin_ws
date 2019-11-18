#include "rospi/GpioServerNode.h"

std::unique_ptr<GpioManager> GpioServerNode::gpio = nullptr;

GpioServerNode::GpioServerNode(int argc, char **argv)
{
	ros::init(argc, argv, "GpioServer");
	node = std::make_unique<ros::NodeHandle>();
	gpio = std::make_unique<GpioManager>();
}

void GpioServerNode::start()
{
	ros::ServiceServer server = node->advertiseService("writePin", writePin);
	ROS_INFO("writePin Service aktiviert");
	ros::spin();
}

bool GpioServerNode::writePin(rospi::WritePin::Request& req, rospi::WritePin::Response& res)
{
	res.success = gpio->writePin(req.pin, req.high);
	ROS_INFO("Request erhalten.");
	
	return true;
}


