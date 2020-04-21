#ifndef __IFRAME_H
#define __IFRAME_H

#include <string>

class Iframe
{
  public:
    virtual std::string getFrameName() const    = 0;
    virtual void setFrameName(std::string val)  = 0;
    virtual std::string getFrameColor() const   = 0;
    virtual void setFrameColor(std::string val) = 0;
};

#endif
