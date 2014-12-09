#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "LinSvg.h"
#include <QColorDialog>
#include <QColor>
#include <QtGui>
#include <QPalette>
#include "returnvalues.h"
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
    void open();
    void Zoom_out();
    void Zoom_in();
    void Reset();
    void Save_picture();
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
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void transcolor();
    void setbutcolor(int i);
    void reload();
    Ui::MainWindow *ui;
    QAction *zoom_out,*zoom_in,*reset,*save;
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
    int stat[4];
};

#endif // MAINWINDOW_H
