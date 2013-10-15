#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "a.out.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->txtLog->setText(this->ReadCommand("a"));
    //ui->txtLog->setText(this->Run("wpa_cli status"));
    //ui->txtLog->setText(this->RunCmd("wpa_cli status").std_err);
      ui->lstWiFiInterfaces->addItem("wlan0");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::BSSScan()
{
    QString cmd = this->ReadCommand("bss_scan");
    cmdRes res = this->RunCmd(cmd);
    if(res.std_err.length() > 0)
        ui->txtLog->append("Error["+ cmd +"]:" + res.std_err);
    else
        ui->txtLog->append("Start Scan");
}

void MainWindow::P2PFind()
{
    QString cmd = this->ReadCommand("p2p_find");
    cmdRes res = this->RunCmd(cmd);
    if(res.std_err.length() > 0)
        ui->txtLog->append("Error["+ cmd +"]:" + res.std_err);
    else
        ui->txtLog->append("Start Scan");
}

void MainWindow::P2PPeers()
{
    QString cmd = this->ReadCommand("p2p_peers");
    cmdRes res = this->RunCmd(cmd);
    if(res.std_err.length() > 0)
        ui->txtLog->append("Error["+ cmd +"]:" + res.std_err);
    else
        ui->txtLog->append("Here is p2p peers:");
}

void MainWindow::BSSScanResult()
{
    QString str = " | grep -E -o '[[:xdigit:]]{2}(:[[:xdigit:]]{2}){5}[[:space:]][[:xdigit:]]{4}[[:space:]]\-[[:xdigit:]]{1,3}'";
    QString cmd  = this->ReadCommand("bss_get_scan_res") + str;
    cmdRes res = this->RunCmd(cmd);
    if(res.std_err.length() > 0)
    {
        ui->txtLog->append("Error :[" + cmd + "] " + res.std_err);
    }
    else
    {
        ui->txtLog->append("Here is results:");
        QStringList fields = res.std_out.split("=");
        foreach (QString t, fields)
        {
            ui->txtLog->append(t);
        }
    }
}


void MainWindow::getRssi(QString interface)
{

    cmdRes res = this->RunCmd(this->ReadCommand("sudo wpa_cli -i " + interface + " signal_poll | grep RSSI"));
    if(res.std_err.length() > 0)
        ui->txtLog->append("Error" + res.std_err);
    else
    {
        ui->txtLog->append("RSSI is:");
        QStringList fields = res.std_out.split("=");
        foreach (QString t, fields)
            ui->txtLog->append(t);
    }
}

QString MainWindow::Run(QString cmd)
{
    cmdRes temp;
    temp = this->RunCmd(cmd);
    return temp.std_out;
}

cmdRes MainWindow::RunCmd(QString cmd)
{
    cmdRes ret;
    QProcess p;
    p.start(cmd);
    p.waitForFinished(-1);
    QString p_stdout = p.readAllStandardOutput();
    QString p_stderr = p.readAllStandardError();
    ret.std_out = p_stdout;
    ret.std_err = p_stderr;

    return ret;
}

QString MainWindow::ReadCommand(QString val)
{
    QString ret;
    QFile file("./wipp.settings");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split("=");
        //model->appendRow(fields);
        if(!fields[0].compare(val))
        {
            ret = fields[1];
            break;
        }
    }
    file.close();
    return ret;
}

void MainWindow::on_btnScanBSS_clicked()
{
    this->BSSScan();
}

void MainWindow::on_btnGetBSS_clicked()
{
    this->BSSScanResult();
}

void MainWindow::on_btnP2pFind_clicked()
{
    this->P2PFind();
}

void MainWindow::on_btnP2pPeers_clicked()
{
    this->P2PPeers();
}
