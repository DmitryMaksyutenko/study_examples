#include "widget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    mWview = new QWebEngineView(this);
    mProgrBar = new QProgressBar(this);

    mWview->resize(500, 500);

    mTxt.setText("https://google.com");
    mBack.setText("<");
    mForvard.setText(">");
    mGo.setText("&Go");
    mStop.setText("&Stop");
    mRefresh.setText("&Refresh");

    mBack.setEnabled(false);
    mForvard.setEnabled(false);

    connections();

    setupLayout();

    slotGo();
}

Widget::~Widget()
{
}

void Widget::connections()
{
    connect(&mGo, SIGNAL(clicked()), this, SLOT(slotGo()));
    connect(&mTxt, SIGNAL(returnPressed()), this, SLOT(slotGo()));
    connect(&mBack, SIGNAL(clicked()), mWview, SLOT(back()));
    connect(&mForvard, SIGNAL(clicked()), mWview, SLOT(forward()));
    connect(&mRefresh, SIGNAL(clicked()), mWview, SLOT(reload()));
    connect(&mStop, SIGNAL(clicked()), mWview, SLOT(stop()));
    connect(mWview, SIGNAL(loadProgress(int)), mProgrBar, SLOT(setValue(int)));
    connect(mWview, SIGNAL(loadFinished(bool)), this, SLOT(slotFinished(bool)));
}

void Widget::setupLayout()
{
    QHBoxLayout *hbl = new QHBoxLayout(this);
    hbl->addWidget(&mBack);
    hbl->addWidget(&mForvard);
    hbl->addWidget(&mStop);
    hbl->addWidget(&mRefresh);
    hbl->addWidget(&mTxt);
    hbl->addWidget(&mGo);

    QVBoxLayout *vbl = new QVBoxLayout(this);
    vbl->addLayout(hbl);
    vbl->addWidget(mWview);
    vbl->addWidget(mProgrBar);

    setLayout(vbl);
}

void Widget::slotGo()
{
//    if (!mTxt.text().startsWith("ftp://") &&
//        !mTxt.text().startsWith("http://") &&
//        !mTxt.text().startsWith("gopher://")) {
//        mTxt.setText("https://" + mTxt.text());
//    }
    mWview->load(QUrl(mTxt.text()));
}

void Widget::slotFinished(bool state)
{
    if (!state) {
        mWview->setHtml("<CENTER>An Error has occured</CENTER>");
    }
    mTxt.setText(mWview->url().toString());
    mBack.setEnabled(mWview->page()->history()->canGoBack());
    mForvard.setEnabled(mWview->page()->history()->canGoForward());
}

