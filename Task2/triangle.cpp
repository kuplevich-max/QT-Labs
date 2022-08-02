#include "triangle.h"

Triangle::Triangle(QWidget* widget):polygon(widget)
{
    this->widget = widget;
     angle = 3;
     coord = new float*[angle];
     for (int i = 0; i < angle; i++) {
         coord[i] = new float[2];
     }

     coord[0][0]=400;
     coord[0][1]=50;
     coord[1][0]=300;
     coord[1][1]=150;
     coord[2][0]=500;
     coord[2][1]=150;
}

void Triangle::APlus(QPainter* painter)
{

}
void Triangle::BPlus(QPainter* painter)
{

}
void Triangle::AMinus(QPainter* painter)
{

}
void Triangle::BMinus(QPainter* painter)
{

}
