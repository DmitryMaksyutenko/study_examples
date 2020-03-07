#ifndef TRAJECTORY_H
#define TRAJECTORY_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>

class Trajectory : public QWidget
{
    Q_OBJECT

public:
    Trajectory(QWidget *obj = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // TRAJECTORY_H
