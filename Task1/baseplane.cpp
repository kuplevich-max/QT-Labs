#include "baseplane.h"

BasePlane::BasePlane(QWidget* widget)
    :m_widget(widget), x(20), y(20), w(100), h(40)
{}

void BasePlane::Draw(QPainter *qp)
{
    qp->begin(m_widget);
    qp->drawRect(x, y, w, h);
    qp->drawLine(x+w, y, x+w+30, y+h/2);
    qp->drawLine(x+w+30, y+h/2, x+w, y+h);
    qp->drawLine(x, y, x, y-50);
    qp->drawLine(x, y-50, x+20, y-50);
    qp->drawLine(x+20, y-50, x+30, y);
    qp->drawLine(x + 30, y+20, x + 70, y + 20);
    qp->drawLine(x + 70, y + 20, x + 20, y + 30);
    qp->drawLine(x + 20, y + 30, x - 20, y + 30);
    qp->drawLine(x - 20, y + 30, x + 30, y+20);

    qp->end();
}

void BasePlane::Move(QPainter *qp)
{
    qp->begin(m_widget);
    QPen pen(Qt::black);
    Draw(qp);
    x += 3;
    y += 1;
    qp->end();
}
