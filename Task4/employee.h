#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <QString>
#include "date.h"
class Employee
{
    QString fio;
    QString project;
    QString task;
    Date deadline;
    Date startDate;
    Date endDate;
public:
    Employee();
    Employee(QString, QString, QString, Date, Date, Date);
    Employee(QString);
    operator int();
    QString toString(bool duration = false);
    int duration();
    QString Task();
    int StartTime();
    int EndTime();
};

#endif // EMPLOYEE_H
