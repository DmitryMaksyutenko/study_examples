#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene scene(QRectF(-100, -100, 300, 300));
    QGraphicsView gView(&scene);
    gView.setWindowState(Qt::WindowMaximized);

    QGraphicsRectItem *pRectItem = scene.addRect(QRectF(-30, -30, 120, 80),
                                                  QPen(Qt::black),
                                                  QBrush(Qt::green));
    pRectItem->setFlags(QGraphicsItem::ItemIsMovable);

    QGraphicsPixmapItem *pPixItem = scene.addPixmap(QPixmap(":/img/Linux.png"));
    pPixItem->setFlags(QGraphicsItem::ItemIsMovable);

    QGraphicsTextItem *pTextItem = scene.addText("MOVE US!!!");
    pTextItem->setFlags(QGraphicsItem::ItemIsMovable);

    QGraphicsLineItem *pLineItem = scene.addLine(QLineF(-10, -10, -80, -80),
                                                 QPen(Qt::red, 2));
    pLineItem->setFlags(QGraphicsItem::ItemIsMovable);

    gView.show();

    return a.exec();
}
