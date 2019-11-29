#include <QtWidgets>
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QStringList lst;
    QListWidget lwg;
    QListWidgetItem *pitem = nullptr;

    lwg.setIconSize(QSize(96, 96));
    lst << "Linux" << "Windows" << "MacOSX" << "Android";

    foreach (auto str, lst) {
        pitem = new QListWidgetItem(str, &lwg);
        pitem->setIcon(QPixmap("/home/dima/Projects/Qt/SimpleList/" + str + ".png"));
        pitem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable |
                        Qt::ItemIsEditable | Qt::ItemIsDragEnabled);
    }

    lwg.sortItems(Qt::AscendingOrder);
    lwg.resize(250, 400);
    lwg.show();

    return a.exec();
}
