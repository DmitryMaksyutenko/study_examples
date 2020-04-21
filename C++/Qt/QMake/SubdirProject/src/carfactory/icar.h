#ifndef __ICAR_H
#define __ICAR_H

#include "../carframe/iframe.h"
#include "../carwheels/iwheels.h"

class ICar
{
  public:
    virtual Iframe *createFrame() const = 0;
    virtual Wheel *createWheel() const  = 0;
};

#endif
