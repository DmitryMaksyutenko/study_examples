#include <QApplication>

#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //	QWidget(QWidget* pwgt = О, Qt::WindowFlags f = 0); the class constructor.
    MainWindow window(nullptr, Qt::Window);
    /*
       window.setWindowFlag(Qt::WindowFlags) method for setting the window style.

        Widow types:
        Qt::Window
        Qt::Toll
        Qt::ToolTip
        Qt::PopUp
        Qt::SplashScreen

        window modifications:
        Qt::WindowSystemMenuHint
        Qt::WindowMaximizeButtonHint
        Qt::WindowMinimizeButtonHint
        Qt::WindowContextHelpButtonHint
        Qt::FramelessWindowHint
    */

    window.setWindowTitle("Test Window"); // self-titled method.

    //	Method to display a widget on the screen.
    //	hide() - self-titled method of class.
    window.show();

    return a.exec();
}
