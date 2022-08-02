#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    birthday = nullptr;
    filename = "";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(filename == "")
        filename = QFileDialog::getOpenFileName(0, "Open File", "", "*.txt");
    else
    {
        QString fname = QFileDialog::getOpenFileName(0, "Open File", "", "*.txt");
        if(fname != filename)
        {
            QMessageBox *msg = new QMessageBox("Error",
                                               "You have already opened the file!",
                                               QMessageBox::Information,
                                               QMessageBox::Yes,
                                               QMessageBox::No,
                                               QMessageBox::Cancel | QMessageBox::Escape);
            msg->exec();
            delete msg;
            return;
        }
        else
            filename = fname;
    }
        file = new QFile(filename);
        int count = 0;
        if(file->open(QIODevice::ReadOnly))
        {
            QTextStream in(file);
            while(!in.atEnd())
            {
                QString text = in.readLine();
                count++;
            }
            file->close();
        }
        else
        {
            QMessageBox *msg = new QMessageBox("Error",
                                               "File can't be opened!",
                                               QMessageBox::Information,
                                               QMessageBox::Yes,
                                               QMessageBox::No,
                                               QMessageBox::Cancel | QMessageBox::Escape);
            msg->exec();
            delete msg;
            return;
        }
        dates = new Date[count];
        dates_count = count;
        if(file->open(QIODevice::ReadOnly))
        {
            QTextStream in(file);
            int i = 0;
            while(!in.atEnd())
            {
                QString text = in.readLine();
                try{
                dates[i++] = Date(text);
                }
                catch(...)
                {
                    filename = "";
                    QMessageBox *msg = new QMessageBox("Error",
                                                       "Invalid data format!",
                                                       QMessageBox::Information,
                                                       QMessageBox::Yes,
                                                       QMessageBox::No,
                                                       QMessageBox::Cancel | QMessageBox::Escape);
                    msg->exec();
                    delete msg;
                    return;
                }
            }
            file->close();
        }
        else
        {
            QMessageBox *msg = new QMessageBox("Error",
                                               "File can't be opened!",
                                               QMessageBox::Information,
                                               QMessageBox::Yes,
                                               QMessageBox::No,
                                               QMessageBox::Cancel | QMessageBox::Escape);
            msg->exec();
            delete msg;
            return;
        }

        for(int i = 0; i < count; i++)
        {
            ui->tableWidget->insertRow(i);
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(dates[i].toString()));
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem(dates[i].NextDay().toString()));
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString("%1").arg(dates[i].Duration(dates[i != count-1?i+1:i-1]))));
        }
}


void MainWindow::on_pushButton_2_clicked()
{
    if(birthday)
    {
        delete birthday;
        birthday = nullptr;
    }
    try{
        birthday = new Date(ui->lineEdit->text());
    }
    catch(...)
    {
        QMessageBox *msg = new QMessageBox("Error",
                                           "Invalid date format!",
                                           QMessageBox::Information,
                                           QMessageBox::Yes,
                                           QMessageBox::No,
                                           QMessageBox::Cancel | QMessageBox::Escape);
        msg->exec();
        delete msg;
        return;
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    if(!ui->tableWidget->selectedItems().empty())
    {
        ui->prevDayLabel->setText(Date(ui->tableWidget->selectedItems()[0]->text()).PreviousDay().toString());
    }
    else
    {
        QMessageBox *msg = new QMessageBox("Error",
                                           "No date have been selected!",
                                           QMessageBox::Information,
                                           QMessageBox::Yes,
                                           QMessageBox::No,
                                           QMessageBox::Cancel | QMessageBox::Escape);
        msg->exec();
        delete msg;
        return;
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    if(birthday == nullptr)
    {
        QMessageBox *msg = new QMessageBox("Error",
                                           "Birthday was not initialized!",
                                           QMessageBox::Information,
                                           QMessageBox::Yes,
                                           QMessageBox::No,
                                           QMessageBox::Cancel | QMessageBox::Escape);
        msg->exec();
        delete msg;
        return;
    }
    if(!ui->tableWidget->selectedItems().empty())
        ui->birthdayDurationLabel->setText(QString("%1").arg(Date(ui->tableWidget->selectedItems()[0]->text()).DaysTillYourBirthDay(*birthday)));
    else
    {
        QMessageBox *msg = new QMessageBox("Error",
                                           "No date have been selected!",
                                           QMessageBox::Information,
                                           QMessageBox::Yes,
                                           QMessageBox::No,
                                           QMessageBox::Cancel | QMessageBox::Escape);
        msg->exec();
        delete msg;
        return;
    }
}


void MainWindow::on_pushButton_5_clicked()
{
    Date* date;
    try{
    date = new Date(ui->lineEdit_2->text());
    }
    catch(...)
    {
        QMessageBox *msg = new QMessageBox("Error",
                                           "Invalid date format!",
                                           QMessageBox::Information,
                                           QMessageBox::Yes,
                                           QMessageBox::No,
                                           QMessageBox::Cancel | QMessageBox::Escape);
        msg->exec();
        delete msg;
        return;
    }

    int rows = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(rows);
    ui->tableWidget->setItem(rows, 0, new QTableWidgetItem(date->toString()));
    ui->tableWidget->setItem(rows, 1, new QTableWidgetItem(date->NextDay().toString()));
    ui->tableWidget->setItem(rows, 2, new QTableWidgetItem(QString("%1").arg(date->Duration(Date()))));
}


void MainWindow::on_saveButton_clicked()
{
    if(file->open(QIODevice::Append))
    {
        QTextStream out(file);
        for(int i = dates_count; i < ui->tableWidget->rowCount(); i++)
        {
            out << ui->tableWidget->item(i, 0)->text() + "\n";
        }
    }
}

