#include "include/MainWindow.hpp"
#include "include/PenStyleEdit.hpp"

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
    PenCol = new PenStyleEdit(this);
    PenCol->setColorButtonSize(QSize(50,30));
    auto m_layout = new QHBoxLayout();
        m_layout->addWidget(PenCol);
    setLayout(m_layout);
}



