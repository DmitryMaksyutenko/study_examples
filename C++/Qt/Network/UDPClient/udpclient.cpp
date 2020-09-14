#include "udpclient.h"

UdpClient::UdpClient(QWidget *parent)
    : QTextEdit(parent)
{
    setWindowTitle("Client");

    mp_sock = new QUdpSocket(this);
    mp_sock->bind(2424);

    connect(mp_sock, SIGNAL(readyRead()), this, SLOT(slotProcessDatagramm()));
}

UdpClient::~UdpClient()
{
}

void UdpClient::slotProcessDatagramm()
{
    QByteArray data;

    do {
        data.resize(mp_sock->pendingDatagramSize());
        mp_sock->readDatagram(data.data(), data.size());
    } while(mp_sock->hasPendingDatagrams());

    QDataStream in(&data, QIODevice::ReadOnly);
    in.setVersion(QDataStream::Qt_5_9);

    QDateTime date;
    in >> date;

    append("Received :" + date.toString());
}
