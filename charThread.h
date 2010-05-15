#ifndef CHARTHREAD_H
#define CHARTHREAD_H

#include <QThread>
#include <QLabel>

class charThread : public QThread
{
    private:
        QLabel *label;
        char ch;
        //暫停旗標和停止旗標
        bool isPause, isStop;

    public:
        charThread(QLabel *);
        void run();
        void setPause();
        void setStop();
        void setStart();

};

#endif // CHARTHREAD_H
