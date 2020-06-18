#ifndef DOCWINDOW_H
#define DOCWINDOW_H

#include <QTextEdit>

class DocWindow : public QTextEdit
{
    Q_OBJECT

    QString m_strFileName;

  public:
    DocWindow(QWidget *parent = nullptr);
    ~DocWindow();

  signals:
    void changeWindowTitle(const QString &str);

  public slots:
    void slotLoad();
    void slotSave();
    void slotSaveAs();
};
#endif // DOCWINDOW_H
