#ifndef DRAG_H
#define DRAG_H

#include <QtWidgets>
#include <QMouseEvent>

class Drag : public QLabel
{
    Q_OBJECT

  private:
    QPoint mMouseDragPosition;

  public:
    Drag(QWidget *parent = nullptr);
    ~Drag();

  private:
    void startDrag();

  protected:
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseMoveEvent(QMouseEvent *ev) override;

};
#endif // DRAG_H
