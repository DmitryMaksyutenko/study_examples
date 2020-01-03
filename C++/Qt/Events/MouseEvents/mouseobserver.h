#ifndef MOUSEOBSERVER_H
#define MOUSEOBSERVER_H

#include <QtWidgets>
#include <QMouseEvent>
#include <QString>


class MouseObserver : public QLabel
{
public:
    MouseObserver(QWidget *obj = nullptr);

protected:
    void mousePressEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;
    void mouseMoveEvent(QMouseEvent *e) override;

    void dumpEvent(QMouseEvent *e, const QString &message);
    QString modifiersInfo(QMouseEvent *e);
    QString buttonsInfo(QMouseEvent *e);
};

#endif // MOUSEOBSERVER_H
