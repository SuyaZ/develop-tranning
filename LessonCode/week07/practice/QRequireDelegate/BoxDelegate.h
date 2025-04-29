#ifndef __BOXDELEGATE_H__
#define __BOXDELEGATE_H__

#include <QStyledItemDelegate>

class BoxDelegate : public QStyledItemDelegate
{
	Q_OBJECT

public:
	BoxDelegate(QObject* parent);
	~BoxDelegate() = default;
	//渲染单元格
	virtual void
		paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override;

	//返回单元格编辑组件
	virtual QWidget* createEditor(QWidget* parent,
		const QStyleOptionViewItem& option, const QModelIndex& index) const override;

	//将模型数据设置到编辑器
	void setEditorData(QWidget* editor, const QModelIndex& index) const override;

	//将编辑器的数据存储到模型当中
	void setModelData(QWidget* editor, QAbstractItemModel* model,
		const QModelIndex& index) const override;
	void updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option,
		const QModelIndex& index) const override;
};

#endif
