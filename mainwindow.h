#include "common.h"
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_btnScanBSS_clicked();

    void on_btnGetBSS_clicked();

    void on_btnP2pFind_clicked();

    void on_btnP2pPeers_clicked();

private:
    void        P2PFind();
    void        getRssi(QString interface);
    void        P2PPeers();
    Ui::MainWindow *ui;
    QString     ReadCommand(QString val);
    QString     Run(QString cmd);
    cmdRes      RunCmd(QString cmd);
    void        BSSScan();
    void        BSSScanResult();
};

#endif // MAINWINDOW_H
