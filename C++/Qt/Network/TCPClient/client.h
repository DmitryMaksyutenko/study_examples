#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include <QTcpSocket>
#include <QTextEdit>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

namespace cli
{

class Client : public QWidget
{
    Q_OBJECT

private:
    QTcpSocket m_client;
    QTextEdit m_textArea;
    QLineEdit m_msg;
    QLabel m_lbl;
    QPushButton m_buttonSend;
    qint16 m_nextBlockSize;

public:
    Client(const QString &host, int port, QWidget *parent = 0);
    ~Client();

private slots:
    void slotReadyRead();
    void slotError(QAbstractSocket::SocketError);
    void slotSendToServer();
    void slotConnected();
};

}

#endif // CLIENT_H
