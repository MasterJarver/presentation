#include "compositeitem.h"

CompositeItem::CompositeItem(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QVariant CompositeItem::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex CompositeItem::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex CompositeItem::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int CompositeItem::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int CompositeItem::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant CompositeItem::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
