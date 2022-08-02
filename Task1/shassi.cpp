#include "shassi.h"

shassi::shassi(QWidget* parent)
    :BasePlane(parent), x(35), y(60), w(10), h(0), xc((2*x + w)/2)
{
}

void shassi::Draw(QPainter *painter)
{
    painter->drawRect(x, y, w, h);
    painter->drawRect(x + 60, y, w, h);

    painter->drawEllipse(QPoint(xc, y + h), 7, 7);
    painter->drawEllipse(QPoint(xc + 60, y + h), 7, 7);

}

void shassi::Move(QPainter *painter)
{
    painter->begin(m_widget);
    QPen pen(Qt::black);
    Draw(painter);
    x += 3;
    y += 1;
    xc += 3;
    if(h < 30)
        h += 1;
    painter->end();
}
