#include "mainwindow.h"

#include <QVBoxLayout>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    main_rect = new	QQuickWidget(QUrl("qrc:/Qml/Rect.qml"), this);
    QVBoxLayout *vbl = new QVBoxLayout(this);
    vbl->addWidget(main_rect);
    setLayout(vbl);
}

MainWindow::~MainWindow()
{
}

