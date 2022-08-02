#ifndef SHASSI_H
#define SHASSI_H
#include "baseplane.h"

class shassi:public BasePlane
{
protected:
    int x, y, h, w, xc;
public:
    shassi(QWidget* parent = 0);
    void Draw(QPainter*);
    void Move(QPainter*);
};

#endif // SHASSI_H
