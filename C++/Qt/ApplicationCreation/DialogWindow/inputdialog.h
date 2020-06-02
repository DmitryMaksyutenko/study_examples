#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>
#include <QLineEdit>

class InputDialog : public QDialog
{
    Q_OBJECT

  private:
    QLineEdit mFirstName;
    QLineEdit mLastName;

  public:
    InputDialog(QWidget *obj = nullptr);

    QString firstName() const;
    QString lastName() const;
};

#endif // INPUTDIALOG_H
