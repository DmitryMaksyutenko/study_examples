#ifndef READXML_H
#define READXML_H

#include <QObject>
#include <QXmlStreamReader>
#include <QTreeWidgetItem>
#include <QFile>
#include <QFileInfo>

class ReadXml : public QObject
{
    Q_OBJECT
public:
    ReadXml(QObject *obj = nullptr);
    ~ReadXml() {};

public slots:
    void readFile(const QModelIndex &);
    void slotShowClicked();

signals:
    void sendData(const QStringList &);

private:
    QXmlStreamReader m_reader;
    QFile m_file;
    QStringList m_strings;
};

#endif // READXML_H
