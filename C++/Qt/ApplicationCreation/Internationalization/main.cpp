#include "window.h"

#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  Window w;
  w.show();
  return a.exec();
}
