#ifndef SIMPLEDELEGATE_H
#define SIMPLEDELEGATE_H

#include <QtWidgets>

class SimpleDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    SimpleDelegate(QObject *parent = nullptr);
    virtual ~SimpleDelegate();

    void paint(QPainter * painter,
               const QStyleOptionViewItem &option,
               const QModelIndex & index) const;

    QSize sizeHint(const QStyleOptionViewItem &option,
                   const QModelIndex &) const;

};
#endif // SIMPLEDELEGATE_H
