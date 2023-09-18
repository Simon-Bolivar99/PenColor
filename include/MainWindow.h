#pragma once

#include <QMainWindow>

class PenColor;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private:
    void createGui();

private:
    PenColor *PenCol;
};
