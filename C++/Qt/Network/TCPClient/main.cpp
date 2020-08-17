#include <QApplication>

#include "client.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    cli::Client w("127.0.0.1", 8000);

    w.show();

    return a.exec();
}
