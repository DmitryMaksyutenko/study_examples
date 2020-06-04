#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  Widget w(":static", "index.html");
  w.show();
  return a.exec();
}
