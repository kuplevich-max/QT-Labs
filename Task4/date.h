#ifndef DATE_H
#define DATE_H
#include <QObject>

class Date
{
private:
    int m_day, m_month, m_year;
    int days();
    Date date(int);
public:
    Date();
    Date(int, int, int);
    Date(QString);
    Date NextDay();
    Date PreviousDay();
    int DaysTillYourBirthDay(Date);
    int Duration(Date);
    QString toString();
    operator int();
};

#endif // DATE_H
