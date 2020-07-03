#include <QIODevice>
#include <QFile>
#include <QDir>
#include <QDebug>

int main()
{

    QFile file1(QDir::homePath() + "/.zshrc");
    QFile file2("file.txt");

    if (!file1.exists()) qDebug() << "file1 doesn't exists\n";
    if (!file2.exists()) {
        qDebug() << "file2 doesn't exists\n";
        file2.open(QIODevice::Append);
        if (!file2.exists())  qDebug() << "file2 doesn't exists\n";
        file2.close();
    } else {
        char a[1024];
        file1.open(QIODevice::ReadOnly);
        file2.open(QIODevice::Append);
        while (!file1.atEnd()) {
            int size = file1.read(a, sizeof(a));
            file2.write(a, size);
        }
        file1.close();
        file2.close();
    }

    return 0;
}
