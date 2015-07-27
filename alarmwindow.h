#ifndef ALARMWINDOW_H
#define ALARMWINDOW_H

#include <QMainWindow>

namespace Ui {
class AlarmWindow;
}

class Timer;
class AlarmRepository;

class AlarmWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AlarmWindow(QWidget *parent = 0);
    ~AlarmWindow();

private:
    Ui::AlarmWindow *ui;
    QTimer* timer_;
    AlarmRepository* alarmRepository_;
private slots:
    void onTimeout();
};

#endif // ALARMWINDOW_H
