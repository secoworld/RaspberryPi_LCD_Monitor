//
// Created by longtao on 2025/10/7.
//

#ifndef LVGL_TS_DEV_H
#define LVGL_TS_DEV_H

#ifdef __cplusplus
extern "C" {
#endif

#include <tslib.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "lvgl/lvgl.h"

void tsdev_init(void);
void tsdev_read(lv_indev_t * indev, lv_indev_data_t * data);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif // LVGL_TS_DEV_H
