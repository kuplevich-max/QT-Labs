#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "planewidget.h"
#include <QPainter>

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
    void on_pushButton_clicked();
    void slotTimerAlarm();

private:
    Ui::MainWindow *ui;
    PlaneWidget *pw;
    QTimer *timer;
protected:
    void paintEvent(QPaintEvent*) override;
};
#endif // MAINWINDOW_H
