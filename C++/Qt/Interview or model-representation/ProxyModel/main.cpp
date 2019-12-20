#include <QtWidgets>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QWidget widg;

    QStringListModel listModel;
    listModel.setStringList(QStringList() << "Anna"
                            << "Dima" << "Sam" << "Antonio");

    QSortFilterProxyModel proxyModel;
    proxyModel.setSourceModel(&listModel);
    proxyModel.setFilterWildcard("A*");

    QListView v1, v2;
    v1.setModel(&listModel);
    v2.setModel(&proxyModel);

    QHBoxLayout layout;
    layout.addWidget(&v1);
    layout.addWidget(&v2);

    widg.setLayout(&layout);

    widg.show();
    return app.exec();
}
