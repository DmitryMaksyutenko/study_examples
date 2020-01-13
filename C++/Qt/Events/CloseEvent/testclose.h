#ifndef TESTCLOSE_H
#define TESTCLOSE_H

#include <QWidget>
#include <QMessageBox>
#include <QCloseEvent>

class TestClose : public QWidget
{
    Q_OBJECT

public:
    TestClose(QWidget *obj = nullptr);

protected:
    void closeEvent(QCloseEvent *event) override;
};

#endif // TESTCLOSE_H
