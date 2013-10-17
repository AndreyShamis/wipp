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


struct p2p_device
{
    QString MAC_ADDR;
    QString NAME;
    int listen_freq;
    QString wps_method;
    QString manufacturer;
};

#endif // COMMON_H
