#pragma once

#include "libs/ColorToolButton.hpp"

#include <QList>
#include <QWidget>


class ComboLineBox;
class QSpinBox;
class ColorToolButton;
class QHBoxLayout;
class QPen;
class QPushButton;
class PenStyleDelegate;


class PenStyleEdit : public QWidget{
    Q_OBJECT
public:
    PenStyleEdit(QWidget *parent);
    ~PenStyleEdit() = default;

    QColor getPenColor();
    int getPenStyle();
    Qt::PenStyle getPenThick();

    void setColorButtonSize(QSize sz);

private:
    void initTools();
    void createGui();
    void initGui();
    void paintLine();


private:

    ComboLineBox    *LineBox;
    QSpinBox        *ThickBox;
    ColorToolButton *ColorButton;
    QHBoxLayout     *Layout;
    PenStyleDelegate  *StyleDelegate;

};
