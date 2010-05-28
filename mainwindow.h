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
#include <QLCDNumber>
#include <QFrame>
#include <QProcess>
#include <QDate>


#include "WidgetKeyboard.h"

#define MainStack       0
#define PhotoStack      1
#define PhotoMutiStack  2
#define PhotoSingleStack  3
#define PicasaStack        4
#define CalendarStack  5
#define ClockStack  6
#define MusicStack  7
#define MusicPlayStack  8
#define MovieStack  9
#define MoviePlayStack  10
#define SettingStack  11

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
    void MusicFinished();
    void MoiveFinished();
    void BrowserFinished();
    void WirelessFinished();
    void Music_Back_Message();
    void MusicInfoUpdate();

private Q_SLOTS:
    void on_Btn_PicasaStop_clicked();
    void on_Btn_ZoomOut_clicked();
    void on_Btn_Wireless_clicked();
    void on_Btn_MusicNext_clicked();
    void on_Btn_MusicBack_clicked();
    void on_Btn_MusicSeekBack_clicked();
    void on_Btn_MusicSeekNext_clicked();
    void on_Btn_MusicPause_clicked();
    void on_Btn_MusicStop_clicked();
    void on_Btn_MusicPlay_clicked();
    void on_ListWidget_MusicFile_itemClicked(QListWidgetItem* item);
    void on_Btn_SettingInMen_Path_clicked();
    void on_Btn_SettingCancel_clicked();
    void on_Btn_SettingOK_clicked();
    void on_Btn_Internet_clicked();
    void on_ListWidget_MovieFile_itemClicked(QListWidgetItem* item);
    void on_Btn_MovieStop_clicked();
    void on_Btn_MoviePlay_clicked();
    void on_Btn_MoviePause_clicked();
    void on_Btn_MovieSeekNext_clicked();
    void on_Btn_MovieSeekBack_clicked();
    void on_Btn_Movie_clicked();
    void on_Btn_Music_clicked();
    void on_Btn_MemCard_clicked();
    void on_Btn_MemStk_clicked();
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
    void ShowPhotoMutiStack(QFileInfoList FileList);
    void SetPhotoSingleBtn(void);
    bool eventFilter(QObject *obj, QEvent *event);
    void ChangeStackPageTo(int StackPage);
    void ChangeStackPageUp(void);
    void CompVisionCtrl(int StackPage);
    QFileInfoList getPhotoListFiles(QString dirPath) const;
    QFileInfoList getMusicListFiles(QString dirPath) const;
    QFileInfoList getMovieListFiles(QString dirPath) const;

private:
    Ui::MainWindow *ui;
    charThread *ct;
    //ClickLabel *Test_CkLab ;
    QFileInfoList fileList_;
    QFileInfoList MusicFileList;
    QFutureWatcher<QImage> *imagesShow_;
    QPixmap pixmap_;
    QTimer *DigiClockTimer;
    QProcess  *MusicProc;
    QProcess  *MovieProc;
    QProcess  *BrowserProc;
    QProcess  *WirelessProc;
    WidgetKeyboard *virtualKeyBoard;
    QTime *MusicTime;
    QTimer *Music_Update_Timer;


private slots:
    void on_Btn_Home_clicked();
    void on_Btn_PageUp_clicked();
    void on_Btn_Photo_clicked();
    void on_Btn_Setting_clicked();
    void on_Btn_Ok_clicked();
    void on_Btn_Test_clicked();
    void ShowDigiClock();
};

QPixmap prepareIcon(const QFileInfo &infoFile);
QImage prepareImage(const QFileInfo &infoFile);

#endif // MAINWINDOW_H
