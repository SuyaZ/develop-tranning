#ifndef __K_STUTABLEMODEL_H_
#define __K_STUTABLEMODEL_H_
#include <QAbstractTableModel>
#include <QVector>

class KStudent;

class KStuTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    KStuTableModel(QObject* parent);
    ~KStuTableModel();
    void setContent(QVector<KStudent*> students);

    // 返回表头标题内容
    virtual QVariant
        headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // 返回模型的行数
    virtual int
        rowCount(const QModelIndex& parent = QModelIndex()) const override;
    // 返回模型的列数
    virtual int
        columnCount(const QModelIndex& parent = QModelIndex()) const override;

    // 根据模型索引与数据角色,返回模型的数据
    virtual QVariant
        data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    // 设置模型数据，一般由代理来负责调用
    virtual bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;
    // 指定单元格设置一些标志
    virtual  Qt::ItemFlags flags(const QModelIndex& index) const;

private:
    QVector<KStudent*>    m_contents;
};
#endif