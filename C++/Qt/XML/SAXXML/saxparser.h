#ifndef SAXPARSER_H
#define SAXPARSER_H

#include <QXmlDefaultHandler>
#include <QXmlParseException>
#include <QDebug>


class SAXParser : public QXmlDefaultHandler
{
public:
    SAXParser();

    bool startElement(const QString & namespaceURI,
                      const QString & localName,
                      const QString & qName,
                      const QXmlAttributes & atts) override;
    bool characters(const QString &text) override;
    bool endElement(const QString & namespaceURI,
                    const QString & localName,
                    const QString & qName) override;
    bool fatalError(const QXmlParseException & exception) override;

private:
    QString m_text;

};

#endif // SAXPARSER_H
