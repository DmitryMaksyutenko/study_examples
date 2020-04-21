#ifndef __BMW_H
#define __BMW_H

#include "icar.h"
#include "../carframe/perimeterframe.h"
#include "../carwheels/enkel.h"

class BMW : public ICar
{
  public:
    PerimeterFrame *createFrame() const override;
    Enkel *createWheel() const override;
};

#endif
