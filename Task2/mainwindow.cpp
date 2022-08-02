#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QTimer>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    area = new Area(this);
    trian = new Triangle(area);
    pol = new polygon(area);
    qdr = new quadro(area);
    el = new ellipse(area);
    circl = new circle(area);
    rect = new Rectan(area);
    romb = new Rombus(area);
    star = new Star(area);
}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_DrawButton_clicked()
{
    if(ui->polygonRadioButton->isChecked())
    {
        try{
            pol->SetFills(ui->pointLine->text());
        }
        catch(std::string ex)
        {

            QMessageBox *msg = new QMessageBox("Error",
                                               QString(ex.c_str()),
                                               QMessageBox::Information,
                                               QMessageBox::NoButton,
                                               QMessageBox::Ok,
                                               QMessageBox::NoButton);
            msg->exec();
            delete msg;
            return;
        }

        area->setFigure(pol);
    }

    if(ui->rectangleRadioButton->isChecked())
        area->setFigure(rect);
    if(ui->quadroRadioButton->isChecked())
        area->setFigure(qdr);
    if(ui->triangleRadioButton->isChecked())
        area->setFigure(trian);
    if(ui->ellipseRadioButton->isChecked())
        area->setFigure(el);
    if(ui->circleRadioButton->isChecked())
        area->setFigure(circl);
    if(ui->rombusRadioButton->isChecked())
        area->setFigure(romb);
    if(ui->starRadioButton->isChecked())
        area->setFigure(star);
}

void MainWindow::on_RotateButton_clicked()
{
    if(!area->rotateTimerIsStart())
        area->rotateTimerStart();
    else
        area->rotateTimerStop();
}

void MainWindow::on_ResizeButton_clicked()
{
    try{
    area->resize(ui->coefLine->text());
    }
    catch(std::string ex)
    {
        QMessageBox *msg = new QMessageBox("Error",
                                           QString(ex.c_str()),
                                           QMessageBox::Information,
                                           QMessageBox::NoButton,
                                           QMessageBox::Ok,
                                           QMessageBox::NoButton);
        msg->exec();
        delete msg;
        return;
    }
}


void MainWindow::on_ChangeCenterButton_clicked()
{
    try{
        area->changeCenter(ui->xLine->text(), ui->yLine->text());
    }
    catch(std::string ex)
    {
        QMessageBox *msg = new QMessageBox("Error",
                                           QString(ex.c_str()),
                                           QMessageBox::Information,
                                           QMessageBox::NoButton,
                                           QMessageBox::Ok,
                                           QMessageBox::NoButton);
        msg->exec();
        delete msg;
        return;
    }
}


void MainWindow::on_MoveUpButton_clicked()
{
    if(!area->moveUpTimerIsStart())
        area->moveUpTimerStart();
    else
        area->moveUpTimerStop();
}


void MainWindow::on_MoveDownButton_clicked()
{
    if(!area->moveDownTimerIsStart())
        area->moveDownTimerStart();
    else
        area->moveDownTimerStop();
}


void MainWindow::on_MoveLeftButton_clicked()
{
    if(!area->moveLeftTimerIsStart())
        area->moveLeftTimerStart();
    else
        area->moveLeftTimerStop();
}


void MainWindow::on_MoveRightButton_clicked()
{
    if(!area->moveRightTimerIsStart())
        area->moveRightTimerStart();
    else
        area->moveRightTimerStop();
}


void MainWindow::on_elAPlusButton_pressed()
{
    area->elAPlusTimerStart();
}


void MainWindow::on_elAPlusButton_released()
{
    area->elAPlusTimerStop();
}


void MainWindow::on_elAMinusButton_pressed()
{
    area->elAMinusTimerStart();
}



void MainWindow::on_elAMinusButton_released()
{
    area->elAMinusTimerStop();
}


void MainWindow::on_elBPlusButton_pressed()
{
    area->elBPlusTimerStart();
}


void MainWindow::on_elBPlusButton_released()
{
    area->elBPlusTimerStop();
}


void MainWindow::on_elBMinusButton_pressed()
{
    area->elBMinusTimerStart();
}


void MainWindow::on_elBMinusButton_released()
{
    area->elBMinusTimerStop();
}


void MainWindow::on_rectAPlusButton_pressed()
{
    area->rectAPlusTimerStart();
}


void MainWindow::on_rectAPlusButton_released()
{
    area->rectAPlusTimerStop();
}


void MainWindow::on_rectAMinusButton_pressed()
{
    area->rectAMinusTimerStart();
}


void MainWindow::on_rectAMinusButton_released()
{
    area->rectAMinusTimerStop();
}


void MainWindow::on_rectBPlusButton_pressed()
{
    area->rectBPlusTimerStart();
}


void MainWindow::on_rectBPlusButton_released()
{
    area->rectBPlusTimerStop();
}


void MainWindow::on_rectBMinusButton_pressed()
{
    area->rectBMinusTimerStart();
}


void MainWindow::on_rectBMinusButton_released()
{
    area->rectBMinusTimerStop();
}


void MainWindow::on_ShowParamsButton_clicked()
{
    area->showParametres(ui->parametresLabel);
}

