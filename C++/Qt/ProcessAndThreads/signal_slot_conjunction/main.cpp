#include "mainwindow.h"
#include "worker.h"

#include <QApplication>
#include <QLCDNumber>
#include <QProgressBar>
#include <QThread>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLCDNumber lcd;
    Worker worker;
    QThread thread;

    QProgressBar prBar;
    MainWindow w;

    QObject::connect(&w, SIGNAL(process(int)), &prBar, SLOT(setValue(int)));
    prBar.show();
    w.start();

    //----------------------------------------------------------------------------------
    lcd.setSegmentStyle(QLCDNumber::Filled);
    lcd.display(30);
    lcd.setGeometry(500, 300, 300, 50);
    lcd.show();

    worker.moveToThread(&thread);

    QObject::connect(&worker, SIGNAL(valueChanged(int)), &lcd, SLOT(display(int)));
    QObject::connect(&thread, SIGNAL(started()), &worker, SLOT(slotDoWork()));
    QObject::connect(&worker, SIGNAL(finished()), &a, SLOT(quit()));

    thread.start();

    int nResult = a.exec();

    thread.quit();
    thread.wait();

    return nResult;
}
