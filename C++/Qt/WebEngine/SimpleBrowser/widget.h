#ifndef WIDGET_H
#define WIDGET_H

#include <QtWebEngineWidgets>

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QProgressBar>

class Widget : public QWidget
{
    Q_OBJECT

private:
    QLineEdit mTxt;
    QProgressBar *mProgrBar;
    QWebEngineView *mWview;
    QPushButton mBack;
    QPushButton mForvard;
    QPushButton mGo;
    QPushButton mStop;
    QPushButton mRefresh;

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    void connections();
    void setupLayout();

private slots:
    void slotGo();
    void slotFinished(bool state);
};
#endif // WIDGET_H
