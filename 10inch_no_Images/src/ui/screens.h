#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

// Screens

enum ScreensEnum {
    _SCREEN_ID_FIRST = 1,
    SCREEN_ID_HOME_PAGE = 1,
    SCREEN_ID_USER_LIST_VIEW = 2,
    SCREEN_ID_USER_CREATION = 3,
    SCREEN_ID_CHAPTERS = 4,
    SCREEN_ID_ROADMAP = 5,
    SCREEN_ID_LEVEL1 = 6,
    SCREEN_ID_LEVEL2 = 7,
    SCREEN_ID_TESTING_SENSORS = 8,
    SCREEN_ID_PROFILE_PAGE = 9,
    SCREEN_ID_SHOP_PAGE = 10,
    _SCREEN_ID_LAST = 10
};

typedef struct _objects_t {
    lv_obj_t *home_page;
    lv_obj_t *user_list_view;
    lv_obj_t *user_creation;
    lv_obj_t *chapters;
    lv_obj_t *roadmap;
    lv_obj_t *level1;
    lv_obj_t *level2;
    lv_obj_t *testing_sensors;
    lv_obj_t *profile_page;
    lv_obj_t *shop_page;
    lv_obj_t *nav_bar_chapters;
    lv_obj_t *nav_bar_chapters__nav_bar;
    lv_obj_t *nav_bar_chapters__back_button;
    lv_obj_t *nav_bar_chapters__battery_button;
    lv_obj_t *nav_bar_chapters__help_button;
    lv_obj_t *nav_bar_chapters__avatar_button;
    lv_obj_t *nav_bar_chapters__avatar_image;
    lv_obj_t *nav_bar_chapters__coins_button;
    lv_obj_t *nav_bar_chapters__obj0;
    lv_obj_t *nav_bar_chapters__battery_button_no_coins;
    lv_obj_t *nav_bar_chapters__help_button_no_coins;
    lv_obj_t *nav_bar_chapters__avatar_button_no_coins;
    lv_obj_t *nav_bar_chapters__avatar_image_no_coins;
    lv_obj_t *nav_bar_roadmap;
    lv_obj_t *nav_bar_roadmap__nav_bar;
    lv_obj_t *nav_bar_roadmap__back_button;
    lv_obj_t *nav_bar_roadmap__battery_button;
    lv_obj_t *nav_bar_roadmap__help_button;
    lv_obj_t *nav_bar_roadmap__avatar_button;
    lv_obj_t *nav_bar_roadmap__avatar_image;
    lv_obj_t *nav_bar_roadmap__coins_button;
    lv_obj_t *nav_bar_roadmap__obj0;
    lv_obj_t *nav_bar_roadmap__battery_button_no_coins;
    lv_obj_t *nav_bar_roadmap__help_button_no_coins;
    lv_obj_t *nav_bar_roadmap__avatar_button_no_coins;
    lv_obj_t *nav_bar_roadmap__avatar_image_no_coins;
    lv_obj_t *level_point_1;
    lv_obj_t *level_point_1__obj1;
    lv_obj_t *level_point_1__level;
    lv_obj_t *level_point_1__level_image;
    lv_obj_t *level_point_1__level_done;
    lv_obj_t *level_point_1__level_done_image;
    lv_obj_t *level_point_1__level_ongoing;
    lv_obj_t *level_point_1__level_ongoing_image;
    lv_obj_t *level_point_2;
    lv_obj_t *level_point_2__obj1;
    lv_obj_t *level_point_2__level;
    lv_obj_t *level_point_2__level_image;
    lv_obj_t *level_point_2__level_done;
    lv_obj_t *level_point_2__level_done_image;
    lv_obj_t *level_point_2__level_ongoing;
    lv_obj_t *level_point_2__level_ongoing_image;
    lv_obj_t *level_point_3;
    lv_obj_t *level_point_3__obj1;
    lv_obj_t *level_point_3__level;
    lv_obj_t *level_point_3__level_image;
    lv_obj_t *level_point_3__level_done;
    lv_obj_t *level_point_3__level_done_image;
    lv_obj_t *level_point_3__level_ongoing;
    lv_obj_t *level_point_3__level_ongoing_image;
    lv_obj_t *level_point_4;
    lv_obj_t *level_point_4__obj1;
    lv_obj_t *level_point_4__level;
    lv_obj_t *level_point_4__level_image;
    lv_obj_t *level_point_4__level_done;
    lv_obj_t *level_point_4__level_done_image;
    lv_obj_t *level_point_4__level_ongoing;
    lv_obj_t *level_point_4__level_ongoing_image;
    lv_obj_t *level_point_5;
    lv_obj_t *level_point_5__obj1;
    lv_obj_t *level_point_5__level;
    lv_obj_t *level_point_5__level_image;
    lv_obj_t *level_point_5__level_done;
    lv_obj_t *level_point_5__level_done_image;
    lv_obj_t *level_point_5__level_ongoing;
    lv_obj_t *level_point_5__level_ongoing_image;
    lv_obj_t *level_point_6;
    lv_obj_t *level_point_6__obj1;
    lv_obj_t *level_point_6__level;
    lv_obj_t *level_point_6__level_image;
    lv_obj_t *level_point_6__level_done;
    lv_obj_t *level_point_6__level_done_image;
    lv_obj_t *level_point_6__level_ongoing;
    lv_obj_t *level_point_6__level_ongoing_image;
    lv_obj_t *level_point_7;
    lv_obj_t *level_point_7__obj1;
    lv_obj_t *level_point_7__level;
    lv_obj_t *level_point_7__level_image;
    lv_obj_t *level_point_7__level_done;
    lv_obj_t *level_point_7__level_done_image;
    lv_obj_t *level_point_7__level_ongoing;
    lv_obj_t *level_point_7__level_ongoing_image;
    lv_obj_t *level_point_8;
    lv_obj_t *level_point_8__obj1;
    lv_obj_t *level_point_8__level;
    lv_obj_t *level_point_8__level_image;
    lv_obj_t *level_point_8__level_done;
    lv_obj_t *level_point_8__level_done_image;
    lv_obj_t *level_point_8__level_ongoing;
    lv_obj_t *level_point_8__level_ongoing_image;
    lv_obj_t *obj0;
    lv_obj_t *obj0__lvl1_complete_level_button;
    lv_obj_t *obj0__obj2;
    lv_obj_t *nav_bar_level;
    lv_obj_t *nav_bar_level__nav_bar;
    lv_obj_t *nav_bar_level__back_button;
    lv_obj_t *nav_bar_level__battery_button;
    lv_obj_t *nav_bar_level__help_button;
    lv_obj_t *nav_bar_level__avatar_button;
    lv_obj_t *nav_bar_level__avatar_image;
    lv_obj_t *nav_bar_level__coins_button;
    lv_obj_t *nav_bar_level__obj0;
    lv_obj_t *nav_bar_level__battery_button_no_coins;
    lv_obj_t *nav_bar_level__help_button_no_coins;
    lv_obj_t *nav_bar_level__avatar_button_no_coins;
    lv_obj_t *nav_bar_level__avatar_image_no_coins;
    lv_obj_t *obj1;
    lv_obj_t *obj1__lvl1_complete_level_button;
    lv_obj_t *obj1__obj2;
    lv_obj_t *obj2;
    lv_obj_t *obj2__lvl1_complete_level_button;
    lv_obj_t *obj2__obj2;
    lv_obj_t *nav_bar_profile;
    lv_obj_t *nav_bar_profile__nav_bar;
    lv_obj_t *nav_bar_profile__back_button;
    lv_obj_t *nav_bar_profile__battery_button;
    lv_obj_t *nav_bar_profile__help_button;
    lv_obj_t *nav_bar_profile__avatar_button;
    lv_obj_t *nav_bar_profile__avatar_image;
    lv_obj_t *nav_bar_profile__coins_button;
    lv_obj_t *nav_bar_profile__obj0;
    lv_obj_t *nav_bar_profile__battery_button_no_coins;
    lv_obj_t *nav_bar_profile__help_button_no_coins;
    lv_obj_t *nav_bar_profile__avatar_button_no_coins;
    lv_obj_t *nav_bar_profile__avatar_image_no_coins;
    lv_obj_t *nav_bar_shop;
    lv_obj_t *nav_bar_shop__nav_bar;
    lv_obj_t *nav_bar_shop__back_button;
    lv_obj_t *nav_bar_shop__battery_button;
    lv_obj_t *nav_bar_shop__help_button;
    lv_obj_t *nav_bar_shop__avatar_button;
    lv_obj_t *nav_bar_shop__avatar_image;
    lv_obj_t *nav_bar_shop__coins_button;
    lv_obj_t *nav_bar_shop__obj0;
    lv_obj_t *nav_bar_shop__battery_button_no_coins;
    lv_obj_t *nav_bar_shop__help_button_no_coins;
    lv_obj_t *nav_bar_shop__avatar_button_no_coins;
    lv_obj_t *nav_bar_shop__avatar_image_no_coins;
    lv_obj_t *shop_item_1;
    lv_obj_t *shop_item_1__card;
    lv_obj_t *shop_item_1__owned_badge;
    lv_obj_t *shop_item_1__owned_label;
    lv_obj_t *shop_item_2;
    lv_obj_t *shop_item_2__card;
    lv_obj_t *shop_item_2__owned_badge;
    lv_obj_t *shop_item_2__owned_label;
    lv_obj_t *shop_item_3;
    lv_obj_t *shop_item_3__card;
    lv_obj_t *shop_item_3__owned_badge;
    lv_obj_t *shop_item_3__owned_label;
    lv_obj_t *shop_item_4;
    lv_obj_t *shop_item_4__card;
    lv_obj_t *shop_item_4__owned_badge;
    lv_obj_t *shop_item_4__owned_label;
    lv_obj_t *shop_item_5;
    lv_obj_t *shop_item_5__card;
    lv_obj_t *shop_item_5__owned_badge;
    lv_obj_t *shop_item_5__owned_label;
    lv_obj_t *shop_item_6;
    lv_obj_t *shop_item_6__card;
    lv_obj_t *shop_item_6__owned_badge;
    lv_obj_t *shop_item_6__owned_label;
    lv_obj_t *shop_item_7;
    lv_obj_t *shop_item_7__card;
    lv_obj_t *shop_item_7__owned_badge;
    lv_obj_t *shop_item_7__owned_label;
    lv_obj_t *shop_item_8;
    lv_obj_t *shop_item_8__card;
    lv_obj_t *shop_item_8__owned_badge;
    lv_obj_t *shop_item_8__owned_label;
    lv_obj_t *shop_item_9;
    lv_obj_t *shop_item_9__card;
    lv_obj_t *shop_item_9__owned_badge;
    lv_obj_t *shop_item_9__owned_label;
    lv_obj_t *shop_item_10;
    lv_obj_t *shop_item_10__card;
    lv_obj_t *shop_item_10__owned_badge;
    lv_obj_t *shop_item_10__owned_label;
    lv_obj_t *shop_item_11;
    lv_obj_t *shop_item_11__card;
    lv_obj_t *shop_item_11__owned_badge;
    lv_obj_t *shop_item_11__owned_label;
    lv_obj_t *shop_item_12;
    lv_obj_t *shop_item_12__card;
    lv_obj_t *shop_item_12__owned_badge;
    lv_obj_t *shop_item_12__owned_label;
    lv_obj_t *homepage_background;
    lv_obj_t *btn_start;
    lv_obj_t *btn_users;
    lv_obj_t *home_avatar_center;
    lv_obj_t *home_name_center;
    lv_obj_t *home_prev;
    lv_obj_t *home_avatar_prev;
    lv_obj_t *home_arrow_prev;
    lv_obj_t *home_name_prev;
    lv_obj_t *home_next;
    lv_obj_t *home_avatar_next;
    lv_obj_t *home_arrow_next;
    lv_obj_t *home_name_next;
    lv_obj_t *user_list_background;
    lv_obj_t *add_user_button;
    lv_obj_t *user_search;
    lv_obj_t *user_rows;
    lv_obj_t *user_row_1;
    lv_obj_t *user_row_1_avatar;
    lv_obj_t *user_row_1_name;
    lv_obj_t *user_row_1_arrow;
    lv_obj_t *user_row_2;
    lv_obj_t *user_row_2_avatar;
    lv_obj_t *user_row_2_name;
    lv_obj_t *user_row_2_arrow;
    lv_obj_t *user_row_3;
    lv_obj_t *user_row_3_avatar;
    lv_obj_t *user_row_3_name;
    lv_obj_t *user_row_3_arrow;
    lv_obj_t *user_row_4;
    lv_obj_t *user_row_4_avatar;
    lv_obj_t *user_row_4_name;
    lv_obj_t *user_row_4_arrow;
    lv_obj_t *user_row_5;
    lv_obj_t *user_row_5_avatar;
    lv_obj_t *user_row_5_name;
    lv_obj_t *user_row_5_arrow;
    lv_obj_t *user_row_6;
    lv_obj_t *user_row_6_avatar;
    lv_obj_t *user_row_6_name;
    lv_obj_t *user_row_6_arrow;
    lv_obj_t *user_row_7;
    lv_obj_t *user_row_7_avatar;
    lv_obj_t *user_row_7_name;
    lv_obj_t *user_row_7_arrow;
    lv_obj_t *user_row_8;
    lv_obj_t *user_row_8_avatar;
    lv_obj_t *user_row_8_name;
    lv_obj_t *user_row_8_arrow;
    lv_obj_t *user_row_9;
    lv_obj_t *user_row_9_avatar;
    lv_obj_t *user_row_9_name;
    lv_obj_t *user_row_9_arrow;
    lv_obj_t *user_row_10;
    lv_obj_t *user_row_10_avatar;
    lv_obj_t *user_row_10_name;
    lv_obj_t *user_row_10_arrow;
    lv_obj_t *user_row_11;
    lv_obj_t *user_row_11_avatar;
    lv_obj_t *user_row_11_name;
    lv_obj_t *user_row_11_arrow;
    lv_obj_t *user_row_12;
    lv_obj_t *user_row_12_avatar;
    lv_obj_t *user_row_12_name;
    lv_obj_t *user_row_12_arrow;
    lv_obj_t *user_creation_background;
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
    lv_obj_t *action_user_creation_confirm_11;
    lv_obj_t *user_name_input;
    lv_obj_t *chapter_background;
    lv_obj_t *obj3;
    lv_obj_t *obj4;
    lv_obj_t *obj5;
    lv_obj_t *obj6;
    lv_obj_t *obj7;
    lv_obj_t *roadmap_background;
    lv_obj_t *obj8;
    lv_obj_t *level_label_1;
    lv_obj_t *level_label_2;
    lv_obj_t *level_label_3;
    lv_obj_t *level_label_4;
    lv_obj_t *level_label_5;
    lv_obj_t *level_label_6;
    lv_obj_t *level_label_7;
    lv_obj_t *level_label_8;
    lv_obj_t *obj9;
    lv_obj_t *obj10;
    lv_obj_t *obj11;
    lv_obj_t *profile_background;
    lv_obj_t *shop_button;
    lv_obj_t *user_selection;
    lv_obj_t *profile_name;
    lv_obj_t *profile_figure;
    lv_obj_t *outfit_item_1;
    lv_obj_t *outfit_item_2;
    lv_obj_t *outfit_item_3;
    lv_obj_t *outfit_item_4;
    lv_obj_t *outfit_item_5;
    lv_obj_t *outfit_item_6;
    lv_obj_t *outfit_label_1;
    lv_obj_t *outfit_label_2;
    lv_obj_t *outfit_label_3;
    lv_obj_t *outfit_label_4;
    lv_obj_t *outfit_label_5;
    lv_obj_t *outfit_label_6;
    lv_obj_t *shop_background;
    lv_obj_t *shop_figure;
    lv_obj_t *shop_overlay;
    lv_obj_t *overlay_buy_wear;
    lv_obj_t *overlay_item;
    lv_obj_t *overlay_action;
    lv_obj_t *overlay_action_icon;
    lv_obj_t *overlay_action_title;
    lv_obj_t *overlay_action_detail;
    lv_obj_t *close_button;
    lv_obj_t *overlay_balance;
    lv_obj_t *overlay_price;
} objects_t;

extern objects_t objects;

void create_screen_home_page();
void delete_screen_home_page();
void tick_screen_home_page();

void create_screen_user_list_view();
void delete_screen_user_list_view();
void tick_screen_user_list_view();

void create_screen_user_creation();
void delete_screen_user_creation();
void tick_screen_user_creation();

void create_screen_chapters();
void delete_screen_chapters();
void tick_screen_chapters();

void create_screen_roadmap();
void delete_screen_roadmap();
void tick_screen_roadmap();

void create_screen_level1();
void delete_screen_level1();
void tick_screen_level1();

void create_screen_level2();
void delete_screen_level2();
void tick_screen_level2();

void create_screen_testing_sensors();
void delete_screen_testing_sensors();
void tick_screen_testing_sensors();

void create_screen_profile_page();
void delete_screen_profile_page();
void tick_screen_profile_page();

void create_screen_shop_page();
void delete_screen_shop_page();
void tick_screen_shop_page();

void create_user_widget_nav_bar(lv_obj_t *parent_obj, void *flowState, int startWidgetIndex);
void tick_user_widget_nav_bar(void *flowState, int startWidgetIndex);

void create_user_widget_level_point(lv_obj_t *parent_obj, void *flowState, int startWidgetIndex);
void tick_user_widget_level_point(void *flowState, int startWidgetIndex);

void create_user_widget_complete_level_button(lv_obj_t *parent_obj, void *flowState, int startWidgetIndex);
void tick_user_widget_complete_level_button(void *flowState, int startWidgetIndex);

void create_user_widget_shop_item(lv_obj_t *parent_obj, void *flowState, int startWidgetIndex);
void tick_user_widget_shop_item(void *flowState, int startWidgetIndex);

void create_screen_by_id(enum ScreensEnum screenId);
void delete_screen_by_id(enum ScreensEnum screenId);
void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/