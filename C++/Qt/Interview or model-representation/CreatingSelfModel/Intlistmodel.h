#ifndef INTLISTMODEL_H
#define INTLISTMODEL_H

#include <QAbstractListModel>
#include <QList>

class IntListModel : public QAbstractListModel
{
    Q_OBJECT

private:
    QList<int> mList;

public:
    IntListModel(QList<int> &list, QObject *pObj = nullptr);

    //	Overridden pure virtual methods of QAbstractListModel.
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    int rowCount(const QModelIndex &index = QModelIndex()) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
};

#endif // INTLISTMODEL_H
