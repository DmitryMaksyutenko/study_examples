#include <QCoreApplication>
#include <QtXml>
#include <QDir>
#include <QFile>
#include <QTextStream>

void traverseNode(const QDomNode &node)
{
    QDomNode root = node.firstChild();
    while (!root.isNull()) {
        if (root.isElement()) {
            QDomElement element = root.toElement();
            if (!element.isNull()) {
                if (element.tagName() != "person") {
                    QTextStream out(stdout);
                    out << element.tagName() << ": " << element.text() << "\n";
                    out.flush();
                }

            }
        }
        traverseNode(root);
        root = root.nextSibling();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFile file("../ReadXML/person.xml");
    QDomDocument xmlDoc;
    QTextStream out(stdout);

    if (file.open(QIODevice::ReadOnly)) {
        out << "File is opend!\n";
        out.flush();
        xmlDoc.setContent(&file);
        traverseNode(xmlDoc.documentElement());
        file.close();
        out << "File is closed!\n";
        out.flush();

    } else {
        out << "File doesn't opend!\n";
        out.flush();
    }


    return a.exec();
}
