#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl/lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

// Screens

enum ScreensEnum {
    _SCREEN_ID_FIRST = 1,
    SCREEN_ID_HOME_PAGE = 1,
    SCREEN_ID_USER_LIST_VIEW = 2,
    SCREEN_ID_USER_CREATION = 3,
    SCREEN_ID_ROADMAP = 4,
    SCREEN_ID_ROADMAP_MY_VERSION = 5,
    _SCREEN_ID_LAST = 5
};

typedef struct _objects_t {
    lv_obj_t *home_page;
    lv_obj_t *user_list_view;
    lv_obj_t *user_creation;
    lv_obj_t *roadmap;
    lv_obj_t *roadmap_my_version;
    lv_obj_t *color;
    lv_obj_t *elizabeth_venter;
    lv_obj_t *elizabeth;
    lv_obj_t *anna_venter;
    lv_obj_t *anna;
    lv_obj_t *emma_venter;
    lv_obj_t *emma;
    lv_obj_t *title;
    lv_obj_t *btn_start;
    lv_obj_t *btn_users;
    lv_obj_t *obj0;
    lv_obj_t *backdrop_users_list_view;
    lv_obj_t *shape_users_list_view_0;
    lv_obj_t *shape_users_list_view_2;
    lv_obj_t *text_users_list_view_0;
    lv_obj_t *text_users_list_view_1;
    lv_obj_t *shape_users_list_view_1;
    lv_obj_t *text_users_list_view_2;
    lv_obj_t *action_users_list_view_add_user_0;
    lv_obj_t *text_users_list_view_14;
    lv_obj_t *action_users_list_view_select_learner_1_1;
    lv_obj_t *text_users_list_view_4;
    lv_obj_t *action_users_list_view_select_learner_2_2;
    lv_obj_t *text_users_list_view_5;
    lv_obj_t *action_users_list_view_select_learner_3_3;
    lv_obj_t *text_users_list_view_6;
    lv_obj_t *action_users_list_view_select_learner_4_4;
    lv_obj_t *text_users_list_view_7;
    lv_obj_t *action_users_list_view_select_learner_5_5;
    lv_obj_t *text_users_list_view_8;
    lv_obj_t *action_users_list_view_select_learner_6_6;
    lv_obj_t *text_users_list_view_9;
    lv_obj_t *action_users_list_view_select_learner_7_7;
    lv_obj_t *text_users_list_view_10;
    lv_obj_t *action_users_list_view_select_learner_8_8;
    lv_obj_t *text_users_list_view_11;
    lv_obj_t *action_users_list_view_select_learner_9_9;
    lv_obj_t *text_users_list_view_12;
    lv_obj_t *action_users_list_view_select_learner_10_10;
    lv_obj_t *text_users_list_view_13;
    lv_obj_t *action_users_list_view_select_learner_11_11;
    lv_obj_t *text_users_list_view_15;
    lv_obj_t *action_users_list_view_select_learner_12_12;
    lv_obj_t *text_users_list_view_16;
    lv_obj_t *obj1;
    lv_obj_t *backdrop_user_creation;
    lv_obj_t *shape_user_creation_0;
    lv_obj_t *text_user_creation_0;
    lv_obj_t *text_user_creation_2;
    lv_obj_t *action_user_creation_avatar_1_1;
    lv_obj_t *action_user_creation_avatar_2_2;
    lv_obj_t *action_user_creation_avatar_3_3;
    lv_obj_t *action_user_creation_avatar_4_4;
    lv_obj_t *action_user_creation_avatar_5_5;
    lv_obj_t *action_user_creation_avatar_6_6;
    lv_obj_t *action_user_creation_avatar_7_7;
    lv_obj_t *action_user_creation_avatar_8_8;
    lv_obj_t *action_user_creation_avatar_9_9;
    lv_obj_t *action_user_creation_cancel_10;
    lv_obj_t *text_user_creation_3;
    lv_obj_t *action_user_creation_confirm_11;
    lv_obj_t *text_user_creation_4;
    lv_obj_t *obj2;
    lv_obj_t *backdrop_ver3_interface_roadmap_lvl1;
    lv_obj_t *shape_ver3_interface_roadmap_lvl1_0;
    lv_obj_t *shape_ver3_interface_roadmap_lvl1_9;
    lv_obj_t *topbar_divider_ver3_interface_roadmap_lvl1;
    lv_obj_t *text_ver3_interface_roadmap_lvl1_2;
    lv_obj_t *text_ver3_interface_roadmap_lvl1_0;
    lv_obj_t *action_ver3_interface_roadmap_lvl1_back_0;
    lv_obj_t *text_ver3_interface_roadmap_lvl1_1;
    lv_obj_t *action_ver3_interface_roadmap_lvl1_listen_mock_1;
    lv_obj_t *text_ver3_interface_roadmap_lvl1_15;
    lv_obj_t *action_ver3_interface_roadmap_lvl1_help_2;
    lv_obj_t *text_ver3_interface_roadmap_lvl1_18;
    lv_obj_t *action_ver3_interface_roadmap_lvl1_profile_3;
    lv_obj_t *action_ver3_interface_roadmap_lvl1_shop_4;
    lv_obj_t *text_ver3_interface_roadmap_lvl1_21;
    lv_obj_t *action_ver3_interface_roadmap_lvl1_lesson_1_5;
    lv_obj_t *text_ver3_interface_roadmap_lvl1_3;
    lv_obj_t *text_ver3_interface_roadmap_lvl1_4;
    lv_obj_t *action_ver3_interface_roadmap_lvl1_lesson_2_6;
    lv_obj_t *text_ver3_interface_roadmap_lvl1_5;
    lv_obj_t *text_ver3_interface_roadmap_lvl1_6;
    lv_obj_t *action_ver3_interface_roadmap_lvl1_lesson_3_7;
    lv_obj_t *text_ver3_interface_roadmap_lvl1_11;
    lv_obj_t *text_ver3_interface_roadmap_lvl1_12;
    lv_obj_t *action_ver3_interface_roadmap_lvl1_lesson_4_8;
    lv_obj_t *text_ver3_interface_roadmap_lvl1_16;
    lv_obj_t *text_ver3_interface_roadmap_lvl1_17;
    lv_obj_t *action_ver3_interface_roadmap_lvl1_lesson_5_9;
    lv_obj_t *text_ver3_interface_roadmap_lvl1_19;
    lv_obj_t *text_ver3_interface_roadmap_lvl1_20;
    lv_obj_t *action_ver3_interface_roadmap_lvl1_lesson_6_10;
    lv_obj_t *text_ver3_interface_roadmap_lvl1_13;
    lv_obj_t *text_ver3_interface_roadmap_lvl1_14;
    lv_obj_t *action_ver3_interface_roadmap_lvl1_lesson_7_11;
    lv_obj_t *text_ver3_interface_roadmap_lvl1_7;
    lv_obj_t *text_ver3_interface_roadmap_lvl1_8;
    lv_obj_t *action_ver3_interface_roadmap_lvl1_lesson_8_12;
    lv_obj_t *text_ver3_interface_roadmap_lvl1_9;
    lv_obj_t *text_ver3_interface_roadmap_lvl1_10;
} objects_t;

extern objects_t objects;

void create_screen_home_page();
void tick_screen_home_page();

void create_screen_user_list_view();
void tick_screen_user_list_view();

void create_screen_user_creation();
void tick_screen_user_creation();

void create_screen_roadmap();
void tick_screen_roadmap();

void create_screen_roadmap_my_version();
void tick_screen_roadmap_my_version();

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/