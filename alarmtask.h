#ifndef ALARMTASK_H
#define ALARMTASK_H

#include <QDateTime>
#include <QString>
#include <QDebug>

class AlarmTask
{
public:
    AlarmTask();
    AlarmTask(const QString &text,const QTime &time, int duration);
    QString getText() const
    {
        return text_;
    }
    QTime getTime() const
    {
        return time_;
    }
    int getDurationMs() const
    {
        return duration_;
    }

private:
    QString text_;
    QTime time_;
    int duration_;
};

QDebug& operator <<(QDebug debug,const AlarmTask & alarmTask);

#endif // ALARMTASK_H
