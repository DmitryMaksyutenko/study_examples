#include <QApplication>

#include "oglquad.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    OGLQuad quad;
    quad.resize(200, 200);
    quad.show();

    return app.exec();
}
