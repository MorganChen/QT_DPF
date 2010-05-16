#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "charThread.h"
//#include "ClickLabel.h"
#include <QFileInfo>
#include <QDir>
#include <QPainter>
#include <QImageReader>
#include <QFutureWatcher>
//#include <qtconcurrentexception.h>
#include <QtCore>
#include <QFuture>
#include <QListWidget>
#include <QEvent>


#define MainStack       0
#define PhotoStack      1
#define PhotoMutiStack  2
#define PhotoSingleStack  3
#define PicasaStack        4
#define CalendarStack  5
#define ClockStack  6

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void ThreadStart();
    void ThreadPause();
    void ThreadStop();

private Q_SLOTS:
    void on_Btn_Picasa_clicked();
    void on_Btn_Alarm_clicked();
    void on_Btn_Cal_clicked();
    void on_Btn_PhotoFull_clicked();
    void on_Btn_InMem_clicked();
    void on_Btn_ZoomIn_clicked();
    void on_Btn_PhotoSinglePage_L_clicked();
    void on_Btn_PhotoSinglePage_R_clicked();
    void on_listWidget_Photo_itemClicked(QListWidgetItem* item);
    void on_Btn_PageLeft_clicked();
    void on_Btn_PageRight_clicked();
    void setItemInList(int index);
    void finished();

protected:
    void changeEvent(QEvent *e);
    void ShowSinglePhoto(QString filePath);
    void SetPhotoSingleBtn(void);
    bool eventFilter(QObject *obj, QEvent *event);
    void ChangeStackPageTo(int StackPage);
    void ChangeStackPageUp(void);
    void CompVisionCtrl(int StackPage);

private:
    Ui::MainWindow *ui;
    charThread *ct;
    //ClickLabel *Test_CkLab ;
    QFileInfoList fileList_;
    QFutureWatcher<QImage> *imagesShow_;
    QPixmap pixmap_;

private slots:
    void on_Btn_Home_clicked();
    void on_Btn_PageUp_clicked();
    void on_Btn_Photo_clicked();
    void on_Btn_Setting_clicked();
    void on_Btn_Ok_clicked();
    void on_Btn_Test_clicked();
    QFileInfoList getListFiles(QString dirPath) const;
};

QPixmap prepareIcon(const QFileInfo &infoFile);
QImage prepareImage(const QFileInfo &infoFile);

#endif // MAINWINDOW_H
