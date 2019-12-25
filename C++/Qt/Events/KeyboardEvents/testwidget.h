#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <QString>

class TestWidget : public QWidget
{
    Q_OBJECT

public:
    TestWidget();

protected:
    void keyPressEvent(QKeyEvent *event) override;


signals:
    void keyAsString(const QString &str);

};

#endif // TESTWIDGET_H
