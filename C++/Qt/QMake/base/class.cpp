#include "class.h"

Hello::Hello()
{
  helloString = "Hello QMake!\n";
}

const std::string Hello::getHelloString() const
{
  return helloString;
}
