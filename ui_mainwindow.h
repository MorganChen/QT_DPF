/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Tue May 25 23:46:50 2010
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCalendarWidget>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSlider>
#include <QtGui/QStackedWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <QtWebKit/QWebView>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *Btn_Test;
    QPushButton *Btn_Ok;
    QPushButton *Btn_Home;
    QPushButton *Btn_PhotoFull;
    QPushButton *Btn_PageUp;
    QLabel *label_ThreadInfo;
    QStackedWidget *stackedWidget;
    QWidget *MainPage;
    QWidget *Mainwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *VLay_Photo;
    QPushButton *Btn_Photo;
    QLabel *lab_Photo;
    QVBoxLayout *VLay_Music;
    QPushButton *Btn_Music;
    QLabel *lab_Music;
    QVBoxLayout *VLay_Movie;
    QPushButton *Btn_Movie;
    QLabel *Lab_Movie;
    QVBoxLayout *VLay_Cal;
    QPushButton *Btn_Cal;
    QLabel *lab_Cal;
    QVBoxLayout *VLay_Alarm;
    QPushButton *Btn_Alarm;
    QLabel *lab_Alarm;
    QVBoxLayout *VLay_Internet;
    QPushButton *Btn_Internet;
    QLabel *Lab_Internet;
    QVBoxLayout *VLay_Wireless;
    QPushButton *Btn_Wireless;
    QLabel *Lab_Wireless;
    QVBoxLayout *VLay_Setting;
    QPushButton *Btn_Setting;
    QLabel *Lab_Setting;
    QWidget *PhotoPage;
    QWidget *Photowidget;
    QLabel *Lab_SubPhoto;
    QPushButton *Btn_MemStk;
    QPushButton *Btn_MemCard;
    QPushButton *Btn_Picasa;
    QPushButton *Btn_InMem;
    QWidget *PhotoMutiPage;
    QListWidget *listWidget_Photo;
    QPushButton *Btn_PageRight;
    QPushButton *Btn_PageLeft;
    QWidget *PhotoSinglePage;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *Lab_PhotoSingle;
    QPushButton *Btn_PhotoSinglePage_L;
    QPushButton *Btn_PhotoSinglePage_R;
    QWidget *PicasaPage;
    QWebView *webView;
    QPushButton *Btn_ZoomIn;
    QPushButton *Btn_ZoomOut;
    QWidget *CalenderPage;
    QCalendarWidget *calendarWidget;
    QWidget *ClockPage;
    QLCDNumber *LcdNum_DigiClock;
    QWidget *MusicPage;
    QLabel *Lab_Music;
    QListWidget *ListWidget_MusicFile;
    QWidget *MusicPlayPage;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QPushButton *Btn_MusicSeekBack;
    QPushButton *Btn_MusicPause;
    QPushButton *Btn_MusicStop;
    QPushButton *Btn_MusicPlay;
    QPushButton *Btn_MusicSeekNext;
    QPushButton *Btn_MusicBack;
    QPushButton *Btn_MusicNext;
    QProgressBar *ProBar_MusicPro;
    QLabel *Lab_MusicTitle;
    QLCDNumber *LcdNum_MusicTime;
    QLabel *label_2;
    QWidget *MoviePage;
    QLabel *Lab_MoviePage;
    QListWidget *ListWidget_MovieFile;
    QWidget *MoviePlayPage;
    QWidget *MoviePlayBtnWidget;
    QGridLayout *gridLayout1;
    QPushButton *Btn_MovieSeekBack;
    QPushButton *Btn_MovieStop;
    QPushButton *Btn_MoviePause;
    QPushButton *Btn_MoviePlay;
    QPushButton *Btn_MovieSeekNext;
    QLabel *Lab_MoviePlay;
    QWidget *MoviePlayWidget;
    QWidget *SettingPage;
    QLabel *Lab_SettingPage;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *Lab_SettingSliceShowTimer;
    QComboBox *CbBox_SettingSSTimer;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *LEdit_SettingInMen_Path;
    QPushButton *Btn_SettingInMen_Path;
    QPushButton *Btn_SettingOK;
    QPushButton *Btn_SettingCancel;
    QSlider *Bar_VolAdj;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->setEnabled(true);
        MainWindow->resize(800, 480);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QPalette palette;
        QBrush brush(QColor(220, 218, 213, 150));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush2(QColor(220, 218, 213, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        MainWindow->setPalette(palette);
        MainWindow->setWindowTitle(QString::fromUtf8(""));
        MainWindow->setAutoFillBackground(false);
        MainWindow->setIconSize(QSize(57, 59));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Btn_Test = new QPushButton(centralWidget);
        Btn_Test->setObjectName(QString::fromUtf8("Btn_Test"));
        Btn_Test->setGeometry(QRect(120, 10, 91, 27));
        Btn_Ok = new QPushButton(centralWidget);
        Btn_Ok->setObjectName(QString::fromUtf8("Btn_Ok"));
        Btn_Ok->setGeometry(QRect(250, 10, 91, 27));
        Btn_Home = new QPushButton(centralWidget);
        Btn_Home->setObjectName(QString::fromUtf8("Btn_Home"));
        Btn_Home->setGeometry(QRect(0, 0, 60, 60));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/actions/icon/lincity-ng.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Home->setIcon(icon);
        Btn_Home->setIconSize(QSize(60, 60));
        Btn_Home->setFlat(true);
        Btn_PhotoFull = new QPushButton(centralWidget);
        Btn_PhotoFull->setObjectName(QString::fromUtf8("Btn_PhotoFull"));
        Btn_PhotoFull->setGeometry(QRect(372, 0, 60, 60));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/actions/icon/go-next.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_PhotoFull->setIcon(icon1);
        Btn_PhotoFull->setIconSize(QSize(60, 60));
        Btn_PhotoFull->setFlat(true);
        Btn_PageUp = new QPushButton(centralWidget);
        Btn_PageUp->setObjectName(QString::fromUtf8("Btn_PageUp"));
        Btn_PageUp->setGeometry(QRect(740, 0, 60, 60));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/actions/icon/edit-undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_PageUp->setIcon(icon2);
        Btn_PageUp->setIconSize(QSize(60, 60));
        Btn_PageUp->setFlat(true);
        label_ThreadInfo = new QLabel(centralWidget);
        label_ThreadInfo->setObjectName(QString::fromUtf8("label_ThreadInfo"));
        label_ThreadInfo->setGeometry(QRect(440, 10, 281, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("AR PL Mingti2L Big5"));
        font.setPointSize(11);
        label_ThreadInfo->setFont(font);
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 60, 800, 420));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Button, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        stackedWidget->setPalette(palette1);
        stackedWidget->setAutoFillBackground(true);
        MainPage = new QWidget();
        MainPage->setObjectName(QString::fromUtf8("MainPage"));
        Mainwidget = new QWidget(MainPage);
        Mainwidget->setObjectName(QString::fromUtf8("Mainwidget"));
        Mainwidget->setEnabled(true);
        Mainwidget->setGeometry(QRect(20, 0, 700, 360));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Mainwidget->sizePolicy().hasHeightForWidth());
        Mainwidget->setSizePolicy(sizePolicy1);
        gridLayout = new QGridLayout(Mainwidget);
        gridLayout->setSpacing(6);
        gridLayout->setMargin(11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetFixedSize);
        gridLayout->setHorizontalSpacing(45);
        gridLayout->setVerticalSpacing(35);
        VLay_Photo = new QVBoxLayout();
        VLay_Photo->setSpacing(0);
        VLay_Photo->setObjectName(QString::fromUtf8("VLay_Photo"));
        VLay_Photo->setSizeConstraint(QLayout::SetMinimumSize);
        VLay_Photo->setContentsMargins(0, -1, -1, -1);
        Btn_Photo = new QPushButton(Mainwidget);
        Btn_Photo->setObjectName(QString::fromUtf8("Btn_Photo"));
        Btn_Photo->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Btn_Photo->sizePolicy().hasHeightForWidth());
        Btn_Photo->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        font1.setStrikeOut(false);
        font1.setKerning(false);
        font1.setStyleStrategy(QFont::PreferAntialias);
        Btn_Photo->setFont(font1);
        Btn_Photo->setFocusPolicy(Qt::StrongFocus);
        Btn_Photo->setContextMenuPolicy(Qt::NoContextMenu);
        Btn_Photo->setAcceptDrops(false);
        Btn_Photo->setLayoutDirection(Qt::RightToLeft);
        Btn_Photo->setAutoFillBackground(true);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/apps/icon/f-spot.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Photo->setIcon(icon3);
        Btn_Photo->setIconSize(QSize(128, 128));
        Btn_Photo->setFlat(true);

        VLay_Photo->addWidget(Btn_Photo);

        lab_Photo = new QLabel(Mainwidget);
        lab_Photo->setObjectName(QString::fromUtf8("lab_Photo"));
        lab_Photo->setAlignment(Qt::AlignCenter);

        VLay_Photo->addWidget(lab_Photo);


        gridLayout->addLayout(VLay_Photo, 0, 0, 1, 1);

        VLay_Music = new QVBoxLayout();
        VLay_Music->setSpacing(0);
        VLay_Music->setObjectName(QString::fromUtf8("VLay_Music"));
        Btn_Music = new QPushButton(Mainwidget);
        Btn_Music->setObjectName(QString::fromUtf8("Btn_Music"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/apps/icon/audacious.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Music->setIcon(icon4);
        Btn_Music->setIconSize(QSize(128, 128));
        Btn_Music->setFlat(true);

        VLay_Music->addWidget(Btn_Music);

        lab_Music = new QLabel(Mainwidget);
        lab_Music->setObjectName(QString::fromUtf8("lab_Music"));
        lab_Music->setAlignment(Qt::AlignCenter);

        VLay_Music->addWidget(lab_Music);


        gridLayout->addLayout(VLay_Music, 0, 1, 1, 1);

        VLay_Movie = new QVBoxLayout();
        VLay_Movie->setSpacing(0);
        VLay_Movie->setObjectName(QString::fromUtf8("VLay_Movie"));
        Btn_Movie = new QPushButton(Mainwidget);
        Btn_Movie->setObjectName(QString::fromUtf8("Btn_Movie"));
        Btn_Movie->setEnabled(true);
        Btn_Movie->setBaseSize(QSize(0, 0));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/apps/icon/mplayer.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Movie->setIcon(icon5);
        Btn_Movie->setIconSize(QSize(128, 128));
        Btn_Movie->setFlat(true);

        VLay_Movie->addWidget(Btn_Movie);

        Lab_Movie = new QLabel(Mainwidget);
        Lab_Movie->setObjectName(QString::fromUtf8("Lab_Movie"));
        Lab_Movie->setAlignment(Qt::AlignCenter);

        VLay_Movie->addWidget(Lab_Movie);


        gridLayout->addLayout(VLay_Movie, 0, 2, 1, 1);

        VLay_Cal = new QVBoxLayout();
        VLay_Cal->setSpacing(0);
        VLay_Cal->setObjectName(QString::fromUtf8("VLay_Cal"));
        Btn_Cal = new QPushButton(Mainwidget);
        Btn_Cal->setObjectName(QString::fromUtf8("Btn_Cal"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/apps/icon/dates.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Cal->setIcon(icon6);
        Btn_Cal->setIconSize(QSize(128, 128));
        Btn_Cal->setAutoDefault(true);
        Btn_Cal->setFlat(true);

        VLay_Cal->addWidget(Btn_Cal);

        lab_Cal = new QLabel(Mainwidget);
        lab_Cal->setObjectName(QString::fromUtf8("lab_Cal"));
        lab_Cal->setAlignment(Qt::AlignCenter);

        VLay_Cal->addWidget(lab_Cal);


        gridLayout->addLayout(VLay_Cal, 0, 3, 1, 1);

        VLay_Alarm = new QVBoxLayout();
        VLay_Alarm->setSpacing(0);
        VLay_Alarm->setObjectName(QString::fromUtf8("VLay_Alarm"));
        Btn_Alarm = new QPushButton(Mainwidget);
        Btn_Alarm->setObjectName(QString::fromUtf8("Btn_Alarm"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/apps/icon/clock.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Alarm->setIcon(icon7);
        Btn_Alarm->setIconSize(QSize(128, 128));
        Btn_Alarm->setFlat(true);

        VLay_Alarm->addWidget(Btn_Alarm);

        lab_Alarm = new QLabel(Mainwidget);
        lab_Alarm->setObjectName(QString::fromUtf8("lab_Alarm"));
        lab_Alarm->setAlignment(Qt::AlignCenter);

        VLay_Alarm->addWidget(lab_Alarm);


        gridLayout->addLayout(VLay_Alarm, 1, 0, 1, 1);

        VLay_Internet = new QVBoxLayout();
        VLay_Internet->setSpacing(0);
        VLay_Internet->setObjectName(QString::fromUtf8("VLay_Internet"));
        Btn_Internet = new QPushButton(Mainwidget);
        Btn_Internet->setObjectName(QString::fromUtf8("Btn_Internet"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/apps/icon/web-browser.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Internet->setIcon(icon8);
        Btn_Internet->setIconSize(QSize(128, 128));
        Btn_Internet->setFlat(true);

        VLay_Internet->addWidget(Btn_Internet);

        Lab_Internet = new QLabel(Mainwidget);
        Lab_Internet->setObjectName(QString::fromUtf8("Lab_Internet"));
        Lab_Internet->setAlignment(Qt::AlignCenter);

        VLay_Internet->addWidget(Lab_Internet);


        gridLayout->addLayout(VLay_Internet, 1, 1, 1, 1);

        VLay_Wireless = new QVBoxLayout();
        VLay_Wireless->setSpacing(0);
        VLay_Wireless->setObjectName(QString::fromUtf8("VLay_Wireless"));
        Btn_Wireless = new QPushButton(Mainwidget);
        Btn_Wireless->setObjectName(QString::fromUtf8("Btn_Wireless"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/apps/icon/network-wireless.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Wireless->setIcon(icon9);
        Btn_Wireless->setIconSize(QSize(128, 128));
        Btn_Wireless->setFlat(true);

        VLay_Wireless->addWidget(Btn_Wireless);

        Lab_Wireless = new QLabel(Mainwidget);
        Lab_Wireless->setObjectName(QString::fromUtf8("Lab_Wireless"));
        Lab_Wireless->setAlignment(Qt::AlignCenter);

        VLay_Wireless->addWidget(Lab_Wireless);


        gridLayout->addLayout(VLay_Wireless, 1, 2, 1, 1);

        VLay_Setting = new QVBoxLayout();
        VLay_Setting->setSpacing(0);
        VLay_Setting->setObjectName(QString::fromUtf8("VLay_Setting"));
        Btn_Setting = new QPushButton(Mainwidget);
        Btn_Setting->setObjectName(QString::fromUtf8("Btn_Setting"));
        Btn_Setting->setAutoFillBackground(false);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/apps/icon/gkdebconf.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Setting->setIcon(icon10);
        Btn_Setting->setIconSize(QSize(128, 128));
        Btn_Setting->setCheckable(false);
        Btn_Setting->setChecked(false);
        Btn_Setting->setAutoDefault(false);
        Btn_Setting->setDefault(false);
        Btn_Setting->setFlat(true);

        VLay_Setting->addWidget(Btn_Setting);

        Lab_Setting = new QLabel(Mainwidget);
        Lab_Setting->setObjectName(QString::fromUtf8("Lab_Setting"));
        Lab_Setting->setAlignment(Qt::AlignCenter);

        VLay_Setting->addWidget(Lab_Setting);


        gridLayout->addLayout(VLay_Setting, 1, 3, 1, 1);

        stackedWidget->addWidget(MainPage);
        PhotoPage = new QWidget();
        PhotoPage->setObjectName(QString::fromUtf8("PhotoPage"));
        Photowidget = new QWidget(PhotoPage);
        Photowidget->setObjectName(QString::fromUtf8("Photowidget"));
        Photowidget->setGeometry(QRect(80, 30, 641, 301));
        Lab_SubPhoto = new QLabel(Photowidget);
        Lab_SubPhoto->setObjectName(QString::fromUtf8("Lab_SubPhoto"));
        Lab_SubPhoto->setGeometry(QRect(30, 20, 128, 128));
        Lab_SubPhoto->setPixmap(QPixmap(QString::fromUtf8(":/apps/icon/f-spot.png")));
        Btn_MemStk = new QPushButton(Photowidget);
        Btn_MemStk->setObjectName(QString::fromUtf8("Btn_MemStk"));
        Btn_MemStk->setGeometry(QRect(260, 80, 240, 70));
        QFont font2;
        font2.setPointSize(16);
        Btn_MemStk->setFont(font2);
        Btn_MemCard = new QPushButton(Photowidget);
        Btn_MemCard->setObjectName(QString::fromUtf8("Btn_MemCard"));
        Btn_MemCard->setGeometry(QRect(260, 150, 240, 70));
        Btn_MemCard->setFont(font2);
        Btn_Picasa = new QPushButton(Photowidget);
        Btn_Picasa->setObjectName(QString::fromUtf8("Btn_Picasa"));
        Btn_Picasa->setGeometry(QRect(260, 220, 240, 70));
        Btn_Picasa->setFont(font2);
        Btn_InMem = new QPushButton(Photowidget);
        Btn_InMem->setObjectName(QString::fromUtf8("Btn_InMem"));
        Btn_InMem->setGeometry(QRect(260, 10, 240, 70));
        sizePolicy.setHeightForWidth(Btn_InMem->sizePolicy().hasHeightForWidth());
        Btn_InMem->setSizePolicy(sizePolicy);
        Btn_InMem->setFont(font2);
        Btn_InMem->setIconSize(QSize(60, 60));
        stackedWidget->addWidget(PhotoPage);
        PhotoMutiPage = new QWidget();
        PhotoMutiPage->setObjectName(QString::fromUtf8("PhotoMutiPage"));
        listWidget_Photo = new QListWidget(PhotoMutiPage);
        listWidget_Photo->setObjectName(QString::fromUtf8("listWidget_Photo"));
        listWidget_Photo->setEnabled(true);
        listWidget_Photo->setGeometry(QRect(60, 10, 670, 331));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        listWidget_Photo->setPalette(palette2);
        listWidget_Photo->setAutoFillBackground(true);
        listWidget_Photo->setFrameShape(QFrame::NoFrame);
        listWidget_Photo->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget_Photo->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget_Photo->setAutoScroll(true);
        listWidget_Photo->setAutoScrollMargin(3);
        listWidget_Photo->setIconSize(QSize(190, 130));
        listWidget_Photo->setTextElideMode(Qt::ElideRight);
        listWidget_Photo->setMovement(QListView::Static);
        listWidget_Photo->setFlow(QListView::LeftToRight);
        listWidget_Photo->setProperty("isWrapping", QVariant(true));
        listWidget_Photo->setSpacing(10);
        listWidget_Photo->setGridSize(QSize(220, 180));
        listWidget_Photo->setViewMode(QListView::IconMode);
        listWidget_Photo->setModelColumn(0);
        listWidget_Photo->setUniformItemSizes(false);
        Btn_PageRight = new QPushButton(PhotoMutiPage);
        Btn_PageRight->setObjectName(QString::fromUtf8("Btn_PageRight"));
        Btn_PageRight->setGeometry(QRect(740, 140, 60, 60));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/actions/icon/go-last.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_PageRight->setIcon(icon11);
        Btn_PageRight->setIconSize(QSize(60, 60));
        Btn_PageRight->setFlat(true);
        Btn_PageLeft = new QPushButton(PhotoMutiPage);
        Btn_PageLeft->setObjectName(QString::fromUtf8("Btn_PageLeft"));
        Btn_PageLeft->setGeometry(QRect(0, 140, 60, 60));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/actions/icon/go-first.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_PageLeft->setIcon(icon12);
        Btn_PageLeft->setIconSize(QSize(57, 59));
        Btn_PageLeft->setFlat(true);
        stackedWidget->addWidget(PhotoMutiPage);
        PhotoSinglePage = new QWidget();
        PhotoSinglePage->setObjectName(QString::fromUtf8("PhotoSinglePage"));
        scrollArea = new QScrollArea(PhotoSinglePage);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(60, 24, 681, 341));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        scrollArea->setPalette(palette3);
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 681, 341));
        Lab_PhotoSingle = new QLabel(scrollAreaWidgetContents);
        Lab_PhotoSingle->setObjectName(QString::fromUtf8("Lab_PhotoSingle"));
        Lab_PhotoSingle->setGeometry(QRect(-1, 15, 661, 321));
        sizePolicy.setHeightForWidth(Lab_PhotoSingle->sizePolicy().hasHeightForWidth());
        Lab_PhotoSingle->setSizePolicy(sizePolicy);
        QPalette palette4;
        QBrush brush3(QColor(87, 255, 163, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        Lab_PhotoSingle->setPalette(palette4);
        QFont font3;
        font3.setItalic(false);
        Lab_PhotoSingle->setFont(font3);
        Lab_PhotoSingle->setAutoFillBackground(true);
        Lab_PhotoSingle->setScaledContents(false);
        Lab_PhotoSingle->setAlignment(Qt::AlignCenter);
        scrollArea->setWidget(scrollAreaWidgetContents);
        Btn_PhotoSinglePage_L = new QPushButton(PhotoSinglePage);
        Btn_PhotoSinglePage_L->setObjectName(QString::fromUtf8("Btn_PhotoSinglePage_L"));
        Btn_PhotoSinglePage_L->setGeometry(QRect(0, 140, 57, 59));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/actions/icon/go-previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_PhotoSinglePage_L->setIcon(icon13);
        Btn_PhotoSinglePage_L->setIconSize(QSize(57, 59));
        Btn_PhotoSinglePage_L->setFlat(true);
        Btn_PhotoSinglePage_R = new QPushButton(PhotoSinglePage);
        Btn_PhotoSinglePage_R->setObjectName(QString::fromUtf8("Btn_PhotoSinglePage_R"));
        Btn_PhotoSinglePage_R->setGeometry(QRect(743, 140, 57, 59));
        Btn_PhotoSinglePage_R->setIcon(icon1);
        Btn_PhotoSinglePage_R->setIconSize(QSize(57, 59));
        Btn_PhotoSinglePage_R->setFlat(true);
        stackedWidget->addWidget(PhotoSinglePage);
        PicasaPage = new QWidget();
        PicasaPage->setObjectName(QString::fromUtf8("PicasaPage"));
        webView = new QWebView(PicasaPage);
        webView->setObjectName(QString::fromUtf8("webView"));
        webView->setGeometry(QRect(0, 0, 740, 420));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        webView->setPalette(palette5);
        webView->setUrl(QUrl("http://picasaweb.google.com/elandman.chuang"));
        webView->setZoomFactor(0.6);
        Btn_ZoomIn = new QPushButton(PicasaPage);
        Btn_ZoomIn->setObjectName(QString::fromUtf8("Btn_ZoomIn"));
        Btn_ZoomIn->setGeometry(QRect(740, 360, 60, 60));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/actions/icon/zoom-fit-page.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_ZoomIn->setIcon(icon14);
        Btn_ZoomIn->setIconSize(QSize(60, 60));
        Btn_ZoomIn->setFlat(true);
        Btn_ZoomOut = new QPushButton(PicasaPage);
        Btn_ZoomOut->setObjectName(QString::fromUtf8("Btn_ZoomOut"));
        Btn_ZoomOut->setGeometry(QRect(740, 290, 60, 60));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/actions/icon/zoom-fit-width.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_ZoomOut->setIcon(icon15);
        Btn_ZoomOut->setIconSize(QSize(60, 60));
        Btn_ZoomOut->setFlat(true);
        stackedWidget->addWidget(PicasaPage);
        CalenderPage = new QWidget();
        CalenderPage->setObjectName(QString::fromUtf8("CalenderPage"));
        calendarWidget = new QCalendarWidget(CalenderPage);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(0, 0, 800, 360));
        calendarWidget->setGridVisible(true);
        calendarWidget->setHorizontalHeaderFormat(QCalendarWidget::LongDayNames);
        calendarWidget->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
        calendarWidget->setNavigationBarVisible(true);
        calendarWidget->setDateEditEnabled(true);
        stackedWidget->addWidget(CalenderPage);
        ClockPage = new QWidget();
        ClockPage->setObjectName(QString::fromUtf8("ClockPage"));
        LcdNum_DigiClock = new QLCDNumber(ClockPage);
        LcdNum_DigiClock->setObjectName(QString::fromUtf8("LcdNum_DigiClock"));
        LcdNum_DigiClock->setGeometry(QRect(30, 80, 740, 200));
        QPalette palette6;
        QBrush brush4(QColor(75, 107, 173, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        LcdNum_DigiClock->setPalette(palette6);
        QFont font4;
        font4.setBold(false);
        font4.setWeight(50);
        LcdNum_DigiClock->setFont(font4);
        LcdNum_DigiClock->setAutoFillBackground(false);
        LcdNum_DigiClock->setFrameShape(QFrame::Box);
        LcdNum_DigiClock->setFrameShadow(QFrame::Raised);
        LcdNum_DigiClock->setLineWidth(2);
        LcdNum_DigiClock->setMidLineWidth(0);
        LcdNum_DigiClock->setSmallDecimalPoint(false);
        LcdNum_DigiClock->setNumDigits(8);
        LcdNum_DigiClock->setSegmentStyle(QLCDNumber::Filled);
        LcdNum_DigiClock->setProperty("value", QVariant(0));
        stackedWidget->addWidget(ClockPage);
        MusicPage = new QWidget();
        MusicPage->setObjectName(QString::fromUtf8("MusicPage"));
        Lab_Music = new QLabel(MusicPage);
        Lab_Music->setObjectName(QString::fromUtf8("Lab_Music"));
        Lab_Music->setGeometry(QRect(40, 20, 128, 128));
        Lab_Music->setPixmap(QPixmap(QString::fromUtf8(":/apps/icon/audacious.png")));
        ListWidget_MusicFile = new QListWidget(MusicPage);
        ListWidget_MusicFile->setObjectName(QString::fromUtf8("ListWidget_MusicFile"));
        ListWidget_MusicFile->setGeometry(QRect(200, 20, 551, 371));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        ListWidget_MusicFile->setPalette(palette7);
        QFont font5;
        font5.setPointSize(20);
        ListWidget_MusicFile->setFont(font5);
        ListWidget_MusicFile->setFrameShape(QFrame::Box);
        ListWidget_MusicFile->setFrameShadow(QFrame::Raised);
        ListWidget_MusicFile->setLineWidth(5);
        ListWidget_MusicFile->setAutoScrollMargin(16);
        stackedWidget->addWidget(MusicPage);
        MusicPlayPage = new QWidget();
        MusicPlayPage->setObjectName(QString::fromUtf8("MusicPlayPage"));
        widget = new QWidget(MusicPlayPage);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(140, 300, 491, 91));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setMargin(11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(2);
        Btn_MusicSeekBack = new QPushButton(widget);
        Btn_MusicSeekBack->setObjectName(QString::fromUtf8("Btn_MusicSeekBack"));
        Btn_MusicSeekBack->setIcon(icon12);
        Btn_MusicSeekBack->setIconSize(QSize(60, 60));
        Btn_MusicSeekBack->setAutoRepeat(true);
        Btn_MusicSeekBack->setFlat(true);

        gridLayout_2->addWidget(Btn_MusicSeekBack, 0, 1, 1, 1);

        Btn_MusicPause = new QPushButton(widget);
        Btn_MusicPause->setObjectName(QString::fromUtf8("Btn_MusicPause"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/actions/icon/media-playback-pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_MusicPause->setIcon(icon16);
        Btn_MusicPause->setIconSize(QSize(60, 60));
        Btn_MusicPause->setFlat(true);

        gridLayout_2->addWidget(Btn_MusicPause, 0, 2, 1, 1);

        Btn_MusicStop = new QPushButton(widget);
        Btn_MusicStop->setObjectName(QString::fromUtf8("Btn_MusicStop"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/actions/icon/media-playback-stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_MusicStop->setIcon(icon17);
        Btn_MusicStop->setIconSize(QSize(60, 60));
        Btn_MusicStop->setFlat(true);

        gridLayout_2->addWidget(Btn_MusicStop, 0, 3, 1, 1);

        Btn_MusicPlay = new QPushButton(widget);
        Btn_MusicPlay->setObjectName(QString::fromUtf8("Btn_MusicPlay"));
        Btn_MusicPlay->setIcon(icon1);
        Btn_MusicPlay->setIconSize(QSize(60, 60));
        Btn_MusicPlay->setFlat(true);

        gridLayout_2->addWidget(Btn_MusicPlay, 0, 4, 1, 1);

        Btn_MusicSeekNext = new QPushButton(widget);
        Btn_MusicSeekNext->setObjectName(QString::fromUtf8("Btn_MusicSeekNext"));
        Btn_MusicSeekNext->setIcon(icon11);
        Btn_MusicSeekNext->setIconSize(QSize(60, 60));
        Btn_MusicSeekNext->setAutoRepeat(true);
        Btn_MusicSeekNext->setFlat(true);

        gridLayout_2->addWidget(Btn_MusicSeekNext, 0, 5, 1, 1);

        Btn_MusicBack = new QPushButton(widget);
        Btn_MusicBack->setObjectName(QString::fromUtf8("Btn_MusicBack"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/actions/icon/media-seek-forward2.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_MusicBack->setIcon(icon18);
        Btn_MusicBack->setIconSize(QSize(60, 60));
        Btn_MusicBack->setFlat(true);

        gridLayout_2->addWidget(Btn_MusicBack, 0, 0, 1, 1);

        Btn_MusicNext = new QPushButton(widget);
        Btn_MusicNext->setObjectName(QString::fromUtf8("Btn_MusicNext"));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/actions/icon/media-seek-forward1.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_MusicNext->setIcon(icon19);
        Btn_MusicNext->setIconSize(QSize(60, 60));
        Btn_MusicNext->setFlat(true);

        gridLayout_2->addWidget(Btn_MusicNext, 0, 6, 1, 1);

        ProBar_MusicPro = new QProgressBar(MusicPlayPage);
        ProBar_MusicPro->setObjectName(QString::fromUtf8("ProBar_MusicPro"));
        ProBar_MusicPro->setGeometry(QRect(150, 270, 481, 16));
        ProBar_MusicPro->setValue(24);
        ProBar_MusicPro->setTextVisible(false);
        Lab_MusicTitle = new QLabel(MusicPlayPage);
        Lab_MusicTitle->setObjectName(QString::fromUtf8("Lab_MusicTitle"));
        Lab_MusicTitle->setGeometry(QRect(240, 90, 491, 81));
        Lab_MusicTitle->setFont(font5);
        Lab_MusicTitle->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        LcdNum_MusicTime = new QLCDNumber(MusicPlayPage);
        LcdNum_MusicTime->setObjectName(QString::fromUtf8("LcdNum_MusicTime"));
        LcdNum_MusicTime->setEnabled(true);
        LcdNum_MusicTime->setGeometry(QRect(240, 180, 281, 81));
        QFont font6;
        font6.setPointSize(10);
        font6.setBold(false);
        font6.setItalic(false);
        font6.setWeight(50);
        LcdNum_MusicTime->setFont(font6);
        LcdNum_MusicTime->setSmallDecimalPoint(false);
        label_2 = new QLabel(MusicPlayPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 50, 151, 141));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/apps/icon/audacious.png")));
        stackedWidget->addWidget(MusicPlayPage);
        MoviePage = new QWidget();
        MoviePage->setObjectName(QString::fromUtf8("MoviePage"));
        Lab_MoviePage = new QLabel(MoviePage);
        Lab_MoviePage->setObjectName(QString::fromUtf8("Lab_MoviePage"));
        Lab_MoviePage->setGeometry(QRect(50, 20, 128, 128));
        Lab_MoviePage->setPixmap(QPixmap(QString::fromUtf8(":/apps/icon/mplayer.png")));
        ListWidget_MovieFile = new QListWidget(MoviePage);
        ListWidget_MovieFile->setObjectName(QString::fromUtf8("ListWidget_MovieFile"));
        ListWidget_MovieFile->setGeometry(QRect(200, 20, 561, 361));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        ListWidget_MovieFile->setPalette(palette8);
        ListWidget_MovieFile->setFont(font5);
        ListWidget_MovieFile->setFrameShape(QFrame::Box);
        ListWidget_MovieFile->setFrameShadow(QFrame::Raised);
        ListWidget_MovieFile->setLineWidth(5);
        ListWidget_MovieFile->setIconSize(QSize(20, 20));
        ListWidget_MovieFile->setViewMode(QListView::ListMode);
        ListWidget_MovieFile->setModelColumn(0);
        stackedWidget->addWidget(MoviePage);
        MoviePlayPage = new QWidget();
        MoviePlayPage->setObjectName(QString::fromUtf8("MoviePlayPage"));
        MoviePlayBtnWidget = new QWidget(MoviePlayPage);
        MoviePlayBtnWidget->setObjectName(QString::fromUtf8("MoviePlayBtnWidget"));
        MoviePlayBtnWidget->setGeometry(QRect(160, 270, 491, 91));
        QPalette palette9;
        QBrush brush5(QColor(8, 231, 255, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        MoviePlayBtnWidget->setPalette(palette9);
        gridLayout1 = new QGridLayout(MoviePlayBtnWidget);
        gridLayout1->setSpacing(6);
        gridLayout1->setMargin(11);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        gridLayout1->setHorizontalSpacing(0);
        Btn_MovieSeekBack = new QPushButton(MoviePlayBtnWidget);
        Btn_MovieSeekBack->setObjectName(QString::fromUtf8("Btn_MovieSeekBack"));
        Btn_MovieSeekBack->setIcon(icon12);
        Btn_MovieSeekBack->setIconSize(QSize(60, 60));
        Btn_MovieSeekBack->setAutoRepeat(true);
        Btn_MovieSeekBack->setFlat(true);

        gridLayout1->addWidget(Btn_MovieSeekBack, 2, 1, 1, 1);

        Btn_MovieStop = new QPushButton(MoviePlayBtnWidget);
        Btn_MovieStop->setObjectName(QString::fromUtf8("Btn_MovieStop"));
        Btn_MovieStop->setIcon(icon17);
        Btn_MovieStop->setIconSize(QSize(60, 60));
        Btn_MovieStop->setFlat(true);

        gridLayout1->addWidget(Btn_MovieStop, 2, 2, 1, 1);

        Btn_MoviePause = new QPushButton(MoviePlayBtnWidget);
        Btn_MoviePause->setObjectName(QString::fromUtf8("Btn_MoviePause"));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::Button, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush);
        Btn_MoviePause->setPalette(palette10);
        Btn_MoviePause->setIcon(icon16);
        Btn_MoviePause->setIconSize(QSize(60, 60));
        Btn_MoviePause->setFlat(true);

        gridLayout1->addWidget(Btn_MoviePause, 2, 3, 1, 1);

        Btn_MoviePlay = new QPushButton(MoviePlayBtnWidget);
        Btn_MoviePlay->setObjectName(QString::fromUtf8("Btn_MoviePlay"));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        Btn_MoviePlay->setPalette(palette11);
        Btn_MoviePlay->setIcon(icon1);
        Btn_MoviePlay->setIconSize(QSize(60, 60));
        Btn_MoviePlay->setFlat(true);

        gridLayout1->addWidget(Btn_MoviePlay, 2, 4, 1, 1);

        Btn_MovieSeekNext = new QPushButton(MoviePlayBtnWidget);
        Btn_MovieSeekNext->setObjectName(QString::fromUtf8("Btn_MovieSeekNext"));
        Btn_MovieSeekNext->setIcon(icon11);
        Btn_MovieSeekNext->setIconSize(QSize(60, 60));
        Btn_MovieSeekNext->setAutoRepeat(true);
        Btn_MovieSeekNext->setFlat(true);

        gridLayout1->addWidget(Btn_MovieSeekNext, 2, 5, 1, 1);

        Lab_MoviePlay = new QLabel(MoviePlayPage);
        Lab_MoviePlay->setObjectName(QString::fromUtf8("Lab_MoviePlay"));
        Lab_MoviePlay->setGeometry(QRect(50, 20, 128, 128));
        Lab_MoviePlay->setPixmap(QPixmap(QString::fromUtf8(":/apps/icon/mplayer.png")));
        MoviePlayWidget = new QWidget(MoviePlayPage);
        MoviePlayWidget->setObjectName(QString::fromUtf8("MoviePlayWidget"));
        MoviePlayWidget->setGeometry(QRect(290, 100, 201, 141));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush6(QColor(0, 0, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette12.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette12.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette12.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette12.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette12.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        MoviePlayWidget->setPalette(palette12);
        MoviePlayWidget->setAutoFillBackground(true);
        stackedWidget->addWidget(MoviePlayPage);
        SettingPage = new QWidget();
        SettingPage->setObjectName(QString::fromUtf8("SettingPage"));
        Lab_SettingPage = new QLabel(SettingPage);
        Lab_SettingPage->setObjectName(QString::fromUtf8("Lab_SettingPage"));
        Lab_SettingPage->setGeometry(QRect(10, 10, 128, 128));
        Lab_SettingPage->setPixmap(QPixmap(QString::fromUtf8(":/apps/icon/gkdebconf.png")));
        horizontalLayoutWidget = new QWidget(SettingPage);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(170, 20, 531, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(8);
        horizontalLayout->setMargin(11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Lab_SettingSliceShowTimer = new QLabel(horizontalLayoutWidget);
        Lab_SettingSliceShowTimer->setObjectName(QString::fromUtf8("Lab_SettingSliceShowTimer"));
        Lab_SettingSliceShowTimer->setFont(font5);

        horizontalLayout->addWidget(Lab_SettingSliceShowTimer);

        CbBox_SettingSSTimer = new QComboBox(horizontalLayoutWidget);
        CbBox_SettingSSTimer->setObjectName(QString::fromUtf8("CbBox_SettingSSTimer"));
        QFont font7;
        font7.setPointSize(22);
        CbBox_SettingSSTimer->setFont(font7);
        CbBox_SettingSSTimer->setMaxVisibleItems(7);
        CbBox_SettingSSTimer->setInsertPolicy(QComboBox::InsertAtBottom);
        CbBox_SettingSSTimer->setFrame(true);

        horizontalLayout->addWidget(CbBox_SettingSSTimer);

        horizontalLayoutWidget_2 = new QWidget(SettingPage);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(170, 80, 611, 47));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setMargin(11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 6, 0);
        label = new QLabel(horizontalLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font5);

        horizontalLayout_2->addWidget(label);

        LEdit_SettingInMen_Path = new QLineEdit(horizontalLayoutWidget_2);
        LEdit_SettingInMen_Path->setObjectName(QString::fromUtf8("LEdit_SettingInMen_Path"));
        LEdit_SettingInMen_Path->setFont(font5);
        LEdit_SettingInMen_Path->setAutoFillBackground(false);
        LEdit_SettingInMen_Path->setFrame(true);

        horizontalLayout_2->addWidget(LEdit_SettingInMen_Path);

        Btn_SettingInMen_Path = new QPushButton(horizontalLayoutWidget_2);
        Btn_SettingInMen_Path->setObjectName(QString::fromUtf8("Btn_SettingInMen_Path"));
        Btn_SettingInMen_Path->setFont(font7);
        Btn_SettingInMen_Path->setIconSize(QSize(60, 60));

        horizontalLayout_2->addWidget(Btn_SettingInMen_Path);

        Btn_SettingOK = new QPushButton(SettingPage);
        Btn_SettingOK->setObjectName(QString::fromUtf8("Btn_SettingOK"));
        Btn_SettingOK->setGeometry(QRect(670, 340, 120, 60));
        Btn_SettingOK->setFont(font2);
        Btn_SettingCancel = new QPushButton(SettingPage);
        Btn_SettingCancel->setObjectName(QString::fromUtf8("Btn_SettingCancel"));
        Btn_SettingCancel->setGeometry(QRect(550, 340, 120, 60));
        Btn_SettingCancel->setFont(font2);
        stackedWidget->addWidget(SettingPage);
        Bar_VolAdj = new QSlider(centralWidget);
        Bar_VolAdj->setObjectName(QString::fromUtf8("Bar_VolAdj"));
        Bar_VolAdj->setGeometry(QRect(460, 30, 251, 18));
        Bar_VolAdj->setOrientation(Qt::Horizontal);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(7);
        CbBox_SettingSSTimer->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        Btn_Test->setText(QApplication::translate("MainWindow", "TEST", 0, QApplication::UnicodeUTF8));
        Btn_Ok->setText(QApplication::translate("MainWindow", "OK", 0, QApplication::UnicodeUTF8));
        Btn_Home->setText(QString());
        Btn_PhotoFull->setText(QString());
        Btn_PageUp->setText(QString());
        label_ThreadInfo->setText(QApplication::translate("MainWindow", " Thread Ready", 0, QApplication::UnicodeUTF8));
        Btn_Photo->setText(QString());
        lab_Photo->setText(QApplication::translate("MainWindow", "Photo", 0, QApplication::UnicodeUTF8));
        Btn_Music->setText(QString());
        lab_Music->setText(QApplication::translate("MainWindow", "Music", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        Btn_Movie->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        Btn_Movie->setText(QString());
        Lab_Movie->setText(QApplication::translate("MainWindow", "Movie", 0, QApplication::UnicodeUTF8));
        Btn_Cal->setText(QString());
        lab_Cal->setText(QApplication::translate("MainWindow", "Calendar", 0, QApplication::UnicodeUTF8));
        Btn_Alarm->setText(QString());
        lab_Alarm->setText(QApplication::translate("MainWindow", "Alarm Clock", 0, QApplication::UnicodeUTF8));
        Btn_Internet->setText(QString());
        Lab_Internet->setText(QApplication::translate("MainWindow", "Internet", 0, QApplication::UnicodeUTF8));
        Btn_Wireless->setText(QString());
        Lab_Wireless->setText(QApplication::translate("MainWindow", "Wireless", 0, QApplication::UnicodeUTF8));
        Btn_Setting->setText(QString());
        Lab_Setting->setText(QApplication::translate("MainWindow", "Setting", 0, QApplication::UnicodeUTF8));
        Lab_SubPhoto->setText(QString());
        Btn_MemStk->setText(QApplication::translate("MainWindow", "Memory Stick", 0, QApplication::UnicodeUTF8));
        Btn_MemCard->setText(QApplication::translate("MainWindow", "Memory Card", 0, QApplication::UnicodeUTF8));
        Btn_Picasa->setText(QApplication::translate("MainWindow", "Picasa Web Albums", 0, QApplication::UnicodeUTF8));
        Btn_InMem->setText(QApplication::translate("MainWindow", "Internal Memory", 0, QApplication::UnicodeUTF8));
        Btn_PageRight->setText(QString());
        Btn_PageLeft->setText(QString());
        Lab_PhotoSingle->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        Btn_PhotoSinglePage_L->setText(QString());
        Btn_PhotoSinglePage_R->setText(QString());
        Btn_ZoomIn->setText(QString());
        Btn_ZoomOut->setText(QString());
        Lab_Music->setText(QString());
        Btn_MusicSeekBack->setText(QString());
        Btn_MusicPause->setText(QString());
        Btn_MusicStop->setText(QString());
        Btn_MusicPlay->setText(QString());
        Btn_MusicSeekNext->setText(QString());
        Btn_MusicBack->setText(QString());
        Btn_MusicNext->setText(QString());
        Lab_MusicTitle->setText(QString());
        label_2->setText(QString());
        Lab_MoviePage->setText(QString());
        Btn_MovieSeekBack->setText(QString());
        Btn_MovieStop->setText(QString());
        Btn_MoviePause->setText(QString());
        Btn_MoviePlay->setText(QString());
        Btn_MovieSeekNext->setText(QString());
        Lab_MoviePlay->setText(QString());
        Lab_SettingPage->setText(QString());
        Lab_SettingSliceShowTimer->setText(QApplication::translate("MainWindow", "Slice Show Timer(MS):", 0, QApplication::UnicodeUTF8));
        CbBox_SettingSSTimer->clear();
        CbBox_SettingSSTimer->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "500", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "1000", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "1500", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "2000", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "2500", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "3000", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "3500", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "4000", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "4500", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "5000", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "5500", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "6000", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "6500", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "7000", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "7500", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "8000", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "8500", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "9000", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "9500", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "10000", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("MainWindow", "Internal Memory Path:", 0, QApplication::UnicodeUTF8));
        LEdit_SettingInMen_Path->setText(QApplication::translate("MainWindow", "/root/QT/Picture", 0, QApplication::UnicodeUTF8));
        Btn_SettingInMen_Path->setText(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
        Btn_SettingOK->setText(QApplication::translate("MainWindow", "OK", 0, QApplication::UnicodeUTF8));
        Btn_SettingCancel->setText(QApplication::translate("MainWindow", "Cancel", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
