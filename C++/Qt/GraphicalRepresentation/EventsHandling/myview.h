#ifndef MYVIEW_H
#define MYVIEW_H

#include <QGraphicsView>

#include <QObject>

class MyView : public QGraphicsView
{
    Q_OBJECT

public:
    MyView(QGraphicsScene *pScene, QWidget *obj = nullptr);

public slots:
    void slotZoomIn();
    void slotZoomOut();
    void slotRotateLeft();
    void slotRotateRight();
};

#endif // MYVIEW_H
