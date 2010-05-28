#include "mainwindow.h"
#include "ui_mainwindow.h"

#define ARM_PLF
//#define TEST_BTN

#define MUSIC_UP_TIMER 1000
const int WIDTH_ICON = 200;
const int HEIGHT_ICON = 140;

const int WIDTH_IMAGE = 190;
const int HEIGHT_IMAGE = 130;

const int MUTI_PHOTO_NUM = 6;

const int PANEL_WIDTH = 800;
const int PANEL_HEIGHT = 480;

const int STACK_PAGE_HIS_NUM = 5;

const int MOVIE_SCREEN_CLR_TIME = 3000;

QString InMemPath = "/demo";
QString MemStk_PhotoPath = "/mnt/sd/photo";
QString MemCard_PhotoPath = "/mnt/sd/photo";
QString MemCard_MusicPath = "/mnt/sd/music";
QString MemCard_MoviePath = "/mnt/sd/movie";
QString MemCard_BG_MusicPath = "/mnt/sd/music/BG_Music";

QString InMem_BG_MusicPath = "/demo/music/BG_Music";
QString InMem_MusicPath = "/demo/music";
QString InMem_MoviePath = "/demo/movie";
QString InMem_PhotoPath = "/demo/photo";


QString BG_MusicPath;
QString MusicPath;
QString MoviePath;


QString MovieItemPath;
QString MusicItemPath;

int Para_PhotoSliceShow_Timer = 2500;

int CurPhotoMutiPageIdx = 0;
int MaxPhotoMutiPageCount = 0;
int CurPhotoMutiFileIdx = 0;
int MaxPhotoMutiFileCount = 0;
int MaxMusicFileCount = 0 ;
int current_index_;
int MusicIdx;

int SliceTimerID;
int MovieTimerID;

QRect stackWidget_Gem;
QRect Lab_PhotoSingle_Gem;
QRect scrollArea_Gem;
QRect FullScreen_Gem;
QRect MoviePlayWidget_Gem;


bool isMoviePlay = false;
bool isMovieBgBlack = false;
bool isMusicPlay = false;
bool isSliceMusicPlay = true;

double opacity=1;



int PrvStackPage, CurStackPage, Prv2StackPage;
int StackPageHis[STACK_PAGE_HIS_NUM], StackPageHisIdx=0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    //setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    setWindowFlags(Qt::FramelessWindowHint );
#ifdef ARM_PLF
    QApplication::setOverrideCursor(QCursor(Qt::BlankCursor));
    /*MusicPath = MemCardPath;
    MoviePath = MemCardPath;
    BG_MusicPath = MemCard_BG_MusicPath;*/
    MusicPath = InMem_MusicPath;
    MoviePath = InMem_MoviePath;
    BG_MusicPath = InMem_BG_MusicPath;
#else
    MusicPath = InMem_MusicPath;
    MoviePath = InMem_MoviePath;
    BG_MusicPath = InMem_BG_MusicPath;
#endif
    FullScreen_Gem.setRect(0,0,PANEL_WIDTH,PANEL_HEIGHT);
    ui->setupUi(this);
    ct = new charThread(ui->label_ThreadInfo);
    virtualKeyBoard = new WidgetKeyboard(this);
    DigiClockTimer = new QTimer(this);
    ChangeStackPageTo(MainStack);
    CompVisionCtrl(MainStack);
    imagesShow_ = new QFutureWatcher<QImage>(this);

    ui->LcdNum_CalTime->setSegmentStyle(QLCDNumber::Filled);

    connect(DigiClockTimer, SIGNAL(timeout()), this, SLOT(ShowDigiClock()));

    DigiClockTimer->start(1000);


    // for test
#ifdef TEST_BTN
    bool Test_Flag =  true;
#else
    bool Test_Flag =  false;
#endif

    ui->label_ThreadInfo->setVisible(Test_Flag);
    ui->Btn_Test->setVisible(Test_Flag);
    ui->Btn_Ok->setVisible(Test_Flag);




}



MainWindow::~MainWindow()
{
    delete ui;
}

/*------------------------------------------------------
//
//
//
//    Flow Control Function
--------------------------------------------------------*/
void MainWindow::ChangeStackPageTo(int StackPage)
{

    StackPageHis[StackPageHisIdx] = ui->stackedWidget->currentIndex();
    StackPageHis[++StackPageHisIdx] = StackPage;
    ui->stackedWidget->setCurrentIndex(StackPage);
    if(StackPage==MainStack)
    {    
        StackPageHisIdx = 0;
        StackPageHis[StackPageHisIdx] = MainStack;
    }
}

void MainWindow::ChangeStackPageUp(void)
{
    ui->stackedWidget->setCurrentIndex(StackPageHis[--StackPageHisIdx]);

}

void MainWindow::CompVisionCtrl(int StackPage)
{
    switch(StackPage)
    {
    case MainStack :
        ui->Btn_Home->setVisible(false);
        ui->Btn_PageUp->setVisible(false);
        ui->Btn_PhotoFull->setVisible(false);
        ui->Btn_ZoomIn->setVisible(false);
        ui->Btn_ZoomOut->setVisible(false);
        ui->Btn_PicasaStop->setVisible(false);
#ifdef ARM_PLF
        QApplication::setOverrideCursor(QCursor(Qt::BlankCursor));
#endif
        break;
    case PhotoStack :
        ui->Btn_Home->setVisible(true);
        ui->Btn_PageUp->setVisible(true);
        ui->Btn_PhotoFull->setVisible(false);
        ui->Btn_ZoomIn->setVisible(false);
        ui->Btn_ZoomOut->setVisible(false);
        ui->Btn_PicasaStop->setVisible(false);
        break;
    case PhotoMutiStack :
        ui->Btn_Home->setVisible(true);
        ui->Btn_PageUp->setVisible(true);
        ui->Btn_PhotoFull->setVisible(true);

        ui->Btn_PageLeft->setVisible(true);
        ui->Btn_PageRight->setVisible(true);
        break;
    case PhotoSingleStack :
        ui->Btn_Home->setVisible(true);
        ui->Btn_PageUp->setVisible(true);
        ui->Btn_PhotoFull->setVisible(true);

        ui->Btn_PhotoSinglePage_L->setVisible(true);
        ui->Btn_PhotoSinglePage_R->setVisible(true);
        break;
    case PicasaStack :
        ui->Btn_Home->setVisible(true);
        ui->Btn_PageUp->setVisible(true);
        ui->Btn_PhotoFull->setVisible(false);
        ui->Btn_ZoomIn->setVisible(true);
        ui->Btn_ZoomOut->setVisible(true);
        ui->Btn_PicasaStop->setVisible(true);

    case CalendarStack :
        ui->Btn_Home->setVisible(true);
        ui->Btn_PageUp->setVisible(true);
        break;
    case ClockStack :
        ui->Btn_Home->setVisible(true);
        ui->Btn_PageUp->setVisible(true);
    case MusicStack :
        ui->Btn_Home->setVisible(true);
        ui->Btn_PageUp->setVisible(true);
        break;
    case MovieStack :
        ui->Btn_Home->setVisible(true);
        ui->Btn_PageUp->setVisible(true);
    case MoviePlayStack :
        break;
    case MusicPlayStack :
        break;
    case SettingStack :
        ui->Btn_Home->setVisible(false);
        ui->Btn_PageUp->setVisible(false);
        ui->LEdit_SettingInMen_Path->setEnabled(false);
        ui->Btn_SettingInMen_Path->setEnabled(false);
        break;
    }
}


QFileInfoList MainWindow::getPhotoListFiles(QString dirPath) const
{
    QDir dir(dirPath);

    QStringList filters;
    filters << "*.jpg" << "*.jpeg" << "*.png" << "*.tiff" << "*.ico";
    dir.setNameFilters(filters);

    return dir.entryInfoList(filters, QDir::Files);
}

QFileInfoList MainWindow::getMusicListFiles(QString dirPath) const
{
    QDir dir(dirPath);

    QStringList filters;
    filters << "*.mp3" << "*.wav" ;
    dir.setNameFilters(filters);

    return dir.entryInfoList(filters, QDir::Files);
}

QFileInfoList MainWindow::getMovieListFiles(QString dirPath) const
{
    QDir dir(dirPath);

    QStringList filters;
    filters << "*.avi" << "*.mp4" << "*.mpg" << "*.mpeg" ;
    dir.setNameFilters(filters);

    return dir.entryInfoList(filters, QDir::Files);
}

void MainWindow::on_Btn_PageUp_clicked()
{
    ChangeStackPageUp();
    CompVisionCtrl(StackPageHis[StackPageHisIdx]);
}

void MainWindow::on_Btn_Home_clicked()
{
    ChangeStackPageTo(MainStack);
    CompVisionCtrl(MainStack);

}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->Lab_PhotoSingle)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {

            //ui->stackedWidget->setGeometry(0, 0, stackedWidget_OrgW, stackedWidget_OrgH);

            ui->stackedWidget->setGeometry(stackWidget_Gem);
            ui->scrollArea->setGeometry(scrollArea_Gem);
            ui->Lab_PhotoSingle->setGeometry(Lab_PhotoSingle_Gem);
            ShowSinglePhoto(fileList_[current_index_].filePath());
            ui->Btn_PhotoSinglePage_L->setVisible(true);
            ui->Btn_PhotoSinglePage_R->setVisible(true);
            ui->Lab_PhotoSingle->removeEventFilter(this);
            removeEventFilter(this);
            killTimer(SliceTimerID);

            // BG_Music
            /*
            MusicProc->write("quit\n");
            if(!MusicProc->waitForFinished(3000)){}
            MusicProc->kill();
            */
            MusicProc->kill();

            return true;
        }
        else if(event->type() == QEvent::Timer)
        {
            if (current_index_ + 1 < fileList_.count())
                current_index_++;
            else
                current_index_ = 0;

            ShowSinglePhoto(fileList_[current_index_].filePath());
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(obj == ui->MoviePlayWidget)
    {
        if(event->type() == QEvent::MouseButtonPress)
        {
            if(isMovieBgBlack == true)
            {
                ui->stackedWidget->setGeometry(0,60,800,420);
                ui->MoviePlayWidget->setGeometry(MoviePlayWidget_Gem);
                isMovieBgBlack = false;
            }
            else
            {
                ui->stackedWidget->setGeometry(FullScreen_Gem);
                ui->MoviePlayWidget->setGeometry(FullScreen_Gem);
                isMovieBgBlack = true;
            }
        }
    }
    /*
    else if(obj == ui->LcdNum_DigiClock)
    {

        if(event->type() == QEvent::MouseButtonPress)
        {
           ui->stackedWidget->setGeometry(stackWidget_Gem);
           ChangeStackPageTo(MainStack);
           CompVisionCtrl(MainStack);
           ui->LcdNum_DigiClock->removeEventFilter(this);
           removeEventFilter(this);

        }
        return true;
    }*/
    else if(event->type() == QEvent::MouseButtonPress)
    {
        switch(ui->stackedWidget->currentIndex())
        {
        case ClockStack :
            ui->stackedWidget->setGeometry(stackWidget_Gem);
            ChangeStackPageTo(MainStack);
            CompVisionCtrl(MainStack);
            removeEventFilter(this);
            break;
        case SettingStack :
            virtualKeyBoard->hide();
            break;
        }
        return true;
    }
    else
    {
        // pass the event on to the parent class
        return QMainWindow::eventFilter(obj, event);
    }
}

/*------------------------------------------------------
//
//
//
//    Photo Widget
--------------------------------------------------------*/
QPixmap prepareIcon(const QFileInfo &infoFile)
{
    QImage imageIcon(QLatin1String(":btn/icon/Photos.png"));
    imageIcon = imageIcon.scaledToHeight(HEIGHT_IMAGE, Qt::SmoothTransformation);

    int image_width = imageIcon.width();
    int image_height = imageIcon.height();

    QRectF target((WIDTH_ICON - image_width) / 2, 0, image_width, image_height);
    QRectF source(0, 0, image_width, image_height);


    QPixmap pixDraw(QSize(WIDTH_ICON, HEIGHT_ICON));
    QPainter painter(&pixDraw);

    painter.setBrush(Qt::NoBrush);
    painter.fillRect(QRect(0, 0, WIDTH_ICON, HEIGHT_ICON), Qt::white);


    painter.setPen(Qt::black);
    painter.drawImage(target, imageIcon, source);
    painter.drawRect(target);


    painter.setPen(Qt::darkBlue);

    /*
    QRect rect((WIDTH_ICON - image_width) / 2, image_height + 2, image_width, HEIGHT_ICON - image_height - 4);
    QFontMetrics font_metrics(painter.font());
    QString elideText = font_metrics.elidedText(infoFile.completeBaseName(), Qt::ElideRight, image_width);
    painter.drawText(rect, Qt::AlignCenter | Qt::ElideRight, elideText);
    */
    return pixDraw;
}

QImage prepareImage(const QFileInfo &infoFile)
{
    QImageReader imageReader(infoFile.filePath());
    QSize size;
    int image_width = WIDTH_IMAGE;
    int image_height = HEIGHT_IMAGE;

    if (imageReader.supportsOption(QImageIOHandler::Size))
    {
        size = imageReader.size();
        image_width = size.width();
        image_height = size.height();
    }

    double ratio = (double)image_width / (double)image_height;
    image_height = HEIGHT_IMAGE;
    image_width = ratio * image_height;

    imageReader.setScaledSize(QSize(image_width, image_height));
    QImage image = imageReader.read();



    if (image.isNull())
    {
        QImage imageIcon(QLatin1String(":btn/icon/Photos.png"));
        image = imageIcon;
        //image = image.scaledToHeight(HEIGHT_IMAGE, Qt::SmoothTransformation);
        image = image.scaledToHeight(HEIGHT_IMAGE, Qt::FastTransformation);
        image_width = image.width();
        image_height = image.height();
    }


    QRectF target((WIDTH_ICON - image_width) / 2, 0, image_width, image_height);
    QRectF source(0, 0, image_width, image_height);


    QImage imgDraw(QSize(WIDTH_ICON, HEIGHT_ICON), QImage::Format_RGB32);
    QPainter painter(&imgDraw);

    painter.setBrush(Qt::NoBrush);
    //painter.fillRect(QRect(0, 0, WIDTH_ICON, HEIGHT_ICON), Qt::red);
    painter.fillRect(QRect(0, 0, WIDTH_ICON, HEIGHT_ICON), QColor(220,218,213,255));

    painter.setPen(Qt::black);
    painter.drawImage(target, image, source);
    painter.drawRect(target);

    painter.setPen(Qt::darkBlue);
    /*
    QRect rect((WIDTH_ICON - WIDTH_IMAGE) / 2, image_height + 2, WIDTH_IMAGE, HEIGHT_ICON - image_height - 4);
    QFontMetrics font_metrics(painter.font());
    QString elideText = font_metrics.elidedText(infoFile.completeBaseName(), Qt::ElideRight, WIDTH_IMAGE);
    painter.drawText(rect, Qt::AlignCenter | Qt::ElideRight, elideText);
    */
    return (imgDraw);
}


void MainWindow::setItemInList(int index)
{
    ui->listWidget_Photo->item(index)->setIcon(QIcon(QPixmap::fromImage(imagesShow_->resultAt(index))));

}

void MainWindow::finished()
{
}

void MainWindow::ThreadStart()
{
    if(!ct->isRunning() )
    {
        ct->setStart();
        ct->start();        
    }
}

void MainWindow::ThreadPause()
{
    ct->setPause();
}

void MainWindow::ThreadStop()
{
    ct->setStop();
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}


void MainWindow::on_Btn_InMem_clicked()
{
    fileList_ = getPhotoListFiles(InMem_PhotoPath);
    ShowPhotoMutiStack(fileList_);


}

void MainWindow::on_Btn_MemStk_clicked()
{

    fileList_ = getPhotoListFiles(MemStk_PhotoPath);
    ShowPhotoMutiStack(fileList_);

}

void MainWindow::on_Btn_MemCard_clicked()
{

    fileList_ = getPhotoListFiles(MemCard_PhotoPath);
    ShowPhotoMutiStack(fileList_);

}

void MainWindow::on_Btn_Picasa_clicked()
{
    ui->WebView_Picase->setUrl(QUrl("http://picasaweb.google.com/elandman.chuang"));

    ChangeStackPageTo(PicasaStack);
    CompVisionCtrl(PicasaStack);
}

void MainWindow::on_Btn_ZoomOut_clicked()
{
    qreal zf = ui->WebView_Picase->zoomFactor();
    if(zf > 0.2)
        zf -= 0.1;
    ui->WebView_Picase->setZoomFactor(zf);
}

void MainWindow::on_Btn_ZoomIn_clicked()
{
    qreal zf = ui->WebView_Picase->zoomFactor();
    if(zf < 2)
        zf += 0.1;
    ui->WebView_Picase->setZoomFactor(zf);
}


void MainWindow::on_Btn_PicasaStop_clicked()
{
    ui->WebView_Picase->stop();
}


void MainWindow::ShowPhotoMutiStack(QFileInfoList FileList)
{
    int i,ShowIdx;
    QString strTemp;

    CurPhotoMutiPageIdx = 0;
    MaxPhotoMutiPageCount = 0;
    CurPhotoMutiFileIdx = 0;
    MaxPhotoMutiFileCount = 0;

    ui->listWidget_Photo->clear();


    MaxPhotoMutiFileCount = FileList.count();
    ui->label_ThreadInfo->setText(strTemp.setNum(MaxPhotoMutiFileCount));  // for test

    ui->Btn_PageRight->setEnabled(false);
    ui->Btn_PageLeft->setEnabled(false);

    i = MaxPhotoMutiFileCount;
    while(i>0)
    {
        MaxPhotoMutiPageCount++;
        i -= MUTI_PHOTO_NUM;
    }

    if(MaxPhotoMutiPageCount == 1)
        ShowIdx = MaxPhotoMutiFileCount;
    else
    {
        ui->Btn_PageRight->setEnabled(true);
        ShowIdx = MUTI_PHOTO_NUM;
    }

    for (i = 0; i < ShowIdx; ++i)
    {
        QListWidgetItem *item = new QListWidgetItem;
        item->setData(Qt::WhatsThisRole, QString(FileList[CurPhotoMutiFileIdx].filePath()));
        ui->listWidget_Photo->addItem(item);
        ui->listWidget_Photo->item(i)->setIcon(QIcon(QPixmap::fromImage(prepareImage(fileList_[CurPhotoMutiFileIdx]))));
        CurPhotoMutiFileIdx++;
    }
    ChangeStackPageTo(PhotoMutiStack);
    CompVisionCtrl(PhotoMutiStack);

}

void MainWindow::on_Btn_PageRight_clicked()
{
    int i,ShowIdx=MUTI_PHOTO_NUM;

    if(ui->Btn_PageLeft->isEnabled() == false)
        ui->Btn_PageLeft->setEnabled(true);

    CurPhotoMutiPageIdx++;
    if(CurPhotoMutiPageIdx == (MaxPhotoMutiPageCount - 1))
    {
        ui->Btn_PageRight->setEnabled(false);
        ShowIdx = MaxPhotoMutiFileCount%MUTI_PHOTO_NUM;
    }

    ui->listWidget_Photo->clear();
    for (i = 0; i < ShowIdx; ++i)
    {
        QListWidgetItem *item = new QListWidgetItem;
        //item->setIcon(QIcon(prepareIcon(fileList_[i])));
        item->setData(Qt::WhatsThisRole, QString(fileList_[CurPhotoMutiFileIdx].filePath()));
        ui->listWidget_Photo->addItem(item);
        ui->listWidget_Photo->item(i)->setIcon(QIcon(QPixmap::fromImage(prepareImage(fileList_[CurPhotoMutiFileIdx]))));
        CurPhotoMutiFileIdx++;
    }

}

void MainWindow::on_Btn_PageLeft_clicked()
{
    int i,ShowIdx=MUTI_PHOTO_NUM;

    if(ui->Btn_PageRight->isEnabled() == false)
        ui->Btn_PageRight->setEnabled(true);

    if(CurPhotoMutiPageIdx == (MaxPhotoMutiPageCount - 1))
        CurPhotoMutiFileIdx -= (MaxPhotoMutiFileCount%MUTI_PHOTO_NUM + MUTI_PHOTO_NUM);
    else
        CurPhotoMutiFileIdx -= (MUTI_PHOTO_NUM + MUTI_PHOTO_NUM);


    CurPhotoMutiPageIdx--;
    if(CurPhotoMutiPageIdx == 0)
    {
        ui->Btn_PageLeft->setEnabled(false);
        //ShowIdx = MaxPhotoMutiFileCount%6;
    }

    ui->listWidget_Photo->clear();
    for (i = 0; i < ShowIdx; ++i)
    {
        QListWidgetItem *item = new QListWidgetItem;
        //item->setIcon(QIcon(prepareIcon(fileList_[i])));
        item->setData(Qt::WhatsThisRole, QString(fileList_[CurPhotoMutiFileIdx].filePath()));
        ui->listWidget_Photo->addItem(item);
        ui->listWidget_Photo->item(i)->setIcon(QIcon(QPixmap::fromImage(prepareImage(fileList_[CurPhotoMutiFileIdx]))));
        CurPhotoMutiFileIdx++;
    }
}

void MainWindow::on_listWidget_Photo_itemClicked(QListWidgetItem* item)
{
    QString strDirPath = item->data(Qt::WhatsThisRole).toString();

    current_index_ = fileList_.indexOf(QFileInfo(strDirPath));
    ShowSinglePhoto(strDirPath);
    SetPhotoSingleBtn();

    ChangeStackPageTo(PhotoSingleStack);
    CompVisionCtrl(PhotoSingleStack);
}


void MainWindow::on_Btn_PhotoFull_clicked()
{
    QStringList file;
    int i;


    if(StackPageHis[StackPageHisIdx] == PhotoMutiStack)
    {
        current_index_ = 0;
        ChangeStackPageTo(PhotoSingleStack);
        CompVisionCtrl(PhotoSingleStack);

    }

    stackWidget_Gem = ui->stackedWidget->geometry();
    scrollArea_Gem = ui->scrollArea->geometry();
    Lab_PhotoSingle_Gem = ui->Lab_PhotoSingle->geometry();

    ui->stackedWidget->setGeometry(FullScreen_Gem);
    ui->scrollArea->setGeometry(FullScreen_Gem);
    ui->Lab_PhotoSingle->setGeometry(FullScreen_Gem);

    ui->stackedWidget->raise();
    ui->Btn_PhotoSinglePage_L->setVisible(false);
    ui->Btn_PhotoSinglePage_R->setVisible(false);

    ShowSinglePhoto(fileList_[current_index_].filePath());
    ui->Lab_PhotoSingle->installEventFilter(this);
    installEventFilter(this);    
    SliceTimerID = ui->Lab_PhotoSingle->startTimer(Para_PhotoSliceShow_Timer);


    MusicFileList = getMusicListFiles(BG_MusicPath);
    MaxMusicFileCount = MusicFileList.count();
    MusicIdx = 0;
    MusicProc = new QProcess(this);

    if(isSliceMusicPlay == true)
    {
        file << "-vzr";
        for(i=MusicIdx ; i<MaxMusicFileCount ; i++)
            file << QString(MusicFileList[i].filePath());
        if(MusicIdx != 0)
        {
            for(i=0 ; i<MusicIdx ; i++)
                file << QString(MusicFileList[i].filePath());
        }

    #ifdef ARM_PLF
        MusicProc->start("madplay",file);
    #else
        MusicProc->start("madplay",file);
    #endif
    }
    //Play BG_Music
    /*
    MusicFileList = getMusicListFiles(BG_MusicPath);
    MaxMusicFileCount = MusicFileList.count();
    MusicIdx = 0;
    MusicProc = new QProcess(this);


    file << "-slave";
    file << "-quiet";
    file << "-loop";
    file << "0";
    //file << "-shuffle";    
    for(i=MusicIdx ; i<MaxMusicFileCount ; i++)
        file << QString(MusicFileList[i].filePath());
    if(MusicIdx != 0)
    {
        for(i=0 ; i<MusicIdx ; i++)
            file << QString(MusicFileList[i].filePath());
    }

#ifdef ARM_PLF
    MusicProc->start("/opt/Qtopia/demos/mplayer",file);
#else
    MusicProc->start("./mplayer",file);
#endif
    */

}


void MainWindow::ShowSinglePhoto(QString filePath)
{
    QPixmap PixmapScaled;
    int im_h, im_w;

    PixmapScaled = QPixmap::fromImage(QImage(filePath));
    im_h = ui->Lab_PhotoSingle->height();
    im_w = ui->Lab_PhotoSingle->width();

    if(PixmapScaled.height() > im_h)
    {
        PixmapScaled = PixmapScaled.scaledToHeight(im_h, Qt::SmoothTransformation );
        if(PixmapScaled.width() > im_w)
            PixmapScaled = PixmapScaled.scaledToWidth(im_w, Qt::SmoothTransformation );
    }
    else if(PixmapScaled.width() > im_w)
    {
        PixmapScaled = PixmapScaled.scaledToWidth(im_w, Qt::SmoothTransformation );
        if(PixmapScaled.height() > im_h)
            PixmapScaled = PixmapScaled.scaledToHeight(im_h, Qt::SmoothTransformation );
    }
    ui->Lab_PhotoSingle->setPixmap(PixmapScaled);
}

void MainWindow::on_Btn_PhotoSinglePage_R_clicked()
{
    if (current_index_ + 1 < fileList_.count())
    {
        current_index_++;
        ShowSinglePhoto(fileList_[current_index_].filePath());
    }
    SetPhotoSingleBtn();
}

void MainWindow::on_Btn_PhotoSinglePage_L_clicked()
{
    if (current_index_ -1 >= 0)
    {
        current_index_--;
        ShowSinglePhoto(fileList_[current_index_].filePath());
    }
    SetPhotoSingleBtn();
}



void MainWindow::SetPhotoSingleBtn(void)
{
    if(current_index_ > 0)
        ui->Btn_PhotoSinglePage_L->setEnabled(true);
    else
        ui->Btn_PhotoSinglePage_L->setEnabled(false);

    if(current_index_ + 1 < fileList_.count())
        ui->Btn_PhotoSinglePage_R->setEnabled(true);
    else
        ui->Btn_PhotoSinglePage_R->setEnabled(false);
}

void MainWindow::on_Btn_Photo_clicked()
{
    ChangeStackPageTo(PhotoStack);
    CompVisionCtrl(PhotoStack);
}

/*------------------------------------------------------
//
//
//
//    Setting Widget
--------------------------------------------------------*/

void MainWindow::on_Btn_Setting_clicked()
{
    ChangeStackPageTo(SettingStack);
    CompVisionCtrl(SettingStack);

    installEventFilter(this);

}

void MainWindow::on_Btn_SettingCancel_clicked()
{

    removeEventFilter(this);
    ChangeStackPageTo(MainStack);
    CompVisionCtrl(MainStack);
}

void MainWindow::on_Btn_SettingInMen_Path_clicked()
{
    virtualKeyBoard->show();
    ui->LEdit_SettingInMen_Path->setFocus();
}

void MainWindow::on_Btn_SettingOK_clicked()
{
    QString Str;

    Str = ui->CbBox_SettingSSTimer->currentText();
    Para_PhotoSliceShow_Timer = Str.toInt();
    InMemPath = ui->LEdit_SettingInMen_Path->text();

    if(ui->ComBox_SettingMMSource->currentIndex() == 0)
    {
        MusicPath = MemCard_MusicPath;
        MoviePath = MemCard_MoviePath;
        BG_MusicPath = MemCard_BG_MusicPath;
    }
    else
    {
        MusicPath = InMem_MusicPath;
        MoviePath = InMem_MoviePath;
        BG_MusicPath = InMem_BG_MusicPath;
    }

    if(ui->ComBox_SliceMusic->currentIndex() == 0)
        isSliceMusicPlay = true;
    else
        isSliceMusicPlay = false;

    removeEventFilter(this);
    ChangeStackPageTo(MainStack);
    CompVisionCtrl(MainStack);
}






/*------------------------------------------------------
//
//
//
//    TEST Btn
--------------------------------------------------------*/
void MainWindow::on_Btn_Ok_clicked()
{
    ui->WebView_Picase->reload();
}

void MainWindow::on_Btn_Test_clicked()
{

    /*
    if(opacity>0)
        opacity-=0.1;
    setWindowOpacity(opacity);
    */
}

/*------------------------------------------------------
//
//
//
//    Calender Widget
--------------------------------------------------------*/
void MainWindow::on_Btn_Cal_clicked()
{
    ChangeStackPageTo(CalendarStack);
    CompVisionCtrl(CalendarStack);
}


/*------------------------------------------------------
//
//
//
//    Alarm Widget
--------------------------------------------------------*/
void MainWindow::on_Btn_Alarm_clicked()
{
    ChangeStackPageTo(ClockStack);
    CompVisionCtrl(ClockStack);

    ui->Btn_PageUp->lower();
    stackWidget_Gem = ui->stackedWidget->geometry();
    ui->stackedWidget->setGeometry(FullScreen_Gem);

    installEventFilter(this);

}


void MainWindow::ShowDigiClock()
{

    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm:ss");
    QDate temp=QDate::currentDate();
    if ((time.second() % 2) == 0)
    {
        text[2] = ' ';
        text[5] = ' ';
    }
    ui->LcdNum_DigiClock->display(text);
    ui->LcdNum_CalTime->display(text);       
    ui->Lab_CalDate->setText(temp.toString(Qt::TextDate));

}

/*------------------------------------------------------
//
//
//
//    Music Widget
--------------------------------------------------------*/


void MainWindow::on_Btn_Music_clicked()
{
    int i;


    QString ItemNum, ItemFileName, ItemFileSize, ItemStr;

    fileList_ = getMusicListFiles(MusicPath);
    ui->ListWidget_MusicFile->clear();


    MaxMusicFileCount = fileList_.count();
    ui->label_ThreadInfo->setText(ItemNum.setNum(MaxMusicFileCount));  // for test


    for (i = 0; i < MaxMusicFileCount; ++i)
    {
        QListWidgetItem *ItemFile = new QListWidgetItem;
        ItemFile->setData(Qt::WhatsThisRole, QString(fileList_[i].filePath()));
        ItemNum = ItemNum.setNum(i+1)+" :";
        ItemFileName = QString(fileList_[i].fileName());
        ItemFileSize = "Size:"+ItemFileSize.setNum(fileList_[i].size()/1024)+"KB";
        ItemStr = QString("%1 %2 %3").arg(ItemNum,-5).arg(ItemFileName,-19).arg(ItemFileSize,-11);
        ItemFile->setText(ItemStr);
        ui->ListWidget_MusicFile->addItem(ItemFile);

    }

    ChangeStackPageTo(MusicStack);
    CompVisionCtrl(MusicStack);

}

void MainWindow::on_ListWidget_MusicFile_itemClicked(QListWidgetItem* item)
{
    MusicItemPath = item->data(Qt::WhatsThisRole).toString();
    MusicIdx = fileList_.indexOf(QFileInfo(MusicItemPath));

    ChangeStackPageTo(MusicPlayStack);
    CompVisionCtrl(MusicPlayStack);

    on_Btn_MusicPlay_clicked();


}

void MainWindow::on_Btn_MusicPlay_clicked()
{
    QString StrTemp;
    QStringList file;
    int i;

    MusicTime = new QTime();
    Music_Update_Timer = new QTimer();
    connect(Music_Update_Timer,SIGNAL(timeout()),this,SLOT(MusicInfoUpdate()));


    ui->LcdNum_MusicTime->display("00:00");
    ui->LcdNum_MusicTime->setSegmentStyle(QLCDNumber::Filled);

    ui->Btn_Home->setEnabled(false);
    ui->Btn_PageUp->setEnabled(false);
    ui->Btn_MusicNext->setEnabled(true);
    ui->Btn_MusicBack->setEnabled(true);
    ui->Btn_MusicPause->setEnabled(true);
    ui->Btn_MusicPlay->setEnabled(false);
    ui->Btn_MusicStop->setEnabled(true);
    ui->Btn_MusicSeekBack->setEnabled(true);
    ui->Btn_MusicSeekNext->setEnabled(true);

    MusicTime->setHMS(0,0,0,0);
    ui->ProBar_MusicPro->setValue(0);


    MusicProc = new QProcess(this);
    connect(MusicProc, SIGNAL(finished(int, QProcess::ExitStatus)),
               this, SLOT(MusicFinished()));

    connect(MusicProc,SIGNAL(readyReadStandardOutput()),this,SLOT(Music_Back_Message()));

    file << "-slave";
    file << "-quiet";
    //file << "-loop";
    //file << "0";
    //file << "-shuffle";
    for(i=MusicIdx ; i<MaxMusicFileCount ; i++)
        file << QString(fileList_[i].filePath());
    if(MusicIdx != 0)
    {
        for(i=0 ; i<MusicIdx ; i++)
            file << QString(fileList_[i].filePath());
    }

#ifdef ARM_PLF
    MusicProc->start("/opt/Qtopia/demos/mplayer",file);
#else
    MusicProc->start("./mplayer",file);
#endif
    Music_Update_Timer->start(MUSIC_UP_TIMER);

    isMusicPlay = true;
}

void MainWindow::on_Btn_MusicStop_clicked()
{
    MusicProc->write("quit\n");
    if(!MusicProc->waitForFinished(3000)){}
    MusicProc->kill();
}

void MainWindow::on_Btn_MusicPause_clicked()
{

    if(isMusicPlay == true)
    {
        isMusicPlay = false;
        ui->Btn_MusicSeekBack->setEnabled(false);
        ui->Btn_MusicSeekNext->setEnabled(false);
        ui->Btn_MusicBack->setEnabled(false);
        ui->Btn_MusicNext->setEnabled(false);
        Music_Update_Timer->stop();
        MusicProc->write("pause\n");        
    }
    else
    {
        isMusicPlay = true;
        ui->Btn_MusicSeekBack->setEnabled(true);
        ui->Btn_MusicSeekNext->setEnabled(true);
        ui->Btn_MusicBack->setEnabled(true);
        ui->Btn_MusicNext->setEnabled(true);
        MusicProc->write("get_time_pos\n");
        Music_Update_Timer->start(MUSIC_UP_TIMER);
    }   


}

void MainWindow::on_Btn_MusicSeekNext_clicked()
{
    MusicProc->write("seek 5\n");
    MusicProc->write("get_time_pos\n");
}

void MainWindow::on_Btn_MusicSeekBack_clicked()
{
    MusicProc->write("seek -5\n");
    MusicProc->write("get_time_pos\n");
}

void MainWindow::on_Btn_MusicBack_clicked()
{
    MusicProc->write("pt_step -1\n");
}

void MainWindow::on_Btn_MusicNext_clicked()
{
    MusicProc->write("pt_step 1\n");
}

void MainWindow::MusicFinished()
{
    Music_Update_Timer->stop();

    ui->ProBar_MusicPro->setValue(0);
    ui->LcdNum_MusicTime->display("00:00");

    ui->Btn_Home->setEnabled(true);
    ui->Btn_PageUp->setEnabled(true);
    ui->Btn_MusicNext->setEnabled(false);
    ui->Btn_MusicBack->setEnabled(false);
    ui->Btn_MusicPause->setEnabled(false);
    ui->Btn_MusicPlay->setEnabled(true);
    ui->Btn_MusicStop->setEnabled(false);
    ui->Btn_MusicSeekBack->setEnabled(false);
    ui->Btn_MusicSeekNext->setEnabled(false);
    MusicProc->kill();
}


void MainWindow::Music_Back_Message()
{

    while(MusicProc->canReadLine())
    {
        char temp[128];
        qstrcpy(temp,MusicProc->readLine());

        if (!qstrncmp("Starting",temp,8))
        {
            MusicTime->setHMS(1,0,0,0);
            ui->ProBar_MusicPro->setValue(0);
            MusicProc->write("get_time_length\n");
        }
        else if (!qstrncmp("ANS_LENGTH",temp,10))
        {
            int timebarlength;
            sscanf(temp+11,"%d",&timebarlength);
            ui->ProBar_MusicPro->setMaximum(timebarlength);
        }
        else if (!qstrncmp("Playing",temp,7))
        {
            int i;
            i = MusicPath.count();
            ui->Lab_MusicTitle->setText(temp+9+i);
        }
        else if (!qstrncmp("ANS_TIME",temp,8))
        {
            int timebarvalue;
            sscanf(temp+18,"%d",&timebarvalue);
            ui->ProBar_MusicPro->setValue(timebarvalue);
            MusicTime->setHMS(0,0,0,0);
            *MusicTime = MusicTime->addSecs(timebarvalue);
            QString strTime = MusicTime->toString("mm:ss");
            ui->LcdNum_MusicTime->display(strTime);

        }
    }

}


void MainWindow::MusicInfoUpdate()
{
    QString strTime = MusicTime->toString("mm:ss");
    ui->LcdNum_MusicTime->display(strTime);

    MusicProc->write("get_time_pos\n");
}

/*------------------------------------------------------
//
//
//
//    Movie Widget
--------------------------------------------------------*/
void MainWindow::on_Btn_Movie_clicked()
{
    int i;

    QString ItemNum, ItemFileName, ItemFileSize, ItemStr;

    fileList_ = getMovieListFiles(MoviePath);
    ui->ListWidget_MovieFile->clear();


    MaxPhotoMutiFileCount = fileList_.count();
    ui->label_ThreadInfo->setText(ItemNum.setNum(MaxPhotoMutiFileCount));  // for test


    for (i = 0; i < MaxPhotoMutiFileCount; ++i)
    {
        QListWidgetItem *ItemFile = new QListWidgetItem;
        ItemFile->setData(Qt::WhatsThisRole, QString(fileList_[i].filePath()));
        ItemNum = ItemNum.setNum(i+1)+" :";
        ItemFileName = QString(fileList_[i].fileName());
        ItemFileSize = "Size:"+ItemFileSize.setNum(fileList_[i].size()/1024)+"KB";
        ItemStr = QString("%1 %2 %3").arg(ItemNum,-5).arg(ItemFileName,-19).arg(ItemFileSize,-11);
        ItemFile->setText(ItemStr);
        ui->ListWidget_MovieFile->addItem(ItemFile);

    }

    ChangeStackPageTo(MovieStack);
    CompVisionCtrl(MovieStack);
}

void MainWindow::on_ListWidget_MovieFile_itemClicked(QListWidgetItem* item)
{
    MovieItemPath = item->data(Qt::WhatsThisRole).toString();

    ChangeStackPageTo(MoviePlayStack);
    CompVisionCtrl(MoviePlayStack);

    on_Btn_MoviePlay_clicked();
}


void MainWindow::on_Btn_MovieSeekBack_clicked()
{
    MovieProc->write("seek -5\n");
}

void MainWindow::on_Btn_MovieSeekNext_clicked()
{
    MovieProc->write("seek 5\n");
}



void MainWindow::on_Btn_MoviePause_clicked()
{
    MovieProc->write("pause\n");
    if(isMoviePlay == true)
        isMoviePlay = false;
    else
        isMoviePlay = true;
    ui->Btn_MovieSeekBack->setEnabled(isMoviePlay);
    ui->Btn_MovieSeekNext->setEnabled(isMoviePlay);

}

void MainWindow::on_Btn_MoviePlay_clicked()
{
    QStringList file;


    ui->Btn_Home->setEnabled(false);
    ui->Btn_PageUp->setEnabled(false);

    ui->Btn_MoviePlay->setEnabled(false);

    ui->Btn_MoviePause->setEnabled(true);
    ui->Btn_MovieSeekBack->setEnabled(true);
    ui->Btn_MovieSeekNext->setEnabled(true);
    ui->Btn_MovieStop->setEnabled(true);

    file << "-slave";
    file << "-quiet";
#ifdef ARM_PLF
    file << "-fs" ;
#endif
    file << MovieItemPath ;

    MovieProc = new QProcess(this);
    connect(MovieProc, SIGNAL(finished(int, QProcess::ExitStatus)),
               this, SLOT(MoiveFinished()));

#ifdef ARM_PLF
    MovieProc->start("/opt/Qtopia/demos/mplayer",file);
#else
    MovieProc->start("./mplayer",file);
#endif
    if(!MovieProc->waitForStarted(1000)){}

    isMoviePlay = true;

    stackWidget_Gem = ui->stackedWidget->geometry();
    MoviePlayWidget_Gem = ui->MoviePlayWidget->geometry();
    ui->MoviePlayWidget->setGeometry(FullScreen_Gem);
    ui->stackedWidget->setGeometry(FullScreen_Gem);
    ui->MoviePlayBtnWidget->setGeometry(160,310,490,90);
    ui->MoviePlayWidget->raise();
    ui->MoviePlayWidget->setAutoFillBackground(true);
    ui->MoviePlayWidget->installEventFilter(this);
    installEventFilter(this);
    isMovieBgBlack = true;


}

void MainWindow::MoiveFinished()
{

    ui->Btn_Home->setEnabled(true);
    ui->Btn_PageUp->setEnabled(true);

    ui->Btn_MoviePlay->setEnabled(true);

    ui->Btn_MoviePause->setEnabled(false);
    ui->Btn_MovieSeekBack->setEnabled(false);
    ui->Btn_MovieSeekNext->setEnabled(false);
    ui->Btn_MovieStop->setEnabled(false);

    isMoviePlay = false;
    isMovieBgBlack = false;

    ui->stackedWidget->setGeometry(0,60,800,420);
    ui->MoviePlayWidget->setGeometry(MoviePlayWidget_Gem);
    ui->MoviePlayWidget->setAutoFillBackground(false);
    ui->stackedWidget->repaint();

    ui->MoviePlayWidget->removeEventFilter(this);
    removeEventFilter(this);


    ui->label_ThreadInfo->setText("MovieFinished");
    MovieProc->kill();

}

void MainWindow::on_Btn_MovieStop_clicked()
{
    MovieProc->write("quit\n");
    if(!MovieProc->waitForFinished(3000)){}    
    MovieProc->kill();
}


/*------------------------------------------------------
//
//
//
//    Internet Widget
--------------------------------------------------------*/
void MainWindow::on_Btn_Internet_clicked()
{        
    BrowserProc = new QProcess(this);
    connect(BrowserProc, SIGNAL(finished(int, QProcess::ExitStatus)),
               this, SLOT(BrowserFinished()));

#ifdef ARM_PLF
    BrowserProc->start("/opt/Qtopia/demos/browser");
#else
    BrowserProc->start("./browser");
#endif
    if(!BrowserProc->waitForStarted(3000)){}
}

void MainWindow::BrowserFinished()
{

    BrowserProc->kill();
}


/*------------------------------------------------------
//
//
//
//    Wireless Widget
--------------------------------------------------------*/
void MainWindow::on_Btn_Wireless_clicked()
{
    WirelessProc = new QProcess(this);
    connect(WirelessProc, SIGNAL(finished(int, QProcess::ExitStatus)),
               this, SLOT(WirelessFinished()));

#ifdef ARM_PLF
    WirelessProc->start("/opt/Qtopia/demos/wireless");
#else
    WirelessProc->start("./wireless");
#endif
    if(!WirelessProc->waitForStarted(3000)){}
}

void MainWindow::WirelessFinished()
{
    WirelessProc->kill();
}

