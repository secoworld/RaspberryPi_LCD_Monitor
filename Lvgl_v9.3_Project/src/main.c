
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "lvgl/lvgl.h"
#include "ts_dev.h"
#include "gui_guider.h"
#include <signal.h>
#include "NetTools.h"
#include "DevInfo.h"

#include <signal.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>

#define LVGL_TICK 5

lv_ui guider_ui;

#define TEMP_STR_LEN    64
#define IP_STR_LEN      20
#define TO_GB(b)        ((b) / pow(1024, 3))
#define TO_SEC(h, m)    ((h) * 3600 + (m) * 60)

time_t currentTime;
struct tm *localTime;
uint8_t UpdateFlag;
char ipStr[IP_STR_LEN];
char tempStr[TEMP_STR_LEN];
unsigned int freeMem, totalMem;
long int start_rcv_rates = 0;   //保存开始时的流量计数
long int end_rcv_rates = 0;	    //保存结束时的流量计数
long int start_tx_rates = 0;    //保存开始时的流量计数
long int end_tx_rates = 0;      //保存结束时的流量计数
float tx_rates = 0;             //上传速度Bytes/s
float rx_rates = 0;             //下载速度Bytes/s
CPU_OCCUPY cpu_stat1;           //用于CPU利用率计算
CPU_OCCUPY cpu_stat2;
float cpuUsage;
Net_State wlanState;
char netSpeedUnit[4][5] = {
    "B/s",
    "KB/s",
    "MB/s",
    "GB/s",
};

void UpdateScreen();
void UpdateScreen()
{
    printf("start update screen!\n");
    /*显示网络状态*/
    // wlanState = GetWirelessState();

    const char *default_net_ip = "N/A";
    char *netDervice[] = {"eth0", "wlan0"};

    memset(tempStr, 0, TEMP_STR_LEN);
    for (int i = 0; i < 2; i++) {
        char *device = netDervice[i];
        memcpy(ipStr, default_net_ip, IP_STR_LEN);
        Net_State net_drive_state = getNetDriveState(device);
        if (net_drive_state == STATE_CONNECT) {
            memset(ipStr, 0, IP_STR_LEN);
            int ret = 0;
            ret = GetLocalIP(device, ipStr);
            // printf("device:%s, ip %s, ret: %d\n", device, ipStr, ret);
            if (ret != 0)   memcpy(ipStr, default_net_ip, IP_STR_LEN);
        }
        char buffer[128];
        int len = snprintf(buffer, TEMP_STR_LEN, "%s%s: %s\n", tempStr, device, ipStr);
        if (len < TEMP_STR_LEN) {
            strcpy(tempStr, buffer);
        } else {
            strncpy(tempStr, buffer, TEMP_STR_LEN - 1);
            tempStr[TEMP_STR_LEN - 1] = '\0';
        }
    }

    lv_label_set_text(guider_ui.screen_ip_label, tempStr);
    // printf("netstat : %s", tempStr);

    /*显示CPU利用率*/
    memset(tempStr, 0, TEMP_STR_LEN);
    sprintf(tempStr, "%.1f%%", cpuUsage);
    lv_label_set_text(guider_ui.screen_cpu_show_info, tempStr);
    lv_scale_set_line_needle_value(guider_ui.screen_cpu_meter, guider_ui.screen_cpu_meter_ndline_0, 40,  (uint32_t)cpuUsage);


    /*显示内存利用率*/
    float memUsage = GetMemUsage();

    memset(tempStr, 0, TEMP_STR_LEN);
    sprintf(tempStr, "%.1lf%%", memUsage);
    lv_label_set_text(guider_ui.screen_mem_show_info, tempStr);
    lv_scale_set_line_needle_value(guider_ui.screen_mem_meter, guider_ui.screen_mem_meter_ndline_0, 40, (uint32_t)memUsage);


    /*显示温度*/
    memset(tempStr, 0, TEMP_STR_LEN);
    sprintf(tempStr, "%.2f C", GetCpuTemp());
    lv_label_set_text(guider_ui.screen_label_temporary, tempStr);


    /*显示网速*/
    uint8_t rxUnitLevel = 0;
    uint8_t txUnitLevel = 0;
    while (tx_rates >= 1000)
    {
        tx_rates /= 1000;
        txUnitLevel++;
    }
    while (rx_rates >= 1000)
    {
        rx_rates /= 1000;
        rxUnitLevel++;
    }
    //显示Tx(Upload)
    memset(tempStr, 0, TEMP_STR_LEN);
    sprintf(tempStr, "%.1lf%s",
            tx_rates,
            netSpeedUnit[txUnitLevel]);
    lv_label_set_text(guider_ui.screen_label_upload, tempStr);

    //显示Rx(Download)
    memset(tempStr, 0, TEMP_STR_LEN);
    sprintf(tempStr, "%.1lf%s",
            rx_rates,
            netSpeedUnit[rxUnitLevel]);
    lv_label_set_text(guider_ui.screen_label_download, tempStr);

    /*显示磁盘剩余容量*/

    memset(tempStr, 0, TEMP_STR_LEN);
    float total_gb = GetTotalDiskGB();
    float used_gb = GetUsedDiskGB();
    sprintf(tempStr, "%.1f/%.1fG", used_gb, total_gb);
    lv_label_set_text(guider_ui.screen_usage_label, tempStr);
    lv_bar_set_value(guider_ui.screen_udis_bar, (int)((used_gb / total_gb) * 100), LV_ANIM_OFF);

    /*显示时间*/
    currentTime = time(NULL);
    localTime = localtime(&currentTime);
    sprintf(tempStr, "%02d:%02d:%02d", localTime->tm_hour, localTime->tm_min, localTime->tm_sec);
    lv_label_set_text(guider_ui.screen_time_label, tempStr);

    sprintf(tempStr, "%04d/%02d/%02d", localTime->tm_year+1900, localTime->tm_mon+1, localTime->tm_mday);
    lv_label_set_text(guider_ui.screen_date_label, tempStr);
}

void Timer_Handler()
{
    UpdateFlag = 1;
    lv_tick_inc(REFRESH_TIME * 1000);
}

void Timer_Init()
{
    struct sigaction sa;
    struct itimerval timer;

    // 设置定时器信号处理函数
    sa.sa_handler = Timer_Handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGALRM, &sa, NULL);

    // 设置定时器的时间间隔
    timer.it_value.tv_sec = 0;          // 初始延迟为0秒
    timer.it_value.tv_usec = 1000;      // 初始延迟为1毫秒
    timer.it_interval.tv_sec = REFRESH_TIME;       // 重复间隔为0秒
    timer.it_interval.tv_usec = 0;   // 重复间隔为1毫秒

    // 启动定时器
    setitimer(ITIMER_REAL, &timer, NULL);
}



int main()
{
    // Timer_Init();

    // 初始化LVGL
    lv_init();
    lv_display_t* disp = lv_linux_fbdev_create();
    lv_linux_fbdev_set_file(disp, "/dev/fb0");


    tsdev_init();
    lv_indev_t * indev = lv_indev_create();
    lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
    lv_indev_set_read_cb(indev, tsdev_read);
    lv_indev_set_display(indev, disp);

    // lv_example_btn_1();
    setup_ui(&guider_ui);
    UpdateScreen();
    uint32_t last_update = 0;

    while (true)
    {
        uint32_t start_tick = lv_tick_get();
        usleep(LVGL_TICK); /*Sleep for 5 millisecond*/
        lv_task_handler();
        lv_tick_inc(LVGL_TICK); /*Tell LVGL that 5 milliseconds were elapsed*/

        if (start_tick - last_update >= 1000) {
            last_update = start_tick;

            GetCurNetFlow(WLAN_IF, &end_rcv_rates, &end_tx_rates);
            get_cpuoccupy((CPU_OCCUPY *)&cpu_stat2);

            rx_rates = (float)(end_rcv_rates - start_rcv_rates);
            tx_rates = (float)(end_tx_rates - start_tx_rates);

            cpuUsage = cal_cpuoccupy(&cpu_stat1, &cpu_stat2);

            start_rcv_rates = end_rcv_rates;
            start_tx_rates = end_tx_rates;
            cpu_stat1 = cpu_stat2;

            UpdateScreen();
        }

    }
}