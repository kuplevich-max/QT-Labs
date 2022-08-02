#ifndef FIGURE_H
#define FIGURE_H
#include <QPainter>
#include <QLabel>
class figure{
public:
    virtual void Draw(QPainter*) = 0;
    virtual void Rotate(QPainter*) = 0;
    virtual void GetCentre(QPainter*) = 0;
    virtual void GetSquare() = 0;
    virtual void ShowParam(QLabel*) = 0;
    virtual void ChangeCentre(QPainter*, QString, QString) = 0;
    virtual void ToRight(QPainter*) = 0;
    virtual void ToLeft(QPainter*) = 0;
    virtual void ToUp(QPainter*) = 0;
    virtual void ToDown(QPainter*) = 0;
    virtual void Resize(QPainter*, QString) = 0;
    virtual void APlus(QPainter* painter) = 0;
    virtual void BPlus(QPainter* painter) = 0;
    virtual void AMinus(QPainter* painter) = 0;
    virtual void BMinus(QPainter* painter) = 0;
};
#endif // FIGURE_H
