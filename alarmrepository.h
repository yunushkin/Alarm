#ifndef ALARMREPOSITORY_H
#define ALARMREPOSITORY_H

#include <QVector>
#include "alarmtask.h"

class AlarmRepository
{
public:
    AlarmRepository();
    QVector<AlarmTask> getAll() const;
    QVector<AlarmTask> match(const QTime &currentTime) const;
    bool load();
private:
    QVector<AlarmTask> alarmTaskList;
    static const QString jsonFile_;
};

#endif // ALARMREPOSITORY_H
