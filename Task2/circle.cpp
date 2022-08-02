#include "circle.h"

circle::circle(QWidget* widget):ellipse(widget)
{
    this->widget = widget;
    a = b = 100;
    xc = 300;
    yc = 200;
    angle = 0;
    x0 = 0;
    y0 = 0;
}


