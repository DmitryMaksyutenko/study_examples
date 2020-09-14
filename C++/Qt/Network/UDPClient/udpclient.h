#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QTextEdit>
#include <QUdpSocket>
#include <QDataStream>
#include <QByteArray>
#include <QDateTime>

class UdpClient : public QTextEdit
{
    Q_OBJECT

private:
    QUdpSocket *mp_sock;

public:
    UdpClient(QWidget *parent = nullptr);
    ~UdpClient();

private slots:
    void slotProcessDatagramm();
};
#endif // UDPCLIENT_H
