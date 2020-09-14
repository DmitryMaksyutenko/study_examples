#include "udpserver.h"

UdpServer::UdpServer(QWidget *parent)
    : QTextEdit(parent)
{
    setWindowTitle("Server");

    mp_sock = new QUdpSocket(this);
    mp_timer = new QTimer(this);

    mp_timer->setInterval(500);
    mp_timer->start();

    connect(mp_timer, SIGNAL(timeout()), this, SLOT(slotSendDatagramm()));
}

UdpServer::~UdpServer()
{
}

void UdpServer::slotSendDatagramm()
{
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_9);

    m_date = QDateTime::currentDateTime();
    out << m_date;
    append("Sent: " + m_date.toString());

    mp_sock->writeDatagram(data, QHostAddress::LocalHost, 2424);
}

