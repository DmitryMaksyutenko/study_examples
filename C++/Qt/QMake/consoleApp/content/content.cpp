#include "content.h"

Content::Content()
{
  content = "Base content";
}

std::string Content::getContent() const
{
  return content;
}

void Content::setContent(std::string val)
{
  content = val;
}
