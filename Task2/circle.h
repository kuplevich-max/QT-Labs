#ifndef CIRCLE_H
#define CIRCLE_H
#include "ellipse.h"

class circle: public ellipse
{
    QWidget* widget;
public:
    circle(QWidget* widget = 0);
};

#endif // CIRCLE_H
