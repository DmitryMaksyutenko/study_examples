#include "bmw.h"

PerimeterFrame *BMW::createFrame() const
{
  return new PerimeterFrame();
}

Enkel *BMW::createWheel() const
{
  return new Enkel();
}
