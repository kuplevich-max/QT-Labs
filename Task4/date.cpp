#include "date.h"
#include <QDate>
#include <math.h>
#include <stdexcept>
Date::Date()
    :m_day(QDate::currentDate().day()), m_month(QDate::currentDate().month()),
      m_year(QDate::currentDate().year())
{}

Date::Date(int day, int month, int year)
    :m_day(day), m_month(month), m_year(year)
{}

bool isNumber(QString s)
{
    for(auto c: s)
    {
        if(!c.isDigit())
            return false;
    }
    return true;
}

Date::Date(QString dateString)
{
    if(!dateString.contains('.'))
        throw std::string("Invalid date format!");
    auto list = dateString.split('.');
    if(list.size() != 3)
        throw std::string("Invalid date format!");
    if(list[0].size() != 2 && list[1].size() != 2 && list[2].size() != 4)
        throw std::string("Invalid date format!");
    for(auto item: list)
    {
        if(!isNumber(item))
            throw std::string("Invalid date format!");
    }
    int d, m, y;
    d = dateString.split('.')[0].toInt();
    m = dateString.split('.')[1].toInt();
    y = dateString.split('.')[2].toInt();
    if(m > 12)
        throw std::string("Invalid date!");
    switch (m) {
    case 1:
        if(d > 31)
            throw std::string("Invalid date!");
        break;
    case 2:
        if(y % 4 == 0)
        {
            if(d > 29)
                throw std::string("Invalid date!");
        }
        else
            if(d > 28)
                throw std::string("Invalid date!");
        break;
    case 3:
        if(d > 31)
            throw std::string("Invalid date!");
        break;
    case 4:
        if(d > 30)
            throw std::string("Invalid date!");
        break;
    case 5:
        if(d > 31)
            throw std::string("Invalid date!");
        break;
    case 6:
        if(d > 30)
            throw std::string("Invalid date!");
        break;
    case 7:
        if(d > 31)
            throw std::string("Invalid date!");
        break;
    case 8:
        if(d > 31)
            throw std::string("Invalid date!");
        break;
    case 9:
        if(d > 30)
            throw std::string("Invalid date!");
        break;
    case 10:
        if(d > 31)
            throw std::string("Invalid date!");
        break;
    case 11:
        if(d > 30)
            throw std::string("Invalid date!");
        break;
    case 12:
        if(d > 31)
            throw std::string("Invalid date!");
        break;
    default:
        break;
    }
    m_day = d;
    m_month = m;
    m_year = y;
}

int Date::days(){
    int sum = 0;
    for(int i = 1; i < m_month; i++)
    {
        if(i == 2)
        {
            m_year % 4 == 0?sum += 29 : sum += 28;
        }
        else{
            if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
                sum += 31;
            else
                sum += 30;
        }
    }
    return m_day + sum + int(m_year / 4) * 366 + (m_year - int(m_year/4)) * 365;
}

Date Date::date(int days){
    int year = 0, month = 1, day;
    for(; days > 366; year++)
    {
        if((year + 1) % 4 == 0)
            days -= 366;
        else
            days -= 365;
    }
    for(; days > 31; month++)
    {
        if(month == 2)
        {
            year % 4 == 0?days -= 29 : days -= 28;
        }
        else{
            if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
                days -= 31;
            else days -= 30;
        }
    }
    day = days;
    if(month == 2 && day > 28)
    {
       if(year % 4 == 0 && day > 29)
       {
           day %= 29;
           month += 1;
       }
       else
       {
           day %= 28;
           month += 1;
       }
    }
    if(month > 12)
    {
        month %= 12;
        year += 1;
    }
    return Date(day, month, year);
}

Date Date::NextDay()
{
    return date(this->days() + 1);
}
Date Date::PreviousDay()
{
    return date(this->days() - 1);
}
int Date::DaysTillYourBirthDay(Date birthday)
{
    if(this->days() > birthday.days())
    {
        return this->m_year % 4 == 0? birthday.days() + 366 - this->days() : birthday.days() + 365 - this->days();
    }
    else
    {
        return birthday.days() - this->days();
    }
}
int Date::Duration(Date date)
{
    return abs(date.days() - this->days());
}

QString Date::toString()
{
    QString s1(QString("%1").arg(m_day));
    QString s2(QString("%1").arg(m_month));
    QString s3(QString("%1").arg(m_year));

    QString s(QString("%1.%2.%3").arg(s1, 2, '0').arg(s2, 2, '0').arg(s3, 4, '0'));
    //return QString("%1.%2.%3").arg(m_day).arg(m_month).arg(m_year);
    return s;
}

Date::operator int(){
    return this->days();
}
