#include "rospi/GpioManager.h"

#include <stdio.h>

extern "C" {
#include <pigpio.h>
}

GpioManager::GpioManager()
:initialisationFailed(false)
{
    //init lib
    int pigpio_version = gpioInitialise();

    if (pigpio_version == PI_INIT_FAILED)
    {
        printf("PI_INIT_FAILED\n");
        initialisationFailed = true;
    }
}

GpioManager::~GpioManager()
{
    //terminiert Bibliothek
    gpioTerminate();
}

bool GpioManager::writePin(unsigned int pin, bool high)
{
	if (initialisationFailed)	return false;

    int mode_success = gpioSetMode(pin, PI_OUTPUT);
    if (mode_success != 0)
    {
        printf("Setting mode for GPIO Pin failed!\n");
        return false;
    }

    //http://abyz.me.uk/rpi/pigpio/cif.html#gpioSetPullUpDown

    int write_success = gpioWrite(pin, high ? 1 : 0);
    if (write_success != 0)
    {
        printf("Writing GPIO Pin failed!\n");
        return false;
    }
    
    return true;
}


