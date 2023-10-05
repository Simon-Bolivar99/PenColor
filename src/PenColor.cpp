#include "include/PenColor.h"
#include "include/CustomDelegate.h"

#include <QComboBox>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QPen>
#include <QPainter>
#include <QAction>
#include <QPushButton>

#include <QDebug>

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

int PenColor::getLine()
{
    return LineBox->currentIndex();
}

int PenColor::getThick()
{
    return ThickBox->value();
}

void PenColor::initTools()
{
    ThickBox->setValue(2);
    LineBox->setIconSize(QSize(60,20));
        //createLineBoxActions();
    LineBox->setItemDelegate(new CustomDelegate);
}

void PenColor::createGui()
{
     LineBox->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        LineBox->setMinimumSize(QSize(100,25));
        Layout->addWidget(LineBox);
    ThickBox->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        Layout->addWidget(ThickBox);
    ColorButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        ColorButton->setMinimumSize(QSize(40,25));
        Layout->addWidget(ColorButton);
    Layout->setSizeConstraint(QLayout::SetFixedSize);

//   auto Button = new QPushButton("Ok");
//    Layout->addWidget(Button);
//    connect(Button, &QPushButton::clicked, this, [this](){
//          qDebug()<<getLine();
//          qDebug()<<getThick();
//          qDebug()<<getColor();
//    });

    setLayout(Layout);
}

void PenColor::createLineBoxActions()
{
    for (int i = 1; i < 6;i++){
        QPen pen(Qt::black, 3, Qt::PenStyle(i));
        QPixmap pix(60,20);
        pix.fill(QColor(QRgb(0xefefef)));
        QPainter painter;
            painter.begin(&pix);
            painter.setPen(pen);
            painter.drawLine(0,LineBox->height()*0.35,60,LineBox->height()*0.35);
            painter.end();
        LineBox->addItem(QIcon(pix),"");
    }

}
