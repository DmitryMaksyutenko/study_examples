#include "mainwindow.h"

MainWindow::MainWindow() : cursor_counter(0)
{}

MainWindow::~MainWindow()
{}

void MainWindow::mouse_cursor_change(const QPoint &p)
{
    if ((p.x() > 0) && (p.y() > 0))
        this->setCursor(Qt::CursorShape(cursor_counter));

    if (cursor_counter > Qt::CursorShape::PointingHandCursor)
        cursor_counter = 0;

    cursor_counter++;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    mouse_cursor_change(event->pos());
}
