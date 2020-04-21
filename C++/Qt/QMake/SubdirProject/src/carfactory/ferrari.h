#ifndef __FERRARI_H
#define __FERRARI_H

#include "icar.h"
#include "../carframe/xframe.h"
#include "../carwheels/aloca.h"

class Ferrari : public ICar
{
  public:
    Xframe *createFrame() const override;
    Aloca *createWheel() const override;
};

#endif
