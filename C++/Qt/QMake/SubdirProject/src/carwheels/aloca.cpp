#include "aloca.h"


Aloca::Aloca() : size(16), producer("Aloca")
{}

Aloca::Aloca(int val, std::string str) : size(val), producer(str)
{}

void Aloca::setWheelSize(int val)
{
  size = val;
}

int Aloca::getWheelSize() const
{
  return size;
}

void Aloca::setWheelProducer(std::string str)
{
  producer = str;
}

std::string Aloca::getWheelProducer() const
{
  return producer;
}
