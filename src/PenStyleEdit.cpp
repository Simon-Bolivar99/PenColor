#include "include/PenStyleEdit.hpp"
#include "include/PenStyleDelegate.hpp"
#include "include/ComboLineBox.hpp"

#include <QComboBox>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QPen>
#include <QPainter>
#include <QAction>
#include <QPushButton>

#include <QDebug>

PenStyleEdit::PenStyleEdit(QWidget* parent) : LineBox(new ComboLineBox(this)), ThickBox(new QSpinBox(this)),
    ColorButton(new ColorToolButton(this))
{
    createGui();
    initGui();
}

QColor PenStyleEdit::getPenColor()
{
    return ColorButton->getColor();
}

int PenStyleEdit::getPenStyle()
{
    return LineBox->currentIndex();
}

Qt::PenStyle PenStyleEdit::getPenThick()
{
    return Qt::PenStyle(ThickBox->value());
}



void PenStyleEdit::createGui()
{
    auto Layout = new QHBoxLayout(this);
        Layout->addWidget(LineBox);
        Layout->addWidget(ThickBox);
        Layout->addWidget(ColorButton);

        Layout->setStretch(0, 1);
        //Layout->setStretch(1, 1);
        //Layout->setStretch(2, 1);


    setLayout(Layout);
}

void PenStyleEdit::initGui()
{
    ThickBox->setMinimum(1);
    ThickBox->setMaximum(20);

    LineBox->setItemDelegate(new PenStyleDelegate);
        LineBox->addItem("", static_cast<int>(Qt::SolidLine));
        LineBox->addItem("", static_cast<int>(Qt::DashLine));
        LineBox->addItem("", static_cast<int>(Qt::DotLine));
        LineBox->addItem("", static_cast<int>(Qt::DashDotLine));
        LineBox->addItem("", static_cast<int>(Qt::DashDotDotLine));

}

