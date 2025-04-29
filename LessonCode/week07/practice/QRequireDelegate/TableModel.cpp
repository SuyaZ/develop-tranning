#include "TableModel.h"
#include "Require.h"
#include <QDebug>

TableModel::TableModel(QObject* parent)
    : QAbstractTableModel(parent)
{
}

TableModel::~TableModel()
{

}

void TableModel::setContent(QVector<Require*> require)
{
    m_require = require;
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
    {
        switch (section)
        {
        case 0:
            return QString("Require Name");
        case 1:
            return QString("Require Source");

        default:
            break;

        }
    }
    return QVariant();
}

int TableModel::rowCount(const QModelIndex& parent) const
{
    return parent.isValid() ? 0 : m_require.size();
}

int TableModel::columnCount(const QModelIndex& parent) const
{
    return parent.isValid() ? 0 : 2;
}

QVariant TableModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= m_require.size() || index.row() < 0)
        return QVariant();
    // 返回显示数据或者编辑数据
    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        const auto& rq = m_require.at(index.row());
        switch (index.column())
        {
        case 0:
            return rq->getName();
        case 1:
            return rq->getSource();
        
        default:
            break;
        }

    }
    return QVariant();
}

bool TableModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if (!index.isValid())
        return false;

    if (index.row() >= m_require.size() || index.row() < 0)
        return false;

    if (role == Qt::EditRole) // 设置编辑时的数据
    {
        const auto& rq = m_require.at(index.row());
        switch (index.column())
        {
        case 0:
            rq->setName(value.toString());
            break;
        case 1:
            rq->setSource(value.toString());
            break;
        
        default:
            break;
        }
    }

    return true;
}

Qt::ItemFlags TableModel::flags(const QModelIndex& index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;
    Qt::ItemFlags defaultFlags = QAbstractTableModel::flags(index);
    if (index.column() == 1)
        return defaultFlags | Qt::ItemIsEditable; // 对于第一列增加编辑标志
    else
        return defaultFlags;

}