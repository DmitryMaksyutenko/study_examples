#include <QtWidgets>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QTabWidget tab;
    QStringList OSList;

    OSList << "Linux" << "Windows" << "MacOSX" << "Android";
    foreach (QString str, OSList)
        tab.addTab(new QLabel(str, &tab), QPixmap("/home/dima/Pictures/"+ str +".png"), str);

    tab.resize(420, 100);
    tab.show();
    return app.exec();
}
