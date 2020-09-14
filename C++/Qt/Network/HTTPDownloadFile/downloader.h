#ifndef DWNLOADER_H
#define DWNLOADER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QByteArray>

class Dwnloader : public QObject
{
    Q_OBJECT

private:
    QNetworkAccessManager *mp_netManager;

public:
    Dwnloader(QObject *obj = nullptr);

    void download(const QUrl &url);

signals:
    void downloadProgress(qint64, qint64);
    void done(const QUrl &, const QByteArray &);
    void error();

private slots:
    void slotFinished(QNetworkReply *reply);
};

#endif // DWNLOADER_H
