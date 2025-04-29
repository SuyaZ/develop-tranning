#include "kcomboxdelegate.h"

#include <QComboBox>

KComboxDelegate::KComboxDelegate(QObject* parent)
    :QStyledItemDelegate(parent)
{}
void KComboxDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    QStyledItemDelegate::paint(painter, option, index);
}

QWidget* KComboxDelegate::createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const
{

    if (index.column() == 1)
    {
        QComboBox* pcombox = new QComboBox(parent);

        pcombox->addItem("Male");
        pcombox->addItem("Female");
        pcombox->setCurrentIndex(0);

        return pcombox;
    }
    return QStyledItemDelegate::createEditor(parent, option, index);
}

// 将模型中的数据赋值到编辑控件上
void KComboxDelegate::setEditorData(QWidget* editor, const QModelIndex& index) const
{
    //从模型中获取数据赋值到编辑控件上 
    if (index.column() == 1)
    {
        // 从模型中获取第一列的数据
        QString gender = index.model()->data(index, Qt::EditRole).toString();
        // 赋值到控件上
        QComboBox* pcombox = static_cast<QComboBox*>(editor);
        int currentIndex = pcombox->findText(gender);

        if (currentIndex >= 0)
            pcombox->setCurrentIndex(currentIndex);
    }
    else
        QStyledItemDelegate::setEditorData(editor, index);
}

void KComboxDelegate::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const
{
    //将第1列的数据存储到模型中
    if (index.column() == 1)
    {
        QComboBox* pcombox = static_cast<QComboBox*>(editor);
        // 从控件上获取数据
        QVariant data = pcombox->currentText();
        // 将获取的数据存储到模型中
        model->setData(index, data, Qt::EditRole);
    }
    else
        QStyledItemDelegate::setModelData(editor, model, index);// 如果是其他列，则可以使用默认委托来完成
}

void KComboxDelegate::updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    editor->setGeometry(option.rect);
}