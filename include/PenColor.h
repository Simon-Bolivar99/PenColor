#pragma once

#include "libs/ColorToolButton.h"

#include <QWidget>

class QComboBox;
class QSpinBox;
class ColorToolButton;
class QHBoxLayout;
class QPen;



class PenColor : public QWidget{
    Q_OBJECT
public:
    PenColor(QWidget *parent);
    ~PenColor() = default;

    QColor getColor();
    void getLine();
    void getThick();

private:
    void initTools();
    void createGui();
    void connectSignals();
    void createLineBoxActions();


private:

    QComboBox       *LineBox;
    QSpinBox        *ThickBox;
    ColorToolButton *ColorButton;
    QHBoxLayout     *Layout;

    QAction *Action;
    QAction *Action1;
};
