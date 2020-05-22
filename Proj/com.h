#ifndef COM_H
#define COM_H

#include <QString>
class com
{
public:
    com();
    static void setStyle(const QString &style);

    static void whiteStyle(void);
    static void blackStyle(void);
    int r = 111;
    int g = 156;
    int b = 207;

    int br = 232;
    int bg = 241;
    int bb = 252;
};

#endif // COM_H
