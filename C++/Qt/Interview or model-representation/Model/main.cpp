#include <QApplication>
#include <QWidget>
#include <QStringListModel>
#include <QStringList>
#include <QListWidget>
#include <QListWidgetItem>
#include <QModelIndex>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QStringListModel model;
    model.setStringList(QStringList() << "One" << "Two" << "Three");

    QListWidget list1;
    list1.setWindowTitle("window 1");
    list1.setGeometry(100, 100, 500, 300);

    QListWidgetItem *listItem;
    foreach (QString str, model.stringList())
        listItem = new QListWidgetItem(str, &list1);

    QStringList tmp = model.stringList();
    tmp.append("Four");
    model.setStringList(tmp);

    QModelIndex index = model.index(model.rowCount() - 1);
    model.setData(index, "Five");

    QListWidget list2;
    list2.setWindowTitle("window 2");
    list2.setGeometry(700, 100, 500, 300);

    foreach(QString str, model.stringList())
        listItem = new QListWidgetItem(str, &list2);

    list1.show();
    list2.show();
    app.exec();
}
