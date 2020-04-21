#include "ferrari.h"

Xframe *Ferrari::createFrame() const
{
  return new Xframe();
}

Aloca *Ferrari::createWheel() const
{
  return new Aloca();
}
