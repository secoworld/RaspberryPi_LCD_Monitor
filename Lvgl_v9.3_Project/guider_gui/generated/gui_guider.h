/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"


typedef struct
{
  
	lv_obj_t *screen;
	bool screen_del;
	lv_obj_t *screen_logo_container;
	lv_obj_t *screen_logo__label;
	lv_obj_t *screen_respberr_pi;
	lv_obj_t *screen_CPU_label;
	lv_obj_t *screen_ip_container;
	lv_obj_t *screen_ip_label;
	lv_obj_t *screen_net_container;
	lv_obj_t *screen_img_4;
	lv_obj_t *screen_net_list;
	lv_obj_t *screen_net_list_item0;
	lv_obj_t *screen_net_list_item1;
	lv_obj_t *screen_net_list_item2;
	lv_obj_t *screen_label_upload;
	lv_obj_t *screen_img_temporary;
	lv_obj_t *screen_img_upload;
	lv_obj_t *screen_img_download;
	lv_obj_t *screen_label_download;
	lv_obj_t *screen_label_temporary;
	lv_obj_t *screen_mem_container;
	lv_obj_t *screen_mem_arc;
	lv_obj_t *screen_mem_label;
	lv_obj_t *screen_mem_show_info;
	lv_obj_t *screen_mem_meter;
	lv_obj_t *screen_mem_meter_ndline_0;
	lv_obj_t *screen_cpu_container;
	lv_obj_t *screen_cpu_arc;
	lv_obj_t *screen_cpu__label;
	lv_obj_t *screen_cpu_show_info;
	lv_obj_t *screen_cpu_meter;
	lv_obj_t *screen_cpu_meter_ndline_0;
	lv_obj_t *screen_disk_container;
	lv_obj_t *screen_Udisk_label;
	lv_obj_t *screen_usage_label;
	lv_obj_t *screen_alipan_label;
	lv_obj_t *screen_udisk_label;
	lv_obj_t *screen_udis_bar;
	lv_obj_t *screen_time_container;
	lv_obj_t *screen_date_label;
	lv_obj_t *screen_time_label;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_screen_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, uint32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                  uint32_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                  lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_completed_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_bottom_layer(void);

void setup_ui(lv_ui *ui);

void video_play(lv_ui *ui);

void init_keyboard(lv_ui *ui);

extern lv_ui guider_ui;


void setup_scr_screen(lv_ui *ui);
LV_IMAGE_DECLARE(_rpi_logo_e7_16bit_RGB565A8_31x29);
LV_IMAGE_DECLARE(_flow_RGB565A8_21x23);
LV_IMAGE_DECLARE(_upload_RGB565_20x20);
LV_IMAGE_DECLARE(_download_RGB565_20x20);
LV_IMAGE_DECLARE(_flow_RGB565_20x20);
LV_IMAGE_DECLARE(_temp_RGB565A8_24x24);
LV_IMAGE_DECLARE(_upload_RGB565A8_24x24);
LV_IMAGE_DECLARE(_download_RGB565A8_24x24);

LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_16)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_montserratMedium_14)


#ifdef __cplusplus
}
#endif
#endif
