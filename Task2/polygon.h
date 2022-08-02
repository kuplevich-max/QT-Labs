#ifndef POLYGON_H
#define POLYGON_H
#include "figure.h"

class polygon: public figure
{
    QWidget* widget;
protected:
    int angle;
    float **coord;
    float xc, yc;
    float S;

    public:
    polygon(QWidget* widget = 0);
    void Rotate(QPainter* painter);
    void Draw(QPainter* painter);
    void SetFills(QString);
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


#endif // POLYGON_H
