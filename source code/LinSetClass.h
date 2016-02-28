#ifndef LINSETCLASS_H
#define LINSETCLASS_H
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <string>
#include <QString>
#include <QMainWindow>
#include <QFileDialog>
#include <QWebView>
#include <QtWebKit/QtWebKit>
#include <QList>
#include <QAction>
#include <QDir>
#include <QTemporaryFile>
#include <QWheelEvent>
#include <QMessageBox>
#include <QtCore>
#include <QPlainTextEdit>
#include "values.h"
const  int nameMaxSize = 256;
const  int itemMaxSize = 256;
const  int hashArrayMaxSize = 240000;
const  int shareSet = 256;
const  int maxSamples = 8;
const  int stackMaxSize=2048;
const  int maxNonraph=31;
struct fileIfo
{
    std::string name;
    std::string absaddr;
    int id ;    //file's id
    fileIfo(){
        id=0;
    }
};

struct itemName
{
    std::string item;
    int list;      //which file contains this item:list=list+(1<<(id-1))
    itemName* next;
    itemName* line;
    itemName(){
        list=0;
        next=NULL;
        line=NULL;
    }
};

class setClass
{
public:
    setClass(QString fileList);
    setClass();
	~setClass();
    void Remove();
    void traversal(); // 遍历
    void statistica(int list=255);
//    char stack[stackMaxSize],Rstack[stackMaxSize];
    int Top,RTop;
    int statistic[shareSet];//
    int outputStatistic[shareSet];
    std::string outputstring[shareSet];
    int total ;
    fileIfo *Head[maxNonraph];
    fileIfo *outPutHead[maxNonraph];
    int addFile(QString fileList);
    int initFileIfo(const char *tempfile);
    void transoutput(int list);
    void exportsharesets(QString filename, int list);
    void exportMatrixs(QString filename,int list);
    void exportvertical(QString filename, int list);
    int findunit(int vennId, int list);
    itemName *vertical[shareSet];
	itemName *hashItemArray[hashArrayMaxSize];
private:
    unsigned int BKDRHash(const char *str);
    void fillHashItemArray(int seq, int id, std::string item);
    void transoutput();
};

#endif
