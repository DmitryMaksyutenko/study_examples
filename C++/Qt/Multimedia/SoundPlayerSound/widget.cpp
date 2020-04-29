#include "widget.h"

#include <QPushButton>
#include <QSlider>
#include <QLabel>
#include <QVBoxLayout>
#include <QDial>
#include <QStyle>
#include <QFileDialog>
#include <QTime>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *pOpen = new QPushButton("&Open");
    QDial *pVolume = new QDial;

    pPlayButton = new QPushButton("&Play");
    pStopButton = new QPushButton("&Stop");
    pTrackPosition = new QSlider;
    pCurrent = new QLabel(msecToString(0));
    pRemain = new QLabel(msecToString(0));
    pMediaPlayer = new QMediaPlayer;

    pPlayButton->setEnabled(false);
    pPlayButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));

    pStopButton->setEnabled(false);
    pStopButton->setIcon(style()->standardIcon(QStyle::SP_MediaStop));

    pTrackPosition->setRange(0, 100);
    pTrackPosition->setOrientation(Qt::Horizontal);

    pVolume->setRange(0, 100);
    int defaltValume = 40;
    pMediaPlayer->setVolume(defaltValume);
    pVolume->setValue(defaltValume);

    connect(pOpen, SIGNAL(clicked()), SLOT(slotOpen()));
    connect(pPlayButton, SIGNAL(clicked()), SLOT(slotPlay()));
    connect(pStopButton, SIGNAL(clicked()), pMediaPlayer, SLOT(stop()));
    connect(pVolume, SIGNAL(valueChanged(int)), pMediaPlayer, SLOT(setVolume(int)));
    connect(pTrackPosition, SIGNAL(sliderMoved(int)),
            SLOT(slotSetMediaPosition(int)));
    connect(pMediaPlayer, SIGNAL(positionChanged(qint64)),
            SLOT(slotSetSliderPosition(qint64)));
    connect(pMediaPlayer, SIGNAL(durationChanged(qint64)),
            SLOT(slotSetDuration(qint64)));
    connect(pMediaPlayer, SIGNAL(stateChanged(QMediaPlayer::State)),
            SLOT(slotStatusChanged(QMediaPlayer::State)));

    QHBoxLayout *pPlayControlsLayout = new QHBoxLayout;
    pPlayControlsLayout->addWidget(pOpen);
    pPlayControlsLayout->addWidget(pPlayButton);
    pPlayControlsLayout->addWidget(pStopButton);
    pPlayControlsLayout->addWidget(pVolume);

    QHBoxLayout *pTimeControlsLayout = new QHBoxLayout;
    pTimeControlsLayout->addWidget(pCurrent);
    pTimeControlsLayout->addWidget(pTrackPosition);
    pPlayControlsLayout->addWidget(pRemain);

    pVBLayout = new QVBoxLayout;
    pVBLayout->addLayout(pPlayControlsLayout);
    pVBLayout->addLayout(pTimeControlsLayout);

    setLayout(pVBLayout);
}

Widget::~Widget()
{
}

QString Widget::msecToString(qint64 msec)
{
    int hours = (msec / (60 * 60 * 1000));
    int minutes = ((msec % (60 * 60 * 100)) / (60 * 1000));
    int seconds = ((msec % (60 * 100)) / 1000);

    return QTime(hours, minutes, seconds).toString("hh:mm:ss");
}

void Widget::slotOpen()
{
    QString file = QFileDialog::getOpenFileName(this, "Open File");

    if(!file.isEmpty())
    {
        pMediaPlayer->setMedia(QUrl::fromLocalFile(file));
        pPlayButton->setEnabled(true);
        pStopButton->setEnabled(true);
    }
}

void Widget::slotPlay()
{
    switch (pMediaPlayer->state())
    {
        case QMediaPlayer::PlayingState:
            pMediaPlayer->pause();
        break;
        default:
            pMediaPlayer->play();
        break;
    }
}

void Widget::slotSetSliderPosition(qint64 pos)
{
    pTrackPosition->setValue(pos);

    pCurrent->setText(msecToString(pos));
    int duration = pTrackPosition->maximum();
    pRemain->setText(msecToString(duration - pos));
}

void Widget::slotSetMediaPosition(int position)
{
    pMediaPlayer->setPosition(position);
}

void Widget::slotSetDuration(qint64 pos)
{
    pTrackPosition->setRange(0, pos);
    pCurrent->setText(msecToString(0));
    pRemain->setText(msecToString(pos));
}

void Widget::slotStatusChanged(QMediaPlayer::State state)
{
    switch (state)
    {
        case QMediaPlayer::PlayingState:
            pPlayButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
        break;
        default:
            pPlayButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
        break;
    }
}

