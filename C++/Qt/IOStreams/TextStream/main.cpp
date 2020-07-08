#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QTextStream>

int main()
{
    QFile file(QDir::homePath() + "/.zshrc");
    QTextStream tStream;

    if (!file.exists()) {
        qDebug() << "file doesn't exists.";
        QCoreApplication::exit();
    } else {
        if (file.open(QIODevice::ReadOnly)) {
            tStream.setDevice(&file);
            while (!tStream.atEnd()) {
               qDebug() << tStream.readLine();
            }
            file.close();
        } else {
            qDebug() << "file don't opened.";
        }
    }

    QString forWrite = "String for write.";
    QFile newFile("testFile.txt");

    if (!newFile.open(QIODevice::ReadWrite)) {
        qDebug() << "file don't opened.";
        QCoreApplication::exit();
    } else {
        tStream.setDevice(&newFile);
        tStream << forWrite;
        qDebug() << tStream.readAll();
        newFile.close();
    }

    return 0;
}
