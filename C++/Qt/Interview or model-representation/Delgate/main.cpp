#include "simpledelegate.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QStringListModel model;
    model.setStringList(QStringList() << "One" << "Two" << "Three");

    QListView listView;
    listView.setModel(&model);
    listView.setItemDelegate(new SimpleDelegate(&listView));
    listView.viewport()->setAttribute(Qt::WA_Hover);

    listView.show();
    return a.exec();
}
