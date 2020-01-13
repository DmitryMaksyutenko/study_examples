#include "testclose.h"

TestClose::TestClose(QWidget *obj) : QWidget(obj)
{

}

void TestClose::closeEvent(QCloseEvent *event)
{
    QMessageBox message;
    message.setText("Close window ?");
    message.setStandardButtons( QMessageBox::Ok |
                                QMessageBox::Cancel);

    switch (message.exec()) {

        case QMessageBox::Ok:
            close();
            break;
        case QMessageBox::Cancel:
            event->ignore();
            break;
    }
}
