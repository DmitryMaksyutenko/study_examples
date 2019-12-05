#include <QtWidgets>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QToolBox tools;
    QStringList toolsList;

    toolsList << "Linux" << "Windows" << "MacOSX" << "Android";
    foreach (QString str, toolsList)
        tools.addItem(new QLabel(str, &tools), QPixmap("/home/dima/Pictures/"+ str +".png"), str);

    tools.resize(100, 80);
    tools.show();
    return app.exec();
}
