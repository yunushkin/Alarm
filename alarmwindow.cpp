#include "alarmwindow.h"
#include "ui_alarmwindow.h"
#include "alarmrepository.h"

#include <QDateTime>
#include <QTimer>
#include <QDebug>

const int AlarmWindow::refreshTime = 1000;

AlarmWindow::AlarmWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AlarmWindow)
{

    ui->setupUi(this);
    alarmRepository_ = new AlarmRepository();
    alarmRepository_->load();
    timer_ = new QTimer(this);
    timer_->setInterval(refreshTime);
    connect(timer_, SIGNAL(timeout()),this, SLOT(onTimeout()));
    timer_->start();
}

AlarmWindow::~AlarmWindow()
{
    delete ui;
    delete timer_;
    delete alarmRepository_;
}

void AlarmWindow::onTimeout()
{
    QDateTime dt = QDateTime::currentDateTime();
    ui->lbTime->setText("Текущее время:" + dt.toString("hh:mm:ss dd/MM/yyyy"));
    QString lbText = "";
    QVector<AlarmTask> alarmList = alarmRepository_->match(dt.time());
    int taskNumber = 1;
    foreach (AlarmTask task, alarmList) {
        lbText += QString("Задача N%1 :").arg(taskNumber++) + "\n" +
                        "с "  + task.getTime().toString() +
                        " по " + task.getTime().addMSecs(task.getDurationMs()).toString() + "\n" +
                        task.getText() + +  "\n";
    }
    if (alarmList.empty()) {
        hide();
    } else {
        if (isHidden()) {
            setWindowFlags(Qt::WindowStaysOnTopHint);
            showMaximized();
            activateWindow();
            ui->lbTodo->setText(lbText);
        }
//        QApplication::beep();
    }
}
