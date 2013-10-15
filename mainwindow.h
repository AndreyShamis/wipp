#include "common.h"
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    QString ReadCommand(QString val);
    QString Run(QString cmd);
    cmdRes RunCmd(QString cmd);
};

#endif // MAINWINDOW_H
