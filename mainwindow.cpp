#include "mainwindow.h"
#include "ui_mainwindow.h"


const int WIDTH_ICON = 200;
const int HEIGHT_ICON = 140;

const int WIDTH_IMAGE = 190;
const int HEIGHT_IMAGE = 130;

const int MUTI_PHOTO_NUM = 6;

const int PANEL_WIDTH = 800;
const int PANEL_HEIGHT = 480;

const int STACK_PAGE_HIS_NUM = 5;

const int MOVIE_SCREEN_CLR_TIME = 100;

const QString InMemPath = "/root/QT/Picture";
const QString MemStkPath = "/root/QT/Picture";
const QString MemCardPath = "/root/QT/Picture";

QString MovieItemPath;

int Para_PhotoSliceShow_Timer = 2500;

int CurPhotoMutiPageIdx = 0;
int MaxPhotoMutiPageCount = 0;
int CurPhotoMutiFileIdx = 0;
int MaxPhotoMutiFileCount = 0;
int current_index_;

int SliceTimerID;
int MovieTimerID,MovieTimerID1;

QRect stackWidget_Gem;
QRect Lab_PhotoSingle_Gem;
QRect scrollArea_Gem;
QRect FullScreen_Gem;
QRect MoviePlayWidget_Gem;

bool isMoviePlay = false;

double opacity=1;



int PrvStackPage, CurStackPage, Prv2StackPage;
int StackPageHis[STACK_PAGE_HIS_NUM], StackPageHisIdx=0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    //setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    setWindowFlags(Qt::FramelessWindowHint );
    FullScreen_Gem.setRect(0,0,PANEL_WIDTH,PANEL_HEIGHT);
    ui->setupUi(this);
    ct = new charThread(ui->label_ThreadInfo);
    virtualKeyBoard = new WidgetKeyboard(this);
    DigiClockTimer = new QTimer(this);
    ChangeStackPageTo(MainStack);
    CompVisionCtrl(MainStack);
    imagesShow_ = new QFutureWatcher<QImage>(this);

    connect(DigiClockTimer, SIGNAL(timeout()), this, SLOT(ShowDigiClock()));

    DigiClockTimer->start(1000);


    // for test
    bool flag =  true;
    ui->label_ThreadInfo->setVisible(flag);
    ui->Btn_Test->setVisible(flag);
    ui->Btn_Ok->setVisible(flag);
    //virtualKeyBoard->show();




}

void MainWindow::ShowDigiClock()
{

    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm:ss");
    if ((time.second() % 2) == 0)
    {
        text[2] = ' ';
        text[5] = ' ';
    }
    ui->LcdNum_DigiClock->display(text);

}

MainWindow::~MainWindow()
{
    delete ui;
}

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
        ui->Bar_VolAdj->setVisible(false);
        break;
    case PhotoStack :
        ui->Btn_Home->setVisible(true);
        ui->Btn_PageUp->setVisible(true);
        ui->Btn_PhotoFull->setVisible(false);
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
    case SettingStack :
        ui->Btn_Home->setVisible(false);
        ui->Btn_PageUp->setVisible(false);
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
    filters << "*.mp3" << "*.jpg" ;
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
    fileList_ = getPhotoListFiles(InMemPath);
    ShowPhotoMutiStack(fileList_);
}

void MainWindow::on_Btn_MemStk_clicked()
{
    fileList_ = getPhotoListFiles(MemStkPath);
    ShowPhotoMutiStack(fileList_);
}

void MainWindow::on_Btn_MemCard_clicked()
{
    fileList_ = getPhotoListFiles(MemCardPath);
    ShowPhotoMutiStack(fileList_);
}

void MainWindow::on_Btn_Picasa_clicked()
{
    ChangeStackPageTo(PicasaStack);
    CompVisionCtrl(PicasaStack);
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
        if (event->type() == QEvent::MouseButtonPress)
        {            
            ui->stackedWidget->setGeometry(stackWidget_Gem);
            ui->MoviePlayWidget->setGeometry(MoviePlayWidget_Gem);
            ui->Lab_MoviePlay->setVisible(true);

            //ui->MoviePlayWidget->repaint(0,0,320,240);
            MovieTimerID = ui->MoviePlayWidget->startTimer(MOVIE_SCREEN_CLR_TIME);

            return true;

        }
        else if(event->type() == QEvent::Timer)
        {


            if(ui->MoviePlayWidget->geometry() != FullScreen_Gem)
            {
                ui->MoviePlayWidget->killTimer(MovieTimerID);
                ui->MoviePlayWidget->killTimer(MovieTimerID1);
                ui->MoviePlayWidget->repaint(0,0,320,240);
                ui->MoviePlayWidget->removeEventFilter(this);
                removeEventFilter(this);
            }
            else
            {
                ui->MoviePlayWidget->killTimer(MovieTimerID);
                ui->MoviePlayWidget->killTimer(MovieTimerID1);
                ui->MoviePlayWidget->repaint(FullScreen_Gem);

            }
            return true;

        }
        return false;

    }
    else if(obj == ui->LEdit_SettingInMenPath)
    {
        if(event->type() == QEvent::MouseButtonPress)
        {
            virtualKeyBoard->show();

        }
    }
    else if(event->type() == QEvent::MouseButtonPress)
    {
        virtualKeyBoard->hide();
    }
    else
    {
        // pass the event on to the parent class
        return QMainWindow::eventFilter(obj, event);
    }
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



void MainWindow::on_Btn_Setting_clicked()
{
    ChangeStackPageTo(SettingStack);
    CompVisionCtrl(SettingStack);

    ui->LEdit_SettingInMenPath->installEventFilter(this);
    installEventFilter(this);

}

void MainWindow::on_Btn_Photo_clicked()
{
    ChangeStackPageTo(PhotoStack);
    CompVisionCtrl(PhotoStack);
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


void MainWindow::on_Btn_ZoomIn_clicked()
{

}

void MainWindow::on_Btn_Test_clicked()
{
    if(opacity>0)
        opacity-=0.1;
    setWindowOpacity(opacity);
}



void MainWindow::on_Btn_Ok_clicked()
{
    if(opacity<1)
        opacity+=0.1;
    setWindowOpacity(opacity);

    //MoviePlayWidget_Gem = ui->MoviePlayWidget->geometry();

    //QPainter pal;
    //pal.fillRect(MoviePlayWidget_Gem,QColor(255, 8, 220, 225));

    //ui->MoviePlayWidget->repaint(0,0,320,240);

    /*
    MovieProc->write("quit\n");
    if(!MovieProc->waitForFinished(3000))
    {
        //qDebug("ZOMG, ça plante :(");
        //return false;
    }
    */

}


void MainWindow::on_Btn_Cal_clicked()
{
    ChangeStackPageTo(CalendarStack);
    CompVisionCtrl(CalendarStack);
}

void MainWindow::on_Btn_Alarm_clicked()
{
    ChangeStackPageTo(ClockStack);
    CompVisionCtrl(ClockStack);


}

void MainWindow::on_Btn_Music_clicked()
{
    int i;


    QString ItemNum, ItemFileName, ItemFileSize, ItemStr;

    fileList_ = getPhotoListFiles(InMemPath);
    ui->ListWidget_MusicFile->clear();


    MaxPhotoMutiFileCount = fileList_.count();
    ui->label_ThreadInfo->setText(ItemNum.setNum(MaxPhotoMutiFileCount));  // for test


    for (i = 0; i < MaxPhotoMutiFileCount; ++i)
    {
        QListWidgetItem *ItemFile = new QListWidgetItem;
        ItemFile->setData(Qt::WhatsThisRole, QString(fileList_[i].filePath()));
        ItemNum = ItemNum.setNum(i+1)+" :";
        ItemFileName = QString(fileList_[i].fileName());
        ItemFileSize = "Size:"+ItemFileSize.setNum(fileList_[i].size()/1024)+"KB";
        ItemStr = QString("%1 %2 %3").arg(ItemNum,-5).arg(ItemFileName,-20).arg(ItemFileSize,-11);       
        ItemFile->setText(ItemStr);
        ui->ListWidget_MusicFile->addItem(ItemFile);

    }

    ChangeStackPageTo(MusicStack);
    CompVisionCtrl(MusicStack);

}

void MainWindow::on_Btn_Movie_clicked()
{
    int i;

    QString ItemNum, ItemFileName, ItemFileSize, ItemStr;

    fileList_ = getMovieListFiles(InMemPath);
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
        ItemStr = QString("%1 %2 %3").arg(ItemNum,-5).arg(ItemFileName,-20).arg(ItemFileSize,-11);
        ItemFile->setText(ItemStr);
        ui->ListWidget_MovieFile->addItem(ItemFile);

    }

    ui->MoviePlayWidget->raise();
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
    ui->Btn_MovieScreen->setEnabled(isMoviePlay);
    ui->Btn_MovieSeekBack->setEnabled(isMoviePlay);
    ui->Btn_MovieSeekNext->setEnabled(isMoviePlay);

}

void MainWindow::on_Btn_MoviePlay_clicked()
{
    QStringList file;


    ui->Btn_Home->setEnabled(false);
    ui->Btn_PageUp->setEnabled(false);

    ui->Btn_MoviePlay->setEnabled(false);

    ui->Btn_MovieScreen->setEnabled(true);
    ui->Btn_MoviePause->setEnabled(true);
    ui->Btn_MovieSeekBack->setEnabled(true);
    ui->Btn_MovieSeekNext->setEnabled(true);
    ui->Btn_MovieStop->setEnabled(true);

    //ui->label_ThreadInfo->setText(QString::number(X11eCon->winId()));


    file << "-slave";
    //file << "-quiet";
    //file << "-wid" << QString::number(ui->MoviePlayWidget->winId());
    //file << "-fs" ;
    file << MovieItemPath << "-zoom" ;//<< "-xy" <<"480";// << "-x" << "800" << "-y" << "480";

    MovieProc = new QProcess(this);
    connect(MovieProc, SIGNAL(finished(int, QProcess::ExitStatus)),
               this, SLOT(MoiveFinished()));

    //MovieProc->start("/opt/Qtopia/demos/mplayer",file);
    MovieProc->start("./mplayer",file);
    if(!MovieProc->waitForStarted(1000)){}

    isMoviePlay = true;




}

void MainWindow::MoiveFinished()
{

    ui->Btn_Home->setEnabled(true);
    ui->Btn_PageUp->setEnabled(true);

    ui->Btn_MoviePlay->setEnabled(true);

    ui->Btn_MovieScreen->setEnabled(false);
    ui->Btn_MoviePause->setEnabled(false);
    ui->Btn_MovieSeekBack->setEnabled(false);
    ui->Btn_MovieSeekNext->setEnabled(false);
    ui->Btn_MovieStop->setEnabled(false);

    isMoviePlay = false;

    ui->label_ThreadInfo->setText("MovieFinished");
    MovieProc->kill();
}

void MainWindow::on_Btn_MovieStop_clicked()
{
    MovieProc->write("quit\n");
    if(!MovieProc->waitForFinished(3000)){}    
    MovieProc->kill();
}

void MainWindow::on_Btn_MovieScreen_clicked()
{
    stackWidget_Gem = ui->stackedWidget->geometry();
    MoviePlayWidget_Gem = ui->MoviePlayWidget->geometry();

    ui->stackedWidget->setGeometry(FullScreen_Gem);
    ui->MoviePlayWidget->setGeometry(FullScreen_Gem);

    ui->Lab_MoviePlay->setVisible(false);
    ui->stackedWidget->raise();
    ui->MoviePlayWidget->raise();


    ui->MoviePlayWidget->installEventFilter(this);
    installEventFilter(this);

    MovieTimerID1 = ui->MoviePlayWidget->startTimer(MOVIE_SCREEN_CLR_TIME);

}



void MainWindow::on_Btn_Internet_clicked()
{        
    BrowserProc = new QProcess(this);
    connect(BrowserProc, SIGNAL(finished(int, QProcess::ExitStatus)),
               this, SLOT(BrowserFinished()));

    BrowserProc->start("/opt/Qtopia/demos/browser");

}

void MainWindow::BrowserFinished()
{

    BrowserProc->kill();
}

void MainWindow::on_Btn_SettingOK_clicked()
{
    ui->LEdit_SettingInMenPath->removeEventFilter(this);
    removeEventFilter(this);
    ChangeStackPageTo(MainStack);
    CompVisionCtrl(MainStack);
}

void MainWindow::on_Btn_SettingCancel_clicked()
{
    ui->LEdit_SettingInMenPath->removeEventFilter(this);
    removeEventFilter(this);
    ChangeStackPageTo(MainStack);
    CompVisionCtrl(MainStack);
}
