#pragma once

#include "libs/ColorToolButton.h"

#include <QList>
#include <QWidget>


class QComboBox;
class QSpinBox;
class ColorToolButton;
class QHBoxLayout;
class QPen;
class QPushButton;



class PenColor : public QWidget{
    Q_OBJECT
public:
    PenColor(QWidget *parent);
    ~PenColor() = default;

    QColor getColor();
    int getLine();
    int getThick();

private:
    void initTools();
    void createGui();
    void createLineBoxActions();


private:

    QComboBox       *LineBox;
    QSpinBox        *ThickBox;
    ColorToolButton *ColorButton;
    QHBoxLayout     *Layout;

};
