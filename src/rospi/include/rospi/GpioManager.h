#ifndef GPIOMANAGER_H
#define GPIOMANAGER_H

class GpioManager
{
    public:
    GpioManager();
    ~GpioManager();

    void writePin(unsigned int pin, bool high);
};

#endif


