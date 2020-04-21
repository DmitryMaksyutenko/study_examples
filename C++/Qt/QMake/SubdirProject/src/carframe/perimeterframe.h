#ifndef __PERIMETERFRAME_H
#define __PERIMETERFRAME_H

#include "iframe.h"

class PerimeterFrame : public Iframe
{
  private:
    std::string frameName;
    std::string frameColor;

  public:
    PerimeterFrame();
    PerimeterFrame(std::string name, std::string color);

    std::string getFrameName() const override;
    void setFrameName(std::string val) override;
    std::string getFrameColor() const override;
    void setFrameColor(std::string val) override;
};

#endif
