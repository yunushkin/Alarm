#ifndef ALARMREPOSITORY_H
#define ALARMREPOSITORY_H

#include <QVector>
#include "alarmtask.h"

class AlarmRepository
{
public:
    AlarmRepository();
    QVector<AlarmTask> getAll() {
        return alarmTaskList;
    }
    QVector<AlarmTask> match(const QTime &currentTime) {
        QVector<AlarmTask> result;
        foreach (AlarmTask alarmTask, alarmTaskList) {
            QTime begin = alarmTask.getTime();
            QTime end = begin.addMSecs(alarmTask.getDurationMs());
            if (currentTime >= begin  && currentTime <=end) {
                result.push_back(alarmTask);
            }
        }
        return result;
    }
    bool load();
private:
    QVector<AlarmTask> alarmTaskList;
    static const QString jsonFile_;
};

#endif // ALARMREPOSITORY_H
