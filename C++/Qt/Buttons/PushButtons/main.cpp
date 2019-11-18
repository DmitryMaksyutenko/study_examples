#include "widget.h"

#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    QPushButton pushButton("Push me!"); // Simple push button

    QPushButton toggleButton("Toggle me!"); // 	The toggle
    toggleButton.setCheckable(true);
    toggleButton.setChecked(true);

    QPushButton secretButton("This is secret button!"); // Hide borders
    secretButton.setFlat(true);

    QPixmap img("/home/dima/Projects/Designe/trycpppy/Moon.png"); //	Button with image
    QPushButton imgButton("PixMap button!");
    imgButton.setIcon(img);
    imgButton.setIconSize(img.size());

    QPushButton menuButton("Menu");	//	The menu button
    QMenu menu(&menuButton);		// Menu widget
    menu.addAction("row 1");
    menu.addAction("row 2");
    menu.addAction("row 3");
    menu.addAction("Quit");
    menuButton.setMenu(&menu);

    //	Set vertical layout
    QVBoxLayout vBox;
    vBox.addWidget(&pushButton);
    vBox.addWidget(&toggleButton);
    vBox.addWidget(&secretButton);
    vBox.addWidget(&imgButton);
    vBox.addWidget(&menuButton);

    w.setLayout(&vBox);
    w.show();
    return a.exec();
}
