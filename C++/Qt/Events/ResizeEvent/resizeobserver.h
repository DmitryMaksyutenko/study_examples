#ifndef RESIZEOBSERVER_H
#define RESIZEOBSERVER_H

#include <QLabel>
#include <QResizeEvent>

class ResizeObserver : public QLabel
{
    Q_OBJECT

public:
    ResizeObserver(QWidget *obj = nullptr);

protected:
    void resizeEvent(QResizeEvent *e) override;

};

#endif // RESIZEOBSERVER_H
