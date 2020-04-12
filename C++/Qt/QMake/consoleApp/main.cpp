#include "content/content.h"
#include "showmessage/output.h"

int main(int argc, char *argv[])
{
  Output out;
  Content content;

  std::string strArgv = argv[0];
  std::string strArgc = std::to_string(argc);

  out.print(strArgv);
  out.print(strArgc);
  out.print(content.getContent());

  content.setContent("some new value");
  out.print(content.getContent());

  return 0;
}
