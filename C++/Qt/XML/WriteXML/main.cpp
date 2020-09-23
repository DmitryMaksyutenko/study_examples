#include <QCoreApplication>
#include <QtXml>
#include <QFile>
#include <QTextStream>
#include <QDebug>

QDomElement createShelf(QDomDocument &xmlDoc,
                          const QString &elemName,
                          const QString &attr = QString(),
                          const QString &text = QString())
{
    QDomElement element = xmlDoc.createElement(elemName);
    if (!attr.isEmpty()) {
        QDomAttr attribure = xmlDoc.createAttribute("number");
        attribure.setValue(attr);
        element.setAttributeNode(attribure);
    }
    if (!text.isEmpty()) {
        QDomText domText = xmlDoc.createTextNode(text);
        element.appendChild(domText);
    }

    return element;
}

QDomElement desctibeShelf(QDomDocument &xmlDoc,
                        const QString &stafName,
                        const QString &stafSerialNum,
                        const int stafQuantity)
{
    static int number = 1;
    QDomElement element = createShelf(xmlDoc, "shelf", QString::number(number), "");

    element.appendChild(createShelf(xmlDoc, "name", "", stafName));
    element.appendChild(createShelf(xmlDoc, "serial_number", "", stafSerialNum));
    element.appendChild(createShelf(xmlDoc, "staf_quantity", "", QString::number(stafQuantity)));

    number++;
    return element;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFile file("../WriteXML/store.xml");
    QDomDocument xmlDoc("store");
    QTextStream intoFile(&file);

    QDomElement root = xmlDoc.createElement("area");
    xmlDoc.appendChild(root);

    QDomElement el1 = desctibeShelf(xmlDoc, "Car", "xx123", 3);
    root.appendChild(el1);

    QDomElement el2 = desctibeShelf(xmlDoc, "Military", "xx1232352", 5);
    root.appendChild(el2);

    QDomElement el3 = desctibeShelf(xmlDoc, "Bear", "xSax123", 3);
    root.appendChild(el3);

    QDomElement el4 = desctibeShelf(xmlDoc, "Lego", "AAxx123", 32);
    root.appendChild(el4);

    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "File opening failed!!!";
    } else {
        qDebug() << "File opening success!!!";
        intoFile << xmlDoc.toString();
        file.close();
    }

    return a.exec();
}
