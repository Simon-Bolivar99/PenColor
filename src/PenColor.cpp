#include "include/PenColor.h"
#include <QComboBox>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QPen>
#include <QPainter>
#include <QAction>

PenColor::PenColor(QWidget* parent) : LineBox(new QComboBox(this)), ThickBox(new QSpinBox(this)),
    ColorButton(new ColorToolButton(this)), Layout(new QHBoxLayout(this))
{
    initTools();
    createGui();
}

QColor PenColor::getColor()
{
    return ColorButton->getColor();
}

void PenColor::getLine()
{

}

void PenColor::getThick()
{

}

void PenColor::initTools()
{
    ThickBox->setValue(5);
    createLineBoxActions();
}

void PenColor::createGui()
{
     LineBox->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        LineBox->setMinimumSize(QSize(100,25));
        Layout->addWidget(LineBox);
    ColorButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        ColorButton->setMinimumSize(QSize(40,25));
        Layout->addWidget(ColorButton);
    ThickBox->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        Layout->addWidget(ThickBox);
    Layout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(Layout);
}

void PenColor::connectSignals()
{

}

void PenColor::createLineBoxActions()
{
    LineBox->addItem("");
    LineBox->addItem("");
    QPen pen(Qt::black, 10);
    QPainter painter(this);
        //painter.begin(this);
        painter.setPen(QPen(Qt::black, 10));
        painter.drawLine(0,0,100,100);




        //Action->setIcon(QIcon(pix));

}
