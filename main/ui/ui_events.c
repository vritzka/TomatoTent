// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: TT

#include "lvgl.h"
#include "ui_events.h"
#include "ui.h"
#include <math.h>  
#include "esp_log.h"
#include <stdio.h>
#include "esp_system.h"
#include "esp_err.h"
#include "nvs_flash.h"
#include "nvs.h"

static const char *TAG = "ui_events.c";
nvs_handle_t storage_handle;
esp_err_t err;

//static char str[12];

static uint16_t light_duration_slider_value;
static float_t light_duration;
static float_t dark_duration;
static uint16_t now_slider_value;


//SplashScreen

#ifndef PI
#define PI  (3.14159f)
#endif

typedef struct {
    lv_obj_t *scr;
    int count_val;
} my_timer_context_t;

my_timer_context_t my_tim_ctx;
lv_obj_t *arc[3];
 lv_obj_t *img_text = NULL;
lv_color_t arc_color[] = {
    LV_COLOR_MAKE(0, 116, 0),
    LV_COLOR_MAKE(0, 162, 0),
    LV_COLOR_MAKE(0, 228, 0),
};

// LVGL image declare
LV_IMG_DECLARE(ui_img_tomato_png)
LV_IMG_DECLARE(tomatotent_text)

void anim_timer_cb(lv_timer_t *timer)
{
    my_timer_context_t *timer_ctx = (my_timer_context_t *) timer->user_data;
    int count = timer_ctx->count_val;
    lv_obj_t *scr = timer_ctx->scr;

    // Play arc animation
    if (count < 90) {
        lv_coord_t arc_start = count > 0 ? (1 - cosf(count / 180.0f * PI)) * 270 : 0;
        lv_coord_t arc_len = (sinf(count / 180.0f * PI) + 1) * 135;

        for (size_t i = 0; i < sizeof(arc) / sizeof(arc[0]); i++) {
            lv_arc_set_bg_angles(arc[i], arc_start, arc_len);
            lv_arc_set_rotation(arc[i], (count + 120 * (i + 1)) % 360);
        }
    }

    // Delete arcs when animation finished
    if (count == 90) {
        for (size_t i = 0; i < sizeof(arc) / sizeof(arc[0]); i++) {
            lv_obj_del(arc[i]);
        }

        // Create new image and make it transparent
        img_text = lv_img_create(scr);
        lv_img_set_src(img_text, &tomatotent_text);
        lv_obj_set_style_img_opa(img_text, 0, 0);
    }

    // Move images when arc animation finished
    if ((count >= 100) && (count <= 180)) {
        lv_coord_t offset = (sinf((count - 140) * 2.25f / 90.0f) + 1) * 20.0f;
        lv_obj_align(img_text, LV_ALIGN_CENTER, 0, -2.8 * offset);
        lv_obj_set_style_img_opa(img_text, offset / 40.0f * 255, 0);
    }

    // Delete timer when all animation finished
    if ((count += 5) == 220) {
        lv_timer_del(timer);
        
    } else {
        timer_ctx->count_val = count;
    }
}

void start_animation(lv_obj_t *scr)
{

    // Create arcs
    for (size_t i = 0; i < sizeof(arc) / sizeof(arc[0]); i++) {
        arc[i] = lv_arc_create(scr);

        // Set arc caption
        lv_obj_set_size(arc[i], 220 - 30 * i, 220 - 30 * i);
        lv_arc_set_bg_angles(arc[i], 120 * i, 10 + 120 * i);
        lv_arc_set_value(arc[i], 0);

        // Set arc style
        lv_obj_remove_style(arc[i], NULL, LV_PART_KNOB);
        lv_obj_set_style_arc_width(arc[i], 10, 0);
        lv_obj_set_style_arc_color(arc[i], arc_color[i], 0);

        // Make arc center
        lv_obj_center(arc[i]);
    }

    if (img_text) {
        lv_obj_del(img_text);
        img_text = NULL;
    }

    // Create timer for animation
    my_tim_ctx.count_val = -200;
    my_tim_ctx.scr = scr;
    lv_timer_create(anim_timer_cb, 20, &my_tim_ctx);

}

void play_intro(lv_event_t * e)
{
    start_animation(ui_SplashScreen);
}

/////////////////////////////////////
/////// LightDurationScreen /////////
/////////////////////////////////////

void light_duration_slider(lv_event_t * e) {
	
	lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
	light_duration_slider_value = lv_slider_get_value(target);
	
	light_duration = (float_t)light_duration_slider_value / 2;
	dark_duration = 24 - light_duration;

	//ESP_LOGI(TAG, "%.1f", light_duration);
	
	lv_label_set_text_fmt(ui_LightDurationLightLabel, "%.1f HRS", light_duration );
	lv_label_set_text_fmt(ui_LightDurationDarkLabel, "%.1f HRS", dark_duration );
}

void now_slider(lv_event_t * e) {
	
	lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
	now_slider_value = lv_slider_get_value(target);

	ESP_LOGI(TAG, "%d", now_slider_value);

}

void save_light_duration_screen(lv_event_t * e)
{
    err = nvs_open("storage", NVS_READWRITE, &storage_handle);
    if (err != ESP_OK) {
        printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
    } else {
		
		err = nvs_set_u16(storage_handle, "light_slider", light_duration_slider_value);
        //printf((err != ESP_OK) ? "Failed!\n" : "Done\n");
        
        err = nvs_set_u16(storage_handle, "now_slider", now_slider_value);
		printf((err != ESP_OK) ? "Failed!\n" : "Done\n");
		
		err = nvs_commit(storage_handle);
        //printf((err != ESP_OK) ? "Failed!\n" : "Done\n");

        // Close
        nvs_close(storage_handle);
	}
}

void init_tomatotent(lv_event_t * e)
{	
	err = nvs_open("storage", NVS_READONLY, &storage_handle);
    if (err != ESP_OK) {
        printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
    } else { 
		
		// light duration screen
        err = nvs_get_u16(storage_handle, "light_slider", &light_duration_slider_value);
        lv_slider_set_value(ui_LightDurationSlider, light_duration_slider_value, LV_ANIM_OFF);
		
		light_duration = (float_t)light_duration_slider_value / 2;
		dark_duration = 24 - light_duration;
	
		lv_label_set_text_fmt(ui_LightDurationLightLabel, "%.1f HRS", light_duration );
		lv_label_set_text_fmt(ui_LightDurationDarkLabel, "%.1f HRS", dark_duration ); 
		
		err = nvs_get_u16(storage_handle, "now_slider", &now_slider_value); 
		lv_slider_set_value(ui_NowSlider, now_slider_value, LV_ANIM_OFF);

        // Close NVS
        nvs_close(storage_handle);
	}
	
}
