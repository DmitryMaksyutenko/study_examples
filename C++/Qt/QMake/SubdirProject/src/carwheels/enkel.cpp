#include "enkel.h"


Enkel::Enkel() : size(16), producer("Enkel")
{}

Enkel::Enkel(int val, std::string str) : size(val), producer(str)
{}

void Enkel::setWheelSize(int val)
{
  size = val;
}

int Enkel::getWheelSize() const
{
  return size;
}

void Enkel::setWheelProducer(std::string str)
{
  producer = str;
}

std::string Enkel::getWheelProducer() const
{
  return producer;
}
