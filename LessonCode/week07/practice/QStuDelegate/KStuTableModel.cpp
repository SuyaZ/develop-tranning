#include "KStuTableModel.h"
#include "Kxstudent.h"
#include <QDebug>

KStuTableModel::KStuTableModel(QObject* parent)
    : QAbstractTableModel(parent)
{
}

KStuTableModel::~KStuTableModel()
{

}

void KStuTableModel::setContent(QVector<KStudent*> students)
{
    m_contents = students;
}

QVariant KStuTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
    {
        switch (section)
        {
        case 0:
            return QString("Name");
        case 1:
            return QString("Gender");
        case 2:
            return QString("Age");
        case 3:
            return QString("Score");
        default:
            break;

        }
    }
    return QVariant();
}

int KStuTableModel::rowCount(const QModelIndex& parent) const
{

    return parent.isValid() ? 0 : m_contents.size();
}
int KStuTableModel::columnCount(const QModelIndex& parent) const
{
    return parent.isValid() ? 0 : 4;
}

QVariant KStuTableModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= m_contents.size() || index.row() < 0)
        return QVariant();
    // 返回显示数据或者编辑数据
    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        const auto& student = m_contents.at(index.row());
        switch (index.column())
        {
        case 0:
            return student->getName();
        case 1:
            return student->getGender();
        case 2:
            return student->getAge();
        case 3:
            return student->getScore();
        default:
            break;
        }

    }
    return QVariant();
}

bool KStuTableModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if (!index.isValid())
        return false;

    if (index.row() >= m_contents.size() || index.row() < 0)
        return false;

    if (role == Qt::EditRole) // 设置编辑时的数据
    {
        const auto& student = m_contents.at(index.row());
        switch (index.column())
        {
        case 0:
            student->setName(value.toString());
            break;
        case 1:
            student->setGender(value.toString());
            break;
        case 2:
            student->setAge(value.toInt());
            break;
        case 3:
            student->setScore(value.toInt());
            break;
        default:
            break;
        }
    }

    return true;
}

Qt::ItemFlags KStuTableModel::flags(const QModelIndex& index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;
    Qt::ItemFlags defaultFlags = QAbstractTableModel::flags(index);
    if (index.column() == 1)
        return defaultFlags | Qt::ItemIsEditable; // 对于第一列增加编辑标志
    else
        return defaultFlags;

}