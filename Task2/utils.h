#ifndef UTILS_H
#define UTILS_H
#include <QString>

class Utils
{
public:
    Utils();
    static bool isNumber(QString);
    static bool hasChar(wchar_t*, wchar_t);
    static bool hasChar(QString, char);

};

#endif // UTILS_H
