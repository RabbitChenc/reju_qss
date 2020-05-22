#include "com.h"
#include <QFile>
#include <QApplication>
com::com()
{

}

void com::setStyle(const QString &style)
{
    QFile qss(style);
    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());
    qss.close();
}


void com::whiteStyle(void)
{

     qApp->setStyleSheet("QWidget#MainWindow {"
                         "border: 1px solid rgb(r, g, b);"
                         "background: rgb(232,241,252);"
                         "}"
                         "QPushButton{"
                         "border-image:url(://Image/btn2_normal.png) 10 10 10 10;"
                         "border: 10px transparent;"
                         "}"
                         "QPushButton:pressed{"
                         " border-image:url(://Image/btn2_pressed.png) 10 10 10 10;"
                         "border: 10px transparent;"
                         "}");

}
void com::blackStyle(void)
{

}
