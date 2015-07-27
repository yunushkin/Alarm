#include "alarmwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    AlarmWindow w;
    //w.hide();

    return a.exec();
}
