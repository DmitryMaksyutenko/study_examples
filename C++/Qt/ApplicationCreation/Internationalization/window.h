#ifndef WINDOW_H
#define WINDOW_H

#include <QLabel>
#include <QPushButton>
#include <QTranslator>
#include <QEvent>

class Window : public QLabel
{
    Q_OBJECT

  private:
    QTranslator transl;
    QPushButton ru;
    QPushButton de;

  public:
    Window(QWidget *parent = nullptr);
    ~Window();

  protected:
    void changeEvent(QEvent *e) override;

  public slots:
    void slotButtonClicked();
};
#endif // WINDOW_H
