#include "Intlistmodel.h"

IntListModel::IntListModel(QList<int> &list, QObject *pObj) : QAbstractListModel(pObj), mList(list)
{}

QVariant IntListModel::data(const QModelIndex &index, int role) const
{
    //	The QVariant class acts like a union for the most common Qt data types.
    //	QModelInex::isValid() - Returns true if this model index is valid; otherwise returns false.
    //	A valid index belongs to a model, and has non-negative row and column numbers.
    //	QModelIndex::row() - Returns the row this model index refers to.
    if(!index.isValid())
        return QVariant();
    if(index.row() < 0 || index.row() >= mList.size())
        return QVariant();

    return (role == Qt::DisplayRole || role == Qt::EditRole) ? mList.at(index.row()) : QVariant();
}

bool IntListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.isValid() && role == Qt::EditRole)
    {
        //	QVariant::value<T>() - Returns the stored value converted to the template type T.
        mList.replace(index.row(), value.value<int>());
        emit dataChanged(index, index);
        return true;
    }

    return false;
}

int IntListModel::rowCount(const QModelIndex &index) const
{
    if(index.isValid())
        return 0;

    return mList.size();
}

QVariant IntListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole)
        return QVariant();

    return (orientation == Qt::Horizontal) ? QString("Number") : QString::number(section);
}

Qt::ItemFlags IntListModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags flags = QAbstractItemModel::flags(index);

    return index.isValid() ? (flags | Qt::ItemIsEditable) : flags;
}

bool IntListModel::insertRows(int row, int count, const QModelIndex &parent)
{
    if(parent.isValid())
        return false;

    //	Must call this function before inserting data into the model's.
    beginInsertRows(QModelIndex(), row, row + count - 1);

    for(int i = 0; i < count; i++)
        mList.insert(row, 0);

    //	Must call this function after inserting data into the model's.
    endInsertRows();

    return true;
}

bool IntListModel::removeRows(int row, int count, const QModelIndex &parent)
{
    if(parent.isValid())
        return false;

    //	Must call this function before delete data from the model's.
    beginRemoveRows(QModelIndex(), row, row + count - 1);

    for(int i = 0; i < count; i++)
        mList.insert(row, 0);

    //	 Must call this function before delete data from the model's.
    endRemoveRows();

    return true;
}
