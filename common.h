#include <QString>
#ifndef COMMON_H
#define COMMON_H
struct cmdRes{
    QString std_out;
    QString std_err;

};

struct wpa_cli_sta
{
    QString MAC_ADDR;
    QString SSID;
    int     Channel;
    int     Frequency;
    int     RSSI;
};

struct netInterface{
    QString MAC_ADDR;
    QString IP_ADDR;
    QString NAME;
};

#endif // COMMON_H
