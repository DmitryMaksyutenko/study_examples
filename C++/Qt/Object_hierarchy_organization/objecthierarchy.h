#ifndef OBJECTHIERARCHY_H
#define OBJECTHIERARCHY_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ObjectHierarchy; }
QT_END_NAMESPACE

class ObjectHierarchy : public QMainWindow
{
    Q_OBJECT

public:
    ObjectHierarchy(QWidget *parent = nullptr);
    ~ObjectHierarchy();

private:
    Ui::ObjectHierarchy *ui;
};
#endif // OBJECTHIERARCHY_H
