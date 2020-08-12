#include <QCoreApplication>
#include <QtConcurrent/QtConcurrent>
#include <QFuture>
#include <QDebug>

QString toUpper(const QString &str)
{
    return str.toUpper();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString str1 = "lower case text to upper case";
    QStringList list;
    list << "one" << "two" << "three" << "four" << "five";

    QFuture<QString> future1 = QtConcurrent::run(toUpper, str1);
    QFuture<QString> future2 = QtConcurrent::mapped(list, toUpper);
    future1.waitForFinished();
    future2.waitForFinished();

    qDebug() << future1;
    qDebug() << future2.results();

    return a.exec();
}
