#include "rospi/GpioClientNode.h"

GpioClientNode::GpioClientNode(int argc, char **argv)
{
	ros::init(argc, argv, "GpioClient");
	node     = std::make_unique<ros::NodeHandle>();
	client   = std::unique_ptr<ros::ServiceClient>(new ros::ServiceClient(node->serviceClient<rospi::WritePin>("writePin"))); //Stack->Heap per copy-constructor
}

void GpioClientNode::writePin(rospi::WritePin::Request::_pin_type pin, rospi::WritePin::Request::_high_type high)
{
	rospi::WritePin writePin;

  writePin.request.pin = pin;
  writePin.request.high = high;

	ROS_INFO("Pin: %d, High: %d", pin, high);

  bool success = client->call(writePin);

  if (success)
  {
		if (writePin.response.success)
		{
			ROS_INFO("Hat funktioniert.");
		}
		else
		{
  	  ROS_ERROR("Beim Server ist etwas schiefgelaufen.");
		}
  }
  else
  {
    ROS_ERROR("Zwischen Client und Server ist etwas schiefgelaufen.");
  }
}

void GpioClientNode::ledAn()
{
	ROS_INFO("LED anschalten:");
	writePin(3, true);
	writePin(2, false);
}

void GpioClientNode::ledAus()
{
	ROS_INFO("LED ausschalten:");
	writePin(3, false);
	writePin(2, true);
}

void GpioClientNode::testBlink()
{
	ros::Rate loop_rate(2);
	bool an = false;
	
	while (ros::ok())
	{
		if (an) ledAus();
		else ledAn();
	
		an = !an;
	
		ros::spinOnce();
		loop_rate.sleep();
	}
}


