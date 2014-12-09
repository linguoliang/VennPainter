#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    temppath=QDir::tempPath();
    temppath.append("/Linvenn.svg");
    //QMessageBox::warning(this,"NI hao",temppath);
    //ui->webView->load(QUrl("set_share\\venn.svg"));
    ui->webView->setContextMenuPolicy(Qt::ActionsContextMenu);
    List=new QList<QAction*>();
    ui->webView->installEventFilter(this);

    zoom_out=new QAction(QIcon(":/Zoom_out.png"),"zoom out",ui->webView);
    zoom_in=new QAction(QIcon(":/Zoom_in.png"),"zoom in",ui->webView);
    reset=new QAction("reset",ui->webView);
    save=new QAction(QIcon(":/Save_Image.png"),"save image",ui->webView);
    Zoom=new QCursor(QPixmap(":/Zoom.png"));
    major=new setClass();
    picture=new svg();
    tempqColor[7]=new QColor(0xE5,0x4E,0x3E,0xEF);
    tempqColor[6]=new QColor(0x89,0x41,0xE5,0xEF);
    tempqColor[5]=new QColor(0x3D,0xD1,0x8A,0xEF);
    tempqColor[4]=new QColor(0xE2,0xAF,0x49,0xEF);
    tempqColor[3]=new QColor(0xE6,0x1E,0x66,0xEF);
    tempqColor[2]=new QColor(0x36,0xA6,0xDF,0xEF);
    tempqColor[1]=new QColor(0x68,0xB8,0x2E,0xEF);
    tempqColor[0]=new QColor(0xF3,0xEB,0x34,0xEF);
    for(int i=0;i<8;i++){
        qColor[i]=*tempqColor[i];
    }

    transcolor();

    //控件初始化
    qPushButton[0]=ui->pushButton;
    qPushButton[1]=ui->pushButton_2;
    qPushButton[2]=ui->pushButton_3;
    qPushButton[3]=ui->pushButton_4;
    qPushButton[4]=ui->pushButton_5;
    qPushButton[5]=ui->pushButton_6;
    qPushButton[6]=ui->pushButton_7;
    qPushButton[7]=ui->pushButton_8;
    qCheckBox[0]=ui->checkBox;
    qCheckBox[1]=ui->checkBox_2;
    qCheckBox[2]=ui->checkBox_3;
    qCheckBox[3]=ui->checkBox_4;
    qCheckBox[4]=ui->checkBox_5;
    qCheckBox[5]=ui->checkBox_6;
    qCheckBox[6]=ui->checkBox_7;
    qCheckBox[7]=ui->checkBox_8;
    for(int i=0;i<8;i++){
        qPushButton[i]->setDisabled(true);
        qCheckBox[i]->setDisabled(true);
        qCheckBox[i]->setChecked(true);
    }
    ui->pushButton_9->setDisabled(true);
    ui->actionSave_as_S->setDisabled(true);
    ui->actionSave_Imgage_I->setDisabled(true);
    ui->actionSave_color_palette->setDisabled(true);
    statisticList=0;
    Listnumber=0;
    outputfilename="output.svg";
    for(int i=0;i<4;i++){
        stat[0]=0;
    }

    for(int i=0;i<8;i++){
        setbutcolor(i);
    }

    List->append(zoom_out);
    List->append(zoom_in);
    List->append(reset);
    List->append(save);


    ui->webView->addActions(*List);

    //信号槽链接
    connect(ui->action_Open,SIGNAL(triggered()),this,SLOT(open()));
    connect(ui->actionSave_as_S,SIGNAL(triggered()),this,SLOT(exportsharesets()));
    connect(ui->actionSave_Imgage_I,SIGNAL(triggered()),this,SLOT(Save_picture()));
    connect(zoom_out,SIGNAL(triggered()),this,SLOT(Zoom_out()));
    connect(zoom_in,SIGNAL(triggered()),this,SLOT(Zoom_in()));
    connect(reset,SIGNAL(triggered()),this,SLOT(Reset()));
    connect(save,SIGNAL(triggered()),this,SLOT(Save_picture()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(Remove()));
    for(int i=0;i<8;i++){
        connect(qCheckBox[i],SIGNAL(clicked()),this,SLOT(Check_checkbox()));
    }
    connect(ui->actionAbout_A,SIGNAL(triggered()),this,SLOT(about()));
    connect(ui->actionAbout_Qt,SIGNAL(triggered()),this,SLOT(aboutQt()));
    connect(qPushButton[0],SIGNAL(clicked()),this,SLOT(ChangeColor1()));
    connect(qPushButton[1],SIGNAL(clicked()),this,SLOT(ChangeColor2()));
    connect(qPushButton[2],SIGNAL(clicked()),this,SLOT(ChangeColor3()));
    connect(qPushButton[3],SIGNAL(clicked()),this,SLOT(ChangeColor4()));
    connect(qPushButton[4],SIGNAL(clicked()),this,SLOT(ChangeColor5()));
    connect(qPushButton[5],SIGNAL(clicked()),this,SLOT(ChangeColor6()));
    connect(qPushButton[6],SIGNAL(clicked()),this,SLOT(ChangeColor7()));
    connect(qPushButton[7],SIGNAL(clicked()),this,SLOT(ChangeColor8()));
    connect(ui->actionSave_color_palette,SIGNAL(triggered()),this,SLOT(Save_palette()));
    connect(ui->actionLoad_color_palette,SIGNAL(triggered()),this,SLOT(Load_palette()));
}

MainWindow::~MainWindow()
{
    for(int i=0;i<8;i++){
        delete tempqColor[i];
    }
    delete picture;
    delete major;
    delete save;
    delete reset;
    delete zoom_in;
    delete zoom_out;
    delete List;
    delete Zoom;
    delete ui;
}

void MainWindow::open(){
    int state;
    fileName = QFileDialog::getOpenFileNames(this,tr("Open Files"),tr("/"));
    if(!fileName.empty()){
        fileList=fileName.join("\r");
        state=major->addFile(fileList);
        if(state<0)
        {
            Remove();
            return;
        }
        for(int i=0;i<major->total;i++){
            qPushButton[i]->setDisabled(false);
            qCheckBox[i]->setDisabled(false);
            qCheckBox[i]->setText(major->Head[i]->name.c_str());
        }
        Check_checkbox();
        ui->actionSave_as_S->setDisabled(false);
        ui->actionSave_Imgage_I->setDisabled(false);
        ui->pushButton_9->setDisabled(false);
        ui->actionExport_shared_sets->setDisabled(false);
    }
}

void MainWindow::exportsharesets(){
    QString file1;
    int fm=0;
    QFileDialog dialog(this,tr("Save File"),"",tr("Horizontal Form (*.hf);;Vertical Form (*.vf);;Matrix Form (*.mf)"));
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    if (dialog.exec()==QDialog::Accepted)
    {
        file1=dialog.selectedFiles().at(0);
        if(dialog.selectedNameFilter().contains(".hf")){
            if(!file1.endsWith(".hf"))
                file1.append(".hf");
            fm=1;
        }else if (dialog.selectedNameFilter().contains(".vf")) {
            if(!file1.endsWith(".vf"))
                file1.append(".vf");
            fm=2;
          }else {
             if(!file1.endsWith(".mf"))
                file1.append(".mf");
            fm=3;
          }
        QFile* temp=new QFile(file1);
        if(temp->exists()){
            QString mbs=file1;
            mbs.append(" already exist.\n Do you want to replace it?");
            if(QMessageBox::Yes==QMessageBox::warning(this,"Save File",mbs,QMessageBox::Yes,QMessageBox::No)){
                if(!(temp->remove())){
                    QMessageBox::critical(this,"Oops!","Can't Replace the File!",QMessageBox::Ok);
                    delete temp;
                    return;
                }
            }else {
                return;
            }
        }
        delete temp;
        switch (fm) {
        case 1:
            major->exportsharesets(file1,statisticList);
            break;
        case 2:
            major->exportvertical(file1,statisticList);
            break;
        case 3:
            major->exportMatrixs(file1,statisticList);
            break;
        default:
            break;
        }
    }
    else{

    }                     //点的是取消
}

void MainWindow::Zoom_out(){
    ui->webView->setZoomFactor(7*ui->webView->zoomFactor()/8);
}

void MainWindow::Zoom_in(){
    ui->webView->setZoomFactor(8*ui->webView->zoomFactor()/7);
}

void MainWindow::Reset(){
    ui->webView->setZoomFactor(1);
}

void MainWindow::Save_picture(){
    QString file1;
    file1= QFileDialog::getSaveFileName(this,
            tr("Save File"), "", tr("Files (*.svg);;All Files (*.*)"));

        if (!file1.isNull())
        {
            QFile* temp=new QFile(file1);
            if(temp->exists()){
                if(!(temp->remove())){
                    QMessageBox::critical(this,"Oops!","Can't Replace the File!",QMessageBox::Ok);
                    delete temp;
                    return;
                }
            }
            delete temp;
            QFile::copy(temppath,file1);
            return;
        }
        else{

        }                     //点的是取消
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)//重写eventFilter函数
 {
     if (obj == ui->webView) {
         if (event->type() == QEvent::Wheel) {
             QWheelEvent *wheelEvent = static_cast<QWheelEvent*>(event);
             if(QApplication::keyboardModifiers()==Qt::ControlModifier){//若Ctrl键被按下，滚轮滑动的话就进行放大缩小
                 wheelRolled(wheelEvent);
                 return true;
             }
             else {
                 return false;
             }
         } else {
             if(event->type()==QEvent::KeyPress){
                 QKeyEvent *keyEvent=static_cast<QKeyEvent*>(event);
                 if(keyEvent->modifiers()==Qt::ControlModifier){
                     ui->webView->setCursor(*Zoom);
                 }
             }
             else {
                 if(event->type()==QEvent::MouseMove){
                     if(QApplication::keyboardModifiers()==Qt::ControlModifier){
                         ui->webView->setCursor(*Zoom);
                         return true;
                     }
                 }
                 else {
                     if(event->type()==QEvent::KeyRelease){
                         QKeyEvent *keyEvent=static_cast<QKeyEvent*>(event);
                         if(keyEvent->key()==Qt::Key_Control){
                             ui->webView->setCursor(Qt::ArrowCursor);
                            // return true;
                         }
                     }
                 }
             }
             return false;
         }
     } else {
         // pass the event on to the parent class
         return QMainWindow::eventFilter(obj, event);
     }
 }

void MainWindow::wheelRolled(QWheelEvent *event)//放大缩小
{

    int z=event->delta();
    if(z>=0){
        if(ui->webView->zoomFactor()<1){
            ui->webView->setZoomFactor(ui->webView->zoomFactor()+0.05*ui->webView->zoomFactor());
        }
        else {
            ui->webView->setZoomFactor(ui->webView->zoomFactor()+0.05);
        }
    }
    else{
        if(ui->webView->zoomFactor()<1){
            ui->webView->setZoomFactor(ui->webView->zoomFactor()-0.05*ui->webView->zoomFactor());
        }
        else {
            ui->webView->setZoomFactor(ui->webView->zoomFactor()-0.05);
        }
    }
}

void MainWindow::Generate(){//产生
    major->statistica(statisticList);
    major->transoutput(statisticList);
    transcolor();
    for(int i=0,j=0;i<8;i++){
        if(qCheckBox[i]->isChecked()){
            FColor[j]=Color[i];
            j++;
        }
    }
    picture->flush(Listnumber,major->outputStatistic,major->outPutHead,FColor,temppath);
    ui->webView->load(QUrl(temppath));
}


void MainWindow::Check_checkbox(){//检查有多少被选中，并将结果存在statisticList里
    int list=0;
    Listnumber=0;
    for(int i=0;i<major->total;i++){
        if(qCheckBox[i]->isChecked()){
            list=list+(1<<i);
            Listnumber++;
            qPushButton[i]->setEnabled(true);
        }
        else
            qPushButton[i]->setDisabled(true);
    }
    statisticList=list;
    Generate();
}

void MainWindow::about(){
    QMessageBox::about(this,QString("CopyRight"),QString("\n\nVennPainter Version 1.0\n Based on Qt"));
}

void MainWindow::aboutQt(){
    QMessageBox::aboutQt(this);
}

void MainWindow::ChangeColor1(){
    qColorDialog=new QColorDialog(Qt::white, this);
    if(qColorDialog->exec()==QDialog::Accepted){
        qColor[0]=qColorDialog->selectedColor();
        bkgrd[0]=qPushButton[0]->palette();
        setbutcolor(0);
        reload();
        ui->actionSave_color_palette->setEnabled(true);
    }
    delete qColorDialog;
}


void MainWindow::ChangeColor2(){
    qColorDialog=new QColorDialog(Qt::white, this);
    if(qColorDialog->exec()==QDialog::Accepted){
        qColor[1]=qColorDialog->selectedColor();
        setbutcolor(1);
        reload();
        ui->actionSave_color_palette->setEnabled(true);
    }
    delete qColorDialog;
}

void MainWindow::ChangeColor3(){
    qColorDialog=new QColorDialog(Qt::white, this);
    if(qColorDialog->exec()==QDialog::Accepted){
        qColor[2]=qColorDialog->selectedColor();
        setbutcolor(2);
        reload();
        ui->actionSave_color_palette->setEnabled(true);
    }
    delete qColorDialog;
}

void MainWindow::ChangeColor4(){
    qColorDialog=new QColorDialog(Qt::white, this);
    if(qColorDialog->exec()==QDialog::Accepted){
        qColor[3]=qColorDialog->selectedColor();
        setbutcolor(3);
        reload();
        ui->actionSave_color_palette->setEnabled(true);
    }
    delete qColorDialog;
}

void MainWindow::ChangeColor5(){
    qColorDialog=new QColorDialog(Qt::white, this);
    if(qColorDialog->exec()==QDialog::Accepted){
        qColor[4]=qColorDialog->selectedColor();
        setbutcolor(4);
        reload();
        ui->actionSave_color_palette->setEnabled(true);
    }
    delete qColorDialog;
}

void MainWindow::ChangeColor6(){
    qColorDialog=new QColorDialog(Qt::white, this);
    if(qColorDialog->exec()==QDialog::Accepted){
        qColor[5]=qColorDialog->selectedColor();
        setbutcolor(5);
        reload();
        ui->actionSave_color_palette->setEnabled(true);
    }
    delete qColorDialog;
}

void MainWindow::ChangeColor7(){
    qColorDialog=new QColorDialog(Qt::white, this);
    if(qColorDialog->exec()==QDialog::Accepted){
        qColor[6]=qColorDialog->selectedColor();
        setbutcolor(6);
        reload();
        ui->actionSave_color_palette->setEnabled(true);
    }
    delete qColorDialog;
}

void MainWindow::ChangeColor8(){
    qColorDialog=new QColorDialog(Qt::white, this);
    if(qColorDialog->exec()==QDialog::Accepted){
        qColor[7]=qColorDialog->selectedColor();
        setbutcolor(7);
        reload();
        ui->actionSave_color_palette->setEnabled(true);
    }
    delete qColorDialog;
}

//改变图形颜色
void MainWindow::transcolor(){
    for(int i=0;i<8;i++){
        Color[i]=0;
        Color[i]=qColor[i].red();
        Color[i]=Color[i]<<8;
        Color[i]=Color[i]+qColor[i].green();
        Color[i]=Color[i]<<8;
        Color[i]=Color[i]+qColor[i].blue();
    }
}

//设置按钮颜色
void MainWindow::setbutcolor(int i){
    QString temp;
    temp="background-color:";
    temp.append(qColor[i].name());
    temp.append(";");
    qPushButton[i]->setStyleSheet(temp);
}

void MainWindow::reload(){
    transcolor();
    for(int i=0,j=0;i<8;i++){
        if(qCheckBox[i]->isChecked()){
            FColor[j]=Color[i];
            j++;
        }
    }
    picture->flush(Listnumber,major->outputStatistic,major->outPutHead,FColor,temppath);
     ui->webView->reload();
}

//清除载入的数据
void MainWindow::Remove(){
    int temp=major->total;
    major->Remove();
    while(temp>0){
        temp--;
        qCheckBox[temp]->setText("");
        qCheckBox[temp]->setDisabled(true);
        qPushButton[temp]->setDisabled(true);
    }
    ui->actionSave_as_S->setDisabled(true);
    ui->actionSave_Imgage_I->setDisabled(true);

}

//存储配置文件
void MainWindow::Save_palette(){
    QString filenm;
    filenm = QFileDialog::getSaveFileName(this,tr("Save File"),"", tr("Files (*.plt);;All Files (*.*)"));
    if(!filenm.isNull()){
        FILE *p;
        p=fopen(filenm.toLocal8Bit(),"w");
        for(int i=0;i<8;i++){
            fprintf(p,"red:%d blue:%d green:%d alpha:%d\n",qColor[i].red(),qColor[i].blue(),qColor[i].green(),qColor[i].alpha());
        }
        fclose(p);
    }
}

//载入颜色配置文件
void MainWindow::Load_palette(){
    QString filenm;
    filenm = QFileDialog::getOpenFileName(this,tr("Open Files"),tr("/"),tr("Files (*.plt);;All Files (*.*)"));
    if(!filenm.isNull()){
        FILE* p;
        p=fopen(filenm.toLocal8Bit(),"r");
        for(int i=0,red=0,blue=0,green=0,alpha=0;i<8;i++){
            fscanf(p,"red:%d blue:%d green:%d alpha:%d\n",&red,&blue,&green,&alpha);
            if((red>0xFF)||(blue>0xFF)||(green>0xFF)||(alpha>0xFF)){
                QMessageBox::warning(this,"Error","Data error!",QMessageBox::Ok);
                fclose(p);
                return;
            }
            qColor[i].setRed(red);
            qColor[i].setGreen(green);
            qColor[i].setBlue(blue);
            qColor[i].setAlpha(alpha);
        }
        fclose(p);
        transcolor();
        for(int i=0;i<8;i++){
            setbutcolor(i);
        }
        reload();
    }
}

