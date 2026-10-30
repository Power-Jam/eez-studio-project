#ifndef EEZ_LVGL_UI_IMAGES_H
#define EEZ_LVGL_UI_IMAGES_H

#include <lvgl/lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const lv_img_dsc_t img_roadmap_screen_shot;
extern const lv_img_dsc_t img_level_done;
extern const lv_img_dsc_t img_level_ongoing;
extern const lv_img_dsc_t img_level;
extern const lv_img_dsc_t img_chapters_screen_background;
extern const lv_img_dsc_t img_nav_bar;
extern const lv_img_dsc_t img_coins_logo;
extern const lv_img_dsc_t img_profile_background;
extern const lv_img_dsc_t img_shop_background;
extern const lv_img_dsc_t img_homepage_background;
extern const lv_img_dsc_t img_user_list_background;
extern const lv_img_dsc_t img_overlay_shop;
extern const lv_img_dsc_t img_hat;
extern const lv_img_dsc_t img_level1_screen1;
extern const lv_img_dsc_t img_level1_screen2;
extern const lv_img_dsc_t img_level1_screen3;

#ifndef EXT_IMG_DESC_T
#define EXT_IMG_DESC_T
typedef struct _ext_img_desc_t {
    const char *name;
    const lv_img_dsc_t *img_dsc;
} ext_img_desc_t;
#endif

extern const ext_img_desc_t images[16];

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_IMAGES_H*/