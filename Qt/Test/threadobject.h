#ifndef THREADOBJECT_H
#define THREADOBJECT_H
#include <QMutex>
#include <QDebug>
#include <QThread>

enum Gender{female,male};

class ThreadObject : public QObject
{
    Q_OBJECT
protected:
    QMutex* _mutex;
    const int _interval;
    int _count;
    int & _savings;
    Gender _gender;

public:
    ThreadObject(int & saving, QMutex *mutex = nullptr, Gender gender_flag = Gender::male, int sleep_interval = 2000);
public slots:
    void mainMethod();
};

#endif // THREADOBJECT_H
