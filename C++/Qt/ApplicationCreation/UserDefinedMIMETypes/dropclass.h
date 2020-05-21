#ifndef DROPCLASS_H
#define DROPCLASS_H

#include <QLabel>
#include <QMouseEvent>
#include <QDragEnterEvent>
#include <QDropEvent>

class DropClass : public QLabel
{
    Q_OBJECT

private:
    QPoint mDragPos;

public:
    DropClass();

protected:
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseMoveEvent(QMouseEvent *ev) override;
    void dragEnterEvent(QDragEnterEvent *ev) override;
    void dropEvent(QDropEvent *ev) override;

  private:
    void startDrag();
};

#endif // DROPCLASS_H
