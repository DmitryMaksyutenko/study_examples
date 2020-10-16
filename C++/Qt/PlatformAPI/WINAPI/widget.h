#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPaintEngine>
#include <QResizeEvent>
#include <QPaintEvent>

class Widget : public QWidget
{
    Q_OBJECT

protected:
    virtual bool nativeEvent(const QByteArray &bArr,
                             void *message,
                             long *result);
    virtual void paintEvent(QPaintEvent *event);
    virtual void resizeEvent(QResizeEvent *event);

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    QPaintEngine *paintEngine() const;
};
#endif // WIDGET_H
