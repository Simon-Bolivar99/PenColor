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

PenStyleEdit::PenStyleEdit(QWidget* parent)
{
    createGui();
    initGui();
}

void PenStyleEdit::createGui()
{
    LineBox = new ComboLineBox;
    ThickBox = new QSpinBox;
    ColorButton = new ColorToolButton;
        ColorButton->setMinimumSize(QSize(ThickBox->sizeHint().rheight(),ThickBox->sizeHint().rheight()));

    auto Layout = new QHBoxLayout(this);
        Layout->addWidget(LineBox,1);
        Layout->addWidget(ThickBox,0);
        Layout->addWidget(ColorButton,0);
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

    qDebug()<<ThickBox->sizeHint();

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
