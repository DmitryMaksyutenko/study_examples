#ifndef __IWHEELS_H
#define __IWHEELS_H

#include <string>

class Wheel
{
  public:
    virtual void setWheelSize(int val)              = 0;
    virtual int getWheelSize() const                = 0;
    virtual void setWheelProducer(std::string str)  = 0;
    virtual std::string getWheelProducer() const    = 0;
};

#endif
