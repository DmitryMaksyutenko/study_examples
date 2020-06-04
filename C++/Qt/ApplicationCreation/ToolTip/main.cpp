#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow w;
  w.setToolTip("<H1>Tool Tip</H1>");
  w.show();
  return a.exec();
}
