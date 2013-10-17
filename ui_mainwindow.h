/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Oct 17 11:58:48 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTextEdit *txtLog;
    QPushButton *btnGetBSS;
    QPushButton *btnScanBSS;
    QPushButton *btnP2pFind;
    QPushButton *btnP2pPeers;
    QLabel *lblRSSI;
    QLabel *lblRSSIValue;
    QPushButton *btnScanBSS_2;
    QPushButton *btnModprobeR;
    QPushButton *btnModprobe;
    QTreeWidget *treeBSSSTA;
    QTreeWidget *treeP2PSta;
    QPushButton *btnPrintBss;
    QPushButton *pushButton;
    QTreeWidget *treeLblAllInterfaces;
    QPushButton *btnReloadDriver;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1091, 509);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        txtLog = new QTextEdit(centralWidget);
        txtLog->setObjectName(QString::fromUtf8("txtLog"));
        txtLog->setGeometry(QRect(0, 150, 541, 321));
        btnGetBSS = new QPushButton(centralWidget);
        btnGetBSS->setObjectName(QString::fromUtf8("btnGetBSS"));
        btnGetBSS->setGeometry(QRect(650, 0, 80, 23));
        btnScanBSS = new QPushButton(centralWidget);
        btnScanBSS->setObjectName(QString::fromUtf8("btnScanBSS"));
        btnScanBSS->setGeometry(QRect(570, 0, 80, 23));
        btnP2pFind = new QPushButton(centralWidget);
        btnP2pFind->setObjectName(QString::fromUtf8("btnP2pFind"));
        btnP2pFind->setGeometry(QRect(550, 320, 80, 23));
        btnP2pPeers = new QPushButton(centralWidget);
        btnP2pPeers->setObjectName(QString::fromUtf8("btnP2pPeers"));
        btnP2pPeers->setGeometry(QRect(630, 320, 80, 23));
        lblRSSI = new QLabel(centralWidget);
        lblRSSI->setObjectName(QString::fromUtf8("lblRSSI"));
        lblRSSI->setGeometry(QRect(460, 30, 31, 16));
        lblRSSIValue = new QLabel(centralWidget);
        lblRSSIValue->setObjectName(QString::fromUtf8("lblRSSIValue"));
        lblRSSIValue->setGeometry(QRect(500, 30, 41, 16));
        btnScanBSS_2 = new QPushButton(centralWidget);
        btnScanBSS_2->setObjectName(QString::fromUtf8("btnScanBSS_2"));
        btnScanBSS_2->setGeometry(QRect(470, 50, 80, 23));
        btnModprobeR = new QPushButton(centralWidget);
        btnModprobeR->setObjectName(QString::fromUtf8("btnModprobeR"));
        btnModprobeR->setGeometry(QRect(470, 90, 80, 23));
        btnModprobe = new QPushButton(centralWidget);
        btnModprobe->setObjectName(QString::fromUtf8("btnModprobe"));
        btnModprobe->setGeometry(QRect(470, 110, 80, 23));
        treeBSSSTA = new QTreeWidget(centralWidget);
        treeBSSSTA->setObjectName(QString::fromUtf8("treeBSSSTA"));
        treeBSSSTA->setGeometry(QRect(550, 30, 531, 271));
        treeBSSSTA->setSortingEnabled(true);
        treeBSSSTA->header()->setDefaultSectionSize(122);
        treeP2PSta = new QTreeWidget(centralWidget);
        treeP2PSta->setObjectName(QString::fromUtf8("treeP2PSta"));
        treeP2PSta->setGeometry(QRect(550, 350, 531, 111));
        btnPrintBss = new QPushButton(centralWidget);
        btnPrintBss->setObjectName(QString::fromUtf8("btnPrintBss"));
        btnPrintBss->setGeometry(QRect(730, 0, 80, 23));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(470, 70, 80, 23));
        treeLblAllInterfaces = new QTreeWidget(centralWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setTextAlignment(1, Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        treeLblAllInterfaces->setHeaderItem(__qtreewidgetitem);
        treeLblAllInterfaces->setObjectName(QString::fromUtf8("treeLblAllInterfaces"));
        treeLblAllInterfaces->setGeometry(QRect(0, 0, 461, 151));
        treeLblAllInterfaces->setSortingEnabled(true);
        treeLblAllInterfaces->header()->setDefaultSectionSize(120);
        treeLblAllInterfaces->header()->setHighlightSections(false);
        btnReloadDriver = new QPushButton(centralWidget);
        btnReloadDriver->setObjectName(QString::fromUtf8("btnReloadDriver"));
        btnReloadDriver->setGeometry(QRect(470, 0, 91, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1091, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "WIPP", 0, QApplication::UnicodeUTF8));
        btnGetBSS->setText(QApplication::translate("MainWindow", "BSS", 0, QApplication::UnicodeUTF8));
        btnScanBSS->setText(QApplication::translate("MainWindow", "Scan", 0, QApplication::UnicodeUTF8));
        btnP2pFind->setText(QApplication::translate("MainWindow", "P2P Find", 0, QApplication::UnicodeUTF8));
        btnP2pPeers->setText(QApplication::translate("MainWindow", "P2P Peers", 0, QApplication::UnicodeUTF8));
        lblRSSI->setText(QApplication::translate("MainWindow", "RSSI", 0, QApplication::UnicodeUTF8));
        lblRSSIValue->setText(QApplication::translate("MainWindow", "-100", 0, QApplication::UnicodeUTF8));
        btnScanBSS_2->setText(QApplication::translate("MainWindow", "ls", 0, QApplication::UnicodeUTF8));
        btnModprobeR->setText(QApplication::translate("MainWindow", "Remove IWL", 0, QApplication::UnicodeUTF8));
        btnModprobe->setText(QApplication::translate("MainWindow", "Insert IWL", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treeBSSSTA->headerItem();
        ___qtreewidgetitem->setText(3, QApplication::translate("MainWindow", "RSSI", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(2, QApplication::translate("MainWindow", "Freq", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(1, QApplication::translate("MainWindow", "MAC ADDRESS ", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "SSID", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem1 = treeP2PSta->headerItem();
        ___qtreewidgetitem1->setText(0, QApplication::translate("MainWindow", "SSID", 0, QApplication::UnicodeUTF8));
        btnPrintBss->setText(QApplication::translate("MainWindow", "Print", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem2 = treeLblAllInterfaces->headerItem();
        ___qtreewidgetitem2->setText(2, QApplication::translate("MainWindow", "IP", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem2->setText(1, QApplication::translate("MainWindow", "MAC ADDRESS ", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem2->setText(0, QApplication::translate("MainWindow", "Name", 0, QApplication::UnicodeUTF8));
        btnReloadDriver->setText(QApplication::translate("MainWindow", "Reload Driver", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
