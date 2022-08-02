#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    count = 0;
    arr = nullptr;
    file = nullptr;
    filename = "";
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_OpenButton_clicked()
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
        count = 0;
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
        arr = new Employee[count];
        if(file->open(QIODevice::ReadOnly))
        {
            QTextStream in(file);
            int i = 0;
            while(!in.atEnd())
            {
                QString text = in.readLine();
                try{
                arr[i++] = Employee(text);
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

                ui->textEdit->insertPlainText(arr[i-1].toString());
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

}


void MainWindow::on_ExtitButton_clicked()
{
    this->close();
}


void MainWindow::on_SortButton_clicked()
{
    for(int i = 1; i < count; ++i)
        {
            for(int r = 0; r < count-i; r++)
            {
                if(int(arr[r]) < int(arr[r+1]))
                {
                    Employee temp = arr[r];
                    arr[r] = arr[r+1];
                    arr[r+1] = temp;
                }
            }
        }
    ui->textEdit->clear();
    for(int i = 0; i < count; i++)
    {
        ui->textEdit->insertPlainText(arr[i].toString());
    }
}


void MainWindow::on_pushButton_clicked()
{
    ui->textEdit->clear();
    for(int i = 0; i < count; i++)
    {
        ui->textEdit->insertPlainText(arr[i].toString(true));
    }
}


void MainWindow::on_AddButton_clicked()
{
    Employee *arr2 = new Employee[count + 1];
    for(int i = 0; i < count; i++)
    {
        arr2[i] = arr[i];
    }
    try{
    arr2[count] = Employee(QString("%1 %2 %3 %4 %5 %6").arg(ui->fioLine->text()).
                           arg(ui->projectLine->text()).
                           arg(ui->taskLine->text()).
                           arg(ui->deadlineLine->text()).
                           arg(ui->startDateLine->text()).
                           arg(ui->endDateLine->text()));
    }
    catch(std::string ex)
    {
        QMessageBox *msg = new QMessageBox("Error",
                                           ex.c_str(),
                                           QMessageBox::Information,
                                           QMessageBox::Ok,
                                           QMessageBox::NoButton,
                                           QMessageBox::NoButton);
        msg->exec();
        delete msg;
        return;
    }

    if(arr)
        delete[] arr;
    arr = arr2;
    count++;
    ui->textEdit->insertPlainText(arr[count-1].toString());
    if(!file)
    {
        QString filename = QFileDialog::getOpenFileName();
        file = new QFile(filename);
    }
    if(file->open(QIODevice::Append))
    {
        QTextStream out(file);
        out << arr[count - 1].toString();
        file->close();
    }
}


void MainWindow::on_SaveButton_clicked()
{
    if(file->open(QIODevice::WriteOnly))
    {
        QTextStream out(file);
        out << ui->textEdit->toPlainText();
        file->close();
    }
}


void MainWindow::on_SearchButton1_clicked()
{
    ui->textEdit->clear();
    for(int i = 0; i < count; i++)
    {
        bool is_only = true;
        for(int j = 0; j < count; j++)
        {
            if((j != i && arr[i].Task() == arr[j].Task()))
                is_only = false;
        }
        int a = arr[i].StartTime(), b = arr[i].EndTime(), c = int(Date());
        if(is_only && arr[i].StartTime() <= int(Date()) && arr[i].EndTime() >= int(Date()))
            ui->textEdit->insertPlainText(arr[i].Task());
    }
}

