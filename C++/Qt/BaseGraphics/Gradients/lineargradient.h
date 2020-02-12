#ifndef LINEARGRADIENT_H
#define LINEARGRADIENT_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QLinearGradient>

class LinearGradient : public QWidget
{
    Q_OBJECT

public:
    LinearGradient(QWidget *obj = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

};

#endif // LINEARGRADIENT_H
