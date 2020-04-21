#include "perimeterframe.h"

PerimeterFrame::PerimeterFrame()
{
  frameName = "Perimeter frame";
  frameColor = "Black";
}

PerimeterFrame::PerimeterFrame(std::string name, std::string color)
{
  frameName = name;
  frameColor = color;
}

std::string PerimeterFrame::getFrameName() const
{
  return frameName;
}

void PerimeterFrame::setFrameName(std::string val)
{
  frameName = val;
}

std::string PerimeterFrame::getFrameColor() const
{
  return frameColor;
}

void PerimeterFrame::setFrameColor(std::string val)
{
  frameColor = val;
}
