#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QStack>
#include <QGridLayout>
#include <QPushButton>
#include <QRegExp>
#include <QLCDNumber> // Header file for QLCDNumber class


class MainWindow : public QWidget
{
    Q_OBJECT

private:
    QLCDNumber* m_plcd;	//	class displays numbers like LCD-digits. Inherits from QFrame
    QStack<QString> m_stk;
    QString m_strDisplay;

public:
    MainWindow();
    ~MainWindow();

    QPushButton* createButton(const QString& str);
    void calculate();

public slots:
    void slotButtonClicked();

};
#endif // MAINWINDOW_H
