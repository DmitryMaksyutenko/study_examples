#ifndef TESTAREA_H
#define TESTAREA_H

#include <QWidget>
#include <QDragEnterEvent>

class TestArea : public QWidget
{
    Q_OBJECT

public:
    TestArea(QWidget *obj = nullptr);

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragLeaveEvent(QDragLeaveEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;

};

#endif // TESTAREA_H
