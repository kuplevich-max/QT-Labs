#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "circle.h"
#include "polygon.h"
#include "triangle.h"
#include "quadro.h"
#include "rectan.h"
#include "ellipse.h"
#include "area.h"
#include "rombus.h"
#include "star.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_DrawButton_clicked();

    void on_RotateButton_clicked();

    void on_ResizeButton_clicked();

    void on_ChangeCenterButton_clicked();

    void on_MoveUpButton_clicked();

    void on_MoveDownButton_clicked();

    void on_MoveLeftButton_clicked();

    void on_MoveRightButton_clicked();

    void on_elAPlusButton_pressed();

    void on_elAPlusButton_released();

    void on_elAMinusButton_pressed();

    void on_elAMinusButton_released();

    void on_elBPlusButton_pressed();

    void on_elBPlusButton_released();

    void on_elBMinusButton_pressed();

    void on_elBMinusButton_released();

    void on_rectAPlusButton_pressed();

    void on_rectAPlusButton_released();

    void on_rectAMinusButton_pressed();

    void on_rectAMinusButton_released();

    void on_rectBPlusButton_pressed();

    void on_rectBPlusButton_released();

    void on_rectBMinusButton_pressed();

    void on_rectBMinusButton_released();

    void on_ShowParamsButton_clicked();

private:
    Ui::MainWindow *ui;
    Area *area;
    circle* circl;
    Rectan* rect;
    polygon* pol;
    Triangle* trian;
    ellipse* el;
    quadro* qdr;
    Rombus* romb;
    Star* star;
};
#endif // MAINWINDOW_H
