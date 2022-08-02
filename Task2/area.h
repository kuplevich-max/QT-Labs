#ifndef AREA_H
#define AREA_H

#include <QObject>
#include <QWidget>
#include "figure.h"

class Area:public QWidget
{
    figure* fig;
    int rotateTimer, moveUpTimer, moveDownTimer, moveLeftTimer, moveRightTimer,
    elAPlusTimer, elAMinusTimer, elBPlusTimer, elBMinusTimer, rectAPlusTimer,
    rectAMinusTimer, rectBPlusTimer, rectBMinusTimer;
public:
    int Timer;
    Area(QWidget* parent = 0);
    void setFigure(figure* f);
    void paintEvent(QPaintEvent* e = 0);

    void timerEvent(QTimerEvent *event);
    void rotateTimerStart();
    bool rotateTimerIsStart();
    void rotateTimerStop();

    void moveUpTimerStart();
    bool moveUpTimerIsStart();
    void moveUpTimerStop();

    void moveDownTimerStart();
    bool moveDownTimerIsStart();
    void moveDownTimerStop();

    void moveLeftTimerStart();
    bool moveLeftTimerIsStart();
    void moveLeftTimerStop();

    void moveRightTimerStart();
    bool moveRightTimerIsStart();
    void moveRightTimerStop();

    void elAPlusTimerStart();
    bool elAPlusTimerIsStart();
    void elAPlusTimerStop();

    void elAMinusTimerStart();
    bool elAMinusTimerIsStart();
    void elAMinusTimerStop();

    void elBPlusTimerStart();
    bool elBPlusTimerIsStart();
    void elBPlusTimerStop();

    void elBMinusTimerStart();
    bool elBMinusTimerIsStart();
    void elBMinusTimerStop();

    void rectAPlusTimerStart();
    bool rectAPlusTimerIsStart();
    void rectAPlusTimerStop();

    void rectAMinusTimerStart();
    bool rectAMinusTimerIsStart();
    void rectAMinusTimerStop();

    void rectBPlusTimerStart();
    bool rectBPlusTimerIsStart();
    void rectBPlusTimerStop();

    void rectBMinusTimerStart();
    bool rectBMinusTimerIsStart();
    void rectBMinusTimerStop();

    void resize(QString s);
    void changeCenter(QString, QString);
    void showParametres(QLabel* label);
};

#endif // AREA_H
