#include "area.h"
#include "rectan.h"
#include <QTimerEvent>
#include "ellipse.h"

Area::Area(QWidget* parent)
    :QWidget(parent), fig(nullptr), rotateTimer(0),
      moveUpTimer(0), moveDownTimer(0), moveLeftTimer(0),
      moveRightTimer(0)
{
    setFixedSize(940, 300);
    Rectan *r = new Rectan(this);
    fig = r;
}

void Area::setFigure(figure* f)
{
    fig = f;
    update();
}

void Area::rotateTimerStart()
{
    rotateTimer = startTimer(50);
}

bool Area::rotateTimerIsStart()
{
    return rotateTimer > 0;
}

void Area::rotateTimerStop()
{
    killTimer(rotateTimer);
    rotateTimer = 0;
}

void Area::moveUpTimerStart()
{
    moveUpTimer = startTimer(20);
}
bool Area::moveUpTimerIsStart()
{
    return moveUpTimer > 0;
}
void Area::moveUpTimerStop()
{
    killTimer(moveUpTimer);
    moveUpTimer = 0;
}

void Area::moveDownTimerStart()
{
    moveDownTimer = startTimer(20);
}
bool Area::moveDownTimerIsStart()
{
    return moveDownTimer > 0;
}
void Area::moveDownTimerStop()
{
    killTimer(moveDownTimer);
    moveDownTimer = 0;
}

void Area::moveLeftTimerStart()
{
    moveLeftTimer = startTimer(20);
}
bool Area::moveLeftTimerIsStart()
{
    return moveLeftTimer > 0;
}
void Area::moveLeftTimerStop()
{
    killTimer(moveLeftTimer);
    moveLeftTimer = 0;
}

void Area::moveRightTimerStart()
{
    moveRightTimer = startTimer(20);
}
bool Area::moveRightTimerIsStart()
{
    return moveRightTimer > 0;
}
void Area::moveRightTimerStop()
{
    killTimer(moveRightTimer);
    moveRightTimer = 0;
}

void Area::elAPlusTimerStart()
{
    elAPlusTimer = startTimer(20);
}
bool Area::elAPlusTimerIsStart()
{
    return elAPlusTimer > 0;
}
void Area::elAPlusTimerStop()
{
    killTimer(elAPlusTimer);
    elAPlusTimer = 0;
}
void Area::elAMinusTimerStart()
{
    elAMinusTimer = startTimer(20);
}
bool Area::elAMinusTimerIsStart()
{
    return elAMinusTimer > 0;
}
void Area::elAMinusTimerStop()
{
    killTimer(elAMinusTimer);
    elAMinusTimer = 0;
}

void Area::elBPlusTimerStart()
{
    elBPlusTimer = startTimer(20);
}
bool Area::elBPlusTimerIsStart()
{
    return elBPlusTimer > 0;
}
void Area::elBPlusTimerStop()
{
    killTimer(elBPlusTimer);
    elBPlusTimer = 0;
}

void Area::elBMinusTimerStart()
{
    elBMinusTimer = startTimer(20);
}
bool Area::elBMinusTimerIsStart()
{
    return elBMinusTimer > 0;
}
void Area::elBMinusTimerStop()
{
    killTimer(elBMinusTimer);
    elBMinusTimer = 0;
}

void Area::rectAPlusTimerStart()
{
    rectAPlusTimer = startTimer(20);
}
bool Area::rectAPlusTimerIsStart()
{
    return rectAPlusTimer > 0;
}
void Area::rectAPlusTimerStop()
{
    killTimer(rectAPlusTimer);
    rectAPlusTimer = 0;
}

void Area::rectAMinusTimerStart()
{
    rectAMinusTimer = startTimer(20);
}
bool Area::rectAMinusTimerIsStart()
{
    return rectAMinusTimer > 0;
}
void Area::rectAMinusTimerStop()
{
    killTimer(rectAMinusTimer);
    rectAMinusTimer = 0;
}

void Area::rectBPlusTimerStart()
{
    rectBPlusTimer = startTimer(20);
}
bool Area::rectBPlusTimerIsStart()
{
    return rectBPlusTimer > 0;
}
void Area::rectBPlusTimerStop()
{
    killTimer(rectBPlusTimer);
    rectBPlusTimer = 0;
}

void Area::rectBMinusTimerStart()
{
    rectBMinusTimer = startTimer(20);
}
bool Area::rectBMinusTimerIsStart()
{
    return rectBMinusTimer > 0;
}
void Area::rectBMinusTimerStop()
{
    killTimer(rectBMinusTimer);
    rectBMinusTimer = 0;
}


void Area::resize(QString s)
{
    QPainter painter;
    fig->Resize(&painter, s);
    update();
}

void Area::changeCenter(QString dx, QString dy)
{
    QPainter painter;
    fig->ChangeCentre(&painter, dx, dy);
    update();
}

void Area::paintEvent(QPaintEvent* e){
    QPainter painter;
    fig->Draw(&painter);
}

void Area::timerEvent(QTimerEvent *event){
    if(event->timerId() == rotateTimer)
    {
        QPainter painter;
        fig->Rotate(&painter);
        update();
    }
    if(event->timerId() == moveUpTimer)
    {
        QPainter painter;
        fig->ToUp(&painter);
        update();
    }
    if(event->timerId() == moveDownTimer)
    {
        QPainter painter;
        fig->ToDown(&painter);
        update();
    }
    if(event->timerId() == moveLeftTimer)
    {
        QPainter painter;
        fig->ToLeft(&painter);
        update();
    }
    if(event->timerId() == moveRightTimer)
    {
        QPainter painter;
        fig->ToRight(&painter);
        update();
    }
    if(event->timerId() == elAPlusTimer)
    {
        QPainter painter;
        fig->APlus(&painter);
        update();
    }
    if(event->timerId() == elAMinusTimer)
    {
        QPainter painter;
        fig->AMinus(&painter);
        update();
    }
    if(event->timerId() == elBPlusTimer)
    {
        QPainter painter;
        fig->BPlus(&painter);
        update();
    }
    if(event->timerId() == elBMinusTimer)
    {
        QPainter painter;
        fig->BMinus(&painter);
        update();
    }
    if(event->timerId() == rectAPlusTimer)
    {
        QPainter painter;
        fig->APlus(&painter);
        update();
    }
    if(event->timerId() == rectAMinusTimer)
    {
        QPainter painter;
        fig->AMinus(&painter);
        update();
    }
    if(event->timerId() == rectBPlusTimer)
    {
        QPainter painter;
        fig->BPlus(&painter);
        update();
    }
    if(event->timerId() == rectBMinusTimer)
    {
        QPainter painter;
        fig->BMinus(&painter);
        update();
    }
}

void Area::showParametres(QLabel *label)
{
    fig->ShowParam(label);
}
