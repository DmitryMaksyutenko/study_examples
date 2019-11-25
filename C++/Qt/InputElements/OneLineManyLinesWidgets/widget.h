#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QVBoxLayout>

class Widget : public QWidget
{
    Q_OBJECT

private:
    QLineEdit *login;
    QLineEdit *password;
    QTextEdit *information;

public:
    Widget(QLineEdit *log, QLineEdit *pass, QTextEdit *info, QWidget *parent = nullptr);
    ~Widget();

};
#endif // WIDGET_H
