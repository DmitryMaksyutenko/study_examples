#ifndef TESTLABEL_H
#define TESTLABEL_H

#include <QLabel>
#include <QPaintEvent>
#include <QPainter>
#include <QBrush>

class TestLabel : public QLabel
{
    Q_OBJECT

public:
    TestLabel(QWidget *obj = nullptr);

protected:
    void paintEvent(QPaintEvent *e) override;

private:
    const QPoint getLocation() const;

};

#endif // TESTLABEL_H
