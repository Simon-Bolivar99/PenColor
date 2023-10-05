#include "include/CustomDelegate.h"
#include <QPainter>

QSize CustomDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QStyledItemDelegate::sizeHint(option, index);
}

void CustomDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyleOptionViewItem myOption = option;
    myOption.displayAlignment = Qt::AlignCenter | Qt::AlignVCenter;
    painter->setPen(QPen(Qt::black, 3, Qt::PenStyle(1)));
    painter->drawLine(0,10,60,10);

   QStyledItemDelegate::paint(painter,myOption,index);
}
