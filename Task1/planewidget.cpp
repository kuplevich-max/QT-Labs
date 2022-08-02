#include "planewidget.h"

PlaneWidget::PlaneWidget(QWidget* parent)
    :QWidget(parent)
{
    setFixedSize(QSize(600,400));
    plane = new BasePlane(this);
    shas = new shassi(this);
}

void PlaneWidget::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter painter(this);
    plane->Move(&painter);
    shas->Move(&painter);
}


void PlaneWidget::timerEvent(QTimerEvent *event){
    update();
}

void PlaneWidget::showEvent(QShowEvent *event){
    timer = startTimer(50);
}

void PlaneWidget::hideEvent(QHideEvent *event){
    killTimer(timer);
}
