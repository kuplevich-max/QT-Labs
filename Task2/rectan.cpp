#include "rectan.h"

Rectan::Rectan(QWidget* widget):polygon(widget)
{
    this->widget = widget;
    angle = 4;
    a = 200;
    b = 100;
    coord = new float*[angle];
    for (int i = 0; i < angle; i++) {
       coord[i] = new float[2];
    }
    coord[0][0] = 150;
    coord[0][1] = 100;
    coord[1][0] = coord[0][0] + a;
    coord[1][1] = 100;
    coord[2][0] = coord[0][0] + a;
    coord[2][1] = coord[0][1] + b;
    coord[3][0] = 150;
    coord[3][1] = coord[0][1] + b;
}

void Rectan::APlus(QPainter* painter)
{
    coord[1][0]++;
    coord[2][0]++;
    Draw(painter);
}

void Rectan::AMinus(QPainter* painter)
{
    coord[1][0]--;
    coord[2][0]--;
    Draw(painter);
}

void Rectan::BPlus(QPainter* painter)
{
    coord[0][1]--;
    coord[1][1]--;
    Draw(painter);
}

void Rectan::BMinus(QPainter* painter)
{
    coord[0][1]++;
    coord[1][1]++;
    Draw(painter);
}
