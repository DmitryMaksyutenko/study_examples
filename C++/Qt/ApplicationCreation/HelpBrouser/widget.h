#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QTextBrowser>
#include <QVBoxLayout>
#include <QHBoxLayout>

class Widget : public QWidget
{
    Q_OBJECT

  public:
    Widget(const QString &path,
           const QString &fileName,
           QWidget *parent = nullptr);
    ~Widget();
};
#endif // WIDGET_H
