#pragma once

#include <QMainWindow>

class PenStyleEdit;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private:
    void createGui();

private:
    PenStyleEdit *PenCol;
};
