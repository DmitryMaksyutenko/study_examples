#include <QtWidgets>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    const int n = 3;
    QTableWidget table(n, n);
    QTableWidgetItem *tItem = nullptr;

    QStringList names;
    names << "First" << "Second" << "Third";

    table.setHorizontalHeaderLabels(names);
    table.setVerticalHeaderLabels(names);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; ++j)
        {
            tItem = new QTableWidgetItem(QString("%1,%2").arg(i).arg(j));
            table.setItem(i, j, tItem);
        }
    }

    table.resize(370, 135);
    table.show();
    return app.exec();
}
