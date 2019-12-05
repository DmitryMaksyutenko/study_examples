#include <QtWidgets>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QComboBox dropList;
    QStringList names;

    names << "John" << "Paul" << "George" << "Ringo";

    dropList.addItems(names);
    dropList.setEditable(true);
\
    dropList.show();
    return app.exec();
}
