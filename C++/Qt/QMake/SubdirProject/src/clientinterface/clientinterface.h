#ifndef __CLIENTINTERFACE_H
#define __CLIENTINTERFACE_H

#include <iostream>

#include "../carfactory/icar.h"
#include "../carframe/xframe.h"
#include "../carwheels/aloca.h"

void showCar(ICar &car)
{
  Iframe *frame = car.createFrame();
  Wheel *wheel = car.createWheel();

  std::cout << "frame name: " << frame->getFrameName() << "\nframe color: " << frame->getFrameColor() << '\n';
  std::cout << "wheel producer: " << wheel->getWheelProducer() << "\nwhell size: " << wheel->getWheelSize() << '\n';

  delete frame;
  delete wheel;
}

#endif
