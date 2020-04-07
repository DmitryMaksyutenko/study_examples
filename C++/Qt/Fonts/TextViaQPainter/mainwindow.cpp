#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setGeometry(700, 300, 400, 700);
}

MainWindow::~MainWindow()
{
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.setFont(QFont("Ubuntu", 20, QFont::Normal));
    painter.drawText(10, 40, "Text 1");

    painter.setFont(QFont("Ubuntu Mono", 20, QFont::Normal));
    painter.drawText(QRect(0, 50, 100, 100), Qt::TextFlag::TextWordWrap, "Text for second output");

    QLinearGradient gradient(0, 0, 500, 0);
    gradient.setColorAt(0, Qt::red);
    gradient.setColorAt(0.5, Qt::yellow);
    gradient.setColorAt(1, Qt::blue);

    painter.setPen(QPen(gradient, 0));
    painter.setFont(QFont("Ubuntu", 20, QFont::Normal));
    painter.drawText(110, 150, "Text for gradient");

    event->accept();
}
