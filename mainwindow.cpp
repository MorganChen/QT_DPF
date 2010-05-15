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

int CurPhotoMutiPageIdx = 0;
int MaxPhotoMutiPageCount = 0;
int CurPhotoMutiFileIdx = 0;
int MaxPhotoMutiFileCount = 0;
int current_index_;

int SliceTimerID;

QRect stackWidget_Gem;
QRect Lab_PhotoSingle_Gem;
QRect scrollArea_Gem;
QRect FullScreen_Gem;

int PrvStackPage, CurStackPage, Prv2StackPage;
int StackPageHis[STACK_PAGE_HIS_NUM], StackPageHisIdx=0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    setWindowFlags(Qt::FramelessWindowHint);
    FullScreen_Gem.setRect(0,0,PANEL_WIDTH,PANEL_HEIGHT);
    ui->setupUi(this);
    ct = new charThread(ui->label_ThreadInfo);
    ChangeStackPageTo(MainStack);
    CompVisionCtrl(MainStack);
    imagesShow_ = new QFutureWatcher<QImage>(this);    
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
    }
}


QFileInfoList MainWindow::getListFiles(QString dirPath) const
{
    QDir dir(dirPath);

    QStringList filters;
    filters << "*.jpg" << "*.jpeg" << "*.png" << ".bmp" << "tiff" << "ico";
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
    int i,ShowIdx;
    QString strTemp;

    CurPhotoMutiPageIdx = 0;
    MaxPhotoMutiPageCount = 0;
    CurPhotoMutiFileIdx = 0;
    MaxPhotoMutiFileCount = 0;

    ui->listWidget_Photo->clear();

    fileList_ = getListFiles("/root/QT/Picture");
    MaxPhotoMutiFileCount = fileList_.count();
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
        item->setData(Qt::WhatsThisRole, QString(fileList_[CurPhotoMutiFileIdx].filePath()));
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
    SliceTimerID = startTimer(2500);


}


bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->Lab_PhotoSingle)
    {
        if (event->type() == QEvent::MouseButtonDblClick)
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
        } else {
            return false;
        }
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

void MainWindow::on_Btn_Ok_clicked()
{



}

void MainWindow::on_Btn_Setting_clicked()
{

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



}


