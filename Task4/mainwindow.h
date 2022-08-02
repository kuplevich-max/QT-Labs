#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employee.h"
#include "date.h"
#include <QFileDialog>

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
    void on_OpenButton_clicked();

    void on_ExtitButton_clicked();

    void on_SortButton_clicked();

    void on_pushButton_clicked();

    void on_AddButton_clicked();

    void on_SaveButton_clicked();

    void on_SearchButton1_clicked();

private:
    Ui::MainWindow *ui;
    Employee* arr;
    int count;
    QFile *file;
    QString filename;
};
#endif // MAINWINDOW_H
