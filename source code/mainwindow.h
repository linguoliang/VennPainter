#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "LinSvg.h"
#include <QColorDialog>
#include <QColor>
#include <QtGui>
#include <QPalette>
#include <QPoint>
#include <QWebPage>
#include <QUrl>
#include "values.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
protected:
    bool eventFilter(QObject *obj, QEvent *event);
    void wheelRolled(QWheelEvent *event);

private slots:
    void singlecontent(QUrl url);
    void open();
    void Zoom_out();
    void Zoom_in();
    void Reset();
    void Save_picture();
    void nest_stat();
    void edwards_stat();
    void classic_stat();
    void matrix_state();
    void Generate();
    void Remove();
    void Check_checkbox();
    void about();
    void aboutQt();
    void exportsharesets();
    void ChangeColor1();
    void ChangeColor2();
    void ChangeColor3();
    void ChangeColor4();
    void ChangeColor5();
    void ChangeColor6();
    void ChangeColor7();
    void ChangeColor8();
    void Save_palette();
    void Load_palette();
    void exportunit();
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void init_formate(int ListNumber, int trigger_Id);
    void setdisable(int tmp=0);
    void transcolor();
    void setbutcolor(int i);
    void reload();
    void setformat();
    void trigger_format(int );
    void setvennstate(int );
    void setVennIcon(int );
    QWebPage *pagetmp;
    Ui::MainWindow *ui;
    QAction *zoom_out,*zoom_in,*reset,*save,*seprator,*nest,*edwards,*classic;
    QList<QAction* > *List;
    QStringList fileName,inputfilename;
    QString fileList;
    QString outputfilename;
    QString matrixForm;
    QString verticalForm;
    QString horizontalForm;
    QString temppath;
    QDir *temp;
    setClass *major;
    QCursor *Zoom;
    QColorDialog *qColorDialog;
    QColor qColor[8],*tempqColor[8];
    QPushButton  *qPushButton[8];//颜色选取元件
    QCheckBox *qCheckBox[8];
    svg *picture;//画图元件
    int statisticList;//被选中的元素
    int Listnumber;//被选中的元素个数
    int Color[8],FColor[8];
    QPalette bkgrd[8];
//0 for nested Venn, 1 for edward's Venn, 2 for normal, 3 for matrix
    int pvennformat[maxNonraph];
    int selecId;
};

#endif // MAINWINDOW_H
