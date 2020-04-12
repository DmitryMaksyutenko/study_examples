#ifndef __CONTENT_H
#define __CONTENT_H

#include <string>

class Content
{
  std::string content;

  public:
    Content();

    std::string getContent() const;
    void setContent(std::string val);
};

#endif
