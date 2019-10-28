#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QDebug>
#include <QMouseEvent>

class MainWindow : public QWidget
{
    Q_OBJECT

private:
    int cursor_counter;

public:
    MainWindow();
    ~MainWindow() override;

    void mousePressEvent(QMouseEvent *event) override;

    void mouse_cursor_change(const QPoint &p);
};
#endif // MAINWINDOW_H
