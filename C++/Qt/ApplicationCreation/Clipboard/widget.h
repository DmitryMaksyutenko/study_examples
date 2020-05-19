#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTextEdit>

class Widget : public QWidget
{
    Q_OBJECT

  private:
    QTextEdit mTextArea;

  public:
    Widget(QWidget *parent = nullptr);
    ~Widget();


  public slots:
    void slotAddedToClipBoard();
};
#endif // WIDGET_H
