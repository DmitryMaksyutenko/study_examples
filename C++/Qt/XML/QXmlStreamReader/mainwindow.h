#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QTreeWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setFileSystemModel(QFileSystemModel *fsm);

signals:
    void fileSelected(const QModelIndex&);
    void showClicked();

private slots:
    void slotFileSelected(const QModelIndex&);

public slots:
    void slotReceiveData(const QStringList&);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
