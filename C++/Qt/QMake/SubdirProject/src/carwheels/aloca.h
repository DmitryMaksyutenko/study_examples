#ifndef __ALOCA_H
#define __ALOCA_H

#include "iwheels.h"

class Aloca : public Wheel
{
  private:
    int size;
    std::string producer;

  public:
    Aloca();
    Aloca(int val, std::string str);
    void setWheelSize(int val) override;
    int getWheelSize() const override;
    void setWheelProducer(std::string str) override;
    std::string getWheelProducer() const override;
};

#endif
