#include <QApplication>
#include <QItemSelectionModel>
#include <QStringListModel>
#include <QStringList>
#include <QWidget>
#include <QTreeView>
#include <QListView>
#include <QTableView>
#include <QHBoxLayout>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QWidget mainWindow;

    QStringListModel listModel(QStringList() << "One" << "Two" << "Three");

    QTreeView treeView;
    treeView.setModel(&listModel);

    QListView listView;
    listView.setModel(&listModel);

    QTableView tableView;
    tableView.setModel(&listModel);

    QItemSelectionModel selectionModel(&listModel);
    treeView.setSelectionModel(&selectionModel);
    listView.setSelectionModel(&selectionModel);
    tableView.setSelectionModel(&selectionModel);

    QHBoxLayout hBox;
    hBox.addWidget(&treeView);
    hBox.addWidget(&listView);
    hBox.addWidget(&tableView);
    mainWindow.setLayout(&hBox);

    mainWindow.show();
    app.exec();
}
