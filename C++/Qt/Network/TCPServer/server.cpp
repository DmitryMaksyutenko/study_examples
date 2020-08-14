#include <QMessageBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QTime>

#include "server.h"


void srv::Server::sendToClient(QTcpSocket *soc, const QString &str)
{
    QByteArray blockToSend;
    QDataStream out(&blockToSend, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_5);
    out << qint16(0) << QTime::currentTime() << str;
    out.device()->seek(0);
    out << qint16(blockToSend.size() - sizeof(qint16));

    soc->write(blockToSend);
}

srv::Server::Server(int port, QWidget *parent)
    : QWidget(parent)
{
    mp_serverTcp = new QTcpServer(this);

    if (!mp_serverTcp->listen(QHostAddress::Any, port)) {
        QMessageBox::critical(0, "Server Error", mp_serverTcp->errorString());
        mp_serverTcp->close();
        return;
    }

    connect(mp_serverTcp, SIGNAL(newConnection()), this, SLOT(slotNewConnection()));

    m_textArea.setReadOnly(true);

    QVBoxLayout *vbl = new QVBoxLayout(this);
    vbl->addWidget(new QLabel("<H1>Server</H1>", this));
    vbl->addWidget(&m_textArea);
    setLayout(vbl);
}

srv::Server::~Server()
{

}

void srv::Server::slotNewConnection()
{
    QTcpSocket *client = mp_serverTcp->nextPendingConnection();

    connect(client, SIGNAL(disconnect()), client, SLOT(deleteLater()));
    connect(client, SIGNAL(readyRead()), this, SLOT(slotReadClient()));

    sendToClient(client, "Server response: Connected!");
}

void srv::Server::slotReadClient()
{
    QTcpSocket *client = (QTcpSocket*)sender();
    QDataStream in(client);

    in.setVersion(QDataStream::Qt_5_5);
    while(true) {
        if(!m_nextBlockSize) {
            if (client->bytesAvailable() < sizeof(qint16)) {
                break;
            }
            in >> m_nextBlockSize;
        }
        if (client->bytesAvailable() < m_nextBlockSize) {
            break;
        }
        QTime time;
        QString str;
        in >> time >> str;
        QString message = time.toString() + " " + str;
        m_textArea.append(message);
        m_nextBlockSize = 0;
        sendToClient(client, "Server received: " + str);
    }
}
