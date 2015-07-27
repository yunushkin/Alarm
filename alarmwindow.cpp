#include "alarmwindow.h"
#include "ui_alarmwindow.h"
#include <QDateTime>
#include <QTimer>
#include "alarmrepository.h"
#include <QDebug>

AlarmWindow::AlarmWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AlarmWindow)
{
    ui->setupUi(this);
    alarmRepository_ = new AlarmRepository();
    alarmRepository_->load();
    timer_ = new QTimer(this);
    timer_->setInterval(1000);
    connect(timer_, SIGNAL(timeout()),this, SLOT(onTimeout()));
    timer_->start();
}

AlarmWindow::~AlarmWindow()
{
    delete ui;
}


void AlarmWindow::onTimeout()
{
    QDateTime dt = QDateTime::currentDateTime();

    ui->lbTime->setText("Текущее время:" + dt.toString("hh:mm:ss dd/MM/yyyy"));
    QString lbText = "";
    QVector<AlarmTask> alarmList = alarmRepository_->match(dt.time());
    int taskNumber = 1;
    foreach (AlarmTask task, alarmList) {
        lbText += QString("Задача N%1 :").arg(taskNumber++) + "\n" ;
        lbText += "с "  + task.getTime().toString() + " по " + task.getTime().addMSecs(task.getDurationMs()).toString() + "\n" + task.getText() + +  "\n";
    }
    if (alarmList.empty()) {
        hide();
    } else {
        showMaximized();
        ui->lbTodo->setText(lbText);
//        QApplication::beep();
    }
}
