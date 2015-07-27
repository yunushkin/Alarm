#include "alarmrepository.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>


const QString AlarmRepository::jsonFile_ = QString("task.json");
AlarmRepository::AlarmRepository()

{
}

bool AlarmRepository::load()
{
   /*alarmTaskList.push_back(AlarmTask(QString("test1"),QTime(10,00,58),10000));
   alarmTaskList.push_back(AlarmTask(QString("test2"),QTime(11,00,58),10000));
   alarmTaskList.push_back(AlarmTask(QString("test3"),QTime(15,39,58),10000));
   alarmTaskList.push_back(AlarmTask(QString("test4"),QTime(15,40,00),100000));
   alarmTaskList.push_back(AlarmTask(QString("test5"),QTime(15,29,00),100000));*/
    QFile file(jsonFile_);
    if (!file.open(QIODevice::ReadOnly))
        return false;
    QJsonParseError parsError;
    QJsonDocument json = QJsonDocument::fromJson(file.readAll(), &parsError);
    file.close();
    if (parsError.error != QJsonParseError::NoError) {
        qDebug()<<parsError.errorString();
        return false;
    }
    qDebug()<<json.array()<<json.array().size();
    foreach (QJsonValue jsonValue, json.array()) {
        qDebug()<<QTime::fromString(jsonValue.toObject().value("time").toString(), "hh:mm:ss");
        alarmTaskList.push_back(AlarmTask(
                                jsonValue.toObject()["text"].toString(),
                                QTime::fromString(jsonValue.toObject().value("time").toString(), "hh:mm:ss"),
                                jsonValue.toObject()["duration"].toInt() * 1000)
         );
    }
    return true;
}
