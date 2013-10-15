/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue Oct 15 23:26:45 2013
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
#include <QtGui/QListView>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTextEdit *txtLog;
    QListView *lstAP;
    QPushButton *btnGetBSS;
    QPushButton *btnScanBSS;
    QListView *lstP2PPeers;
    QPushButton *btnP2pFind;
    QPushButton *btnP2pPeers;
    QLabel *label;
    QLabel *label_2;
    QListWidget *lstWiFiInterfaces;
    QListWidget *lstP2PInterfaces;
    QLabel *lblRSSI;
    QLabel *lblRSSIValue;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1067, 509);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        txtLog = new QTextEdit(centralWidget);
        txtLog->setObjectName(QString::fromUtf8("txtLog"));
        txtLog->setGeometry(QRect(0, 150, 601, 321));
        lstAP = new QListView(centralWidget);
        lstAP->setObjectName(QString::fromUtf8("lstAP"));
        lstAP->setGeometry(QRect(610, 30, 221, 441));
        btnGetBSS = new QPushButton(centralWidget);
        btnGetBSS->setObjectName(QString::fromUtf8("btnGetBSS"));
        btnGetBSS->setGeometry(QRect(690, 0, 80, 23));
        btnScanBSS = new QPushButton(centralWidget);
        btnScanBSS->setObjectName(QString::fromUtf8("btnScanBSS"));
        btnScanBSS->setGeometry(QRect(610, 0, 80, 23));
        lstP2PPeers = new QListView(centralWidget);
        lstP2PPeers->setObjectName(QString::fromUtf8("lstP2PPeers"));
        lstP2PPeers->setGeometry(QRect(840, 30, 221, 441));
        btnP2pFind = new QPushButton(centralWidget);
        btnP2pFind->setObjectName(QString::fromUtf8("btnP2pFind"));
        btnP2pFind->setGeometry(QRect(840, 0, 80, 23));
        btnP2pPeers = new QPushButton(centralWidget);
        btnP2pPeers->setObjectName(QString::fromUtf8("btnP2pPeers"));
        btnP2pPeers->setGeometry(QRect(920, 0, 80, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 101, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 10, 101, 16));
        lstWiFiInterfaces = new QListWidget(centralWidget);
        lstWiFiInterfaces->setObjectName(QString::fromUtf8("lstWiFiInterfaces"));
        lstWiFiInterfaces->setGeometry(QRect(10, 30, 101, 111));
        lstP2PInterfaces = new QListWidget(centralWidget);
        lstP2PInterfaces->setObjectName(QString::fromUtf8("lstP2PInterfaces"));
        lstP2PInterfaces->setGeometry(QRect(120, 30, 101, 111));
        lblRSSI = new QLabel(centralWidget);
        lblRSSI->setObjectName(QString::fromUtf8("lblRSSI"));
        lblRSSI->setGeometry(QRect(230, 10, 31, 16));
        lblRSSIValue = new QLabel(centralWidget);
        lblRSSIValue->setObjectName(QString::fromUtf8("lblRSSIValue"));
        lblRSSIValue->setGeometry(QRect(270, 10, 41, 16));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1067, 20));
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
        label->setText(QApplication::translate("MainWindow", "WiFi Interfaces", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "P2P Interfaces", 0, QApplication::UnicodeUTF8));
        lblRSSI->setText(QApplication::translate("MainWindow", "RSSI", 0, QApplication::UnicodeUTF8));
        lblRSSIValue->setText(QApplication::translate("MainWindow", "-100", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
