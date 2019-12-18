#include <QApplication>
#include <QListView>
#include <QTableView>

#include "Intlistmodel.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    IntListModel intList(QList<int>() << 1234 << 63246 << 007 << 3452);

    QListView listView;
    listView.setModel(&intList);

    QTableView tableView;
    tableView.setModel(&intList);

    listView.show();
    tableView.show();
    return app.exec();
}
