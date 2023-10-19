#pragma once

#include <QComboBox>

class ComboLineBox : public QComboBox {
    Q_OBJECT
public:
    ComboLineBox(QWidget *parent = nullptr);
    ~ComboLineBox() = default;

    QSize minimumSizeHint() const override;
protected:
    void paintEvent(QPaintEvent *event) override;

private:
    void resizeEvent(QResizeEvent *e) override;

    QSize sz;


};
