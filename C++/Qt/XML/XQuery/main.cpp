#include <QCoreApplication>
#include <QtXmlPatterns>
#include <QDebug>
#include <QFile>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    if (argc < 3) {
        qDebug() << "usage: XQuery any.xml any.xq";
        return 0;
    }

    QString strQuery = "";
    QFile xqFile(argv[2]);
    if (xqFile.open(QIODevice::ReadOnly)) {
        strQuery = xqFile.readAll();
        xqFile.close();
    } else {
        qDebug() << "File opening error.";
        return 0;
    }

    QFile xmlFile(argv[1]);
    if (xmlFile.open(QIODevice::ReadOnly)) {
        QXmlQuery query;
        query.bindVariable("document", &xmlFile);
        query.setQuery(strQuery);
        if (!query.isValid()) {
            qDebug() << "The query is invalid.";
            return 0;
        }

        QString output;
        if (!query.evaluateTo(&output)) {
            qDebug() << "Can't evaluate the string.";
            return 0;
        }

        xmlFile.close();
        qDebug() << output;
    }


    return a.exec();
}
