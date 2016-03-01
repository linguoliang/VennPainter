#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug> //for debug
//#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    temppath=QDir::tempPath();
    file_path=QDir::currentPath();
    ui->webView->setContextMenuPolicy(Qt::ActionsContextMenu);
    ui->webView->installEventFilter(this);
    ui->plainTextEdit->setReadOnly(true);
    ui->plainTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->plainTextEdit->setLineWrapMode(QPlainTextEdit::NoWrap);
    try{
    List=new QList<QAction*>();
    zoom_out=new QAction(QIcon(":/Zoom_out.png"),"Zoom out",ui->webView);
    zoom_in=new QAction(QIcon(":/Zoom_in.png"),"Zoom in",ui->webView);
    reset=new QAction(QIcon(":/reset.png"),"Reset scale",ui->webView);
    save=new QAction(QIcon(":/Save_Image.png"),"Save image",ui->webView);
    seprator=new QAction(ui->webView);
    nest=new QAction(QIcon(":/venn.png"),"Nest Venn",ui->webView);
    edwards=new QAction(QIcon(":/edward.png"),"Edward's Venn",ui->webView);
    classic=new QAction(QIcon(":/classic.png"),"Classic Venn",ui->webView);
    seprator->setSeparator(true);
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
    }
    catch(std::bad_alloc& ba){
        QMessageBox::critical(this,QString("Error!"),QString(ba.what())+"\n This program will exit!");
        exit(1);
    }
    for(int i=0;i<8;i++){
        qColor[i]=*tempqColor[i];
    }

    transcolor();
    pagetmp=ui->webView->page();
    pagetmp->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);
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
        qPushButton[i]->setVisible(false);
        qCheckBox[i]->setDisabled(true);
        qCheckBox[i]->setChecked(false);
        qCheckBox[i]->setVisible(false);
    }
    //set widget invisible
    ui->groupBox->setVisible(false);
    ui->label->setVisible(false);
    ui->plainTextEdit->setVisible(false);
//    ui->groupBox->setMinimumWidth(0);
//    ui->groupBox->setMaximumWidth(0);
    ui->pushButton_9->setDisabled(true);
    ui->pushButton_9->setVisible(false);
    ui->pushButton_10->setDisabled(true);
    ui->pushButton_10->setVisible(false);
    ui->actionSave_as_S->setDisabled(true);
    ui->actionSave_Imgage_I->setDisabled(true);
    ui->actionSave_color_palette->setDisabled(true);
    ui->label->setMaximumWidth(172);
    ui->label->adjustSize();
    ui->label->setWordWrap(true);
    statisticList=0;
    Listnumber=0;
    outputfilename="output.svg";

    for(int i=0;i<8;i++){
        setbutcolor(i);
    }
    pvennformat[0]=2;
    pvennformat[1]=2;
    pvennformat[2]=2;
    pvennformat[3]=2;
    pvennformat[4]=0;
    pvennformat[5]=0;
    pvennformat[6]=0;
    pvennformat[7]=0;
    for(int i=8;i<maxNonraph;i++){
        pvennformat[i]=3;
    }
    selecId=0;
    List->append(zoom_out);
    List->append(zoom_in);
    List->append(reset);
    List->append(save);
    List->append(seprator);
    List->append(nest);
    List->append(edwards);
    List->append(classic);
    zoom_in->setDisabled(true);
    zoom_out->setDisabled(true);
    reset->setDisabled(true);
    save->setDisabled(true);
    nest->setDisabled(true);
    edwards->setDisabled(true);
    classic->setDisabled(true);
    ui->webView->addActions(*List);

    //信号槽链接
    connect(ui->action_Open,SIGNAL(triggered()),this,SLOT(open()));
    connect(ui->actionSave_as_S,SIGNAL(triggered()),this,SLOT(exportsharesets()));
    connect(ui->actionSave_Imgage_I,SIGNAL(triggered()),this,SLOT(Save_picture()));
    connect(zoom_out,SIGNAL(triggered()),this,SLOT(Zoom_out()));
    connect(zoom_in,SIGNAL(triggered()),this,SLOT(Zoom_in()));
    connect(reset,SIGNAL(triggered()),this,SLOT(Reset()));
    connect(save,SIGNAL(triggered()),this,SLOT(Save_picture()));
    connect(nest,SIGNAL(triggered()),this,SLOT(nest_stat()));
    connect(edwards,SIGNAL(triggered()),this,SLOT(edwards_stat()));
    connect(classic,SIGNAL(triggered()),this,SLOT(classic_stat()));
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
    connect(ui->webView,SIGNAL(linkClicked(QUrl)),this,SLOT(singlecontent(QUrl)));
    connect(ui->actionHelp_F1,SIGNAL(triggered()),this,SLOT(help()));
//    connect(ui->webView,SIGNAL(urlChanged(QUrl)),this,SLOT(singlecontent(QUrl)));
    connect(ui->pushButton_10,SIGNAL(clicked()),this,SLOT(exportunit()));
    ui->webView->load(QUrl(QString("Sample_workflow.html")));
    states=0;
}

void MainWindow::singlecontent(QUrl url){
    int id;
    if(url.toString().contains(QString("html"))){
        ui->webView->load(url);
    }else{
        id=url.toString().replace(QRegExp(".*[^0-9]"),"").toInt();
        selecId=major->findunit(id,statisticList);
        itemName *p;
        p=major->vertical[selecId];
        ui->plainTextEdit->clear();
        while (p) {
            ui->plainTextEdit->appendPlainText(p->item.c_str());
            p=p->line;
        }
        ui->label->setVisible(true);
        ui->plainTextEdit->setVisible(true);
        ui->pushButton_10->setVisible(true);
        ui->pushButton_10->setDisabled(false);
        ui->label->setToolTip(QString(major->outputstring[id].c_str()));
        ui->plainTextEdit->setToolTip("click 'Export shared list' button to export shared list");
    }
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

void MainWindow::open(){//
    qDebug()<<file_path;
    fileName = QFileDialog::getOpenFileNames(this,tr("Open Files"),file_path+'/');
//    QTime time;
//    time.start();
    if(!fileName.empty()){
        file_path=fileName[0];
        file_path.replace('\\','/');
        file_path.remove(file_path.lastIndexOf('/'),file_path.length());
        qDebug()<<file_path;
        fileList=fileName.join("\r");
        major->addFile(fileList);
        if(major->total<9)
        for(int i=0;i<major->total;i++){//init buttoms
            qPushButton[i]->setDisabled(false);
            qPushButton[i]->setVisible(true);
            qCheckBox[i]->setDisabled(false);
            qCheckBox[i]->setVisible(true);
            qCheckBox[i]->setChecked(true);
            qCheckBox[i]->setText(major->Head[i]->name.c_str());
        }
        Check_checkbox();
        if(major->total<9){
            ui->actionSave_Imgage_I->setDisabled(false);
            ui->pushButton_9->setDisabled(false);
            ui->pushButton_9->setVisible(true);
        }
        ui->groupBox->setVisible(true);
        ui->actionSave_as_S->setDisabled(false);
        ui->actionExport_shared_sets->setDisabled(false);
    }
//    qDebug()<<time.elapsed()<<"ms";
}

void MainWindow::exportsharesets(){
    QString file1;
    int fm=0;

    file1=QFileDialog::getSaveFileName(this,tr("Save File"),file_path+"/untitled",tr("Matrix Form (*.mf);;Vertical Form (*.vf);;Horizontal Form (*.hf)"),NULL,QFileDialog::HideNameFilterDetails);
    if(!file1.isNull()){
        file_path=file1;
        file_path.replace('\\','/');
        file_path.remove(file_path.lastIndexOf('/'),file_path.length());
        qDebug()<<file_path;
        if(file1.endsWith(".hf"))
            fm=3;
        else if(file1.endsWith(".vf"))
            fm=2;
        else if(file1.endsWith(".mf"))
            fm=1;
        else
            fm=3;
        switch (fm) {
        case 3:
            major->exportsharesets(file1,statisticList);
            break;
        case 2:
            major->exportvertical(file1,statisticList);
            break;
        case 1:
            major->exportMatrixs(file1,statisticList);
            break;
        default:
            break;
        }
    }
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
            tr("Save File"),file_path+"/untitled", tr("Scalable Vector Graphics (*.svg)"),NULL,QFileDialog::HideNameFilterDetails);

        if (!file1.isNull())
        {
            file_path=file1;
            file_path.replace('\\','/');
            file_path.remove(file_path.lastIndexOf('/'),file_path.length());
            qDebug()<<file_path;
            QFile* temp=new QFile(file1);
            if(temp->exists()){
                if(!(temp->remove())){
                    QMessageBox::critical(this,"Oops!","Can't Replace the File!",QMessageBox::Ok);
                    delete temp;
                    return;
                }
            }
            delete temp;
            QFile::copy(temppath+"/Linvenn.svg",file1);
            return;
        }
        else{

        }                     //点的是取消
}


bool MainWindow::eventFilter(QObject *obj, QEvent *event)//overwirte eventFilter function
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
                 }else{if(keyEvent->matches(QKeySequence::Back))
                         return true;
                     else if(keyEvent->key()==Qt::Key_F1){
                         help();
                         return true;
                     }
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
                         }                   
                     }
                 }
             }
             return false;
         }
     } else {
             if(event->type()==QEvent::KeyPress){
                 QKeyEvent *keyEvent=static_cast<QKeyEvent*>(event);
                 if(keyEvent->key()==Qt::Key_F1){
                    help();
                    return true;
             }}
         // pass the event on to the parent class
         return QMainWindow::eventFilter(obj, event);

 }
}

void MainWindow::wheelRolled(QWheelEvent *event)//zoom function
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
    if(major->total<9){
        major->statistica(statisticList);
        major->transoutput(statisticList);
        transcolor();
        for(int i=0,j=0;i<8;i++){
            if(qCheckBox[i]->isChecked()){
                FColor[j]=Color[i];
                j++;
            }
        }
        zoom_in->setDisabled(false);
        zoom_out->setDisabled(false);
        reset->setDisabled(false);
        save->setDisabled(false);
    }
    init_formate(Listnumber,pvennformat[Listnumber-1]);
}


void MainWindow::Check_checkbox(){//检查有多少被选中，并将结果存在statisticList里
    int list=0;
    Listnumber=0;
    if (major->total<9){
        for(int i=0;i<major->total;i++){
            if(qCheckBox[i]->isChecked()){
                list=list+(1<<i);
                Listnumber++;
                qPushButton[i]->setEnabled(true);
                setbutcolor(i);
                qPushButton[i]->setToolTip(("Change "+major->Head[i]->name+"'s Color").c_str());
            }
            else{
                qPushButton[i]->setDisabled(true);
                qPushButton[i]->setStyleSheet("background-color:#F0F0F0");
                qPushButton[i]->setToolTip("");
        }
        }
    }
    else {
        for(int i=0;i<major->total;i++){
            list=list+(1<<i);
            }
        for(int i=0;i<maxSamples;i++)
            qPushButton[i]->setDisabled(true);
        Listnumber=major->total;
    }
    statisticList=list;
    Generate();
}


void MainWindow::about(){
    QMessageBox::about(this,QString("CopyRight(C)"),QString("<html><head/><body><p><span style=\" font-weight:600;\">VennPainter V1.1.0 is a tool for drawing venn diagrams with </span><span style=\" font-weight:600; color:#ff0000;\">nest venn diagrams.</span><span style=\" font-weight:600; color:#000000;\"> It also provide classic venn and Edward's venn.</span></p><p><br/></p><p><span style=\" font-weight:600; color:#000000;\">Bug report:</span><a href=\"mailto:linguoliang1313@gmail.com\"><span style=\" text-decoration: underline; color:#0000ff;\">linguoliang1313@gmail.com</span></a></p></body></html>"));
}

void MainWindow::aboutQt(){
    QMessageBox::aboutQt(this);
}

void MainWindow::ChangeColor1(){
    try{
        qColorDialog=new QColorDialog(Qt::white, this);}
    catch(std::bad_alloc& ba){
        QMessageBox::critical(this,QString("Error!"),QString(ba.what())+"\n This program will exit!");
        exit(1);
    }
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
    try{
        qColorDialog=new QColorDialog(Qt::white, this);}
    catch(std::bad_alloc& ba){
        QMessageBox::critical(this,QString("Error!"),QString(ba.what())+"\n This program will exit!");
        exit(1);
    }
    if(qColorDialog->exec()==QDialog::Accepted){
        qColor[1]=qColorDialog->selectedColor();
        setbutcolor(1);
        reload();
        ui->actionSave_color_palette->setEnabled(true);
    }
    delete qColorDialog;
}

void MainWindow::ChangeColor3(){
    try{
        qColorDialog=new QColorDialog(Qt::white, this);}
    catch(std::bad_alloc& ba){
        QMessageBox::critical(this,QString("Error!"),QString(ba.what())+"\n This program will exit!");
        exit(1);
    }
    if(qColorDialog->exec()==QDialog::Accepted){
        qColor[2]=qColorDialog->selectedColor();
        setbutcolor(2);
        reload();
        ui->actionSave_color_palette->setEnabled(true);
    }
    delete qColorDialog;
}

void MainWindow::ChangeColor4(){
    try{
        qColorDialog=new QColorDialog(Qt::white, this);}
    catch(std::bad_alloc& ba){
        QMessageBox::critical(this,QString("Error!"),QString(ba.what())+"\n This program will exit!");
        exit(1);
    }
    if(qColorDialog->exec()==QDialog::Accepted){
        qColor[3]=qColorDialog->selectedColor();
        setbutcolor(3);
        reload();
        ui->actionSave_color_palette->setEnabled(true);
    }
    delete qColorDialog;
}

void MainWindow::ChangeColor5(){
    try{
        qColorDialog=new QColorDialog(Qt::white, this);}
    catch(std::bad_alloc& ba){
        QMessageBox::critical(this,QString("Error!"),QString(ba.what())+"\n This program will exit!");
        exit(1);
    }
    if(qColorDialog->exec()==QDialog::Accepted){
        qColor[4]=qColorDialog->selectedColor();
        setbutcolor(4);
        reload();
        ui->actionSave_color_palette->setEnabled(true);
    }
    delete qColorDialog;
}

void MainWindow::ChangeColor6(){
    try{
    qColorDialog=new QColorDialog(Qt::white, this);}
    catch(std::bad_alloc& ba){
        QMessageBox::critical(this,QString("Error!"),QString(ba.what())+"\n This program will exit!");
        exit(1);
    }
    if(qColorDialog->exec()==QDialog::Accepted){
        qColor[5]=qColorDialog->selectedColor();
        setbutcolor(5);
        reload();
        ui->actionSave_color_palette->setEnabled(true);
    }
    delete qColorDialog;
}

void MainWindow::ChangeColor7(){
    try{
        qColorDialog=new QColorDialog(Qt::white, this);}
    catch(std::bad_alloc& ba){
        QMessageBox::critical(this,QString("Error!"),QString(ba.what())+"\n This program will exit!");
        exit(1);
    }
    if(qColorDialog->exec()==QDialog::Accepted){
        qColor[6]=qColorDialog->selectedColor();
        setbutcolor(6);
        reload();
        ui->actionSave_color_palette->setEnabled(true);
    }
    delete qColorDialog;
}

void MainWindow::ChangeColor8(){
    try{
    qColorDialog=new QColorDialog(Qt::white, this);}
    catch(std::bad_alloc& ba){
        QMessageBox::critical(this,QString("Error!"),QString(ba.what())+"\n This program will exit!");
        exit(1);
    }
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
    picture->flush(Listnumber,major->outputStatistic,major->outPutHead,FColor,temppath+"/Linvenn.svg",pvennformat[Listnumber-1]);
    picture->flush2(Listnumber,major->outputStatistic,major->outPutHead,FColor,temppath+"/Linvenn_v.svg",pvennformat[Listnumber-1],major->outputstring);
    ui->webView->reload();
    states=1;
}

//清除载入的数据
void MainWindow::Remove(){
    setdisable();
    major->Remove();
    statisticList=0;
    Listnumber=0;
    FILE * p=fopen((temppath+"/Linvenn_v.svg").toLocal8Bit(),"w");
    fclose(p);
    ui->webView->load(QUrl(temppath+"/Linvenn_v.svg"));
    ui->webView->load(QUrl(QString("Sample_workflow.html")));
    ui->plainTextEdit->clear();
    //set very thing invisible
    for(int i=0;i<8;i++){
        qPushButton[i]->setDisabled(true);
        qPushButton[i]->setVisible(false);
        qCheckBox[i]->setDisabled(true);
        qCheckBox[i]->setChecked(false);
        qCheckBox[i]->setVisible(false);
    }
    //set widget invisible
    ui->groupBox->setVisible(false);
    ui->label->setVisible(false);
    ui->plainTextEdit->setVisible(false);
//    ui->groupBox->setMinimumWidth(0);
//    ui->groupBox->setMaximumWidth(0);
    ui->pushButton_9->setDisabled(true);
    ui->pushButton_9->setVisible(false);
    ui->pushButton_10->setDisabled(true);
    ui->pushButton_10->setVisible(false);
    ui->webView->load(QUrl(QString("Sample_workflow.html")));
    states=0;
}

//存储配置文件
void MainWindow::Save_palette(){
    QString filenm;
    filenm = QFileDialog::getSaveFileName(this,tr("Save File"),file_path+"/untitled", tr("Files (*.plt);;All Files (*.*)"));
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
    filenm = QFileDialog::getOpenFileName(this,tr("Open Files"),file_path,tr("Files (*.plt);;All Files (*.*)"));
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

//set disable
void MainWindow::setdisable(int tmp){
    int temp=8;
    while(temp>0){
        temp--;
        qCheckBox[temp]->setText("");
        qCheckBox[temp]->setDisabled(true);
        qPushButton[temp]->setDisabled(true);
    }
    ui->actionSave_Imgage_I->setDisabled(true);
    zoom_in->setDisabled(true);
    zoom_out->setDisabled(true);
    reset->setDisabled(true);   
    nest->setDisabled(true);
    edwards->setDisabled(true);
    classic->setDisabled(true);
    save->setEnabled(false);
    if(tmp==0){
        ui->pushButton_9->setDisabled(true);
        ui->actionSave_as_S->setDisabled(true);
        ui->pushButton_10->setDisabled(true);
    }else{
        ui->pushButton_9->setDisabled(false);
        ui->actionSave_as_S->setDisabled(false);
        ui->pushButton_10->setDisabled(false);
    }
}

//初始化venn_formate状态
void MainWindow::init_formate(int ListNumber,int trigger_Id){
    switch (ListNumber) {
    case 1:
        setvennstate(3);
        break;
    case 2:
        setvennstate(1);
        break;
    case 3:
        setvennstate(1);
        break;
    case 4:
        setvennstate(1);
        break;
    case 5:
        setvennstate(0);
        break;
    case 6:
        setvennstate(4);
        break;
    case 7:
        setvennstate(6);
        break;
    case 8:
        setvennstate(6);
        break;
    default:
        setvennstate(7);
        break;
    }
    trigger_format(trigger_Id);
}

void MainWindow::nest_stat(){
    nest->setIconVisibleInMenu(true);
    classic->setIconVisibleInMenu(false);
    edwards->setIconVisibleInMenu(false);
    pvennformat[Listnumber-1]=0;
    picture->flush2(Listnumber,major->outputStatistic,major->outPutHead,FColor,temppath+"/Linvenn_v.svg",pvennformat[Listnumber-1],major->outputstring);
    picture->flush(Listnumber,major->outputStatistic,major->outPutHead,FColor,temppath+"/Linvenn.svg",pvennformat[Listnumber-1]);
    ui->webView->load(QUrl(temppath+"/Linvenn_v.svg"));
    states=1;
}

void MainWindow::edwards_stat(){
    edwards->setIconVisibleInMenu(true);
    nest->setIconVisibleInMenu(false);
    classic->setIconVisibleInMenu(false);
    pvennformat[Listnumber-1]=1;
    picture->flush2(Listnumber,major->outputStatistic,major->outPutHead,FColor,temppath+"/Linvenn_v.svg",pvennformat[Listnumber-1],major->outputstring);
    picture->flush(Listnumber,major->outputStatistic,major->outPutHead,FColor,temppath+"/Linvenn.svg",pvennformat[Listnumber-1]);
    ui->webView->load(QUrl(temppath+"/Linvenn_v.svg"));
    states=1;
}

void MainWindow::classic_stat(){
    edwards->setIconVisibleInMenu(false);
    nest->setIconVisibleInMenu(false);
    classic->setIconVisibleInMenu(true);
    pvennformat[Listnumber-1]=2;
    picture->flush2(Listnumber,major->outputStatistic,major->outPutHead,FColor,temppath+"/Linvenn_v.svg",pvennformat[Listnumber-1],major->outputstring);
    picture->flush(Listnumber,major->outputStatistic,major->outPutHead,FColor,temppath+"/Linvenn.svg",pvennformat[Listnumber-1]);
    ui->webView->load(QUrl(temppath+"/Linvenn_v.svg"));
    states=1;
}

void MainWindow::matrix_state(){
    edwards->setIconVisibleInMenu(false);
    nest->setIconVisibleInMenu(false);
    classic->setIconVisibleInMenu(false);    
    setdisable(1);
    pvennformat[Listnumber-1]=3;
    picture->flush(Listnumber,major->outputStatistic,major->Head,FColor,temppath+"/Linvenn.html",pvennformat[Listnumber-1]);
    ui->webView->load(QUrl(temppath+"/Linvenn.html"));
    states=1;
    itemName *p;
    int bin=(1<<Listnumber)-1;
    ui->plainTextEdit->clear();
    for(int i=0;i<hashArrayMaxSize;i++){
        p=major->hashItemArray[i];
        while (p) {
            if(p->list==bin)
                ui->plainTextEdit->appendPlainText(p->item.c_str());
            p=p->next;
        }
    }
}

void MainWindow::trigger_format(int trigger_Id){
    switch (trigger_Id) {
    case 0:
        nest->trigger();
        break;
    case 1:
        edwards->trigger();
        break;
    case 2:
        classic->trigger();
        break;
    default:
        matrix_state();
        break;
    }
}

void MainWindow::exportunit(){
    QString file1;
    file1= QFileDialog::getSaveFileName(this,
            tr("Save File"),file_path+'/'+ui->label->toolTip().replace('\\','-'), tr("Text (*.txt);;All Files (*.*)"));

        if (!file1.isNull())
        {
            file_path=file1;
            file_path.replace('\\','/');
            file_path.remove(file_path.lastIndexOf('/'),file_path.length());
            qDebug()<<file_path;
            QFile* temp=new QFile(file1);
            if(temp->exists()){
                if(!(temp->remove())){
                    QMessageBox::critical(this,"Oops!","Can't Replace the File!",QMessageBox::Ok);
                    delete temp;
                    return;
                }
            }
            delete temp;
            FILE *p;
            p=fopen(file1.toLocal8Bit(),"w");
            itemName *q;
            q=major->vertical[selecId];
            while (q) {
                fprintf(p,"%s\n",q->item.c_str());
                q=q->line;
            }
            fclose(p);
            return;
        }
        else{

        }                     //点的是取消
}

void MainWindow::setvennstate(int flag){//设置venn图的状态
    QList<QAction* > list1;
    list1.append(nest);
    list1.append(edwards);
    list1.append(classic);
    for(int i=0,m=flag;i<3;i++){
        if(m%2==1)
            list1[i]->setDisabled(true);
        else
            list1[i]->setDisabled(false);
        m=m/2;
    }
}

void MainWindow::help(){
    if(ui->webView->url().toString().contains(QString("index.html"))){
        if(states){
            if(major->total>8){
                ui->webView->load(QUrl(temppath+"/Linvenn.html"));
            }else{
                ui->webView->load(QUrl(temppath+"/Linvenn_v.svg"));
            }
        }else{
            ui->webView->load(QUrl(QString("Sample_workflow.html")));
        }
    }
    else{
        ui->webView->load(QUrl(QString("index.html")));
    }

}
