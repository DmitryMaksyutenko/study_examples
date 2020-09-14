#ifndef GUIDOWNLOADER_H
#define GUIDOWNLOADER_H

#include <QWidget>
#include <QUrl>
#include <QProgressBar>
#include <QMessageBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QStandardPaths>
#include <QFile>

#include "downloader.h"

class GuiDownloader : public QWidget
{
    Q_OBJECT

private:
    Dwnloader *mp_loader;
    QProgressBar *mp_prgrBar;
    QLineEdit *mp_lEdit;
    QPushButton *mp_goButton;

public:
    GuiDownloader(QWidget *parent = nullptr);
    ~GuiDownloader();

private:
    void showPic(const QString &str);

private slots:
    void slotGo();
    void slotError();
    void slotDownloadProcess(qint64, qint64);
    void slotDone(const QUrl&, const QByteArray&);
};
#endif // GUIDOWNLOADER_H
