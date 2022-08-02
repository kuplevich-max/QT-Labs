#ifndef STAR_H
#define STAR_H
#include "polygon.h"

class Star: public polygon
{
    QWidget* widget;
public:
    Star(QWidget* widget = 0);
};

#endif // STAR_H
