#include <QApplication>

#include "lineargradient.h"
#include "conicalgradient.h"
#include "radialgradient.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    LinearGradient linearGradient;
    ConicalGradient conicalGradient;
    RadialGradient radialGradient;

    linearGradient.show();
    conicalGradient.show();
    radialGradient.show();

    return app.exec();
}
