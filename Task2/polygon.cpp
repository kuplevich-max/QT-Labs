#include "polygon.h"
#include "utils.h"
polygon::polygon(QWidget* widget)
{
    this->widget = widget;
}



bool isValidForm(QString str)
{
    if(!Utils::hasChar(str, '(') || !Utils::hasChar(str, ')') || !Utils::hasChar(str, ';'))
        return false;
    QList<QString> arr = str.split(')');
    if(arr[arr.size() - 1] == "")
        arr.erase(arr.begin() + arr.size() -1);
    for(auto item: arr)
    {
        if(item[0] != '(' || !Utils::hasChar(item, ';'))
            return false;
    }
    for(auto item: arr)
    {
        QList<QString> list = item.split(';');
        if(list.size() != 2)
            return false;
        list[0] = list[0].sliced(1);
        if(!Utils::isNumber(list[0]) || !Utils::isNumber(list[1]))
            return false;
    }
    return true;
}

void polygon::SetFills(QString str1)
{

    int i = 0;
    int n = 0;
    wchar_t*str = new wchar_t[str1.length()];
    str1.toWCharArray(str);
    if(!isValidForm(str1))
    {
        throw std::string("Invalid format for coordinates");
    }
    while (str[i]) {
        if (str[i] == '(') {
            n++;
        }
        i++;
    }
    angle = n;
    coord = new float*[n];
    for (int u = 0; u < n; u++) {
        coord[u] = new float[2];
    }
    int tmp_p = 0;
    i = 0;
    int h = 0;
    int h2 = 0;
    char**tmp = new char*[n * 2];
    for (int u = 0; u < n * 2; u++) {
        tmp[u] = new char[5];
    }
    while (str[i]) {
        if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-') {
            tmp[h2][tmp_p] = str[i];
            tmp_p++;
        }
        else {
            if (str[i] == ';') {
                coord[h][0] = atof(tmp[h2]);
                tmp_p = 0;
                h2++;
            }
            if (str[i] == ')') {
                coord[h][1] = atof(tmp[h2]);

                h++;
                tmp_p = 0;
                h2++;
            }
        }
        i++;
    }
}
 int j = 0;
void polygon::Draw(QPainter* painter)
{
    painter->begin(widget);
    painter->drawPoint(xc + (coord[0][0] - xc)*cos(j*M_PI/180) +(coord[0][1] - yc)*sin(j*M_PI/180), yc + (coord[0][0] - xc)*(0-sin(j*M_PI/180)) + (coord[0][1] -yc)*cos(j*M_PI/180));
    for(int i = 1; i<angle; i++)
    {
        float x0 = coord[i-1][0], y0 = coord[i-1][1], x1 = coord[i][0], y1 = coord[i][1];
        painter->drawLine(xc + (x0 - xc)*cos(j*M_PI/180) +(y0 - yc)*sin(j*M_PI/180), yc + (x0 - xc)*(0-sin(j*M_PI/180)) + (y0 -yc)*cos(j*M_PI/180),
                          xc + (x1 - xc)*cos(j*M_PI/180) +(y1 - yc)*sin(j*M_PI/180), yc + (x1 - xc)*(0-sin(j*M_PI/180)) + (y1 -yc)*cos(j*M_PI/180));
    }
    painter->drawLine(xc + (coord[angle-1][0] - xc)*cos(j*M_PI/180) +(coord[angle-1][1] - yc)*sin(j*M_PI/180), yc + (coord[angle-1][0] - xc)*(0-sin(j*M_PI/180)) + (coord[angle-1][1] -yc)*cos(j*M_PI/180),
                      xc + (coord[0][0] - xc)*cos(j*M_PI/180) +(coord[0][1] - yc)*sin(j*M_PI/180), yc + (coord[0][0] - xc)*(0-sin(j*M_PI/180)) + (coord[0][1] -yc)*cos(j*M_PI/180));
    painter->end();
    GetCentre(painter);
}

void polygon::GetSquare()
{
    int sum = 0;
    for(int j = 0; j<angle-1; j++)
    {
       sum += (coord[j][0]*coord[j+1][1]-coord[j+1][0]*coord[j][1]);
    }
    sum += (coord[angle-1][0]*coord[0][1] - coord[0][0]*coord[angle-1][1]);
    S = sum/2;
}

void polygon::GetCentre(QPainter* painter)
{
    GetSquare();
    int sumx = 0, sumy = 0;

    for(int j = 0; j < angle-1; j++)
    {
        sumx += (coord[j][0] + coord[j+1][0])*(coord[j][0]*coord[j+1][1]-coord[j+1][0]*coord[j][1]);
        sumy += (coord[j][1] + coord[j+1][1])*(coord[j][0]*coord[j+1][1] - coord[j+1][0]*coord[j][1]);
    }
    sumx += (coord[angle - 1][0] + coord[0][0])*(coord[angle-1][0]*coord[0][1] - coord[0][0]*coord[angle-1][1]);
    sumy += (coord[angle-1][1] + coord[0][1])*(coord[angle-1][0]*coord[0][1] - coord[0][0]*coord[angle-1][1]);
    xc = 1/(6*S)*sumx;
    yc = 1/(6*S)*sumy;
    painter->begin(widget);
    painter->setPen(QPen(Qt::red));
    painter->drawPoint(xc,yc);
    painter->end();
}
void polygon::ShowParam(QLabel* label)
{
    float P = 0;
    for(int i = 1; i<angle; i++)
    {
        P+=sqrt(powf(coord[i][0] - coord[i-1][0],2) + powf(coord[i][1] - coord[i-1][1],2));
    }
    P+= sqrt(powf(coord[0][0] - coord[angle-1][0],2) + powf(coord[0][1] - coord[angle-1][1],2));
    label->setText(QString("S = %1\nP = %2\nC(%3;%4)").arg(S).arg(P).arg(xc).arg(yc));
}

void polygon::Rotate(QPainter* painter)
{
    GetCentre(painter);
     j<360?j++: j = 0;

     Draw(painter);
}

 void polygon::ChangeCentre(QPainter* painter, QString s1, QString s2)
 {
    if(!Utils::isNumber(s1) || !Utils::isNumber(s2))
    {
        throw std::string("Invalid parametres");
    }
    xc+=s1.toInt();
    yc+=s2.toInt();
    for(int i = 0; i<angle; i++)
    {
        coord[i][0]+=s1.toInt();
        coord[i][1]+=s2.toInt();
    }
    Draw(painter);
 }

 void polygon::ToRight(QPainter* painter)
 {
    for(int i =0; i<angle; i++)
    {
        coord[i][0]++;
    }
    Draw(painter);
 }

 void polygon::ToLeft(QPainter* painter)
 {
      for(int i =0; i<angle; i++)
    {
        coord[i][0]--;
    }
    Draw(painter);
 }

 void polygon::ToUp(QPainter* painter)
 {
      for(int i =0; i<angle; i++)
    {
        coord[i][1]--;
    }
    Draw(painter);
 }

 void polygon::ToDown(QPainter* painter)
 {
    for(int i =0; i<angle; i++)
    {
        coord[i][1]++;
    }
    Draw(painter);
 }

 void polygon::Resize(QPainter* painter, QString s)
 {
     if(!Utils::isNumber(s))
         throw std::string("Invalid coefficient format!");
     float tempx = xc, tempy = yc;
     for(int i =0; i<angle; i++)
    {
        coord[i][0]*=s.toDouble();
        coord[i][1]*=s.toDouble();
    }
    xc = tempx;
    yc = tempy;
    Draw(painter);
 }

 void polygon::APlus(QPainter* painter)
 {}
 void polygon::BPlus(QPainter* painter)
 {}
 void polygon::AMinus(QPainter* painter)
 {}
 void polygon::BMinus(QPainter* painter)
 {}
