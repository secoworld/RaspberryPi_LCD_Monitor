//
// Created by longtao on 2025/10/7.
//
#include "ts_dev.h"

static struct tsdev *ts;

void tsdev_init(void)
{
    char *tsdevname = getenv("TSLIB_TSDEVICE");
    if (tsdevname == NULL) {
        printf("Not found env named: TSLIB_TSDEVICE, %s \n", tsdevname);
        exit(-1);
    }
    printf("TSLIB_TSDEVICE : %s\n", tsdevname);

    ts = ts_open(tsdevname, 1);
    if (ts == NULL) {
        printf("Failed to open tsdev: %s\n", tsdevname);
        exit(-1);
    }
    ts_config(ts);
}


/**
 * Get the current position and state of the tsdev
 * @param data store the tsdev data here
 * @return false: because the points are not buffered, so no more data to be read
 */
void tsdev_read(lv_indev_t * indev, lv_indev_data_t * data)
{
    static struct ts_sample samp;
    while (ts_read(ts, &samp, 1) == 1) {
        printf("%ld.%06ld: %6d %6d %6d %d\n",
            samp.tv.tv_sec, samp.tv.tv_usec,
            samp.x, samp.y, samp.pressure, data->state);
    }


    data->point.x = samp.x;
    data->point.y = samp.y;
    data->state = samp.pressure ? LV_INDEV_STATE_PR : LV_INDEV_STATE_REL;
}
