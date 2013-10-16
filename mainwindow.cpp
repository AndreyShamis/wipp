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


void MainWindow::ls()
{
    cmdRes res = this->RunCmd("ls -lah");
    if(res.std_err.length() > 0)
        ui->txtLog->append("Error[]:" + res.std_err);
    else
        ui->txtLog->append(res.std_out);
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

void MainWindow::Modprobe(QString driverName,bool remove=false)
{
    QString cmd = "modprobe ";

    if(remove)
        cmd=cmd+ "-r ";

    cmd         = cmd+ driverName;
    cmdRes res  = this->RunCmd(cmd);
    if(res.std_err.length() > 0)
        ui->txtLog->append("Error["+cmd+"]:" + res.std_err);
    else
        ui->txtLog->append(cmd + " " + res.std_out);
}

void MainWindow::P2PPeers()
{
    QString cmd = this->ReadCommand("p2p_peers");
    cmdRes res = this->RunCmd(cmd);
    if(res.std_err.length() > 0)
        ui->txtLog->append("Error["+ cmd +"]:" + res.std_err);
    else
        ui->txtLog->append("Here is p2p peers:" + res.std_out);
}

void MainWindow::BSSScanResult()
{
    QString str = " \| grep -oE '[[:xdigit:]]{2}(:[[:xdigit:]]{2}){5}[[:space:]][[:xdigit:]]{4}[[:space:]]\-[[:xdigit:]]{1,3}'";
    QString cmd  = this->ReadCommand("bss_get_scan_res") ;
    cmdRes res = this->RunCmd(cmd);
    if(res.std_err.length() > 0)
    {
        ui->txtLog->append("Error :[" + cmd + "] " + res.std_err);
    }
    else
    {
        //ui->txtLog->append("Here is results:" + res.std_out);
        QStringList fields = res.std_out.split('\n');
        foreach (QString t, fields)
        {

            QStringList fields2 = t.split('\t');
            if(fields2.length() > 3)
            {
                wpa_cli_sta sta ;
                sta.MAC_ADDR = fields2[0];
                sta.SSID     = fields2[4];
                sta.RSSI     = fields2[2].toInt();
                sta.Frequency=fields2[1].toInt();
                this->PrintWPA_STA(sta);
      //          foreach (QString t2, fields2)
       //         {
       //             ui->txtLog->append(t2);
       //         }
            }
        }
    }
}

void MainWindow::PrintWPA_STA(wpa_cli_sta sta)
{
    ui->txtLog->append("Device: " + sta.SSID + " MAC: " + sta.MAC_ADDR + " Freq: " + QString::number(sta.Frequency) + " RSSI: " + QString::number(sta.RSSI));
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
    p.setProcessChannelMode(QProcess::MergedChannels);
    p.start("sudo",cmd.split(" ") );
    //foreach (QString temp, cmd.split(" ")) {
    //    ui->txtLog->append(temp);
    //}
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

void MainWindow::on_btnScanBSS_2_clicked()
{
    this->ls();
}

void MainWindow::on_btnModprobe_clicked()
{
    this->Modprobe("iwlwifi",false);
    this->Modprobe("iwlmvm",false);
}


void MainWindow::on_btnModprobeR_clicked()
{
    this->Modprobe("iwlmvm",true);
    this->Modprobe("iwlwifi",true);
}
