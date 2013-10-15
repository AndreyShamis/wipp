#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "a.out.h"
#include <QProcess>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //ui->txtLog->setText(this->ReadCommand("a"));
    //ui->txtLog->setText(this->Run("wpa_cli status"));
    //ui->txtLog->setText(this->RunCmd("wpa_cli status").std_err);

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
    {
        ui->txtLog->append("Error["+ cmd +"]:" + res.std_err);
    }
    else
    {
        ui->txtLog->append("Start Scan");
    }
}

void MainWindow::BSSScanResult()
{
    QString str = " | grep -E -o '[[:xdigit:]]{2}(:[[:xdigit:]]{2}){5}[[:space:]][[:xdigit:]]{4}[[:space:]]\-[[:xdigit:]]{1,3}'";
    cmdRes res = this->RunCmd(this->ReadCommand("bss_get_scan_res" + str));
    if(res.std_err.length() > 0)
    {
        ui->txtLog->append("Error" + res.std_err);
    }
    else
    {
        QStringList fields = res.std_out.split("=");
        foreach (QString t, fields)
        {
            ui->txtLog->append(t);
        }
    }
}

QString MainWindow::Run(QString cmd)
{
    QString ret;
    QProcess p;
    p.start(cmd);
    p.waitForFinished(-1);

    QString p_stdout = p.readAllStandardOutput();
    QString p_stderr = p.readAllStandardError();
    ret = p_stdout;

    return ret;
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
    QFile file("/home/andy/wipp.settings");
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
