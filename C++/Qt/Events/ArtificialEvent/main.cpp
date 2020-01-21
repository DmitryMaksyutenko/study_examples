#include <QApplication>
#include <QtWidgets>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QLineEdit text("User input: ");
    text.show();
    text.resize(500, 20);

    for(int i = Qt::Key_A; i < Qt::Key_Z; i++)
    {
//        QChar ch = 65 + i;
//        int nKey = Qt::Key_A + i;

        QKeyEvent press(QEvent::KeyPress, i, Qt::NoModifier, (QChar)i);
        QApplication::sendEvent(&text, &press);

        QKeyEvent release(QEvent::KeyRelease, i, Qt::NoModifier, (QChar)i);
        QApplication::sendEvent(&text, &release);
    }

    return app.exec();
}
