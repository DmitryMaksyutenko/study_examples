#include <QApplication>

#include "SourceCode/gui.h"
#include "SourceCode/add.h"

int main(int argc, char **argv)
{
    QApplication app = QApplication(argc, argv);

    GUI w;
    Add a;

    qint64 result = a.addition(1, 1);

    w.setText(QString::number(result));
    w.show();

    return app.exec();
}
