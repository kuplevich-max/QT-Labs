#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "figure.h"
#include <QtGui>
#include <QLabel>

class ellipse: public figure
{
    QWidget* widget;
protected:
    int a;
    int b;
    int xc,yc, x0, y0;
    int angle;
    float S, P;
public:
    ellipse(QWidget* widget = 0);
   void	 Draw(QPainter* painter);
   void Rotate(QPainter* painter);
   void GetCentre(QPainter* painter);
   void GetSquare();
   void ShowParam(QLabel* label);
   void ChangeCentre(QPainter* painter, QString, QString);
   void ToRight(QPainter* painter);
   void ToLeft(QPainter* painter);
   void ToUp(QPainter* painter);
   void ToDown(QPainter* painter);
   void Resize(QPainter* painter, QString);
   void APlus(QPainter* painter);
   void BPlus(QPainter* painter);
   void AMinus(QPainter* painter);
   void BMinus(QPainter* painter);
};

#endif // ELLIPSE_H
