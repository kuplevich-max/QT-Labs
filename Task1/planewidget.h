#ifndef PLANEWIDGET_H
#define PLANEWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include "baseplane.h"
#include "shassi.h"

class PlaneWidget: public QWidget
{
private:
    int timer;
    BasePlane *plane;
    shassi *shas;
public:
    PlaneWidget(QWidget* parent = 0);
    void paintEvent(QPaintEvent* e = 0);

    void timerEvent(QTimerEvent *event);

    void showEvent(QShowEvent *event);

    void hideEvent(QHideEvent *event);
};

#endif // PLANEWIDGET_H
