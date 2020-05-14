#include <QApplication>

#include "video.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Video v;
    v.resize(400, 450);
    v.show();

    return app.exec();
}
