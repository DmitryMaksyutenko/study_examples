#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow w;
  QDesktopWidget *p_desctop = a.desktop();
  w.move((p_desctop->width() - w.width()) / 2,
         (p_desctop->height() - w.height()) / 2);
  w.show();
  return a.exec();
}
