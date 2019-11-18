#ifndef BUTTONS_H
#define BUTTONS_H

#include <QGroupBox>
#include <QtWidgets>

class Buttons : public QGroupBox
{
    Q_OBJECT

private:
    QCheckBox *m_pcheck;
    QRadioButton *m_rbRed;
    QRadioButton *m_rbGreen;
    QRadioButton *m_rbBlue;


public:
    Buttons(QWidget *parent = nullptr);
    ~Buttons();

public slots:
    void slotButtonClicked();
};
#endif // BUTTONS_H
