#include "saxparser.h"

SAXParser::SAXParser()
{

}

bool SAXParser::startElement(const QString &namespaceURI,
                             const QString &localName,
                             const QString &qName,
                             const QXmlAttributes &atts)
{
    int count = atts.count();
    for (int i = 0; i < count; i++) {
        if (atts.localName(i) == "number") {
            qDebug() << "Attr: " << atts.value(i) << "\n";
        }
    }

    return true;
}

bool SAXParser::characters(const QString &text)
{
    m_text = text;
    return true;
}

bool SAXParser::endElement(const QString &namespaceURI,
                           const QString &localName,
                           const QString &qName)
{
    if (qName != "person" && qName != "users") {
        qDebug() << "Tag: " << qName
                 << "Text: " << m_text << "\n";
    }

    return true;
}

bool SAXParser::fatalError(const QXmlParseException &exception)
{
    qWarning() << "Line: " << exception.lineNumber() << "\n"
               << "Column: " << exception.columnNumber() << "\n"
               << "Message: " << exception.message() << "\n";

    return false;
}
