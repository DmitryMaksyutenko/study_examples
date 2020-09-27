#include "readxml.h"

#include <QDebug>

ReadXml::ReadXml(QObject *obj)
    :QObject(obj)
{

}

void ReadXml::readFile(const QModelIndex &index)
{
    QString file = index.data().toString();
    QModelIndex tmpIndex = index.parent();

    while (tmpIndex.data().toString() != "/") {
        file =  tmpIndex.data().toString() + "/" + file;
        tmpIndex = tmpIndex.parent();
    }
    m_file.setFileName("/" + file);
    if (m_file.open(QIODevice::ReadOnly)) {
        m_reader.setDevice(&m_file);
        do {
            m_reader.readNext();
            m_strings.append(m_reader.name() + ": " + m_reader.text());
        } while (!m_reader.atEnd());
        m_file.close();
    }
}

void ReadXml::slotShowClicked()
{
    emit sendData(m_strings);
}
