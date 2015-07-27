#include "alarmtask.h"

AlarmTask::AlarmTask()
{

}

AlarmTask::AlarmTask(const QString &text, const QTime &time, int duration) :
    text_(text), time_(time), duration_(duration)
{
    qDebug()<<text_<<time<<duration_;
}


QDebug& operator <<(QDebug debug,const AlarmTask & alarmTask)
{
    return debug<<alarmTask.getTime().toString()<<alarmTask.getText();
}
