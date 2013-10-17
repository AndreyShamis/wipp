#include "common.h"
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <unistd.h>
#include <QTimer>
#include <QThread>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    QThread thread;
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_btnScanBSS_clicked();

    void on_btnGetBSS_clicked();

    void on_btnP2pFind_clicked();

    void on_btnP2pPeers_clicked();

    void on_btnScanBSS_2_clicked();

    void on_btnModprobe_clicked();
    void updateCaption();
    void FastTimer();
    void on_btnModprobeR_clicked();

    void on_btnPrintBss_clicked();

    void on_pushButton_clicked();
    void ReloadDriver();
    void on_btnReloadDriver_clicked();

private:
    p2p_device getP2PDeviceInfo(QString);
    void UpdateNetInterfaces();
    void GUI_UpdateInetDevices();
    QString getIpByInetName(QString inetName);
    cmdRes      RunLs(QString paramsAndPath);
    cmdRes      RunScript(QString scriptPath,QString);
    void        getPhy80211Devices();
    void        PrintWPA_STAs();
    void        Modprobe(QString driverName,bool remove);
    void        PrintWPA_STA(wpa_cli_sta sta);
    void        ls();
    void        P2PFind();
    void        getRssi(QString interface);
    void        P2PPeers();

    QString     ReadCommand(QString val);
    QString     Run(QString cmd);
    cmdRes      RunCmd(QString cmd);
    void        BSSScan();
    void        BSSScanResult();
    //-------------- Variables -------------
    Ui::MainWindow  *ui;
    bool            scanned;

    QList<wpa_cli_sta> bss_sta;
    QList<netInterface> interf;
};

#endif // MAINWINDOW_H
