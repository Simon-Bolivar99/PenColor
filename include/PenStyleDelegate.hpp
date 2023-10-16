 #pragma once

#include <QStyledItemDelegate>

class PenStyleDelegate : public QStyledItemDelegate {
    Q_OBJECT
public:
    using QStyledItemDelegate::QStyledItemDelegate;
    static const int DefaultPenWidth = 3;

public:
    PenStyleDelegate();
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;


    int getPenWidth() const;
    void setPenWidth(int width);

    QColor getPenColor() const;
    void setPenColor(QColor color);

private:
    int m_pen_width;
    QColor m_pen_color;


};

inline int PenStyleDelegate::getPenWidth() const
{
    return m_pen_width;
}

inline void PenStyleDelegate::setPenWidth(int width)
{
    m_pen_width = width;
}

inline QColor PenStyleDelegate::getPenColor() const
{
    return m_pen_color;
}

inline void PenStyleDelegate::setPenColor(QColor color)
{
    m_pen_color = color;
}
