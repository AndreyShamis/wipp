#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "a.out.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->scanned = false;
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateCaption()));
    timer->start(1000);

    QTimer *timer2 = new QTimer(this);
    connect(timer2, SIGNAL(timeout()), this, SLOT(FastTimer()));
    timer2->start(300);
}

void MainWindow::FastTimer()
{
    //this->getPhy80211Devices();
    this->GUI_UpdateInetDevices();
}

void MainWindow::GUI_UpdateInetDevices()
{
    //QList<netInterface> temp = interf;
    this->UpdateNetInterfaces();

    //if(temp != interf)
    //{
        ui->treeLblAllInterfaces->clear();
        foreach (netInterface sta, interf) {
            QTreeWidget * tree = ui->treeLblAllInterfaces;

            QTreeWidgetItem * topLevel = new QTreeWidgetItem();
            topLevel->setText(0, sta.NAME );
            topLevel->setText(1, sta.MAC_ADDR);
            topLevel->setText(2, sta.IP_ADDR);
            tree->addTopLevelItem(topLevel);
        }
    //}
}

MainWindow::~MainWindow()
{
    delete ui;
}
cmdRes MainWindow::RunLs(QString paramsAndPath)
{
    cmdRes ret;
    QProcess p;
    p.setProcessChannelMode(QProcess::MergedChannels);

    p.start("ls",paramsAndPath.split(" ") );
    p.waitForFinished(-1);

    QString p_stdout = p.readAllStandardOutput();
    QString p_stderr = p.readAllStandardError();
    ret.std_out = p_stdout;
    ret.std_err = p_stderr;

    return ret;
}

cmdRes MainWindow::RunScript(QString scriptPath,QString params)
{
    cmdRes ret;
    QProcess p;
    p.setProcessChannelMode(QProcess::MergedChannels);

    p.start(scriptPath,params.split(" "));
    p.waitForFinished(-1);

    QString p_stdout = p.readAllStandardOutput();
    QString p_stderr = p.readAllStandardError();
    ret.std_out = p_stdout;
    ret.std_err = p_stderr;

    return ret;
}

void MainWindow::getPhy80211Devices()
{
    QString cmd = "/sys/class/net/";
    cmdRes res = this->RunLs(cmd);
    if(res.std_err.length() > 0)
        ui->txtLog->append("Error["+ cmd +"]:" + res.std_err);
    else
    {
        //ui->lstAllInterfaces->clear();
        QStringList fields = res.std_out.split('\n');
        foreach (QString temp, fields) {
         //   ui->lstAllInterfaces->addItem(temp);
        }
    }
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
        QStringList fields = res.std_out.split('\n');
        this->bss_sta.clear();
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
                //this->PrintWPA_STA(sta);
                bss_sta.append(sta);
            }
        }
        this->PrintWPA_STAs();
    }
}

void MainWindow::PrintWPA_STA(wpa_cli_sta sta)
{
    QTreeWidget * tree = ui->treeBSSSTA;

    QTreeWidgetItem * topLevel = new QTreeWidgetItem();
    topLevel->setText(0, sta.SSID );
    topLevel->setText(1, sta.MAC_ADDR);
    topLevel->setText(2, QString::number(sta.Frequency));
    topLevel->setText(3, QString::number(sta.RSSI));
    tree->addTopLevelItem(topLevel);
}

void MainWindow::PrintWPA_STAs()
{
    ui->treeBSSSTA->clear();

    foreach (wpa_cli_sta sta, bss_sta) {
        this->PrintWPA_STA(sta);
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
    this->scanned = true;
}

void MainWindow::updateCaption()
{
    this->BSSScanResult();
}

void MainWindow::on_btnGetBSS_clicked()
{
    if(!this->scanned )
    {
        this->BSSScan();
        sleep(3);

        this->scanned = true;
    }

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

void MainWindow::on_btnPrintBss_clicked()
{
    this->PrintWPA_STAs();
}

QString MainWindow::getIpByInetName(QString inetName)
{
    QString ret;
    cmdRes res=  this->RunScript("/home/tester/devel/wipp/./getIpAddressByInterface.sh",inetName);
    QStringList ips = res.std_out.split('\n');
    if(ips.length()>0)
    {
        ret = ips[0];
    }
    return ret;
}

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::UpdateNetInterfaces()
{
    interf.clear();
    cmdRes res=  this->RunScript("/home/tester/devel/wipp/getInterfacesAndMac.sh","");
    QStringList interfaces = res.std_out.split('\n');
    foreach (QString t, interfaces)
    {
        QStringList interface = t.split(' ');
        if(interface.length()==2)
        {
        netInterface temp;
        temp.NAME = interface[0];
        temp.MAC_ADDR = interface[1];
        temp.IP_ADDR = this->getIpByInetName(temp.NAME);
        interf.append(temp);
        }
    }
}
