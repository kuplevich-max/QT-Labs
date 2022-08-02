#include "ellipse.h"
#include "utils.h"

ellipse::ellipse(QWidget* widget)
{
    this->widget = widget;
    a=100;
    b=60;
    xc=100;
    yc=150;
    angle=0;
    x0 = 0;
    y0 = 0;
}

void ellipse::Draw(QPainter* painter){
    painter->begin(widget);
    for(int i=0;i<360;i++){
    float x=xc+a*cos(i*M_PI/180)*cos(angle*M_PI/180)+b*sin(i*M_PI/180)*sin(angle*M_PI/180) + x0;
    float y=yc-a*cos(i*M_PI/180)*sin(angle*M_PI/180)+b*sin(i*M_PI/180)*cos(angle*M_PI/180) + y0;
    painter->drawPoint(x, y);
    }
    painter->end();
}
void ellipse::Rotate(QPainter* painter)
{

     angle++;
    Draw(painter);
}


void ellipse::GetSquare()
{
    S = M_PI*a*b;
    P = M_PI*(a+b);
}

void ellipse::GetCentre(QPainter* painter)
{
    GetSquare();
}

void ellipse::ShowParam(QLabel* Label)
{
    GetSquare();
    QString s = QString("S = %1\nP = %2\nC(%3;%4)").arg(S).arg(P).arg(xc).arg(yc);
    Label->setText(s);
}

void ellipse::ChangeCentre(QPainter* painter, QString s1, QString s2)
{
    if(!Utils::isNumber(s1) || !Utils::isNumber(s2))
        throw std::string("Invalid parametres!");
    xc+=s1.toInt();
    yc+=s2.toInt();
    Draw(painter);
}

void ellipse::ToRight(QPainter* painter)
{
   xc++;
   Draw(painter);
}

void ellipse::ToLeft(QPainter* painter)
{
    xc--;
    Draw(painter);
}

void ellipse::ToUp(QPainter* painter)
{
    yc--;
    Draw(painter);
}

void ellipse::ToDown(QPainter* painter)
{
    yc++;
    Draw(painter);
}

void ellipse::APlus(QPainter* painter)
{
   a++;
   Draw(painter);
}

void ellipse::AMinus(QPainter* painter)
{
   a--;
   Draw(painter);
}

void ellipse::BPlus(QPainter* painter)
{
   b++;
   Draw(painter);
}

void ellipse::BMinus(QPainter* painter)
{
   b--;
   Draw(painter);
}

void ellipse::Resize(QPainter* painter, QString s)
{
   if(!Utils::isNumber(s))
       throw std::string("Invalid coefficient format!");
   a*=s.toDouble();
   b*=s.toDouble();
   Draw(painter);

}
