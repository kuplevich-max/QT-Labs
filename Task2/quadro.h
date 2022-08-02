#ifndef QUADRO_H
#define QUADRO_H
#include "rectan.h"

class quadro: public Rectan
{
    QWidget* widget;
public:
    quadro(QWidget* widget = 0);
};

#endif // QUADRO_H
