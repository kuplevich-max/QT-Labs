#include "quadro.h"

quadro::quadro(QWidget* widget):Rectan(widget)
{
    this->widget = widget;
    angle = 4;
    a = b = 100;
    coord[0][0] = 150;
    coord[0][1] = 200;
    coord[1][0] = coord[0][0]+a;
    coord[1][1] = 200;
    coord[2][0] = coord[1][0];
    coord[2][1] = 200 + a;
    coord[3][0] = coord[0][0];
    coord[3][1] = coord[2][1];
}
