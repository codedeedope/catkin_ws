#ifndef GPIOMANAGER_H
#define GPIOMANAGER_H

class GpioManager
{
    public:
    GpioManager();
    ~GpioManager();

    bool writePin(unsigned int pin, bool high);
    
    private:
    bool initialisationFailed;
};

#endif


