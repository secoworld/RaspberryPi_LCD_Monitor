//
// Created by longtao on 2025/10/7.
//

#ifndef LVGL_NETTOOLS_H
#define LVGL_NETTOOLS_H

#define LVGL_NETTOOLS_H


/*无线网卡文件名*/
#define WLAN_IF         "eth0"
/*刷新时间(s)*/
#define REFRESH_TIME    1

#define WIRELESS    "/sys/class/net/"WLAN_IF"/operstate"

typedef enum
{
    STATE_CONNECT = 0,
    STATE_DISCONNECT,
    STATE_FAIL,
}Net_State;

Net_State GetWirelessState();
Net_State GetNetState();
Net_State getNetDriveState(const char* devName);
int GetLocalIP(char * ifname, char * ip);
int GetCurNetFlow(char* netname, long int* rx_rate, long int* tx_rate);


#endif // LVGL_NETTOOLS_H
