#ifndef __XFRAME_H
#define __XFRAME_H

#include "iframe.h"

class Xframe : public Iframe
{
  private:
    std::string frameName;
    std::string frameColor;

  public:
    Xframe();
    Xframe(std::string name, std::string color);

    std::string getFrameName() const override;
    void setFrameName(std::string val) override;
    std::string getFrameColor() const override;
    void setFrameColor(std::string val) override;
};

#endif
