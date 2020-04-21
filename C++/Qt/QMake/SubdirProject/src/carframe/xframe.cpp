#include "xframe.h"

Xframe::Xframe()
{
  frameName = "X-frame";
  frameColor = "Red";
}

Xframe::Xframe(std::string name, std::string color)
{
  frameName = name;
  frameColor = color;
}

std::string Xframe::getFrameName() const
{
  return frameName;
}

void Xframe::setFrameName(std::string val)
{
  frameName = val;
}

std::string Xframe::getFrameColor() const
{
  return frameColor;
}

void Xframe::setFrameColor(std::string val)
{
  frameColor = val;
}
