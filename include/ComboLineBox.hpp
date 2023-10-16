#pragma once

#include <QComboBox>

class ComboLineBox : public QComboBox {
    Q_OBJECT
public:
    ComboLineBox(QWidget *parent = nullptr);
    ~ComboLineBox() = default;

protected:
    void paintEvent(QPaintEvent *event);

private:
    void resizeEvent(QResizeEvent *e);

    QSize sz;
};
