#include "guidownloader.h"

GuiDownloader::GuiDownloader(QWidget *parent)
    : QWidget(parent)
{
    mp_loader = new Dwnloader(this);
    mp_prgrBar = new QProgressBar(this);
    mp_lEdit = new QLineEdit(this);
    mp_goButton = new QPushButton("Go", this);

    connect(mp_goButton, SIGNAL(clicked()), this, SLOT(slotGo()));
    connect(mp_loader, SIGNAL(downloadProgress(qint64, qint64)),
            this, SLOT(slotDownloadProcess(qint64, qint64)));
    connect(mp_loader, SIGNAL(done(const QUrl&, const QByteArray&)),
            this, SLOT(slotDone(const QUrl&, const QByteArray&)));

    QGridLayout *layout = new QGridLayout(this);
    layout->addWidget(mp_lEdit, 0, 0);
    layout->addWidget(mp_goButton, 0, 1);
    layout->addWidget(mp_prgrBar, 1, 0, 1, 1);
    setLayout(layout);
}

GuiDownloader::~GuiDownloader()
{
}

void GuiDownloader::showPic(const QString &str)
{
    QPixmap img(str);

    img.scaled(img.size() / 2, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QLabel *lbl = new QLabel(this);
    lbl->setPixmap(img);
    lbl->setFixedSize(img.size());
    lbl->show();
}

void GuiDownloader::slotGo()
{
    mp_loader->download(mp_lEdit->text());
}

void GuiDownloader::slotError()
{
    QMessageBox::critical(nullptr,
                          "Error",
                          "An error while file downloading!");
}

void GuiDownloader::slotDownloadProcess(qint64 received, qint64 total)
{
    if (total <= 0) {
        slotError();
        return;
    }
    mp_prgrBar->setValue(100 * received / total);
}

void GuiDownloader::slotDone(const QUrl &url, const QByteArray &arr)
{
    QString fileName = QStandardPaths::writableLocation(
                QStandardPaths::PicturesLocation) +
            "/" + url.path().section('/', -1);
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly)) {
        file.write(arr);
        file.close();

        if (fileName.endsWith(".jpg") || fileName.endsWith(".png")) {
            showPic(fileName);
        }
    }
}

