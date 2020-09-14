#ifndef UDPSERVER_H
#define UDPSERVER_H

#include <QTextEdit>
#include <QUdpSocket>
#include <QTimer>
#include <QByteArray>
#include <QDataStream>
#include <QDateTime>


class UdpServer : public QTextEdit
{
    Q_OBJECT

private:
    QUdpSocket *mp_sock;
    QTimer *mp_timer;
    QDateTime m_date;

public:
    UdpServer(QWidget *parent = nullptr);
    ~UdpServer();

private slots:
    void slotSendDatagramm();

};
#endif // UDPSERVER_H
