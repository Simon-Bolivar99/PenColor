#include "include/PenStyleDelegate.hpp"
#include <QPainter>

PenStyleDelegate::PenStyleDelegate()
    : m_pen_width(DefaultPenWidth), m_pen_color(Qt::black)
{
}

QSize PenStyleDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QStyledItemDelegate::sizeHint(option, index);
}

void PenStyleDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    int data = index.model()->data(index, Qt::UserRole).toByteArray().toInt();
    QStyleOptionViewItem myOption = option;
        myOption.displayAlignment = Qt::AlignRight | Qt::AlignVCenter;

    QPixmap pixmap(5,5);    
        pixmap.fill(Qt::white);
    painter->drawPixmap(myOption.rect.x()+3,myOption.rect.y()+3,myOption.rect.width()-6,myOption.rect.height()-3, pixmap);
    myOption.state = option.state & (~QStyle::State_HasFocus); // выделение фокуса
    painter->setPen(QPen(m_pen_color, m_pen_width, Qt::PenStyle(data)));
        QStyledItemDelegate::paint(painter,myOption,index);

    painter->drawLine(myOption.rect.x()+6,myOption.rect.y()+9,myOption.rect.size().rwidth()-7, myOption.rect.y()+9);

}

