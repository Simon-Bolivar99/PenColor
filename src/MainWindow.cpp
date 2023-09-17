#include "include/MainWindow.h"
#include "include/ClickCount.h"

#include <QPushButton>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    createGui();
}

MainWindow::~MainWindow()
{
    delete Click;
}

void MainWindow::createGui()
{
    Click = new ClickCount();
    auto m_layout = new QHBoxLayout();
        m_layout->addWidget(Click);
        m_layout->setStretch(0,1);
    setLayout(m_layout);
    Click->setBaseSize(150, 150);
    Click->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
}

