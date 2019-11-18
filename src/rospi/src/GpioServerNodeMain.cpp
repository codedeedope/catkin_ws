#include "rospi/GpioServerNode.h"

int main(int argc, char **argv)
{
	GpioServerNode gpioServerNode(argc, argv);
	gpioServerNode.start();
	return 0;
}


