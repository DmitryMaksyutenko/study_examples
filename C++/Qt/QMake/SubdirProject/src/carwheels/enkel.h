#ifndef __ENKEL_H
#define __ENKEL_H

#include "iwheels.h"

class Enkel : public Wheel
{
  private:
    int size;
    std::string producer;

  public:
    Enkel();
    Enkel(int val, std::string str);
    void setWheelSize(int val) override;
    int getWheelSize() const override;
    void setWheelProducer(std::string str) override;
    std::string getWheelProducer() const override;
};

#endif
