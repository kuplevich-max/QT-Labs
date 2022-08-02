#include "employee.h"

Employee::Employee()
    :fio(""), project(""), task(""),
      deadline(Date()), startDate(Date()), endDate(Date())
{

}

Employee::Employee(QString f, QString p, QString t, Date d, Date sd, Date ed)
    :fio(f), project(p), task(t), deadline(d), startDate(sd), endDate(ed)
{

}

Employee::Employee(QString data){
    auto list = data.split(' ');
    if(list.size() != 8)
        throw std::string("Invalid value format!");
    fio = QString("%1 %2 %3").arg(data.split(' ')[0]).arg(data.split(' ')[1]).arg(data.split(' ')[2]);
    project = data.split(' ')[3];
    task = data.split(' ')[4];

    try{
    deadline = Date(data.split(' ')[5]);
    }
    catch(std::string ex)
    {
        throw ex;
    }
    try{
    startDate = Date(data.split(' ')[6]);
    }
    catch(std::string ex)
    {
        throw ex;
    }
    try{
    endDate = Date(data.split(' ')[7]);
    }
    catch(std::string ex)
    {
        throw ex;
    }
}

QString Employee::toString(bool duration)
{
    if(!duration)
        return QString("%1 %2 %3 %4 %5 %6\n").arg(fio).arg(project).arg(task).
                arg(deadline.toString()).arg(startDate.toString()).arg(endDate.toString());
    else
    {
        QString s;
        int dur = this->duration();
        switch(dur % 10)
        {
        case 1: s="день";
            break;
        case 2: s = "дня";
            break;
        case 3: s = "дня";
            break;
        case 4: s = "дня";
            break;
        default:
            s = "дней";
            break;
        }

        return QString("%1 %2 %3 %4 %5 %6 %7 %8\n").arg(fio).arg(project).arg(task).
                arg(deadline.toString()).arg(startDate.toString()).arg(endDate.toString()).
                arg(dur).arg(s);
    }
}

Employee::operator int(){
    return int(deadline);
}

int Employee::duration()
{
    return endDate.Duration(startDate);
}

QString Employee::Task()
{
    return task + "\n";
}

int Employee::StartTime()
{
    return int(startDate);
}

int Employee::EndTime()
{
    return int(endDate);
}
