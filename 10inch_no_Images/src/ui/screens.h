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
    lv_obj_t *obj0;
    lv_obj_t *obj0__nav_bar;
    lv_obj_t *obj0__obj0;
    lv_obj_t *obj0__back_button;
    lv_obj_t *obj0__listen_button;
    lv_obj_t *obj0__help_button;
    lv_obj_t *obj0__obj1;
    lv_obj_t *obj0__obj2;
    lv_obj_t *obj0__obj3;
    lv_obj_t *obj0__obj4;
    lv_obj_t *obj0__obj5;
    lv_obj_t *obj1;
    lv_obj_t *obj1__nav_bar;
    lv_obj_t *obj1__obj0;
    lv_obj_t *obj1__back_button;
    lv_obj_t *obj1__listen_button;
    lv_obj_t *obj1__help_button;
    lv_obj_t *obj1__obj1;
    lv_obj_t *obj1__obj2;
    lv_obj_t *obj1__obj3;
    lv_obj_t *obj1__obj4;
    lv_obj_t *obj1__obj5;
    lv_obj_t *level_point_1;
    lv_obj_t *level_point_1__obj6;
    lv_obj_t *level_point_1__level;
    lv_obj_t *level_point_1__level_image;
    lv_obj_t *level_point_1__level_done;
    lv_obj_t *level_point_1__level_done_image;
    lv_obj_t *level_point_1__level_ongoing;
    lv_obj_t *level_point_1__level_ongoing_image;
    lv_obj_t *level_point_2;
    lv_obj_t *level_point_2__obj6;
    lv_obj_t *level_point_2__level;
    lv_obj_t *level_point_2__level_image;
    lv_obj_t *level_point_2__level_done;
    lv_obj_t *level_point_2__level_done_image;
    lv_obj_t *level_point_2__level_ongoing;
    lv_obj_t *level_point_2__level_ongoing_image;
    lv_obj_t *level_point_3;
    lv_obj_t *level_point_3__obj6;
    lv_obj_t *level_point_3__level;
    lv_obj_t *level_point_3__level_image;
    lv_obj_t *level_point_3__level_done;
    lv_obj_t *level_point_3__level_done_image;
    lv_obj_t *level_point_3__level_ongoing;
    lv_obj_t *level_point_3__level_ongoing_image;
    lv_obj_t *level_point_4;
    lv_obj_t *level_point_4__obj6;
    lv_obj_t *level_point_4__level;
    lv_obj_t *level_point_4__level_image;
    lv_obj_t *level_point_4__level_done;
    lv_obj_t *level_point_4__level_done_image;
    lv_obj_t *level_point_4__level_ongoing;
    lv_obj_t *level_point_4__level_ongoing_image;
    lv_obj_t *level_point_5;
    lv_obj_t *level_point_5__obj6;
    lv_obj_t *level_point_5__level;
    lv_obj_t *level_point_5__level_image;
    lv_obj_t *level_point_5__level_done;
    lv_obj_t *level_point_5__level_done_image;
    lv_obj_t *level_point_5__level_ongoing;
    lv_obj_t *level_point_5__level_ongoing_image;
    lv_obj_t *level_point_6;
    lv_obj_t *level_point_6__obj6;
    lv_obj_t *level_point_6__level;
    lv_obj_t *level_point_6__level_image;
    lv_obj_t *level_point_6__level_done;
    lv_obj_t *level_point_6__level_done_image;
    lv_obj_t *level_point_6__level_ongoing;
    lv_obj_t *level_point_6__level_ongoing_image;
    lv_obj_t *level_point_7;
    lv_obj_t *level_point_7__obj6;
    lv_obj_t *level_point_7__level;
    lv_obj_t *level_point_7__level_image;
    lv_obj_t *level_point_7__level_done;
    lv_obj_t *level_point_7__level_done_image;
    lv_obj_t *level_point_7__level_ongoing;
    lv_obj_t *level_point_7__level_ongoing_image;
    lv_obj_t *level_point_8;
    lv_obj_t *level_point_8__obj6;
    lv_obj_t *level_point_8__level;
    lv_obj_t *level_point_8__level_image;
    lv_obj_t *level_point_8__level_done;
    lv_obj_t *level_point_8__level_done_image;
    lv_obj_t *level_point_8__level_ongoing;
    lv_obj_t *level_point_8__level_ongoing_image;
    lv_obj_t *obj2;
    lv_obj_t *obj2__lvl1_complete_level_button;
    lv_obj_t *obj2__obj7;
    lv_obj_t *obj3;
    lv_obj_t *obj3__nav_bar;
    lv_obj_t *obj3__obj0;
    lv_obj_t *obj3__back_button;
    lv_obj_t *obj3__listen_button;
    lv_obj_t *obj3__help_button;
    lv_obj_t *obj3__obj1;
    lv_obj_t *obj3__obj2;
    lv_obj_t *obj3__obj3;
    lv_obj_t *obj3__obj4;
    lv_obj_t *obj3__obj5;
    lv_obj_t *obj4;
    lv_obj_t *obj4__lvl1_complete_level_button;
    lv_obj_t *obj4__obj7;
    lv_obj_t *obj5;
    lv_obj_t *obj5__lvl1_complete_level_button;
    lv_obj_t *obj5__obj7;
    lv_obj_t *obj6;
    lv_obj_t *obj6__nav_bar;
    lv_obj_t *obj6__obj0;
    lv_obj_t *obj6__back_button;
    lv_obj_t *obj6__listen_button;
    lv_obj_t *obj6__help_button;
    lv_obj_t *obj6__obj1;
    lv_obj_t *obj6__obj2;
    lv_obj_t *obj6__obj3;
    lv_obj_t *obj6__obj4;
    lv_obj_t *obj6__obj5;
    lv_obj_t *obj7;
    lv_obj_t *obj7__nav_bar;
    lv_obj_t *obj7__obj0;
    lv_obj_t *obj7__back_button;
    lv_obj_t *obj7__listen_button;
    lv_obj_t *obj7__help_button;
    lv_obj_t *obj7__obj1;
    lv_obj_t *obj7__obj2;
    lv_obj_t *obj7__obj3;
    lv_obj_t *obj7__obj4;
    lv_obj_t *obj7__obj5;
    lv_obj_t *obj8;
    lv_obj_t *obj8__obj8;
    lv_obj_t *obj8__obj9;
    lv_obj_t *obj8__obj10;
    lv_obj_t *obj8__obj11;
    lv_obj_t *obj9;
    lv_obj_t *obj9__obj8;
    lv_obj_t *obj9__obj9;
    lv_obj_t *obj9__obj10;
    lv_obj_t *obj9__obj11;
    lv_obj_t *obj10;
    lv_obj_t *obj10__obj8;
    lv_obj_t *obj10__obj9;
    lv_obj_t *obj10__obj10;
    lv_obj_t *obj10__obj11;
    lv_obj_t *obj11;
    lv_obj_t *obj11__obj8;
    lv_obj_t *obj11__obj9;
    lv_obj_t *obj11__obj10;
    lv_obj_t *obj11__obj11;
    lv_obj_t *obj12;
    lv_obj_t *obj12__obj8;
    lv_obj_t *obj12__obj9;
    lv_obj_t *obj12__obj10;
    lv_obj_t *obj12__obj11;
    lv_obj_t *obj13;
    lv_obj_t *obj13__obj8;
    lv_obj_t *obj13__obj9;
    lv_obj_t *obj13__obj10;
    lv_obj_t *obj13__obj11;
    lv_obj_t *obj14;
    lv_obj_t *obj14__obj8;
    lv_obj_t *obj14__obj9;
    lv_obj_t *obj14__obj10;
    lv_obj_t *obj14__obj11;
    lv_obj_t *obj15;
    lv_obj_t *obj15__obj8;
    lv_obj_t *obj15__obj9;
    lv_obj_t *obj15__obj10;
    lv_obj_t *obj15__obj11;
    lv_obj_t *obj16;
    lv_obj_t *obj16__obj8;
    lv_obj_t *obj16__obj9;
    lv_obj_t *obj16__obj10;
    lv_obj_t *obj16__obj11;
    lv_obj_t *obj17;
    lv_obj_t *obj17__obj8;
    lv_obj_t *obj17__obj9;
    lv_obj_t *obj17__obj10;
    lv_obj_t *obj17__obj11;
    lv_obj_t *obj18;
    lv_obj_t *obj18__obj8;
    lv_obj_t *obj18__obj9;
    lv_obj_t *obj18__obj10;
    lv_obj_t *obj18__obj11;
    lv_obj_t *obj19;
    lv_obj_t *obj19__obj8;
    lv_obj_t *obj19__obj9;
    lv_obj_t *obj19__obj10;
    lv_obj_t *obj19__obj11;
    lv_obj_t *homepage_background;
    lv_obj_t *btn_start;
    lv_obj_t *btn_users;
    lv_obj_t *user_list_background;
    lv_obj_t *add_user_button;
    lv_obj_t *obj20;
    lv_obj_t *obj21;
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
    lv_obj_t *obj22;
    lv_obj_t *chapter_background;
    lv_obj_t *obj23;
    lv_obj_t *obj24;
    lv_obj_t *obj25;
    lv_obj_t *obj26;
    lv_obj_t *obj27;
    lv_obj_t *roadmap_background;
    lv_obj_t *obj28;
    lv_obj_t *obj29;
    lv_obj_t *obj30;
    lv_obj_t *obj31;
    lv_obj_t *profile_background;
    lv_obj_t *shop_button;
    lv_obj_t *user_selection;
    lv_obj_t *shop_background;
    lv_obj_t *shop_overlay;
    lv_obj_t *overlay_buy_wear;
    lv_obj_t *close_button;
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