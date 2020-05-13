#include "video.h"

#include <QtWidgets>
#include <QVideoWidget>

Video::Video(QWidget *pObj) : Widget(pObj) {
    QVideoWidget *pVideoWidget = new QVideoWidget(this);
    pVideoWidget->setMaximumSize(300, 300);
    pVBLayout->addWidget(pVideoWidget);
    pMediaPlayer->setVideoOutput(pVideoWidget);
}
