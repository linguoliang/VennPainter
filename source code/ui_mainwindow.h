/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDockWidget>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include <QtWebKit/QWebView>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Open;
    QAction *actionSave_as_S;
    QAction *actionSave_Imgage_I;
    QAction *actionAbout_A;
    QAction *actionAbout_Qt;
    QAction *actionExport_shared_sets;
    QAction *actionSave_color_palette;
    QAction *actionLoad_color_palette;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QWebView *webView;
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButton_10;
    QMenuBar *menuBar;
    QMenu *menu_Files;
    QMenu *menuSetting_S;
    QMenu *menuHelp_H;
    QToolBar *toolBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_8;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_6;
    QPushButton *pushButton_9;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(916, 502);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Bio.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setWindowOpacity(1);
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setIconSize(QSize(128, 128));
        MainWindow->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks|QMainWindow::VerticalTabs);
        action_Open = new QAction(MainWindow);
        action_Open->setObjectName(QString::fromUtf8("action_Open"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Open.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Open->setIcon(icon1);
        actionSave_as_S = new QAction(MainWindow);
        actionSave_as_S->setObjectName(QString::fromUtf8("actionSave_as_S"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_as_S->setIcon(icon2);
        actionSave_Imgage_I = new QAction(MainWindow);
        actionSave_Imgage_I->setObjectName(QString::fromUtf8("actionSave_Imgage_I"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Save_Image.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_Imgage_I->setIcon(icon3);
        actionAbout_A = new QAction(MainWindow);
        actionAbout_A->setObjectName(QString::fromUtf8("actionAbout_A"));
        actionAbout_A->setIcon(icon);
        actionAbout_Qt = new QAction(MainWindow);
        actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Images/qtlogo-64.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout_Qt->setIcon(icon4);
        actionExport_shared_sets = new QAction(MainWindow);
        actionExport_shared_sets->setObjectName(QString::fromUtf8("actionExport_shared_sets"));
        actionSave_color_palette = new QAction(MainWindow);
        actionSave_color_palette->setObjectName(QString::fromUtf8("actionSave_color_palette"));
        actionLoad_color_palette = new QAction(MainWindow);
        actionLoad_color_palette->setObjectName(QString::fromUtf8("actionLoad_color_palette"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        webView = new QWebView(centralWidget);
        webView->setObjectName(QString::fromUtf8("webView"));
        sizePolicy.setHeightForWidth(webView->sizePolicy().hasHeightForWidth());
        webView->setSizePolicy(sizePolicy);
        webView->setMaximumSize(QSize(16777214, 16777215));
        webView->setUrl(QUrl(QString::fromUtf8("about:blank")));

        gridLayout->addWidget(webView, 0, 0, 2, 1);

        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy1);
        plainTextEdit->setMaximumSize(QSize(125, 16777215));

        gridLayout->addWidget(plainTextEdit, 0, 1, 1, 1);

        pushButton_10 = new QPushButton(centralWidget);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));

        gridLayout->addWidget(pushButton_10, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 916, 21));
        menu_Files = new QMenu(menuBar);
        menu_Files->setObjectName(QString::fromUtf8("menu_Files"));
        menuSetting_S = new QMenu(menuBar);
        menuSetting_S->setObjectName(QString::fromUtf8("menuSetting_S"));
        menuHelp_H = new QMenu(menuBar);
        menuHelp_H->setObjectName(QString::fromUtf8("menuHelp_H"));
        MainWindow->setMenuBar(menuBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidget->setMinimumSize(QSize(165, 295));
        dockWidget->setContextMenuPolicy(Qt::ActionsContextMenu);
        dockWidget->setFloating(false);
        dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        checkBox = new QCheckBox(dockWidgetContents);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(14, 54, 121, 16));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(checkBox->sizePolicy().hasHeightForWidth());
        checkBox->setSizePolicy(sizePolicy2);
        checkBox_2 = new QCheckBox(dockWidgetContents);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(14, 100, 121, 16));
        sizePolicy2.setHeightForWidth(checkBox_2->sizePolicy().hasHeightForWidth());
        checkBox_2->setSizePolicy(sizePolicy2);
        checkBox_4 = new QCheckBox(dockWidgetContents);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setGeometry(QRect(14, 192, 121, 16));
        sizePolicy2.setHeightForWidth(checkBox_4->sizePolicy().hasHeightForWidth());
        checkBox_4->setSizePolicy(sizePolicy2);
        checkBox_3 = new QCheckBox(dockWidgetContents);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(14, 146, 121, 16));
        sizePolicy2.setHeightForWidth(checkBox_3->sizePolicy().hasHeightForWidth());
        checkBox_3->setSizePolicy(sizePolicy2);
        checkBox_6 = new QCheckBox(dockWidgetContents);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));
        checkBox_6->setGeometry(QRect(14, 284, 121, 16));
        sizePolicy2.setHeightForWidth(checkBox_6->sizePolicy().hasHeightForWidth());
        checkBox_6->setSizePolicy(sizePolicy2);
        checkBox_7 = new QCheckBox(dockWidgetContents);
        checkBox_7->setObjectName(QString::fromUtf8("checkBox_7"));
        checkBox_7->setGeometry(QRect(14, 330, 121, 16));
        sizePolicy2.setHeightForWidth(checkBox_7->sizePolicy().hasHeightForWidth());
        checkBox_7->setSizePolicy(sizePolicy2);
        checkBox_5 = new QCheckBox(dockWidgetContents);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setGeometry(QRect(14, 238, 121, 16));
        sizePolicy2.setHeightForWidth(checkBox_5->sizePolicy().hasHeightForWidth());
        checkBox_5->setSizePolicy(sizePolicy2);
        checkBox_8 = new QCheckBox(dockWidgetContents);
        checkBox_8->setObjectName(QString::fromUtf8("checkBox_8"));
        checkBox_8->setGeometry(QRect(14, 376, 121, 16));
        sizePolicy2.setHeightForWidth(checkBox_8->sizePolicy().hasHeightForWidth());
        checkBox_8->setSizePolicy(sizePolicy2);
        pushButton_5 = new QPushButton(dockWidgetContents);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(141, 230, 19, 23));
        sizePolicy2.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy2);
        pushButton_4 = new QPushButton(dockWidgetContents);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(141, 190, 19, 23));
        sizePolicy2.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy2);
        pushButton_2 = new QPushButton(dockWidgetContents);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(141, 97, 19, 23));
        sizePolicy2.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy2);
        pushButton_3 = new QPushButton(dockWidgetContents);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(141, 144, 19, 23));
        sizePolicy2.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy2);
        pushButton = new QPushButton(dockWidgetContents);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(141, 50, 19, 23));
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);
        pushButton->setStyleSheet(QString::fromUtf8(""));
        pushButton_7 = new QPushButton(dockWidgetContents);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(141, 330, 19, 23));
        sizePolicy2.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy2);
        pushButton_8 = new QPushButton(dockWidgetContents);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(141, 370, 19, 23));
        sizePolicy2.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy2);
        pushButton_6 = new QPushButton(dockWidgetContents);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(141, 280, 19, 23));
        sizePolicy2.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy2);
        pushButton_9 = new QPushButton(dockWidgetContents);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(10, 410, 151, 23));
        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);

        menuBar->addAction(menu_Files->menuAction());
        menuBar->addAction(menuSetting_S->menuAction());
        menuBar->addAction(menuHelp_H->menuAction());
        menu_Files->addAction(action_Open);
        menu_Files->addAction(actionSave_as_S);
        menu_Files->addAction(actionSave_Imgage_I);
        menuSetting_S->addAction(actionSave_color_palette);
        menuSetting_S->addAction(actionLoad_color_palette);
        menuHelp_H->addAction(actionAbout_A);
        menuHelp_H->addAction(actionAbout_Qt);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "VennPainter", 0, QApplication::UnicodeUTF8));
        action_Open->setText(QApplication::translate("MainWindow", "Open(&O)", 0, QApplication::UnicodeUTF8));
        actionSave_as_S->setText(QApplication::translate("MainWindow", "Save as(&S)", 0, QApplication::UnicodeUTF8));
        actionSave_Imgage_I->setText(QApplication::translate("MainWindow", "Save imgage(&I)", 0, QApplication::UnicodeUTF8));
        actionAbout_A->setText(QApplication::translate("MainWindow", "About VennPainter(&A)", 0, QApplication::UnicodeUTF8));
        actionAbout_Qt->setText(QApplication::translate("MainWindow", "About Qt", 0, QApplication::UnicodeUTF8));
        actionExport_shared_sets->setText(QApplication::translate("MainWindow", "Export shared sets", 0, QApplication::UnicodeUTF8));
        actionSave_color_palette->setText(QApplication::translate("MainWindow", "Save config", 0, QApplication::UnicodeUTF8));
        actionLoad_color_palette->setText(QApplication::translate("MainWindow", "Load config", 0, QApplication::UnicodeUTF8));
        pushButton_10->setText(QApplication::translate("MainWindow", "Export", 0, QApplication::UnicodeUTF8));
        menu_Files->setTitle(QApplication::translate("MainWindow", "Files(&F)", 0, QApplication::UnicodeUTF8));
        menuSetting_S->setTitle(QApplication::translate("MainWindow", "Setting(&S)", 0, QApplication::UnicodeUTF8));
        menuHelp_H->setTitle(QApplication::translate("MainWindow", "Help(&H)", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
        dockWidget->setWindowTitle(QApplication::translate("MainWindow", "Settings", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QString());
        checkBox_2->setText(QString());
        checkBox_4->setText(QString());
        checkBox_3->setText(QString());
        checkBox_6->setText(QString());
        checkBox_7->setText(QString());
        checkBox_5->setText(QString());
        checkBox_8->setText(QString());
        pushButton_5->setText(QString());
        pushButton_4->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton->setText(QString());
        pushButton_7->setText(QString());
        pushButton_8->setText(QString());
        pushButton_6->setText(QString());
        pushButton_9->setText(QApplication::translate("MainWindow", "Remove", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
