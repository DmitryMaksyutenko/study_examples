#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>

#include "myview.h"
#include "simpleitem.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QWidget w;
    QGraphicsScene scene(-100, -100, 640, 480);
    QGraphicsPixmapItem *image = scene.addPixmap(QPixmap(":img/Linux.png"));

    MyView view(&scene);
    SimpleItem simpleItem;

    QPushButton zoomIn("&Zoom In");
    QPushButton zoomOut("&Zoom Out");
    QPushButton rotateLeft("&Rotate Left");
    QPushButton rotateRight("&Rotate Right");

    view.setRenderHint(QPainter::Antialiasing, true);

    scene.addItem(&simpleItem);

    simpleItem.setPos(0, 0);
    simpleItem.setFlags(QGraphicsItem::ItemIsMovable);

    image->setParentItem(&simpleItem);
    image->setFlags(QGraphicsItem::ItemIsMovable);

    QObject::connect(&zoomIn, SIGNAL(clicked()), &view, SLOT(slotZoomIn()));
    QObject::connect(&zoomOut, SIGNAL(clicked()), &view, SLOT(slotZoomOut()));
    QObject::connect(&rotateLeft, SIGNAL(clicked()), &view, SLOT(slotRotateLeft()));
    QObject::connect(&rotateRight, SIGNAL(clicked()), &view, SLOT(slotRotateRight()));

    QVBoxLayout layout;
    layout.addWidget(&view);
    layout.addWidget(&zoomIn);
    layout.addWidget(&zoomOut);
    layout.addWidget(&rotateLeft);
    layout.addWidget(&rotateRight);
    w.setLayout(&layout);

    w.show();

    return app.exec();
}
