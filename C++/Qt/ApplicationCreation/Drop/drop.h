#ifndef DROP_H
#define DROP_H

#include <QtWidgets>
#include <QDropEvent>
#include <QDragEnterEvent>

class Drop : public QLabel
{
    Q_OBJECT

  public:
    Drop(QWidget *parent = nullptr);
    ~Drop();

  protected:
    void dropEvent(QDropEvent *e) override;
    void dragEnterEvent(QDragEnterEvent *e) override;
};
#endif // DROP_H
