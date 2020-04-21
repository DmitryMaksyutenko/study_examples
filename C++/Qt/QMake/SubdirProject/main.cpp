#include <iostream>

#include "src/clientinterface/clientinterface.h"
#include "src/carfactory/ferrari.h"
#include "src/carfactory/bmw.h"

int main()
{
  Ferrari f;
  BMW b;
  showCar(f);
  showCar(b);

  return 0;
}
