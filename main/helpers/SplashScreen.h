#ifndef _SPLASH_SCREEN_H
#define _SPLASH_SCREEN_H

#include <math.h>
#include "../ui/ui.h"
#include "lvgl.h"

void anim_timer_cb(lv_timer_t *timer);
void start_animation(lv_obj_t *scr);
extern void example_lvgl_demo_ui();

#endif
