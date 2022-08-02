#include "rombus.h"


Rombus::Rombus(QWidget *widget):polygon(widget)
{
    this->widget = widget;
    angle = 4;
    coord = new float*[angle];
    for (int i = 0; i < angle; i++) {
       coord[i] = new float[2];
    }
    coord[0][0] = 200;
    coord[0][1] = 100;
    coord[1][0] = coord[0][0] + 70;
    coord[1][1] = coord[0][1] + 100;
    coord[2][0] = coord[0][0];
    coord[2][1] = coord[0][1] + 200;
    coord[3][0] = coord[0][0] - 70;
    coord[3][1] = coord[0][1] + 100;
}
