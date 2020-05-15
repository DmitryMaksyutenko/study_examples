#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets>
#include <QSettings>

class QComboBox;
class QCheckBox;
class QTextEdit;
class QLabel;

class Widget : public QWidget {
    Q_OBJECT

  private:
    QSettings mSettings;
    QComboBox *mpCbox;
    QCheckBox *mpChck;
    QTextEdit *mpTxt;
    QLabel *mpLbl;
    int mAppStartCounter;

  public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void writeSetings();
    void readSettings();

  public slots:
    void slotCheckBoxClicked();
    void slotComboBoxActivated(int);
};
#endif // WIDGET_H
