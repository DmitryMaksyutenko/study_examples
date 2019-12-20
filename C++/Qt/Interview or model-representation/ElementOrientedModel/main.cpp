#include <QtWidgets>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QStringList strList;
    QListWidget listWidget;
    QListWidgetItem *listWedgItem = nullptr;

    listWidget.setIconSize(QSize(48, 48));
    strList << "Linux" << "Windows" << "MacOSX" << "Android";

    foreach (QString str, strList) {
        listWedgItem = new QListWidgetItem(str, &listWidget);
        listWedgItem->setIcon(QPixmap("home/dima/Pictures/"+ str +".png"));
    }

    listWidget.setWindowTitle("Listwidget");

    QListView listView;
    listView.setModel(listWidget.model());
    listView.setSelectionModel(listWidget.selectionModel());
    listView.setWindowTitle("ListView");

    listWidget.show();
    listView.show();
    return app.exec();
}
