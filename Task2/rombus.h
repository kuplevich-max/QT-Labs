#ifndef ROMBUS_H
#define ROMBUS_H
#include "polygon.h"

class Rombus:public polygon
{
    QWidget *widget;
public:
    Rombus(QWidget *widget = 0);
};

#endif // ROMBUS_H
