#include "rospi/GpioClientNode.h"

int main(int argc, char **argv)
{
	GpioClientNode gpioClientNode(argc, argv);
	gpioClientNode.testBlink();

  return 0;
}


