#include "include/MainWindow.h"
#include "include/PenColor.h"

#include <QPushButton>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    createGui();
}

MainWindow::~MainWindow()
{
    delete PenCol;
}

void MainWindow::createGui()
{
    PenCol = new PenColor(this);
    auto m_layout = new QHBoxLayout();
        m_layout->addWidget(PenCol);
    setLayout(m_layout);
}



