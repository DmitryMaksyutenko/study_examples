#include <QtWidgets>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QStringList systems;
    systems << "Linux" << "Windows" << "MacOSX" << "Android";

    QStandardItemModel model(systems.size(), 1);

    for(int i = 0; i < model.rowCount(); i++)
    {
        QModelIndex index = model.index(i, 0);
        QString osName = systems.at(i);

        model.setData(index, osName, Qt::DisplayRole);
        model.setData(index, "Tip for " + osName, Qt::ToolTipRole);
        model.setData(index, QIcon("/home/dima/Pictures/" + osName + ".png"), Qt::DecorationRole);
    }

    QListView view;
    view.setViewMode(QListView::IconMode);
    view.setModel(&model);
    view.show();

    return app.exec();
}
