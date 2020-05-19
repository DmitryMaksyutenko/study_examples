#include "drop.h"

Drop::Drop(QWidget *parent)
  : QLabel(parent)
{
  setAcceptDrops(true);
  setGeometry(500, 300, 500, 500);
}

Drop::~Drop()
{}

void Drop::dropEvent(QDropEvent *e)
{
    QList<QUrl> urlList = e->mimeData()->urls();
    QString str;
    foreach (QUrl url, urlList)
        str += url.toString() + "\n";
    setText(str);
}

void Drop::dragEnterEvent(QDragEnterEvent *e)
{
    if(e->mimeData()->hasFormat("text/uri-list"))
      e->acceptProposedAction();
}

