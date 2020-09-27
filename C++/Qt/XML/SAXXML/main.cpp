#include <QCoreApplication>
#include <QXmlSimpleReader>
#include <QXmlInputSource>
#include <QFile>

#include "saxparser.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFile file("../SAXXML/users.xml");

    if (file.exists()) {
        QXmlSimpleReader reader;
        QXmlInputSource sourceFile(&file);
        SAXParser parser;

        reader.setContentHandler(&parser);
        reader.parse(sourceFile);
    } else {
        qDebug() << "File reading failed!\n";
    }

    return a.exec();
}
