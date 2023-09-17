#pragma once

#include <QMainWindow>

class ClickCount;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void createGui();

private:
    ClickCount *Click;
};
