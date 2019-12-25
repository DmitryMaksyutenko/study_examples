#include <QApplication>
#include <QTextEdit>
#include <QVBoxLayout>

#include "testwidget.h"
/*
    Class QKeyevent contains data about keyboard events.
    With that class, you can get information about the key, caused the event, and get ASCII code.
    Event object passes into the methods TestWidget::keyPressEvent() and TestWidget::keyReleaseEvent()

    Inside the event handler method with the  QKeyEvent::key() method is possible to retrieve the key code initialized the event.

    Codes from 20 to 3F are equals to ASCII codes.
    Codes from 30 to 39 are equals to digits above keys with letters.
    Codes from 41 to 5A are equals to capital letters on the keyboard.
    Codes from 1000030 to 1000052 are functional.
    Codes from 1000006 to 1000009 and 1000025, 1000026 equal to keys of a digital keyboard.
    Codes from 1000010 to 1000017 are cursor keys.

    For checking  pressed keys "shift", "ctrl", "alt" use method QKeyEvent::modifiers().
*/

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    TestWidget widget;
    QTextEdit info;
    QVBoxLayout layout;

    info.setReadOnly(true);
    layout.addWidget(&info);
    widget.setLayout(&layout);

    QObject::connect(&widget, SIGNAL(keyAsString(const QString&)), &info, SLOT(insertPlainText(const QString&)));

    widget.resize(300, 200);
    widget.show();
    return app.exec();
}
