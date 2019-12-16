#include <QtWidgets>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QSplitter splitWindow;
    QFileSystemModel model;
    model.setRootPath(QDir::rootPath());

    QTreeView fileTree;
    fileTree.setModel(&model);

    QTableView filesTable;
    filesTable.setModel(&model);

    QObject::connect(&fileTree, SIGNAL(clicked(const QModelIndex&)),
                     &filesTable, SLOT(setRootIndex(const QModelIndex&)));

    QObject::connect(&filesTable, SIGNAL(activated(const QModelIndex&)),
                     &fileTree, SLOT(setCurrentIndex(const QModelIndex&)));

    QObject::connect(&fileTree, SIGNAL(activated(const QModelIndex&)),
                     &filesTable, SLOT(setRootIndex(const QModelIndex&)));

    splitWindow.addWidget(&fileTree);
    splitWindow.addWidget(&filesTable);
    splitWindow.show();

    return app.exec();
}
