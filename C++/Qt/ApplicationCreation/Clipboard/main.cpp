#include <QApplication>
#include <QClipboard>

#include "widget.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  Widget w;

  QClipboard *pClipBoard = QApplication::clipboard();

  QObject::connect(pClipBoard, SIGNAL(dataChanged()),
                   &w, SLOT(slotAddedToClipBoard()));

  w.show();
  return a.exec();
}
