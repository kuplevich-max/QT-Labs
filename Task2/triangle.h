#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "polygon.h"

class Triangle: public polygon
{
    QWidget* widget;
public:
    Triangle(QWidget* widget = 0);
    void APlus(QPainter* painter);
    void BPlus(QPainter* painter);
    void AMinus(QPainter* painter);
    void BMinus(QPainter* painter);

};

#endif // TRIANGLE_H
