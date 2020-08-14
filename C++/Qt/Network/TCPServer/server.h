#ifndef SERVER_H
#define SERVER_H


#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTextEdit>

namespace srv{

class Server : public QWidget
{
    Q_OBJECT

private:
    QTextEdit m_textArea;
    qint16 m_nextBlockSize;
    QTcpServer *mp_serverTcp;

    void sendToClient(QTcpSocket *soc, const QString &str);

public:
    Server(int port, QWidget *parent = 0);
    ~Server();

public slots:
    virtual void slotNewConnection();
    void slotReadClient();
};

}
#endif // SERVER_H
