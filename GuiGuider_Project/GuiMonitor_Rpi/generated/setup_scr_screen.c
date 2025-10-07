/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_screen(lv_ui *ui)
{
    //Write codes screen
    ui->screen = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen, 480, 320);
    lv_obj_set_scrollbar_mode(ui->screen, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen, 197, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_logo_container
    ui->screen_logo_container = lv_obj_create(ui->screen);
    lv_obj_set_pos(ui->screen_logo_container, 3, 11);
    lv_obj_set_size(ui->screen_logo_container, 121, 40);
    lv_obj_set_scrollbar_mode(ui->screen_logo_container, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_logo_container, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_logo_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_logo_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_logo_container, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_logo_container, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_logo_container, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_logo_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_logo_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_logo_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_logo_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_logo_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_logo__label
    ui->screen_logo__label = lv_label_create(ui->screen_logo_container);
    lv_obj_set_pos(ui->screen_logo__label, 27, 10);
    lv_obj_set_size(ui->screen_logo__label, 99, 20);
    lv_label_set_text(ui->screen_logo__label, "Raspi 3B:");
    lv_label_set_long_mode(ui->screen_logo__label, LV_LABEL_LONG_WRAP);

    //Write style for screen_logo__label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_logo__label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_logo__label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_logo__label, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_logo__label, &lv_font_SourceHanSerifSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_logo__label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_logo__label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_logo__label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_logo__label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_logo__label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_logo__label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_logo__label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_logo__label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_logo__label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_logo__label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_respberr_pi
    ui->screen_respberr_pi = lv_image_create(ui->screen_logo_container);
    lv_obj_set_pos(ui->screen_respberr_pi, 3, 5);
    lv_obj_set_size(ui->screen_respberr_pi, 31, 29);
    lv_obj_add_flag(ui->screen_respberr_pi, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_respberr_pi, &_rpi_logo_e7_16bit_RGB565A8_31x29);
    lv_image_set_pivot(ui->screen_respberr_pi, 50,50);
    lv_image_set_rotation(ui->screen_respberr_pi, 0);

    //Write style for screen_respberr_pi, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_respberr_pi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_respberr_pi, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_CPU_label
    ui->screen_CPU_label = lv_label_create(ui->screen_logo_container);
    lv_obj_set_pos(ui->screen_CPU_label, 40, 81);
    lv_obj_set_size(ui->screen_CPU_label, 61, 20);
    lv_label_set_text(ui->screen_CPU_label, "CPU");
    lv_label_set_long_mode(ui->screen_CPU_label, LV_LABEL_LONG_WRAP);

    //Write style for screen_CPU_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_CPU_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_CPU_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_CPU_label, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_CPU_label, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_CPU_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_CPU_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_CPU_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_CPU_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_CPU_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_CPU_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_CPU_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_CPU_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_CPU_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_CPU_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_ip_container
    ui->screen_ip_container = lv_obj_create(ui->screen);
    lv_obj_set_pos(ui->screen_ip_container, 139, 11);
    lv_obj_set_size(ui->screen_ip_container, 161, 40);
    lv_obj_set_scrollbar_mode(ui->screen_ip_container, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_ip_container, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_ip_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_ip_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_ip_container, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_ip_container, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_ip_container, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_ip_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_ip_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_ip_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_ip_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_ip_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_ip_label
    ui->screen_ip_label = lv_label_create(ui->screen_ip_container);
    lv_obj_set_pos(ui->screen_ip_label, 2, 4);
    lv_obj_set_size(ui->screen_ip_label, 155, 33);
    lv_label_set_text(ui->screen_ip_label, "eth0: 192.168.0.1");
    lv_label_set_long_mode(ui->screen_ip_label, LV_LABEL_LONG_WRAP);

    //Write style for screen_ip_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_ip_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_ip_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_ip_label, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_ip_label, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_ip_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_ip_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_ip_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_ip_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_ip_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_ip_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_ip_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_ip_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_ip_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_ip_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_net_container
    ui->screen_net_container = lv_obj_create(ui->screen);
    lv_obj_set_pos(ui->screen_net_container, 328, 64);
    lv_obj_set_size(ui->screen_net_container, 140, 161);
    lv_obj_set_scrollbar_mode(ui->screen_net_container, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_net_container, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_net_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_net_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_net_container, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_net_container, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_net_container, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_net_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_net_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_net_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_net_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_net_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_img_4
    ui->screen_img_4 = lv_image_create(ui->screen_net_container);
    lv_obj_set_pos(ui->screen_img_4, 57, 6);
    lv_obj_set_size(ui->screen_img_4, 21, 23);
    lv_obj_add_flag(ui->screen_img_4, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_img_4, &_flow_RGB565A8_21x23);
    lv_image_set_pivot(ui->screen_img_4, 50,50);
    lv_image_set_rotation(ui->screen_img_4, 0);

    //Write style for screen_img_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_img_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_img_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_net_list
    ui->screen_net_list = lv_list_create(ui->screen_net_container);
    lv_obj_set_pos(ui->screen_net_list, 2, 37);
    lv_obj_set_size(ui->screen_net_list, 131, 101);
    lv_obj_set_scrollbar_mode(ui->screen_net_list, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->screen_net_list, LV_OBJ_FLAG_HIDDEN);
    ui->screen_net_list_item0 = lv_list_add_button(ui->screen_net_list, &_upload_RGB565_20x20, "upload");
    ui->screen_net_list_item1 = lv_list_add_button(ui->screen_net_list, &_download_RGB565_20x20, "download");
    ui->screen_net_list_item2 = lv_list_add_button(ui->screen_net_list, &_flow_RGB565_20x20, "temporary");

    //Write style state: LV_STATE_DEFAULT for &style_screen_net_list_main_main_default
    static lv_style_t style_screen_net_list_main_main_default;
    ui_init_style(&style_screen_net_list_main_main_default);

    lv_style_set_pad_top(&style_screen_net_list_main_main_default, 5);
    lv_style_set_pad_left(&style_screen_net_list_main_main_default, 5);
    lv_style_set_pad_right(&style_screen_net_list_main_main_default, 5);
    lv_style_set_pad_bottom(&style_screen_net_list_main_main_default, 5);
    lv_style_set_bg_opa(&style_screen_net_list_main_main_default, 255);
    lv_style_set_bg_color(&style_screen_net_list_main_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_screen_net_list_main_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_screen_net_list_main_main_default, 0);
    lv_style_set_radius(&style_screen_net_list_main_main_default, 0);
    lv_style_set_shadow_width(&style_screen_net_list_main_main_default, 0);
    lv_obj_add_style(ui->screen_net_list, &style_screen_net_list_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_net_list_main_scrollbar_default
    static lv_style_t style_screen_net_list_main_scrollbar_default;
    ui_init_style(&style_screen_net_list_main_scrollbar_default);

    lv_style_set_radius(&style_screen_net_list_main_scrollbar_default, 3);
    lv_style_set_bg_opa(&style_screen_net_list_main_scrollbar_default, 255);
    lv_style_set_bg_color(&style_screen_net_list_main_scrollbar_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_screen_net_list_main_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(ui->screen_net_list, &style_screen_net_list_main_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_net_list_extra_btns_main_default
    static lv_style_t style_screen_net_list_extra_btns_main_default;
    ui_init_style(&style_screen_net_list_extra_btns_main_default);

    lv_style_set_pad_top(&style_screen_net_list_extra_btns_main_default, 5);
    lv_style_set_pad_left(&style_screen_net_list_extra_btns_main_default, 5);
    lv_style_set_pad_right(&style_screen_net_list_extra_btns_main_default, 5);
    lv_style_set_pad_bottom(&style_screen_net_list_extra_btns_main_default, 5);
    lv_style_set_border_width(&style_screen_net_list_extra_btns_main_default, 0);
    lv_style_set_text_color(&style_screen_net_list_extra_btns_main_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_screen_net_list_extra_btns_main_default, &lv_font_montserratMedium_12);
    lv_style_set_text_opa(&style_screen_net_list_extra_btns_main_default, 255);
    lv_style_set_radius(&style_screen_net_list_extra_btns_main_default, 3);
    lv_style_set_bg_opa(&style_screen_net_list_extra_btns_main_default, 255);
    lv_style_set_bg_color(&style_screen_net_list_extra_btns_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_screen_net_list_extra_btns_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(ui->screen_net_list_item2, &style_screen_net_list_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->screen_net_list_item1, &style_screen_net_list_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->screen_net_list_item0, &style_screen_net_list_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_net_list_extra_texts_main_default
    static lv_style_t style_screen_net_list_extra_texts_main_default;
    ui_init_style(&style_screen_net_list_extra_texts_main_default);

    lv_style_set_pad_top(&style_screen_net_list_extra_texts_main_default, 5);
    lv_style_set_pad_left(&style_screen_net_list_extra_texts_main_default, 5);
    lv_style_set_pad_right(&style_screen_net_list_extra_texts_main_default, 5);
    lv_style_set_pad_bottom(&style_screen_net_list_extra_texts_main_default, 5);
    lv_style_set_border_width(&style_screen_net_list_extra_texts_main_default, 0);
    lv_style_set_text_color(&style_screen_net_list_extra_texts_main_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_screen_net_list_extra_texts_main_default, &lv_font_montserratMedium_12);
    lv_style_set_text_opa(&style_screen_net_list_extra_texts_main_default, 255);
    lv_style_set_radius(&style_screen_net_list_extra_texts_main_default, 3);
    lv_style_set_transform_width(&style_screen_net_list_extra_texts_main_default, 0);
    lv_style_set_bg_opa(&style_screen_net_list_extra_texts_main_default, 255);
    lv_style_set_bg_color(&style_screen_net_list_extra_texts_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_screen_net_list_extra_texts_main_default, LV_GRAD_DIR_NONE);

    //Write codes screen_label_upload
    ui->screen_label_upload = lv_label_create(ui->screen_net_container);
    lv_obj_set_pos(ui->screen_label_upload, 36, 36);
    lv_obj_set_size(ui->screen_label_upload, 74, 19);
    lv_label_set_text(ui->screen_label_upload, "Label");
    lv_label_set_long_mode(ui->screen_label_upload, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_upload, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_pad_top(ui->screen_label_upload, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_upload, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_upload, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_upload, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_upload, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_label_upload, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_upload, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_upload, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_upload, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_upload, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_upload, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_upload, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_upload, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_upload, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_img_temporary
    ui->screen_img_temporary = lv_image_create(ui->screen_net_container);
    lv_obj_set_pos(ui->screen_img_temporary, 11, 120);
    lv_obj_set_size(ui->screen_img_temporary, 24, 24);
    lv_obj_add_flag(ui->screen_img_temporary, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_img_temporary, &_temp_RGB565A8_24x24);
    lv_image_set_pivot(ui->screen_img_temporary, 50,50);
    lv_image_set_rotation(ui->screen_img_temporary, 0);

    //Write style for screen_img_temporary, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_img_temporary, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_img_temporary, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_img_upload
    ui->screen_img_upload = lv_image_create(ui->screen_net_container);
    lv_obj_set_pos(ui->screen_img_upload, 11, 33);
    lv_obj_set_size(ui->screen_img_upload, 24, 24);
    lv_obj_add_flag(ui->screen_img_upload, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_img_upload, &_upload_RGB565A8_24x24);
    lv_image_set_pivot(ui->screen_img_upload, 50,50);
    lv_image_set_rotation(ui->screen_img_upload, 0);

    //Write style for screen_img_upload, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_img_upload, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_img_upload, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_img_download
    ui->screen_img_download = lv_image_create(ui->screen_net_container);
    lv_obj_set_pos(ui->screen_img_download, 11, 77);
    lv_obj_set_size(ui->screen_img_download, 24, 24);
    lv_obj_add_flag(ui->screen_img_download, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_img_download, &_download_RGB565A8_24x24);
    lv_image_set_pivot(ui->screen_img_download, 50,50);
    lv_image_set_rotation(ui->screen_img_download, 0);

    //Write style for screen_img_download, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_img_download, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_img_download, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_download
    ui->screen_label_download = lv_label_create(ui->screen_net_container);
    lv_obj_set_pos(ui->screen_label_download, 36, 80);
    lv_obj_set_size(ui->screen_label_download, 74, 19);
    lv_label_set_text(ui->screen_label_download, "Label");
    lv_label_set_long_mode(ui->screen_label_download, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_download, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_pad_top(ui->screen_label_download, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_download, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_download, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_download, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_download, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_label_download, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_download, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_download, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_download, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_download, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_download, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_download, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_download, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_download, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_temporary
    ui->screen_label_temporary = lv_label_create(ui->screen_net_container);
    lv_obj_set_pos(ui->screen_label_temporary, 37, 123);
    lv_obj_set_size(ui->screen_label_temporary, 74, 19);
    lv_label_set_text(ui->screen_label_temporary, "Label");
    lv_label_set_long_mode(ui->screen_label_temporary, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_temporary, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_pad_top(ui->screen_label_temporary, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_temporary, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_temporary, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_temporary, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_temporary, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_label_temporary, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_temporary, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_temporary, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_temporary, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_temporary, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_temporary, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_temporary, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_temporary, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_temporary, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_mem_container
    ui->screen_mem_container = lv_obj_create(ui->screen);
    lv_obj_set_pos(ui->screen_mem_container, 171, 64);
    lv_obj_set_size(ui->screen_mem_container, 140, 161);
    lv_obj_set_scrollbar_mode(ui->screen_mem_container, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_mem_container, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_mem_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_mem_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_mem_container, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_mem_container, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_mem_container, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_mem_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_mem_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_mem_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_mem_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_mem_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_mem_arc
    ui->screen_mem_arc = lv_arc_create(ui->screen_mem_container);
    lv_obj_set_pos(ui->screen_mem_arc, 15, 23);
    lv_obj_set_size(ui->screen_mem_arc, 111, 115);
    lv_obj_add_flag(ui->screen_mem_arc, LV_OBJ_FLAG_HIDDEN);
    lv_arc_set_mode(ui->screen_mem_arc, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->screen_mem_arc, 0, 100);
    lv_arc_set_bg_angles(ui->screen_mem_arc, 135, 45);
    lv_arc_set_value(ui->screen_mem_arc, 70);
    lv_arc_set_rotation(ui->screen_mem_arc, 0);

    //Write style for screen_mem_arc, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_mem_arc, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_mem_arc, lv_color_hex(0xf6f6f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_mem_arc, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_mem_arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->screen_mem_arc, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->screen_mem_arc, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->screen_mem_arc, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->screen_mem_arc, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_mem_arc, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_mem_arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_mem_arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_mem_arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_mem_arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_mem_arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_mem_arc, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->screen_mem_arc, 12, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->screen_mem_arc, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->screen_mem_arc, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->screen_mem_arc, true, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for screen_mem_arc, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_mem_arc, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_mem_arc, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_mem_arc, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->screen_mem_arc, 5, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes screen_mem_label
    ui->screen_mem_label = lv_label_create(ui->screen_mem_container);
    lv_obj_set_pos(ui->screen_mem_label, 10, 134);
    lv_obj_set_size(ui->screen_mem_label, 61, 20);
    lv_label_set_text(ui->screen_mem_label, "MEM");
    lv_label_set_long_mode(ui->screen_mem_label, LV_LABEL_LONG_WRAP);

    //Write style for screen_mem_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_mem_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_mem_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_mem_label, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_mem_label, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_mem_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_mem_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_mem_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_mem_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_mem_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_mem_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_mem_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_mem_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_mem_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_mem_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_mem_show_info
    ui->screen_mem_show_info = lv_label_create(ui->screen_mem_container);
    lv_obj_set_pos(ui->screen_mem_show_info, 76, 135);
    lv_obj_set_size(ui->screen_mem_show_info, 60, 16);
    lv_label_set_text(ui->screen_mem_show_info, "80%");
    lv_label_set_long_mode(ui->screen_mem_show_info, LV_LABEL_LONG_WRAP);

    //Write style for screen_mem_show_info, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_mem_show_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_mem_show_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_mem_show_info, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_mem_show_info, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_mem_show_info, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_mem_show_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_mem_show_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_mem_show_info, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_mem_show_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_mem_show_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_mem_show_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_mem_show_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_mem_show_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_mem_show_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_mem_meter
    ui->screen_mem_meter = lv_scale_create(ui->screen_mem_container);
    lv_obj_set_pos(ui->screen_mem_meter, 13, 12);
    lv_obj_set_size(ui->screen_mem_meter, 112, 112);
    lv_obj_update_layout(ui->screen_mem_meter);
    lv_scale_set_mode(ui->screen_mem_meter, LV_SCALE_MODE_ROUND_INNER);
    lv_scale_set_total_tick_count(ui->screen_mem_meter, 41);
    lv_scale_set_major_tick_every(ui->screen_mem_meter, 8);
    lv_scale_set_label_show(ui->screen_mem_meter, true);
    lv_scale_set_range(ui->screen_mem_meter, 0, 100);
    lv_scale_set_angle_range(ui->screen_mem_meter, 300);
    lv_scale_set_rotation(ui->screen_mem_meter, 90);
    lv_scale_set_post_draw(ui->screen_mem_meter, true);
    lv_scale_section_t * screen_mem_meter_section_0 = lv_scale_add_section(ui->screen_mem_meter);
    static lv_style_t screen_mem_meter_section_0_minor_tick_style;
    static lv_style_t screen_mem_meter_section_0_label_style;
    static lv_style_t screen_mem_meter_section_0_main_line_style;
    lv_style_init(&screen_mem_meter_section_0_label_style);
    lv_style_init(&screen_mem_meter_section_0_minor_tick_style);
    lv_style_init(&screen_mem_meter_section_0_main_line_style);

    lv_scale_section_set_range(screen_mem_meter_section_0, 80, 100);
    lv_scale_section_set_style(screen_mem_meter_section_0, LV_PART_INDICATOR, &screen_mem_meter_section_0_label_style);
    lv_scale_section_set_style(screen_mem_meter_section_0, LV_PART_MAIN, &screen_mem_meter_section_0_main_line_style);
    lv_scale_section_set_style(screen_mem_meter_section_0, LV_PART_ITEMS, &screen_mem_meter_section_0_minor_tick_style);

    lv_style_set_text_color(&screen_mem_meter_section_0_label_style, lv_color_hex(0xed0024));
    lv_style_set_line_color(&screen_mem_meter_section_0_label_style, lv_color_hex(0xff0027));
    lv_style_set_line_color(&screen_mem_meter_section_0_minor_tick_style, lv_color_hex(0xff0027));
    lv_style_set_line_width(&screen_mem_meter_section_0_minor_tick_style, 3);
    lv_style_set_line_color(&screen_mem_meter_section_0_label_style, lv_color_hex(0xff0027));
    lv_style_set_line_width(&screen_mem_meter_section_0_label_style, 3);
    lv_style_set_arc_color(&screen_mem_meter_section_0_main_line_style, lv_color_hex(0xff0027));
    lv_style_set_arc_width(&screen_mem_meter_section_0_main_line_style, 2);

    ui->screen_mem_meter_ndline_0 = lv_line_create(ui->screen_mem_meter);
    lv_obj_set_style_line_width(ui->screen_mem_meter_ndline_0, 4, LV_PART_MAIN);
    lv_obj_set_style_line_color(ui->screen_mem_meter_ndline_0, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_set_style_line_rounded(ui->screen_mem_meter_ndline_0, true, LV_PART_MAIN);
    lv_scale_set_line_needle_value(ui->screen_mem_meter, ui->screen_mem_meter_ndline_0, 40, 10);


    //Write style for screen_mem_meter, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_mem_meter, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_mem_meter, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_mem_meter, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_mem_meter, 100, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_mem_meter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->screen_mem_meter, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->screen_mem_meter, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->screen_mem_meter, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->screen_mem_meter, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_mem_meter, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_mem_meter, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_mem_meter, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_mem_meter, Part: LV_PART_ITEMS, State: LV_STATE_DEFAULT.
    lv_obj_set_style_length(ui->screen_mem_meter, 5, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_line_width(ui->screen_mem_meter, 2, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->screen_mem_meter, lv_color_hex(0x757575), LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->screen_mem_meter, 255, LV_PART_ITEMS|LV_STATE_DEFAULT);

    //Write style for screen_mem_meter, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_length(ui->screen_mem_meter, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_line_width(ui->screen_mem_meter, 2, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->screen_mem_meter, lv_color_hex(0x757575), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->screen_mem_meter, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes screen_cpu_container
    ui->screen_cpu_container = lv_obj_create(ui->screen);
    lv_obj_set_pos(ui->screen_cpu_container, 14, 64);
    lv_obj_set_size(ui->screen_cpu_container, 140, 161);
    lv_obj_set_scrollbar_mode(ui->screen_cpu_container, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_cpu_container, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_cpu_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cpu_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cpu_container, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cpu_container, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cpu_container, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_cpu_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cpu_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cpu_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cpu_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cpu_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_cpu_arc
    ui->screen_cpu_arc = lv_arc_create(ui->screen_cpu_container);
    lv_obj_set_pos(ui->screen_cpu_arc, 14, 24);
    lv_obj_set_size(ui->screen_cpu_arc, 111, 115);
    lv_obj_add_flag(ui->screen_cpu_arc, LV_OBJ_FLAG_HIDDEN);
    lv_arc_set_mode(ui->screen_cpu_arc, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->screen_cpu_arc, 0, 100);
    lv_arc_set_bg_angles(ui->screen_cpu_arc, 135, 45);
    lv_arc_set_value(ui->screen_cpu_arc, 70);
    lv_arc_set_rotation(ui->screen_cpu_arc, 0);

    //Write style for screen_cpu_arc, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_cpu_arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cpu_arc, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cpu_arc, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cpu_arc, lv_color_hex(0xf6f6f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cpu_arc, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_cpu_arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cpu_arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cpu_arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cpu_arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cpu_arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->screen_cpu_arc, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->screen_cpu_arc, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->screen_cpu_arc, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->screen_cpu_arc, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_cpu_arc, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->screen_cpu_arc, 12, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->screen_cpu_arc, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->screen_cpu_arc, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->screen_cpu_arc, true, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for screen_cpu_arc, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_cpu_arc, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cpu_arc, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cpu_arc, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->screen_cpu_arc, 5, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes screen_cpu__label
    ui->screen_cpu__label = lv_label_create(ui->screen_cpu_container);
    lv_obj_set_pos(ui->screen_cpu__label, 10, 135);
    lv_obj_set_size(ui->screen_cpu__label, 61, 20);
    lv_label_set_text(ui->screen_cpu__label, "CPU");
    lv_label_set_long_mode(ui->screen_cpu__label, LV_LABEL_LONG_WRAP);

    //Write style for screen_cpu__label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_cpu__label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cpu__label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_cpu__label, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_cpu__label, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_cpu__label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_cpu__label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_cpu__label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_cpu__label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cpu__label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_cpu__label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cpu__label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cpu__label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cpu__label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cpu__label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_cpu_show_info
    ui->screen_cpu_show_info = lv_label_create(ui->screen_cpu_container);
    lv_obj_set_pos(ui->screen_cpu_show_info, 72, 135);
    lv_obj_set_size(ui->screen_cpu_show_info, 60, 16);
    lv_label_set_text(ui->screen_cpu_show_info, "80%");
    lv_label_set_long_mode(ui->screen_cpu_show_info, LV_LABEL_LONG_WRAP);

    //Write style for screen_cpu_show_info, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_cpu_show_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cpu_show_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cpu_show_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_cpu_show_info, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_cpu_show_info, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_cpu_show_info, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_cpu_show_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_cpu_show_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_cpu_show_info, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_cpu_show_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_cpu_show_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cpu_show_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cpu_show_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cpu_show_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_cpu_meter
    ui->screen_cpu_meter = lv_scale_create(ui->screen_cpu_container);
    lv_obj_set_pos(ui->screen_cpu_meter, 12, 11);
    lv_obj_set_size(ui->screen_cpu_meter, 112, 112);
    lv_obj_update_layout(ui->screen_cpu_meter);
    lv_scale_set_mode(ui->screen_cpu_meter, LV_SCALE_MODE_ROUND_INNER);
    lv_scale_set_total_tick_count(ui->screen_cpu_meter, 41);
    lv_scale_set_major_tick_every(ui->screen_cpu_meter, 8);
    lv_scale_set_label_show(ui->screen_cpu_meter, true);
    lv_scale_set_range(ui->screen_cpu_meter, 0, 100);
    lv_scale_set_angle_range(ui->screen_cpu_meter, 300);
    lv_scale_set_rotation(ui->screen_cpu_meter, 90);
    lv_scale_set_post_draw(ui->screen_cpu_meter, true);
    lv_scale_section_t * screen_cpu_meter_section_0 = lv_scale_add_section(ui->screen_cpu_meter);
    static lv_style_t screen_cpu_meter_section_0_minor_tick_style;
    static lv_style_t screen_cpu_meter_section_0_label_style;
    static lv_style_t screen_cpu_meter_section_0_main_line_style;
    lv_style_init(&screen_cpu_meter_section_0_label_style);
    lv_style_init(&screen_cpu_meter_section_0_minor_tick_style);
    lv_style_init(&screen_cpu_meter_section_0_main_line_style);

    lv_scale_section_set_range(screen_cpu_meter_section_0, 80, 100);
    lv_scale_section_set_style(screen_cpu_meter_section_0, LV_PART_INDICATOR, &screen_cpu_meter_section_0_label_style);
    lv_scale_section_set_style(screen_cpu_meter_section_0, LV_PART_MAIN, &screen_cpu_meter_section_0_main_line_style);
    lv_scale_section_set_style(screen_cpu_meter_section_0, LV_PART_ITEMS, &screen_cpu_meter_section_0_minor_tick_style);

    lv_style_set_text_color(&screen_cpu_meter_section_0_label_style, lv_color_hex(0xed0024));
    lv_style_set_line_color(&screen_cpu_meter_section_0_label_style, lv_color_hex(0xff0027));
    lv_style_set_line_color(&screen_cpu_meter_section_0_minor_tick_style, lv_color_hex(0xff0027));
    lv_style_set_line_width(&screen_cpu_meter_section_0_minor_tick_style, 3);
    lv_style_set_line_color(&screen_cpu_meter_section_0_label_style, lv_color_hex(0xff0027));
    lv_style_set_line_width(&screen_cpu_meter_section_0_label_style, 3);
    lv_style_set_arc_color(&screen_cpu_meter_section_0_main_line_style, lv_color_hex(0xff0027));
    lv_style_set_arc_width(&screen_cpu_meter_section_0_main_line_style, 2);

    ui->screen_cpu_meter_ndline_0 = lv_line_create(ui->screen_cpu_meter);
    lv_obj_set_style_line_width(ui->screen_cpu_meter_ndline_0, 4, LV_PART_MAIN);
    lv_obj_set_style_line_color(ui->screen_cpu_meter_ndline_0, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_set_style_line_rounded(ui->screen_cpu_meter_ndline_0, true, LV_PART_MAIN);
    lv_scale_set_line_needle_value(ui->screen_cpu_meter, ui->screen_cpu_meter_ndline_0, 40, 10);


    //Write style for screen_cpu_meter, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_cpu_meter, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cpu_meter, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cpu_meter, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cpu_meter, 100, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cpu_meter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->screen_cpu_meter, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->screen_cpu_meter, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->screen_cpu_meter, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->screen_cpu_meter, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_cpu_meter, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_cpu_meter, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_cpu_meter, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_cpu_meter, Part: LV_PART_ITEMS, State: LV_STATE_DEFAULT.
    lv_obj_set_style_length(ui->screen_cpu_meter, 5, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_line_width(ui->screen_cpu_meter, 2, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->screen_cpu_meter, lv_color_hex(0x757575), LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->screen_cpu_meter, 255, LV_PART_ITEMS|LV_STATE_DEFAULT);

    //Write style for screen_cpu_meter, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_length(ui->screen_cpu_meter, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_line_width(ui->screen_cpu_meter, 2, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->screen_cpu_meter, lv_color_hex(0x757575), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->screen_cpu_meter, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes screen_disk_container
    ui->screen_disk_container = lv_obj_create(ui->screen);
    lv_obj_set_pos(ui->screen_disk_container, 14, 236);
    lv_obj_set_size(ui->screen_disk_container, 452, 70);
    lv_obj_set_scrollbar_mode(ui->screen_disk_container, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_disk_container, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_disk_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_disk_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_disk_container, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_disk_container, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_disk_container, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_disk_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_disk_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_disk_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_disk_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_disk_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_Udisk_label
    ui->screen_Udisk_label = lv_label_create(ui->screen_disk_container);
    lv_obj_set_pos(ui->screen_Udisk_label, 6, 11);
    lv_obj_set_size(ui->screen_Udisk_label, 67, 19);
    lv_label_set_text(ui->screen_Udisk_label, "U Disk:");
    lv_label_set_long_mode(ui->screen_Udisk_label, LV_LABEL_LONG_WRAP);

    //Write style for screen_Udisk_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_Udisk_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_Udisk_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_Udisk_label, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_Udisk_label, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_Udisk_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_Udisk_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_Udisk_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_Udisk_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_Udisk_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_Udisk_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_Udisk_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_Udisk_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_Udisk_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_Udisk_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_usage_label
    ui->screen_usage_label = lv_label_create(ui->screen_disk_container);
    lv_obj_set_pos(ui->screen_usage_label, 274, 9);
    lv_obj_set_size(ui->screen_usage_label, 75, 18);
    lv_label_set_text(ui->screen_usage_label, "10G/16G");
    lv_label_set_long_mode(ui->screen_usage_label, LV_LABEL_LONG_WRAP);

    //Write style for screen_usage_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_usage_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_usage_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_usage_label, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_usage_label, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_usage_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_usage_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_usage_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_usage_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_usage_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_usage_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_usage_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_usage_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_usage_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_usage_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_alipan_label
    ui->screen_alipan_label = lv_label_create(ui->screen_disk_container);
    lv_obj_set_pos(ui->screen_alipan_label, 78, 40);
    lv_obj_set_size(ui->screen_alipan_label, 100, 19);
    lv_label_set_text(ui->screen_alipan_label, "AliPan: 50");
    lv_label_set_long_mode(ui->screen_alipan_label, LV_LABEL_LONG_WRAP);

    //Write style for screen_alipan_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_alipan_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_alipan_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_alipan_label, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_alipan_label, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_alipan_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_alipan_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_alipan_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_alipan_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_alipan_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_alipan_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_alipan_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_alipan_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_alipan_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_alipan_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_udisk_label
    ui->screen_udisk_label = lv_label_create(ui->screen_disk_container);
    lv_obj_set_pos(ui->screen_udisk_label, 234, 43);
    lv_obj_set_size(ui->screen_udisk_label, 100, 19);
    lv_label_set_text(ui->screen_udisk_label, "UDisk: 50");
    lv_label_set_long_mode(ui->screen_udisk_label, LV_LABEL_LONG_WRAP);

    //Write style for screen_udisk_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_udisk_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_udisk_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_udisk_label, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_udisk_label, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_udisk_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_udisk_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_udisk_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_udisk_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_udisk_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_udisk_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_udisk_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_udisk_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_udisk_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_udisk_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_udis_bar
    ui->screen_udis_bar = lv_bar_create(ui->screen_disk_container);
    lv_obj_set_pos(ui->screen_udis_bar, 83, 5);
    lv_obj_set_size(ui->screen_udis_bar, 180, 20);
    lv_obj_set_style_anim_duration(ui->screen_udis_bar, 1000, 0);
    lv_bar_set_mode(ui->screen_udis_bar, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->screen_udis_bar, 0, 100);
    lv_bar_set_value(ui->screen_udis_bar, 50, LV_ANIM_OFF);

    //Write style for screen_udis_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_udis_bar, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_udis_bar, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_udis_bar, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_udis_bar, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_udis_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_udis_bar, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_udis_bar, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_udis_bar, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_udis_bar, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_udis_bar, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes screen_time_container
    ui->screen_time_container = lv_obj_create(ui->screen);
    lv_obj_set_pos(ui->screen_time_container, 314, 11);
    lv_obj_set_size(ui->screen_time_container, 159, 40);
    lv_obj_set_scrollbar_mode(ui->screen_time_container, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_time_container, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_time_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_time_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_time_container, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_time_container, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_time_container, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_time_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_time_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_time_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_time_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_time_container, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_date_label
    ui->screen_date_label = lv_label_create(ui->screen_time_container);
    lv_obj_set_pos(ui->screen_date_label, 0, 10);
    lv_obj_set_size(ui->screen_date_label, 89, 19);
    lv_label_set_text(ui->screen_date_label, "2025/22/22");
    lv_label_set_long_mode(ui->screen_date_label, LV_LABEL_LONG_WRAP);

    //Write style for screen_date_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_date_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_date_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_date_label, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_date_label, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_date_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_date_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_date_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_date_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_date_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_date_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_date_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_date_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_date_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_date_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_time_label
    ui->screen_time_label = lv_label_create(ui->screen_time_container);
    lv_obj_set_pos(ui->screen_time_label, 85, 10);
    lv_obj_set_size(ui->screen_time_label, 78, 20);
    lv_label_set_text(ui->screen_time_label, "22:22:22");
    lv_label_set_long_mode(ui->screen_time_label, LV_LABEL_LONG_WRAP);

    //Write style for screen_time_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_time_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_time_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_time_label, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_time_label, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_time_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_time_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_time_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_time_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_time_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_time_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_time_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_time_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_time_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_time_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen);

}
