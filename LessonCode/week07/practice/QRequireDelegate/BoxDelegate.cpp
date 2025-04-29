#pragma execution_character_set("utf-8")
#include "BoxDelegate.h"

#include <QComboBox>

BoxDelegate::BoxDelegate(QObject* parent)
    :QStyledItemDelegate(parent)
{}

void BoxDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    QStyledItemDelegate::paint(painter, option, index);
}

QWidget* BoxDelegate::createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const
{

    if (index.column() == 1)
    {
        QComboBox* pcombox = new QComboBox(parent);

        pcombox->addItem("业务创新");
        pcombox->addItem("客户反馈");
        pcombox->addItem("用户调研");
        pcombox->addItem("日常迭代");
        pcombox->setCurrentIndex(0);

        return pcombox;
    }
    return QStyledItemDelegate::createEditor(parent, option, index);
}

// 将模型中的数据赋值到编辑控件上
void BoxDelegate::setEditorData(QWidget* editor, const QModelIndex& index) const
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

void BoxDelegate::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const
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

void BoxDelegate::updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    editor->setGeometry(option.rect);
}