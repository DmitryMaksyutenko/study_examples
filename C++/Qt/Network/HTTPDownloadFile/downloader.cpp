#include "downloader.h"

Dwnloader::Dwnloader(QObject *obj)
    : QObject(obj)
{
    mp_netManager = new QNetworkAccessManager(this);

    connect(mp_netManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(slotFinished(QNetworkReply*)));
}

void Dwnloader::download(const QUrl &url)
{
    QNetworkRequest request(url);
    QNetworkReply *response = mp_netManager->get(request);

    connect(response, SIGNAL(downloadProgress(qint64, qint64)),
            this, SIGNAL(downloadProgress(qint64, qint64)));
}

void Dwnloader::slotFinished(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError) {
        emit error();
    } else {
        emit done(reply->url(), reply->readAll());
    }

    reply->deleteLater();
}
