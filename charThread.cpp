#include "charThread.h"

charThread::charThread(QLabel *label)
{
    this->ch = 'A';
    this->isPause = false;
    this->isStop = false;
    this->label = label;
}

void charThread::run()
{
    while(!isStop)
    {
        label->setText(&ch);
        ch++;
        QThread::msleep(100);

        //暫停動作
        while(isPause)
        {
            QThread::msleep(100);
        }
    }
    this->label->setText("Thread stop");
}

void charThread::setStop()
{
    this->isStop = true;
}

void charThread::setStart()
{
    this->ch = 'A';
    this->isPause = false;
    this->isStop = false;
}

void charThread::setPause()
{
    //利用XOR運算
    this->isPause = this->isPause ^ true;
}
