#include <QTime>

#include "client.h"

cli::Client::Client(const QString &host, int port, QWidget *parent)
    : QWidget(parent),
      m_nextBlockSize(0)
{
    m_client.connectToHost(host, port);

    connect(&m_client, SIGNAL(connected()), this, SLOT(slotConnected()));
    connect(&m_client, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));
    connect(&m_client, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(slotError(QAbstractSocket::SocketError)));

    m_lbl.setText("<H1>Client</H1>");
    m_textArea.setReadOnly(true);
    m_buttonSend.setText("&Send");

    connect(&m_buttonSend, SIGNAL(clicked()), this, SLOT(slotSendToServer()));
    connect(&m_msg, SIGNAL(returnPressed()), this, SLOT(slotSendToServer()));

    QVBoxLayout *vbl = new QVBoxLayout(this);
    vbl->addWidget(&m_lbl);
    vbl->addWidget(&m_textArea);
    vbl->addWidget(&m_msg);
    vbl->addWidget(&m_buttonSend);

    setLayout(vbl);
}

cli::Client::~Client()
{

}

void cli::Client::slotReadyRead()
{
     QDataStream in(&m_client);
     in.setVersion(QDataStream::Qt_5_5);

     while(true) {
        if(!m_nextBlockSize) {
            if (m_client.bytesAvailable() < sizeof(qint16)) {
                break;
            }
            in >> m_nextBlockSize;
        }

        if (m_client.bytesAvailable() < m_nextBlockSize) {
            break;
        }

        QTime time;
        QString str;
        in >> time >> str;

        m_textArea.append(time.toString() + " " + str);
        m_nextBlockSize = 0;
     }

}

void cli::Client::slotError(QAbstractSocket::SocketError err)
{
    QString errorStr = "Error: " + (err == QAbstractSocket::HostNotFoundError ?
                                        "The host was not found!" :
                                        err == QAbstractSocket::RemoteHostClosedError ?
                                            "The remote host is closed!" :
                                        err == QAbstractSocket::ConnectionRefusedError ?
                                                "The connection was refused!" :
                                                QString(m_client.errorString()));
    m_textArea.append(errorStr);
}

void cli::Client::slotSendToServer()
{
    QByteArray blockToSend;
    QDataStream out(&blockToSend, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_5);

    out << qint16(0) << QTime::currentTime() << m_msg.text();

    out.device()->seek(0);
    out << qint16(blockToSend.size() - sizeof(qint16));

    m_client.write(blockToSend);
    m_msg.setText("");
}

void cli::Client::slotConnected()
{
    m_textArea.append("Signal received!");
}
