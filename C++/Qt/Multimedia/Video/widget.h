#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMediaPlayer>

class QPushButton;
class QSlider;
class QLabel;
class QVBoxLayout;

class Widget : public QWidget
{
    Q_OBJECT

    QPushButton *pPlayButton;
    QPushButton *pStopButton;
    QSlider *pTrackPosition;
    QLabel *pCurrent;
    QLabel *pRemain;

protected:
    QMediaPlayer *pMediaPlayer;
    QVBoxLayout *pVBLayout;

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QString msecToString(qint64 msec);

private slots:
    void slotOpen();
    void slotPlay();
    void slotSetSliderPosition(qint64);
    void slotSetMediaPosition(int);
    void slotSetDuration(qint64);
    void slotStatusChanged(QMediaPlayer::State);

};
#endif // WIDGET_H
