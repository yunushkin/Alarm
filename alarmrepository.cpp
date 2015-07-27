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
