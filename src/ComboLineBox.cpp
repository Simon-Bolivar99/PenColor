#include "include/ComboLineBox.hpp"
#include <QStylePainter>

ComboLineBox::ComboLineBox(QWidget *parent)
{
    sz = size();
}

QSize ComboLineBox::minimumSizeHint() const
{
    return QSize(100,QComboBox::sizeHint().rheight());
}

void ComboLineBox::paintEvent(QPaintEvent *event)
{

    QStylePainter painter(this);
    QStyleOptionComboBox opt;
    initStyleOption(&opt);
    opt.palette.setColor(QPalette::ColorRole::Button, Qt::white);
    painter.drawComplexControl(QStyle::CC_ComboBox, opt);

    painter.setPen(QPen(Qt::black,3,Qt::PenStyle(currentIndex()+1)));
    painter.drawLine(7, rect().center().ry(), sz.rwidth()-30, rect().center().ry());
    painter.end();
}

void  ComboLineBox::resizeEvent(QResizeEvent *e)
{
    sz = size();
}
