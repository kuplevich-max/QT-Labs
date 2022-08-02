#ifndef RECTAN_H
#define RECTAN_H
#include "polygon.h"

class Rectan: public polygon
{
    QWidget* widget;
public:
    int a, b;
    Rectan(QWidget* widget = 0);

    void APlus(QPainter*);
    void AMinus(QPainter*);
    void BPlus(QPainter*);
    void BMinus(QPainter*);

};

#endif // RECTAN_H
