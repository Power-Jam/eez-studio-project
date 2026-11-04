#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;

static const char *screen_names[] = { "HomePage", "UserListView", "UserCreation", "Chapters", "Roadmap", "Level1", "Level2", "TestingSensors", "ProfilePage", "ShopPage" };
static const char *object_names[] = { "home_page", "user_list_view", "user_creation", "chapters", "roadmap", "level1", "level2", "testing_sensors", "profile_page", "shop_page", "nav_bar_chapters", "nav_bar_chapters__nav_bar", "nav_bar_chapters__back_button", "nav_bar_chapters__battery_button", "nav_bar_chapters__help_button", "nav_bar_chapters__avatar_button", "nav_bar_chapters__avatar_image", "nav_bar_chapters__coins_button", "nav_bar_chapters__obj0", "nav_bar_chapters__battery_button_no_coins", "nav_bar_chapters__help_button_no_coins", "nav_bar_chapters__avatar_button_no_coins", "nav_bar_chapters__avatar_image_no_coins", "nav_bar_roadmap", "nav_bar_roadmap__nav_bar", "nav_bar_roadmap__back_button", "nav_bar_roadmap__battery_button", "nav_bar_roadmap__help_button", "nav_bar_roadmap__avatar_button", "nav_bar_roadmap__avatar_image", "nav_bar_roadmap__coins_button", "nav_bar_roadmap__obj0", "nav_bar_roadmap__battery_button_no_coins", "nav_bar_roadmap__help_button_no_coins", "nav_bar_roadmap__avatar_button_no_coins", "nav_bar_roadmap__avatar_image_no_coins", "level_point_1", "level_point_1__obj1", "level_point_1__level", "level_point_1__level_image", "level_point_1__level_done", "level_point_1__level_done_image", "level_point_1__level_ongoing", "level_point_1__level_ongoing_image", "level_point_2", "level_point_2__obj1", "level_point_2__level", "level_point_2__level_image", "level_point_2__level_done", "level_point_2__level_done_image", "level_point_2__level_ongoing", "level_point_2__level_ongoing_image", "level_point_3", "level_point_3__obj1", "level_point_3__level", "level_point_3__level_image", "level_point_3__level_done", "level_point_3__level_done_image", "level_point_3__level_ongoing", "level_point_3__level_ongoing_image", "level_point_4", "level_point_4__obj1", "level_point_4__level", "level_point_4__level_image", "level_point_4__level_done", "level_point_4__level_done_image", "level_point_4__level_ongoing", "level_point_4__level_ongoing_image", "level_point_5", "level_point_5__obj1", "level_point_5__level", "level_point_5__level_image", "level_point_5__level_done", "level_point_5__level_done_image", "level_point_5__level_ongoing", "level_point_5__level_ongoing_image", "level_point_6", "level_point_6__obj1", "level_point_6__level", "level_point_6__level_image", "level_point_6__level_done", "level_point_6__level_done_image", "level_point_6__level_ongoing", "level_point_6__level_ongoing_image", "level_point_7", "level_point_7__obj1", "level_point_7__level", "level_point_7__level_image", "level_point_7__level_done", "level_point_7__level_done_image", "level_point_7__level_ongoing", "level_point_7__level_ongoing_image", "level_point_8", "level_point_8__obj1", "level_point_8__level", "level_point_8__level_image", "level_point_8__level_done", "level_point_8__level_done_image", "level_point_8__level_ongoing", "level_point_8__level_ongoing_image", "level1_next", "level1_next__lvl1_complete_level_button", "level1_next__obj2", "nav_bar_level", "nav_bar_level__nav_bar", "nav_bar_level__back_button", "nav_bar_level__battery_button", "nav_bar_level__help_button", "nav_bar_level__avatar_button", "nav_bar_level__avatar_image", "nav_bar_level__coins_button", "nav_bar_level__obj0", "nav_bar_level__battery_button_no_coins", "nav_bar_level__help_button_no_coins", "nav_bar_level__avatar_button_no_coins", "nav_bar_level__avatar_image_no_coins", "obj0", "obj0__lvl1_complete_level_button", "obj0__obj2", "obj1", "obj1__lvl1_complete_level_button", "obj1__obj2", "nav_bar_profile", "nav_bar_profile__nav_bar", "nav_bar_profile__back_button", "nav_bar_profile__battery_button", "nav_bar_profile__help_button", "nav_bar_profile__avatar_button", "nav_bar_profile__avatar_image", "nav_bar_profile__coins_button", "nav_bar_profile__obj0", "nav_bar_profile__battery_button_no_coins", "nav_bar_profile__help_button_no_coins", "nav_bar_profile__avatar_button_no_coins", "nav_bar_profile__avatar_image_no_coins", "nav_bar_shop", "nav_bar_shop__nav_bar", "nav_bar_shop__back_button", "nav_bar_shop__battery_button", "nav_bar_shop__help_button", "nav_bar_shop__avatar_button", "nav_bar_shop__avatar_image", "nav_bar_shop__coins_button", "nav_bar_shop__obj0", "nav_bar_shop__battery_button_no_coins", "nav_bar_shop__help_button_no_coins", "nav_bar_shop__avatar_button_no_coins", "nav_bar_shop__avatar_image_no_coins", "shop_item_1", "shop_item_1__card", "shop_item_1__owned_badge", "shop_item_1__owned_label", "shop_item_2", "shop_item_2__card", "shop_item_2__owned_badge", "shop_item_2__owned_label", "shop_item_3", "shop_item_3__card", "shop_item_3__owned_badge", "shop_item_3__owned_label", "shop_item_4", "shop_item_4__card", "shop_item_4__owned_badge", "shop_item_4__owned_label", "shop_item_5", "shop_item_5__card", "shop_item_5__owned_badge", "shop_item_5__owned_label", "shop_item_6", "shop_item_6__card", "shop_item_6__owned_badge", "shop_item_6__owned_label", "shop_item_7", "shop_item_7__card", "shop_item_7__owned_badge", "shop_item_7__owned_label", "shop_item_8", "shop_item_8__card", "shop_item_8__owned_badge", "shop_item_8__owned_label", "shop_item_9", "shop_item_9__card", "shop_item_9__owned_badge", "shop_item_9__owned_label", "shop_item_10", "shop_item_10__card", "shop_item_10__owned_badge", "shop_item_10__owned_label", "shop_item_11", "shop_item_11__card", "shop_item_11__owned_badge", "shop_item_11__owned_label", "shop_item_12", "shop_item_12__card", "shop_item_12__owned_badge", "shop_item_12__owned_label", "homepage_background", "btn_start", "btn_users", "home_avatar_center", "home_name_center", "home_prev", "home_avatar_prev", "home_arrow_prev", "home_name_prev", "home_next", "home_avatar_next", "home_arrow_next", "home_name_next", "user_list_background", "add_user_button", "user_search", "user_rows", "user_row_1", "user_row_1_avatar", "user_row_1_name", "user_row_1_arrow", "user_row_2", "user_row_2_avatar", "user_row_2_name", "user_row_2_arrow", "user_row_3", "user_row_3_avatar", "user_row_3_name", "user_row_3_arrow", "user_row_4", "user_row_4_avatar", "user_row_4_name", "user_row_4_arrow", "user_row_5", "user_row_5_avatar", "user_row_5_name", "user_row_5_arrow", "user_row_6", "user_row_6_avatar", "user_row_6_name", "user_row_6_arrow", "user_row_7", "user_row_7_avatar", "user_row_7_name", "user_row_7_arrow", "user_row_8", "user_row_8_avatar", "user_row_8_name", "user_row_8_arrow", "user_row_9", "user_row_9_avatar", "user_row_9_name", "user_row_9_arrow", "user_row_10", "user_row_10_avatar", "user_row_10_name", "user_row_10_arrow", "user_row_11", "user_row_11_avatar", "user_row_11_name", "user_row_11_arrow", "user_row_12", "user_row_12_avatar", "user_row_12_name", "user_row_12_arrow", "user_creation_background", "action_user_creation_avatar_1_1", "action_user_creation_avatar_2_2", "action_user_creation_avatar_3_3", "action_user_creation_avatar_4_4", "action_user_creation_avatar_5_5", "action_user_creation_avatar_6_6", "action_user_creation_avatar_7_7", "action_user_creation_avatar_8_8", "action_user_creation_avatar_9_9", "action_user_creation_cancel_10", "action_user_creation_confirm_11", "user_name_input", "chapter_background", "obj2", "obj3", "obj4", "obj5", "obj6", "roadmap_background", "obj7", "level_label_1", "level_label_2", "level_label_3", "level_label_4", "level_label_5", "level_label_6", "level_label_7", "level_label_8", "obj8", "obj9", "lesson_step_0", "lesson_step_0_card_0", "lesson_step_0_pic_0", "lesson_step_0_pic_1", "lesson_step_1", "lesson_step_1_card_0", "lesson_step_1_pic_0", "lesson_step_1_pic_1", "lesson_step_1_pic_2", "lesson_step_1_pic_3", "lesson_step_1_pic_4", "lesson_step_1_pic_5", "lesson_q1_house", "lesson_q1_lamp", "lesson_q1_sun", "lesson_step_2", "lesson_step_2_card_0", "lesson_step_2_pic_0", "lesson_step_2_pic_1", "lesson_step_2_pic_2", "lesson_step_2_pic_3", "lesson_step_2_pic_4", "lesson_step_3", "lesson_step_3_card_0", "lesson_step_3_pic_0", "lesson_step_3_pic_1", "lesson_step_4", "lesson_step_4_card_0", "lesson_step_4_pic_0", "lesson_step_4_pic_1", "lesson_step_5", "lesson_step_5_card_0", "lesson_step_5_pic_0", "lesson_step_5_pic_1", "lesson_step_6", "lesson_step_6_card_0", "lesson_step_6_pic_0", "lesson_step_6_pic_1", "lesson_step_6_pic_2", "lesson_step_6_pic_3", "lesson_step_6_pic_4", "lesson_step_6_pic_5", "lesson_q2_house", "lesson_q2_battery", "lesson_q2_lamp", "lesson_step_7", "lesson_step_7_card_0", "lesson_step_7_pic_0", "lesson_step_7_pic_1", "lesson_step_7_pic_2", "lesson_step_7_pic_3", "lesson_step_7_pic_4", "lesson_branch_1_0", "lesson_branch_1_0_card_0", "lesson_branch_1_0_pic_0", "lesson_branch_1_0_pic_1", "lesson_branch_1_1", "lesson_branch_1_1_card_0", "lesson_branch_1_1_pic_0", "lesson_branch_1_1_pic_1", "lesson_branch_1_2", "lesson_branch_1_2_card_0", "lesson_branch_1_2_pic_0", "lesson_branch_1_2_pic_1", "lesson_branch_1_3", "lesson_branch_1_3_card_0", "lesson_branch_1_3_pic_0", "lesson_branch_1_3_pic_1", "lesson_branch_2_0", "lesson_branch_2_0_card_0", "lesson_branch_2_0_pic_0", "lesson_branch_2_0_pic_1", "lesson_branch_2_1", "lesson_branch_2_1_card_0", "lesson_branch_2_1_pic_0", "lesson_branch_2_1_pic_1", "lesson_branch_2_2", "lesson_branch_2_2_card_0", "lesson_branch_2_2_pic_0", "lesson_branch_2_2_pic_1", "lesson_branch_2_3", "lesson_branch_2_3_card_0", "lesson_branch_2_3_pic_0", "lesson_branch_2_3_pic_1", "lesson_branch_3_0", "lesson_branch_3_0_card_0", "lesson_branch_3_0_pic_0", "lesson_branch_3_0_pic_1", "lesson_branch_3_1", "lesson_branch_3_1_card_0", "lesson_branch_3_1_pic_0", "lesson_branch_3_1_pic_1", "lesson_branch_3_2", "lesson_branch_3_2_card_0", "lesson_branch_3_2_pic_0", "lesson_branch_3_2_pic_1", "lesson_branch_3_3", "lesson_branch_3_3_card_0", "lesson_branch_3_3_pic_0", "lesson_branch_3_3_pic_1", "lesson_keep_up", "obj10", "profile_background", "shop_button", "user_selection", "profile_name", "profile_figure", "outfit_item_1", "outfit_item_2", "outfit_item_3", "outfit_item_4", "outfit_item_5", "outfit_item_6", "outfit_label_1", "outfit_label_2", "outfit_label_3", "outfit_label_4", "outfit_label_5", "outfit_label_6", "shop_background", "shop_figure", "shop_overlay", "overlay_buy_wear", "overlay_item", "overlay_action", "overlay_action_icon", "overlay_action_title", "overlay_action_detail", "close_button", "overlay_balance", "overlay_price" };

//
// Event handlers
//

lv_obj_t *tick_value_change_obj;

static void event_handler_cb_home_page_btn_start(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 2, 0, e);
    }
}

static void event_handler_cb_home_page_btn_users(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_user_list_view_add_user_button(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 2, 0, e);
    }
}

static void event_handler_cb_user_list_view_user_rows(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_user_creation_action_user_creation_cancel_10(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 11, 0, e);
    }
}

static void event_handler_cb_user_creation_action_user_creation_confirm_11(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 12, 0, e);
    }
}

static void event_handler_cb_chapters_obj2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_chapters_obj3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_chapters_obj4(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_chapters_obj5(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 6, 0, e);
    }
}

static void event_handler_cb_chapters_obj6(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 7, 0, e);
    }
}

static void event_handler_cb_roadmap_obj7(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 11, 0, e);
    }
}

static void event_handler_cb_profile_page_shop_button(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_profile_page_user_selection(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_shop_page_close_button(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 24, 0, e);
    }
}

static void event_handler_cb_nav_bar_back_button(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 2, 0, e);
    }
}

static void event_handler_cb_nav_bar_battery_button(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 3, 0, e);
    }
}

static void event_handler_cb_nav_bar_help_button(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 4, 0, e);
    }
}

static void event_handler_cb_nav_bar_avatar_button(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 5, 0, e);
    }
}

static void event_handler_cb_nav_bar_coins_button(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 7, 0, e);
    }
}

static void event_handler_cb_nav_bar_battery_button_no_coins(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 9, 0, e);
    }
}

static void event_handler_cb_nav_bar_help_button_no_coins(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 10, 0, e);
    }
}

static void event_handler_cb_nav_bar_avatar_button_no_coins(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 11, 0, e);
    }
}

static void event_handler_cb_level_point_obj1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 1, 0, e);
    }
}

static void event_handler_cb_level_point_level(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)1;
        flowPropagateValueLVGLEvent(flowState, -1, 15, e);
    }
}

static void event_handler_cb_level_point_level_done(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 15, e);
    }
}

static void event_handler_cb_level_point_level_ongoing(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 15, e);
    }
}

static void event_handler_cb_complete_level_button_lvl1_complete_level_button(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_SINGLE_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 1, 0, e);
    }
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, -1, 14, e);
    }
}

static void event_handler_cb_shop_item_card(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_CLICKED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 1, 0, e);
    }
}

//
// Screens
//

void create_screen_home_page() {
    void *flowState = getFlowState(0, 0);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.home_page = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 1024, 600);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xfaf7ef), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // homepage-background
            lv_obj_t *obj = lv_image_create(parent_obj);
            objects.homepage_background = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
        }
        {
            // Btn_start
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.btn_start = obj;
            lv_obj_set_pos(obj, 381, 526);
            lv_obj_set_size(obj, 243, 37);
            lv_obj_add_event_cb(obj, event_handler_cb_home_page_btn_start, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x2f6b45), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_opa(obj, 50, LV_PART_MAIN | LV_STATE_CHECKED);
        }
        {
            // Btn_Users
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.btn_users = obj;
            lv_obj_set_pos(obj, 805, 96);
            lv_obj_set_size(obj, 120, 40);
            lv_obj_add_event_cb(obj, event_handler_cb_home_page_btn_users, LV_EVENT_ALL, flowState);
            lv_obj_set_style_radius(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_opa(obj, 50, LV_PART_MAIN | LV_STATE_PRESSED);
        }
        {
            // home_avatar_center
            lv_obj_t *obj = lv_image_create(parent_obj);
            objects.home_avatar_center = obj;
            lv_obj_set_pos(obj, 398, 203);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
        }
        {
            // home_name_center
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.home_name_center = obj;
            lv_obj_set_pos(obj, 253, 428);
            lv_obj_set_size(obj, 500, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x18352a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // home_prev
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.home_prev = obj;
            lv_obj_set_pos(obj, 175, 266);
            lv_obj_set_size(obj, 111, 153);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_opa(obj, 30, LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // home_avatar_prev
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.home_avatar_prev = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // home_arrow_prev
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.home_arrow_prev = obj;
                    lv_obj_set_pos(obj, 8, 128);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // home_name_prev
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.home_name_prev = obj;
                    lv_obj_set_pos(obj, 34, 129);
                    lv_obj_set_size(obj, 76, LV_SIZE_CONTENT);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x18352a), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            // home_next
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.home_next = obj;
            lv_obj_set_pos(obj, 719, 266);
            lv_obj_set_size(obj, 111, 153);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_opa(obj, 30, LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // home_avatar_next
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.home_avatar_next = obj;
                    lv_obj_set_pos(obj, 21, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // home_arrow_next
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.home_arrow_next = obj;
                    lv_obj_set_pos(obj, 7, 128);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // home_name_next
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.home_name_next = obj;
                    lv_obj_set_pos(obj, 34, 129);
                    lv_obj_set_size(obj, 76, LV_SIZE_CONTENT);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x18352a), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
    }
    
    tick_screen_home_page();
}

void delete_screen_home_page() {
    lv_obj_delete(objects.home_page);
    objects.home_page = 0;
    objects.homepage_background = 0;
    objects.btn_start = 0;
    objects.btn_users = 0;
    objects.home_avatar_center = 0;
    objects.home_name_center = 0;
    objects.home_prev = 0;
    objects.home_avatar_prev = 0;
    objects.home_arrow_prev = 0;
    objects.home_name_prev = 0;
    objects.home_next = 0;
    objects.home_avatar_next = 0;
    objects.home_arrow_next = 0;
    objects.home_name_next = 0;
    deletePageFlowState(0);
}

void tick_screen_home_page() {
    void *flowState = getFlowState(0, 0);
    (void)flowState;
}

void create_screen_user_list_view() {
    void *flowState = getFlowState(0, 1);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.user_list_view = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 1024, 600);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xfaf7ef), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // user-list-background
            lv_obj_t *obj = lv_image_create(parent_obj);
            objects.user_list_background = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
        }
        {
            // add_user_button
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.add_user_button = obj;
            lv_obj_set_pos(obj, 808, 71);
            lv_obj_set_size(obj, 127, 37);
            lv_obj_add_event_cb(obj, event_handler_cb_user_list_view_add_user_button, LV_EVENT_ALL, flowState);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_ON_FOCUS|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_pad_left(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 9, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x2f6b45), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 50, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_outline_width(obj, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_outline_color(obj, lv_color_hex(0x2f6b45), LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_outline_pad(obj, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_bg_opa(obj, 50, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_CHECKED);
        }
        {
            // user_search
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.user_search = obj;
            lv_obj_set_pos(obj, 90, 119);
            lv_obj_set_size(obj, 845, 36);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_placeholder_text(obj, "Search learner");
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 42, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // user_rows
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.user_rows = obj;
            lv_obj_set_pos(obj, 90, 171);
            lv_obj_set_size(obj, 845, 357);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_add_event_cb(obj, event_handler_cb_user_list_view_user_rows, LV_EVENT_ALL, flowState);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // user_row_1
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.user_row_1 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 412, 53);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xf0ebdd), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 11, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // user_row_1_avatar
                            lv_obj_t *obj = lv_image_create(parent_obj);
                            objects.user_row_1_avatar = obj;
                            lv_obj_set_pos(obj, 11, 6);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                        }
                        {
                            // user_row_1_name
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.user_row_1_name = obj;
                            lv_obj_set_pos(obj, 69, 17);
                            lv_obj_set_size(obj, 290, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0x18352a), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "");
                        }
                        {
                            // user_row_1_arrow
                            lv_obj_t *obj = lv_image_create(parent_obj);
                            objects.user_row_1_arrow = obj;
                            lv_obj_set_pos(obj, 377, 16);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                        }
                    }
                }
                {
                    // user_row_2
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.user_row_2 = obj;
                    lv_obj_set_pos(obj, 433, 0);
                    lv_obj_set_size(obj, 412, 53);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xf0ebdd), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 11, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // user_row_2_avatar
                            lv_obj_t *obj = lv_image_create(parent_obj);
                            objects.user_row_2_avatar = obj;
                            lv_obj_set_pos(obj, 11, 6);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                        }
                        {
                            // user_row_2_name
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.user_row_2_name = obj;
                            lv_obj_set_pos(obj, 69, 17);
                            lv_obj_set_size(obj, 290, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0x18352a), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "");
                        }
                        {
                            // user_row_2_arrow
                            lv_obj_t *obj = lv_image_create(parent_obj);
                            objects.user_row_2_arrow = obj;
                            lv_obj_set_pos(obj, 377, 16);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                        }
                    }
                }
                {
                    // user_row_3
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.user_row_3 = obj;
                    lv_obj_set_pos(obj, 0, 61);
                    lv_obj_set_size(obj, 412, 53);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xf0ebdd), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 11, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // user_row_3_avatar
                            lv_obj_t *obj = lv_image_create(parent_obj);
                            objects.user_row_3_avatar = obj;
                            lv_obj_set_pos(obj, 11, 6);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                        }
                        {
                            // user_row_3_name
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.user_row_3_name = obj;
                            lv_obj_set_pos(obj, 69, 17);
                            lv_obj_set_size(obj, 290, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0x18352a), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "");
                        }
                        {
                            // user_row_3_arrow
                            lv_obj_t *obj = lv_image_create(parent_obj);
                            objects.user_row_3_arrow = obj;
                            lv_obj_set_pos(obj, 377, 16);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                        }
                    }
                }
                {
                    // user_row_4
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.user_row_4 = obj;
                    lv_obj_set_pos(obj, 433, 61);
                    lv_obj_set_size(obj, 412, 53);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xf0ebdd), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 11, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // user_row_4_avatar
                            lv_obj_t *obj = lv_image_create(parent_obj);
                            objects.user_row_4_avatar = obj;
                            lv_obj_set_pos(obj, 11, 6);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                        }
                        {
                            // user_row_4_name
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.user_row_4_name = obj;
                            lv_obj_set_pos(obj, 69, 17);
                            lv_obj_set_size(obj, 290, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0x18352a), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "");
                        }
                        {
                            // user_row_4_arrow
                            lv_obj_t *obj = lv_image_create(parent_obj);
                            objects.user_row_4_arrow = obj;
                            lv_obj_set_pos(obj, 377, 16);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                        }
                    }
                }
                {
                    // user_row_5
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.user_row_5 = obj;
                    lv_obj_set_pos(obj, 0, 122);
                    lv_obj_set_size(obj, 412, 53);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xf0ebdd), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 11, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // user_row_5_avatar
                            lv_obj_t *obj = lv_image_create(parent_obj);
                            objects.user_row_5_avatar = obj;
                            lv_obj_set_pos(obj, 11, 6);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                        }
                        {
                            // user_row_5_name
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.user_row_5_name = obj;
                            lv_obj_set_pos(obj, 69, 17);
                            lv_obj_set_size(obj, 290, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0x18352a), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "");
                        }
                        {
                            // user_row_5_arrow
                            lv_obj_t *obj = lv_image_create(parent_obj);
                            objects.user_row_5_arrow = obj;
                            lv_obj_set_pos(obj, 377, 16);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                        }
                    }
                }
                {
                    // user_row_6
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.user_row_6 = obj;
                    lv_obj_set_pos(obj, 433, 122);
                    lv_obj_set_size(obj, 412, 53);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xf0ebdd), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 11, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // user_row_6_avatar
                            lv_obj_t *obj = lv_image_create(parent_obj);
                            objects.user_row_6_avatar = obj;
                            lv_obj_set_pos(obj, 11, 6);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                        }
                        {
                            // user_row_6_name
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.user_row_6_name = obj;
                            lv_obj_set_pos(obj, 69, 17);
                            lv_obj_set_size(obj, 290, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0x18352a), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "");
                        }
                        {
                            // user_row_6_arrow
                            lv_obj_t *obj = lv_image_create(parent_obj);
                            objects.user_row_6_arrow = obj;
                            lv_obj_set_pos(obj, 377, 16);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                        }
                    }
                }
                {
                    // user_row_7
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.user_row_7 = obj;
                    lv_obj_set_pos(obj, 0, 182);
                    lv_obj_set_size(obj, 412, 53);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xf0ebdd), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 11, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // user_row_7_avatar
                            lv_obj_t *obj = lv_image_create(parent_obj);
                            objects.user_row_7_avatar = obj;
                            lv_obj_set_pos(obj, 11, 6);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                        }
                        {
                            // user_row_7_name
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.user_row_7_name = obj;
                            lv_obj_set_pos(obj, 69, 17);
                            lv_obj_set_size(obj, 290, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0x18352a), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "");
                        }
                        {
                            // user_row_7_arrow
                            lv_obj_t *obj = lv_image_create(parent_obj);
                            objects.user_row_7_arrow = obj;
                            lv_obj_set_pos(obj, 377, 16);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                        }
                    }
                }
                {
                    // user_row_8
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.user_row_8 = obj;
                    lv_obj_set_pos(obj, 433, 182);
                    lv_obj_set_size(obj, 412, 53);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xf0ebdd), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 11, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // user_row_8_avatar
                            lv_obj_t *obj = lv_image_create(parent_obj);
                            objects.user_row_8_avatar = obj;
                            lv_obj_set_pos(obj, 11, 6);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                        }
                        {
                            // user_row_8_name
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.user_row_8_name = obj;
                            lv_obj_set_pos(obj, 69, 17);
                            lv_obj_set_size(obj, 290, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0x18352a), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "");
                        }
                        {
                            // user_row_8_arrow
                            lv_obj_t *obj = lv_image_create(parent_obj);
                            objects.user_row_8_arrow = obj;
                            lv_obj_set_pos(obj, 377, 16);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                        }
                    }
                }
                {
                    // user_row_9
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.user_row_9 = obj;
                    lv_obj_set_pos(obj, 0, 243);
                    lv_obj_set_size(obj, 412, 53);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xf0ebdd), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 11, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // user_row_9_avatar
                            lv_obj_t *obj = lv_image_create(parent_obj);
                            objects.user_row_9_avatar = obj;
                            lv_obj_set_pos(obj, 11, 6);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                        }
                        {
                            // user_row_9_name
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.user_row_9_name = obj;
                            lv_obj_set_pos(obj, 69, 17);
                            lv_obj_set_size(obj, 290, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0x18352a), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "");
                        }
                        {
                            // user_row_9_arrow
                            lv_obj_t *obj = lv_image_create(parent_obj);
                            objects.user_row_9_arrow = obj;
                            lv_obj_set_pos(obj, 377, 16);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                        }
                    }
                }
                {
                    // user_row_10
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.user_row_10 = obj;
                    lv_obj_set_pos(obj, 433, 243);
                    lv_obj_set_size(obj, 412, 53);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xf0ebdd), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 11, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // user_row_10_avatar
                            lv_obj_t *obj = lv_image_create(parent_obj);
                            objects.user_row_10_avatar = obj;
                            lv_obj_set_pos(obj, 11, 6);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                        }
                        {
                            // user_row_10_name
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.user_row_10_name = obj;
                            lv_obj_set_pos(obj, 69, 17);
                            lv_obj_set_size(obj, 290, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0x18352a), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "");
                        }
                        {
                            // user_row_10_arrow
                            lv_obj_t *obj = lv_image_create(parent_obj);
                            objects.user_row_10_arrow = obj;
                            lv_obj_set_pos(obj, 377, 16);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                        }
                    }
                }
                {
                    // user_row_11
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.user_row_11 = obj;
                    lv_obj_set_pos(obj, 0, 304);
                    lv_obj_set_size(obj, 412, 53);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xf0ebdd), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 11, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // user_row_11_avatar
                            lv_obj_t *obj = lv_image_create(parent_obj);
                            objects.user_row_11_avatar = obj;
                            lv_obj_set_pos(obj, 11, 6);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                        }
                        {
                            // user_row_11_name
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.user_row_11_name = obj;
                            lv_obj_set_pos(obj, 69, 17);
                            lv_obj_set_size(obj, 290, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0x18352a), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "");
                        }
                        {
                            // user_row_11_arrow
                            lv_obj_t *obj = lv_image_create(parent_obj);
                            objects.user_row_11_arrow = obj;
                            lv_obj_set_pos(obj, 377, 16);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                        }
                    }
                }
                {
                    // user_row_12
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.user_row_12 = obj;
                    lv_obj_set_pos(obj, 433, 304);
                    lv_obj_set_size(obj, 412, 53);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xf0ebdd), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 11, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // user_row_12_avatar
                            lv_obj_t *obj = lv_image_create(parent_obj);
                            objects.user_row_12_avatar = obj;
                            lv_obj_set_pos(obj, 11, 6);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                        }
                        {
                            // user_row_12_name
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.user_row_12_name = obj;
                            lv_obj_set_pos(obj, 69, 17);
                            lv_obj_set_size(obj, 290, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0x18352a), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "");
                        }
                        {
                            // user_row_12_arrow
                            lv_obj_t *obj = lv_image_create(parent_obj);
                            objects.user_row_12_arrow = obj;
                            lv_obj_set_pos(obj, 377, 16);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                        }
                    }
                }
            }
        }
    }
    
    tick_screen_user_list_view();
}

void delete_screen_user_list_view() {
    lv_obj_delete(objects.user_list_view);
    objects.user_list_view = 0;
    objects.user_list_background = 0;
    objects.add_user_button = 0;
    objects.user_search = 0;
    objects.user_rows = 0;
    objects.user_row_1 = 0;
    objects.user_row_1_avatar = 0;
    objects.user_row_1_name = 0;
    objects.user_row_1_arrow = 0;
    objects.user_row_2 = 0;
    objects.user_row_2_avatar = 0;
    objects.user_row_2_name = 0;
    objects.user_row_2_arrow = 0;
    objects.user_row_3 = 0;
    objects.user_row_3_avatar = 0;
    objects.user_row_3_name = 0;
    objects.user_row_3_arrow = 0;
    objects.user_row_4 = 0;
    objects.user_row_4_avatar = 0;
    objects.user_row_4_name = 0;
    objects.user_row_4_arrow = 0;
    objects.user_row_5 = 0;
    objects.user_row_5_avatar = 0;
    objects.user_row_5_name = 0;
    objects.user_row_5_arrow = 0;
    objects.user_row_6 = 0;
    objects.user_row_6_avatar = 0;
    objects.user_row_6_name = 0;
    objects.user_row_6_arrow = 0;
    objects.user_row_7 = 0;
    objects.user_row_7_avatar = 0;
    objects.user_row_7_name = 0;
    objects.user_row_7_arrow = 0;
    objects.user_row_8 = 0;
    objects.user_row_8_avatar = 0;
    objects.user_row_8_name = 0;
    objects.user_row_8_arrow = 0;
    objects.user_row_9 = 0;
    objects.user_row_9_avatar = 0;
    objects.user_row_9_name = 0;
    objects.user_row_9_arrow = 0;
    objects.user_row_10 = 0;
    objects.user_row_10_avatar = 0;
    objects.user_row_10_name = 0;
    objects.user_row_10_arrow = 0;
    objects.user_row_11 = 0;
    objects.user_row_11_avatar = 0;
    objects.user_row_11_name = 0;
    objects.user_row_11_arrow = 0;
    objects.user_row_12 = 0;
    objects.user_row_12_avatar = 0;
    objects.user_row_12_name = 0;
    objects.user_row_12_arrow = 0;
    deletePageFlowState(1);
}

void tick_screen_user_list_view() {
    void *flowState = getFlowState(0, 1);
    (void)flowState;
}

void create_screen_user_creation() {
    void *flowState = getFlowState(0, 2);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.user_creation = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 1024, 600);
    {
        lv_obj_t *parent_obj = obj;
        {
            // user-creation-background
            lv_obj_t *obj = lv_image_create(parent_obj);
            objects.user_creation_background = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
        }
        {
            // action_user_creation_avatar_1_1
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.action_user_creation_avatar_1_1 = obj;
            lv_obj_set_pos(obj, 357, 176);
            lv_obj_set_size(obj, 161, 75);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_ON_FOCUS|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_pad_left(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 50, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_outline_width(obj, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_outline_color(obj, lv_color_hex(0x2f6b45), LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_outline_pad(obj, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_border_color(obj, lv_color_hex(0x2f6b45), LV_PART_MAIN | LV_STATE_CHECKED);
        }
        {
            // action_user_creation_avatar_2_2
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.action_user_creation_avatar_2_2 = obj;
            lv_obj_set_pos(obj, 530, 176);
            lv_obj_set_size(obj, 161, 75);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_ON_FOCUS|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_pad_left(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 50, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_outline_width(obj, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_outline_color(obj, lv_color_hex(0x2f6b45), LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_outline_pad(obj, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_border_color(obj, lv_color_hex(0x2f6b45), LV_PART_MAIN | LV_STATE_CHECKED);
        }
        {
            // action_user_creation_avatar_3_3
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.action_user_creation_avatar_3_3 = obj;
            lv_obj_set_pos(obj, 703, 176);
            lv_obj_set_size(obj, 161, 75);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_ON_FOCUS|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_pad_left(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 50, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_outline_width(obj, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_outline_color(obj, lv_color_hex(0x2f6b45), LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_outline_pad(obj, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_border_color(obj, lv_color_hex(0x2f6b45), LV_PART_MAIN | LV_STATE_CHECKED);
        }
        {
            // action_user_creation_avatar_4_4
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.action_user_creation_avatar_4_4 = obj;
            lv_obj_set_pos(obj, 357, 262);
            lv_obj_set_size(obj, 161, 75);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_ON_FOCUS|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_pad_left(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 50, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_outline_width(obj, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_outline_color(obj, lv_color_hex(0x2f6b45), LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_outline_pad(obj, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_border_color(obj, lv_color_hex(0x2f6b45), LV_PART_MAIN | LV_STATE_CHECKED);
        }
        {
            // action_user_creation_avatar_5_5
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.action_user_creation_avatar_5_5 = obj;
            lv_obj_set_pos(obj, 530, 262);
            lv_obj_set_size(obj, 161, 75);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_ON_FOCUS|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_pad_left(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 50, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_outline_width(obj, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_outline_color(obj, lv_color_hex(0x2f6b45), LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_outline_pad(obj, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_border_color(obj, lv_color_hex(0x2f6b45), LV_PART_MAIN | LV_STATE_CHECKED);
        }
        {
            // action_user_creation_avatar_6_6
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.action_user_creation_avatar_6_6 = obj;
            lv_obj_set_pos(obj, 703, 262);
            lv_obj_set_size(obj, 161, 75);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_ON_FOCUS|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_pad_left(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 50, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_outline_width(obj, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_outline_color(obj, lv_color_hex(0x2f6b45), LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_outline_pad(obj, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_border_color(obj, lv_color_hex(0x2f6b45), LV_PART_MAIN | LV_STATE_CHECKED);
        }
        {
            // action_user_creation_avatar_7_7
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.action_user_creation_avatar_7_7 = obj;
            lv_obj_set_pos(obj, 357, 349);
            lv_obj_set_size(obj, 161, 75);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_ON_FOCUS|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_pad_left(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 50, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_outline_width(obj, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_outline_color(obj, lv_color_hex(0x2f6b45), LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_outline_pad(obj, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_border_color(obj, lv_color_hex(0x2f6b45), LV_PART_MAIN | LV_STATE_CHECKED);
        }
        {
            // action_user_creation_avatar_8_8
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.action_user_creation_avatar_8_8 = obj;
            lv_obj_set_pos(obj, 530, 349);
            lv_obj_set_size(obj, 161, 75);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_ON_FOCUS|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_pad_left(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 50, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_outline_width(obj, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_outline_color(obj, lv_color_hex(0x2f6b45), LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_outline_pad(obj, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_border_color(obj, lv_color_hex(0x2f6b45), LV_PART_MAIN | LV_STATE_CHECKED);
        }
        {
            // action_user_creation_avatar_9_9
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.action_user_creation_avatar_9_9 = obj;
            lv_obj_set_pos(obj, 703, 349);
            lv_obj_set_size(obj, 161, 75);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_ON_FOCUS|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_pad_left(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 50, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_outline_width(obj, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_outline_color(obj, lv_color_hex(0x2f6b45), LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_outline_pad(obj, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_border_color(obj, lv_color_hex(0x2f6b45), LV_PART_MAIN | LV_STATE_CHECKED);
        }
        {
            // action_user_creation_cancel_10
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.action_user_creation_cancel_10 = obj;
            lv_obj_set_pos(obj, 518, 491);
            lv_obj_set_size(obj, 219, 40);
            lv_obj_add_event_cb(obj, event_handler_cb_user_creation_action_user_creation_cancel_10, LV_EVENT_ALL, flowState);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_ON_FOCUS|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_pad_left(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 50, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_outline_width(obj, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_outline_color(obj, lv_color_hex(0x2f6b45), LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_outline_pad(obj, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
        }
        {
            // action_user_creation_confirm_11
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.action_user_creation_confirm_11 = obj;
            lv_obj_set_pos(obj, 754, 491);
            lv_obj_set_size(obj, 219, 40);
            lv_obj_add_event_cb(obj, event_handler_cb_user_creation_action_user_creation_confirm_11, LV_EVENT_ALL, flowState);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_ON_FOCUS|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            lv_obj_set_style_pad_left(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 50, LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_outline_width(obj, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_outline_color(obj, lv_color_hex(0x2f6b45), LV_PART_MAIN | LV_STATE_FOCUSED);
            lv_obj_set_style_outline_pad(obj, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
        }
        {
            // user_name_input
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.user_name_input = obj;
            lv_obj_set_pos(obj, 51, 103);
            lv_obj_set_size(obj, 219, 46);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_placeholder_text(obj, "Enter name");
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 14, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    
    tick_screen_user_creation();
}

void delete_screen_user_creation() {
    lv_obj_delete(objects.user_creation);
    objects.user_creation = 0;
    objects.user_creation_background = 0;
    objects.action_user_creation_avatar_1_1 = 0;
    objects.action_user_creation_avatar_2_2 = 0;
    objects.action_user_creation_avatar_3_3 = 0;
    objects.action_user_creation_avatar_4_4 = 0;
    objects.action_user_creation_avatar_5_5 = 0;
    objects.action_user_creation_avatar_6_6 = 0;
    objects.action_user_creation_avatar_7_7 = 0;
    objects.action_user_creation_avatar_8_8 = 0;
    objects.action_user_creation_avatar_9_9 = 0;
    objects.action_user_creation_cancel_10 = 0;
    objects.action_user_creation_confirm_11 = 0;
    objects.user_name_input = 0;
    deletePageFlowState(2);
}

void tick_screen_user_creation() {
    void *flowState = getFlowState(0, 2);
    (void)flowState;
}

void create_screen_chapters() {
    void *flowState = getFlowState(0, 3);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.chapters = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 1024, 600);
    {
        lv_obj_t *parent_obj = obj;
        {
            // chapter-background
            lv_obj_t *obj = lv_image_create(parent_obj);
            objects.chapter_background = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
        }
        {
            // NavBarChapters
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.nav_bar_chapters = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 1024, 66);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_nav_bar(obj, getFlowState(flowState, 2), 11);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj2 = obj;
            lv_obj_set_pos(obj, 97, 125);
            lv_obj_set_size(obj, 404, 202);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_add_event_cb(obj, event_handler_cb_chapters_obj2, LV_EVENT_ALL, flowState);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj3 = obj;
            lv_obj_set_pos(obj, 522, 125);
            lv_obj_set_size(obj, 404, 202);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_add_event_cb(obj, event_handler_cb_chapters_obj3, LV_EVENT_ALL, flowState);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj4 = obj;
            lv_obj_set_pos(obj, 97, 343);
            lv_obj_set_size(obj, 404, 202);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_add_event_cb(obj, event_handler_cb_chapters_obj4, LV_EVENT_ALL, flowState);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj5 = obj;
            lv_obj_set_pos(obj, 522, 343);
            lv_obj_set_size(obj, 404, 202);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_add_event_cb(obj, event_handler_cb_chapters_obj5, LV_EVENT_ALL, flowState);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj6 = obj;
            lv_obj_set_pos(obj, 48, 11);
            lv_obj_set_size(obj, 155, 45);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_add_event_cb(obj, event_handler_cb_chapters_obj6, LV_EVENT_ALL, flowState);
        }
    }
    
    tick_screen_chapters();
}

void delete_screen_chapters() {
    lv_obj_delete(objects.chapters);
    objects.chapters = 0;
    objects.chapter_background = 0;
    objects.nav_bar_chapters = 0;
    objects.obj2 = 0;
    objects.obj3 = 0;
    objects.obj4 = 0;
    objects.obj5 = 0;
    objects.obj6 = 0;
    deletePageFlowState(3);
}

void tick_screen_chapters() {
    void *flowState = getFlowState(0, 3);
    (void)flowState;
    tick_user_widget_nav_bar(getFlowState(flowState, 2), 11);
}

void create_screen_roadmap() {
    void *flowState = getFlowState(0, 4);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.roadmap = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 1024, 600);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xfaf7ef), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // roadmap-background
            lv_obj_t *obj = lv_image_create(parent_obj);
            objects.roadmap_background = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
        }
        {
            // NavBarRoadmap
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.nav_bar_roadmap = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 1024, 66);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_nav_bar(obj, getFlowState(flowState, 2), 24);
        }
        {
            // LevelPoint_1
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.level_point_1 = obj;
            lv_obj_set_pos(obj, 108, 130);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_level_point(obj, getFlowState(flowState, 3), 37);
        }
        {
            // LevelPoint_2
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.level_point_2 = obj;
            lv_obj_set_pos(obj, 276, 205);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_level_point(obj, getFlowState(flowState, 4), 45);
        }
        {
            // LevelPoint_3
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.level_point_3 = obj;
            lv_obj_set_pos(obj, 500, 172);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_level_point(obj, getFlowState(flowState, 5), 53);
        }
        {
            // LevelPoint_4
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.level_point_4 = obj;
            lv_obj_set_pos(obj, 724, 182);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_level_point(obj, getFlowState(flowState, 6), 61);
        }
        {
            // LevelPoint_5
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.level_point_5 = obj;
            lv_obj_set_pos(obj, 777, 326);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_level_point(obj, getFlowState(flowState, 7), 69);
        }
        {
            // LevelPoint_6
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.level_point_6 = obj;
            lv_obj_set_pos(obj, 551, 373);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_level_point(obj, getFlowState(flowState, 8), 77);
        }
        {
            // LevelPoint_7
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.level_point_7 = obj;
            lv_obj_set_pos(obj, 349, 340);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_level_point(obj, getFlowState(flowState, 9), 85);
        }
        {
            // LevelPoint_8
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.level_point_8 = obj;
            lv_obj_set_pos(obj, 108, 387);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_level_point(obj, getFlowState(flowState, 10), 93);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj7 = obj;
            lv_obj_set_pos(obj, 48, 13);
            lv_obj_set_size(obj, 75, 40);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_add_event_cb(obj, event_handler_cb_roadmap_obj7, LV_EVENT_ALL, flowState);
        }
        {
            // level_label_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.level_label_1 = obj;
            lv_obj_set_pos(obj, 92, 228);
            lv_obj_set_size(obj, 120, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x090502), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // level_label_2
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.level_label_2 = obj;
            lv_obj_set_pos(obj, 256, 306);
            lv_obj_set_size(obj, 120, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x090502), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // level_label_3
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.level_label_3 = obj;
            lv_obj_set_pos(obj, 479, 278);
            lv_obj_set_size(obj, 120, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x090502), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // level_label_4
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.level_label_4 = obj;
            lv_obj_set_pos(obj, 672, 284);
            lv_obj_set_size(obj, 120, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x090502), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // level_label_5
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.level_label_5 = obj;
            lv_obj_set_pos(obj, 803, 432);
            lv_obj_set_size(obj, 120, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x090502), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // level_label_6
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.level_label_6 = obj;
            lv_obj_set_pos(obj, 529, 474);
            lv_obj_set_size(obj, 120, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x090502), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // level_label_7
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.level_label_7 = obj;
            lv_obj_set_pos(obj, 329, 445);
            lv_obj_set_size(obj, 120, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x090502), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // level_label_8
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.level_label_8 = obj;
            lv_obj_set_pos(obj, 88, 493);
            lv_obj_set_size(obj, 120, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x090502), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
    }
    
    tick_screen_roadmap();
}

void delete_screen_roadmap() {
    lv_obj_delete(objects.roadmap);
    objects.roadmap = 0;
    objects.roadmap_background = 0;
    objects.nav_bar_roadmap = 0;
    objects.level_point_1 = 0;
    objects.level_point_2 = 0;
    objects.level_point_3 = 0;
    objects.level_point_4 = 0;
    objects.level_point_5 = 0;
    objects.level_point_6 = 0;
    objects.level_point_7 = 0;
    objects.level_point_8 = 0;
    objects.obj7 = 0;
    objects.level_label_1 = 0;
    objects.level_label_2 = 0;
    objects.level_label_3 = 0;
    objects.level_label_4 = 0;
    objects.level_label_5 = 0;
    objects.level_label_6 = 0;
    objects.level_label_7 = 0;
    objects.level_label_8 = 0;
    deletePageFlowState(4);
}

void tick_screen_roadmap() {
    void *flowState = getFlowState(0, 4);
    (void)flowState;
    tick_user_widget_nav_bar(getFlowState(flowState, 2), 24);
    tick_user_widget_level_point(getFlowState(flowState, 3), 37);
    tick_user_widget_level_point(getFlowState(flowState, 4), 45);
    tick_user_widget_level_point(getFlowState(flowState, 5), 53);
    tick_user_widget_level_point(getFlowState(flowState, 6), 61);
    tick_user_widget_level_point(getFlowState(flowState, 7), 69);
    tick_user_widget_level_point(getFlowState(flowState, 8), 77);
    tick_user_widget_level_point(getFlowState(flowState, 9), 85);
    tick_user_widget_level_point(getFlowState(flowState, 10), 93);
    {
        const char *new_val = evalTextProperty(flowState, 12, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.level_label_1);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.level_label_1;
            lv_label_set_text(objects.level_label_1, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 13, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.level_label_2);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.level_label_2;
            lv_label_set_text(objects.level_label_2, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 14, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.level_label_3);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.level_label_3;
            lv_label_set_text(objects.level_label_3, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 15, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.level_label_4);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.level_label_4;
            lv_label_set_text(objects.level_label_4, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 16, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.level_label_5);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.level_label_5;
            lv_label_set_text(objects.level_label_5, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 17, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.level_label_6);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.level_label_6;
            lv_label_set_text(objects.level_label_6, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 18, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.level_label_7);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.level_label_7;
            lv_label_set_text(objects.level_label_7, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 19, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.level_label_8);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.level_label_8;
            lv_label_set_text(objects.level_label_8, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_screen_level1() {
    void *flowState = getFlowState(0, 5);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.level1 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 1024, 600);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj10 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 1024, 600);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj8 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 1024, 600);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc3c3), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj9 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 1024, 600);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x841515), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // lesson_step_0
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.lesson_step_0 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 1024, 600);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfaf7ef), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lesson_step_0_card_0
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.lesson_step_0_card_0 = obj;
                    lv_obj_set_pos(obj, 62, 116);
                    lv_obj_set_size(obj, 900, 430);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xf0ebdd), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lesson_step_0_pic_0
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_step_0_pic_0 = obj;
                    lv_obj_set_pos(obj, 272, 191);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // lesson_step_0_pic_1
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_step_0_pic_1 = obj;
                    lv_obj_set_pos(obj, 430, 300);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
            }
        }
        {
            // lesson_step_1
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.lesson_step_1 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 1024, 600);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfaf7ef), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lesson_step_1_card_0
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.lesson_step_1_card_0 = obj;
                    lv_obj_set_pos(obj, 62, 116);
                    lv_obj_set_size(obj, 900, 430);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xf0ebdd), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lesson_step_1_pic_0
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_step_1_pic_0 = obj;
                    lv_obj_set_pos(obj, 345, 315);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // lesson_step_1_pic_1
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_step_1_pic_1 = obj;
                    lv_obj_set_pos(obj, 664, 323);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // lesson_step_1_pic_2
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_step_1_pic_2 = obj;
                    lv_obj_set_pos(obj, 122, 248);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // lesson_step_1_pic_3
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_step_1_pic_3 = obj;
                    lv_obj_set_pos(obj, 757, 248);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // lesson_step_1_pic_4
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_step_1_pic_4 = obj;
                    lv_obj_set_pos(obj, 430, 248);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // lesson_step_1_pic_5
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_step_1_pic_5 = obj;
                    lv_obj_set_pos(obj, 148, 168);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // lesson_q1_house
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_q1_house = obj;
                    lv_obj_set_pos(obj, 588, 442);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // lesson_q1_lamp
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_q1_lamp = obj;
                    lv_obj_set_pos(obj, 486, 443);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // lesson_q1_sun
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_q1_sun = obj;
                    lv_obj_set_pos(obj, 384, 443);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
            }
        }
        {
            // lesson_step_2
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.lesson_step_2 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 1024, 600);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfaf7ef), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lesson_step_2_card_0
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.lesson_step_2_card_0 = obj;
                    lv_obj_set_pos(obj, 62, 116);
                    lv_obj_set_size(obj, 900, 430);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xf0ebdd), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lesson_step_2_pic_0
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_step_2_pic_0 = obj;
                    lv_obj_set_pos(obj, 345, 315);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // lesson_step_2_pic_1
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_step_2_pic_1 = obj;
                    lv_obj_set_pos(obj, 664, 323);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // lesson_step_2_pic_2
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_step_2_pic_2 = obj;
                    lv_obj_set_pos(obj, 122, 248);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // lesson_step_2_pic_3
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_step_2_pic_3 = obj;
                    lv_obj_set_pos(obj, 757, 248);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // lesson_step_2_pic_4
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_step_2_pic_4 = obj;
                    lv_obj_set_pos(obj, 430, 247);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
            }
        }
        {
            // lesson_step_3
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.lesson_step_3 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 1024, 600);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfaf7ef), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lesson_step_3_card_0
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.lesson_step_3_card_0 = obj;
                    lv_obj_set_pos(obj, 62, 116);
                    lv_obj_set_size(obj, 900, 430);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xf0ebdd), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lesson_step_3_pic_0
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_step_3_pic_0 = obj;
                    lv_obj_set_pos(obj, 429, 300);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // lesson_step_3_pic_1
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_step_3_pic_1 = obj;
                    lv_obj_set_pos(obj, 264, 191);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
            }
        }
        {
            // lesson_step_4
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.lesson_step_4 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 1024, 600);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfaf7ef), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lesson_step_4_card_0
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.lesson_step_4_card_0 = obj;
                    lv_obj_set_pos(obj, 62, 116);
                    lv_obj_set_size(obj, 900, 430);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xf0ebdd), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lesson_step_4_pic_0
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_step_4_pic_0 = obj;
                    lv_obj_set_pos(obj, 209, 191);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // lesson_step_4_pic_1
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_step_4_pic_1 = obj;
                    lv_obj_set_pos(obj, 430, 325);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
            }
        }
        {
            // lesson_step_5
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.lesson_step_5 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 1024, 600);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfaf7ef), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lesson_step_5_card_0
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.lesson_step_5_card_0 = obj;
                    lv_obj_set_pos(obj, 62, 116);
                    lv_obj_set_size(obj, 900, 430);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xf0ebdd), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lesson_step_5_pic_0
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_step_5_pic_0 = obj;
                    lv_obj_set_pos(obj, 329, 191);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // lesson_step_5_pic_1
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_step_5_pic_1 = obj;
                    lv_obj_set_pos(obj, 429, 300);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
            }
        }
        {
            // lesson_step_6
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.lesson_step_6 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 1024, 600);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfaf7ef), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lesson_step_6_card_0
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.lesson_step_6_card_0 = obj;
                    lv_obj_set_pos(obj, 62, 116);
                    lv_obj_set_size(obj, 900, 430);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xf0ebdd), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lesson_step_6_pic_0
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_step_6_pic_0 = obj;
                    lv_obj_set_pos(obj, 328, 323);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // lesson_step_6_pic_1
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_step_6_pic_1 = obj;
                    lv_obj_set_pos(obj, 621, 331);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // lesson_step_6_pic_2
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_step_6_pic_2 = obj;
                    lv_obj_set_pos(obj, 692, 256);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // lesson_step_6_pic_3
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_step_6_pic_3 = obj;
                    lv_obj_set_pos(obj, 406, 256);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // lesson_step_6_pic_4
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_step_6_pic_4 = obj;
                    lv_obj_set_pos(obj, 104, 172);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // lesson_step_6_pic_5
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_step_6_pic_5 = obj;
                    lv_obj_set_pos(obj, 115, 256);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // lesson_q2_house
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_q2_house = obj;
                    lv_obj_set_pos(obj, 836, 438);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // lesson_q2_battery
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_q2_battery = obj;
                    lv_obj_set_pos(obj, 632, 439);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // lesson_q2_lamp
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_q2_lamp = obj;
                    lv_obj_set_pos(obj, 734, 439);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
            }
        }
        {
            // lesson_step_7
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.lesson_step_7 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 1024, 600);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfaf7ef), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lesson_step_7_card_0
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.lesson_step_7_card_0 = obj;
                    lv_obj_set_pos(obj, 62, 116);
                    lv_obj_set_size(obj, 900, 430);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xf0ebdd), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lesson_step_7_pic_0
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_step_7_pic_0 = obj;
                    lv_obj_set_pos(obj, 345, 316);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // lesson_step_7_pic_1
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_step_7_pic_1 = obj;
                    lv_obj_set_pos(obj, 664, 324);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // lesson_step_7_pic_2
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_step_7_pic_2 = obj;
                    lv_obj_set_pos(obj, 446, 249);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // lesson_step_7_pic_3
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_step_7_pic_3 = obj;
                    lv_obj_set_pos(obj, 134, 249);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // lesson_step_7_pic_4
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_step_7_pic_4 = obj;
                    lv_obj_set_pos(obj, 759, 249);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
            }
        }
        {
            // lesson_branch_1_0
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.lesson_branch_1_0 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 1024, 600);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfaf7ef), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lesson_branch_1_0_card_0
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.lesson_branch_1_0_card_0 = obj;
                    lv_obj_set_pos(obj, 62, 116);
                    lv_obj_set_size(obj, 900, 430);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xf0ebdd), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lesson_branch_1_0_pic_0
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_branch_1_0_pic_0 = obj;
                    lv_obj_set_pos(obj, 293, 191);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // lesson_branch_1_0_pic_1
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_branch_1_0_pic_1 = obj;
                    lv_obj_set_pos(obj, 430, 315);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
            }
        }
        {
            // lesson_branch_1_1
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.lesson_branch_1_1 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 1024, 600);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfaf7ef), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lesson_branch_1_1_card_0
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.lesson_branch_1_1_card_0 = obj;
                    lv_obj_set_pos(obj, 62, 116);
                    lv_obj_set_size(obj, 900, 430);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xf0ebdd), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lesson_branch_1_1_pic_0
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_branch_1_1_pic_0 = obj;
                    lv_obj_set_pos(obj, 334, 191);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // lesson_branch_1_1_pic_1
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_branch_1_1_pic_1 = obj;
                    lv_obj_set_pos(obj, 430, 315);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
            }
        }
        {
            // lesson_branch_1_2
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.lesson_branch_1_2 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 1024, 600);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfaf7ef), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lesson_branch_1_2_card_0
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.lesson_branch_1_2_card_0 = obj;
                    lv_obj_set_pos(obj, 62, 116);
                    lv_obj_set_size(obj, 900, 430);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xf0ebdd), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lesson_branch_1_2_pic_0
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_branch_1_2_pic_0 = obj;
                    lv_obj_set_pos(obj, 292, 191);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // lesson_branch_1_2_pic_1
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_branch_1_2_pic_1 = obj;
                    lv_obj_set_pos(obj, 429, 315);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
            }
        }
        {
            // lesson_branch_1_3
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.lesson_branch_1_3 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 1024, 600);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfaf7ef), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lesson_branch_1_3_card_0
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.lesson_branch_1_3_card_0 = obj;
                    lv_obj_set_pos(obj, 62, 116);
                    lv_obj_set_size(obj, 900, 430);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xf0ebdd), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lesson_branch_1_3_pic_0
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_branch_1_3_pic_0 = obj;
                    lv_obj_set_pos(obj, 233, 191);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // lesson_branch_1_3_pic_1
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_branch_1_3_pic_1 = obj;
                    lv_obj_set_pos(obj, 429, 315);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
            }
        }
        {
            // lesson_branch_2_0
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.lesson_branch_2_0 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 1024, 600);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfaf7ef), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lesson_branch_2_0_card_0
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.lesson_branch_2_0_card_0 = obj;
                    lv_obj_set_pos(obj, 62, 116);
                    lv_obj_set_size(obj, 900, 430);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xf0ebdd), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lesson_branch_2_0_pic_0
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_branch_2_0_pic_0 = obj;
                    lv_obj_set_pos(obj, 310, 191);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // lesson_branch_2_0_pic_1
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_branch_2_0_pic_1 = obj;
                    lv_obj_set_pos(obj, 430, 315);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
            }
        }
        {
            // lesson_branch_2_1
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.lesson_branch_2_1 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 1024, 600);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfaf7ef), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lesson_branch_2_1_card_0
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.lesson_branch_2_1_card_0 = obj;
                    lv_obj_set_pos(obj, 62, 116);
                    lv_obj_set_size(obj, 900, 430);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xf0ebdd), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lesson_branch_2_1_pic_0
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_branch_2_1_pic_0 = obj;
                    lv_obj_set_pos(obj, 362, 195);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // lesson_branch_2_1_pic_1
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_branch_2_1_pic_1 = obj;
                    lv_obj_set_pos(obj, 430, 315);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
            }
        }
        {
            // lesson_branch_2_2
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.lesson_branch_2_2 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 1024, 600);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfaf7ef), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lesson_branch_2_2_card_0
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.lesson_branch_2_2_card_0 = obj;
                    lv_obj_set_pos(obj, 62, 116);
                    lv_obj_set_size(obj, 900, 430);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xf0ebdd), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lesson_branch_2_2_pic_0
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_branch_2_2_pic_0 = obj;
                    lv_obj_set_pos(obj, 264, 174);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // lesson_branch_2_2_pic_1
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_branch_2_2_pic_1 = obj;
                    lv_obj_set_pos(obj, 430, 315);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
            }
        }
        {
            // lesson_branch_2_3
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.lesson_branch_2_3 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 1024, 600);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfaf7ef), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lesson_branch_2_3_card_0
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.lesson_branch_2_3_card_0 = obj;
                    lv_obj_set_pos(obj, 62, 116);
                    lv_obj_set_size(obj, 900, 430);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xf0ebdd), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lesson_branch_2_3_pic_0
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_branch_2_3_pic_0 = obj;
                    lv_obj_set_pos(obj, 263, 174);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // lesson_branch_2_3_pic_1
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_branch_2_3_pic_1 = obj;
                    lv_obj_set_pos(obj, 430, 315);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
            }
        }
        {
            // lesson_branch_3_0
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.lesson_branch_3_0 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 1024, 600);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfaf7ef), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lesson_branch_3_0_card_0
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.lesson_branch_3_0_card_0 = obj;
                    lv_obj_set_pos(obj, 62, 116);
                    lv_obj_set_size(obj, 900, 430);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xf0ebdd), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lesson_branch_3_0_pic_0
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_branch_3_0_pic_0 = obj;
                    lv_obj_set_pos(obj, 236, 191);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // lesson_branch_3_0_pic_1
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_branch_3_0_pic_1 = obj;
                    lv_obj_set_pos(obj, 430, 315);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
            }
        }
        {
            // lesson_branch_3_1
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.lesson_branch_3_1 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 1024, 600);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfaf7ef), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lesson_branch_3_1_card_0
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.lesson_branch_3_1_card_0 = obj;
                    lv_obj_set_pos(obj, 62, 116);
                    lv_obj_set_size(obj, 900, 430);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xf0ebdd), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lesson_branch_3_1_pic_0
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_branch_3_1_pic_0 = obj;
                    lv_obj_set_pos(obj, 339, 183);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // lesson_branch_3_1_pic_1
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_branch_3_1_pic_1 = obj;
                    lv_obj_set_pos(obj, 394, 279);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
            }
        }
        {
            // lesson_branch_3_2
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.lesson_branch_3_2 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 1024, 600);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfaf7ef), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lesson_branch_3_2_card_0
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.lesson_branch_3_2_card_0 = obj;
                    lv_obj_set_pos(obj, 62, 116);
                    lv_obj_set_size(obj, 900, 430);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xf0ebdd), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lesson_branch_3_2_pic_0
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_branch_3_2_pic_0 = obj;
                    lv_obj_set_pos(obj, 151, 201);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // lesson_branch_3_2_pic_1
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_branch_3_2_pic_1 = obj;
                    lv_obj_set_pos(obj, 430, 315);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
            }
        }
        {
            // lesson_branch_3_3
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.lesson_branch_3_3 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 1024, 600);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfaf7ef), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lesson_branch_3_3_card_0
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.lesson_branch_3_3_card_0 = obj;
                    lv_obj_set_pos(obj, 62, 116);
                    lv_obj_set_size(obj, 900, 430);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xf0ebdd), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // lesson_branch_3_3_pic_0
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_branch_3_3_pic_0 = obj;
                    lv_obj_set_pos(obj, 256, 174);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // lesson_branch_3_3_pic_1
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.lesson_branch_3_3_pic_1 = obj;
                    lv_obj_set_pos(obj, 430, 315);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
            }
        }
        {
            // level1_next
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.level1_next = obj;
            lv_obj_set_pos(obj, 842, 486);
            lv_obj_set_size(obj, 150, 100);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_complete_level_button(obj, getFlowState(flowState, 104), 101);
        }
        {
            // NavBarLevel
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.nav_bar_level = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 1024, 66);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_nav_bar(obj, getFlowState(flowState, 105), 104);
        }
        {
            // lesson_keep_up
            lv_obj_t *obj = lv_image_create(parent_obj);
            objects.lesson_keep_up = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
        }
    }
    
    tick_screen_level1();
}

void delete_screen_level1() {
    lv_obj_delete(objects.level1);
    objects.level1 = 0;
    objects.obj10 = 0;
    objects.obj8 = 0;
    objects.obj9 = 0;
    objects.lesson_step_0 = 0;
    objects.lesson_step_0_card_0 = 0;
    objects.lesson_step_0_pic_0 = 0;
    objects.lesson_step_0_pic_1 = 0;
    objects.lesson_step_1 = 0;
    objects.lesson_step_1_card_0 = 0;
    objects.lesson_step_1_pic_0 = 0;
    objects.lesson_step_1_pic_1 = 0;
    objects.lesson_step_1_pic_2 = 0;
    objects.lesson_step_1_pic_3 = 0;
    objects.lesson_step_1_pic_4 = 0;
    objects.lesson_step_1_pic_5 = 0;
    objects.lesson_q1_house = 0;
    objects.lesson_q1_lamp = 0;
    objects.lesson_q1_sun = 0;
    objects.lesson_step_2 = 0;
    objects.lesson_step_2_card_0 = 0;
    objects.lesson_step_2_pic_0 = 0;
    objects.lesson_step_2_pic_1 = 0;
    objects.lesson_step_2_pic_2 = 0;
    objects.lesson_step_2_pic_3 = 0;
    objects.lesson_step_2_pic_4 = 0;
    objects.lesson_step_3 = 0;
    objects.lesson_step_3_card_0 = 0;
    objects.lesson_step_3_pic_0 = 0;
    objects.lesson_step_3_pic_1 = 0;
    objects.lesson_step_4 = 0;
    objects.lesson_step_4_card_0 = 0;
    objects.lesson_step_4_pic_0 = 0;
    objects.lesson_step_4_pic_1 = 0;
    objects.lesson_step_5 = 0;
    objects.lesson_step_5_card_0 = 0;
    objects.lesson_step_5_pic_0 = 0;
    objects.lesson_step_5_pic_1 = 0;
    objects.lesson_step_6 = 0;
    objects.lesson_step_6_card_0 = 0;
    objects.lesson_step_6_pic_0 = 0;
    objects.lesson_step_6_pic_1 = 0;
    objects.lesson_step_6_pic_2 = 0;
    objects.lesson_step_6_pic_3 = 0;
    objects.lesson_step_6_pic_4 = 0;
    objects.lesson_step_6_pic_5 = 0;
    objects.lesson_q2_house = 0;
    objects.lesson_q2_battery = 0;
    objects.lesson_q2_lamp = 0;
    objects.lesson_step_7 = 0;
    objects.lesson_step_7_card_0 = 0;
    objects.lesson_step_7_pic_0 = 0;
    objects.lesson_step_7_pic_1 = 0;
    objects.lesson_step_7_pic_2 = 0;
    objects.lesson_step_7_pic_3 = 0;
    objects.lesson_step_7_pic_4 = 0;
    objects.lesson_branch_1_0 = 0;
    objects.lesson_branch_1_0_card_0 = 0;
    objects.lesson_branch_1_0_pic_0 = 0;
    objects.lesson_branch_1_0_pic_1 = 0;
    objects.lesson_branch_1_1 = 0;
    objects.lesson_branch_1_1_card_0 = 0;
    objects.lesson_branch_1_1_pic_0 = 0;
    objects.lesson_branch_1_1_pic_1 = 0;
    objects.lesson_branch_1_2 = 0;
    objects.lesson_branch_1_2_card_0 = 0;
    objects.lesson_branch_1_2_pic_0 = 0;
    objects.lesson_branch_1_2_pic_1 = 0;
    objects.lesson_branch_1_3 = 0;
    objects.lesson_branch_1_3_card_0 = 0;
    objects.lesson_branch_1_3_pic_0 = 0;
    objects.lesson_branch_1_3_pic_1 = 0;
    objects.lesson_branch_2_0 = 0;
    objects.lesson_branch_2_0_card_0 = 0;
    objects.lesson_branch_2_0_pic_0 = 0;
    objects.lesson_branch_2_0_pic_1 = 0;
    objects.lesson_branch_2_1 = 0;
    objects.lesson_branch_2_1_card_0 = 0;
    objects.lesson_branch_2_1_pic_0 = 0;
    objects.lesson_branch_2_1_pic_1 = 0;
    objects.lesson_branch_2_2 = 0;
    objects.lesson_branch_2_2_card_0 = 0;
    objects.lesson_branch_2_2_pic_0 = 0;
    objects.lesson_branch_2_2_pic_1 = 0;
    objects.lesson_branch_2_3 = 0;
    objects.lesson_branch_2_3_card_0 = 0;
    objects.lesson_branch_2_3_pic_0 = 0;
    objects.lesson_branch_2_3_pic_1 = 0;
    objects.lesson_branch_3_0 = 0;
    objects.lesson_branch_3_0_card_0 = 0;
    objects.lesson_branch_3_0_pic_0 = 0;
    objects.lesson_branch_3_0_pic_1 = 0;
    objects.lesson_branch_3_1 = 0;
    objects.lesson_branch_3_1_card_0 = 0;
    objects.lesson_branch_3_1_pic_0 = 0;
    objects.lesson_branch_3_1_pic_1 = 0;
    objects.lesson_branch_3_2 = 0;
    objects.lesson_branch_3_2_card_0 = 0;
    objects.lesson_branch_3_2_pic_0 = 0;
    objects.lesson_branch_3_2_pic_1 = 0;
    objects.lesson_branch_3_3 = 0;
    objects.lesson_branch_3_3_card_0 = 0;
    objects.lesson_branch_3_3_pic_0 = 0;
    objects.lesson_branch_3_3_pic_1 = 0;
    objects.level1_next = 0;
    objects.nav_bar_level = 0;
    objects.lesson_keep_up = 0;
    deletePageFlowState(5);
}

void tick_screen_level1() {
    void *flowState = getFlowState(0, 5);
    (void)flowState;
    {
        bool new_val = evalBooleanProperty(flowState, 0, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj10, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj10;
            if (new_val) {
                lv_obj_add_flag(objects.obj10, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.obj10, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 2, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj8, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj8;
            if (new_val) {
                lv_obj_add_flag(objects.obj8, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.obj8, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 3, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.obj9, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.obj9;
            if (new_val) {
                lv_obj_add_flag(objects.obj9, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.obj9, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 4, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.lesson_step_0, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.lesson_step_0;
            if (new_val) {
                lv_obj_add_flag(objects.lesson_step_0, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.lesson_step_0, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 8, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.lesson_step_1, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.lesson_step_1;
            if (new_val) {
                lv_obj_add_flag(objects.lesson_step_1, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.lesson_step_1, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 19, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.lesson_step_2, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.lesson_step_2;
            if (new_val) {
                lv_obj_add_flag(objects.lesson_step_2, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.lesson_step_2, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 26, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.lesson_step_3, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.lesson_step_3;
            if (new_val) {
                lv_obj_add_flag(objects.lesson_step_3, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.lesson_step_3, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 30, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.lesson_step_4, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.lesson_step_4;
            if (new_val) {
                lv_obj_add_flag(objects.lesson_step_4, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.lesson_step_4, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 34, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.lesson_step_5, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.lesson_step_5;
            if (new_val) {
                lv_obj_add_flag(objects.lesson_step_5, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.lesson_step_5, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 38, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.lesson_step_6, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.lesson_step_6;
            if (new_val) {
                lv_obj_add_flag(objects.lesson_step_6, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.lesson_step_6, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 49, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.lesson_step_7, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.lesson_step_7;
            if (new_val) {
                lv_obj_add_flag(objects.lesson_step_7, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.lesson_step_7, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 56, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.lesson_branch_1_0, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.lesson_branch_1_0;
            if (new_val) {
                lv_obj_add_flag(objects.lesson_branch_1_0, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.lesson_branch_1_0, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 60, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.lesson_branch_1_1, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.lesson_branch_1_1;
            if (new_val) {
                lv_obj_add_flag(objects.lesson_branch_1_1, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.lesson_branch_1_1, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 64, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.lesson_branch_1_2, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.lesson_branch_1_2;
            if (new_val) {
                lv_obj_add_flag(objects.lesson_branch_1_2, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.lesson_branch_1_2, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 68, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.lesson_branch_1_3, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.lesson_branch_1_3;
            if (new_val) {
                lv_obj_add_flag(objects.lesson_branch_1_3, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.lesson_branch_1_3, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 72, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.lesson_branch_2_0, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.lesson_branch_2_0;
            if (new_val) {
                lv_obj_add_flag(objects.lesson_branch_2_0, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.lesson_branch_2_0, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 76, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.lesson_branch_2_1, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.lesson_branch_2_1;
            if (new_val) {
                lv_obj_add_flag(objects.lesson_branch_2_1, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.lesson_branch_2_1, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 80, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.lesson_branch_2_2, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.lesson_branch_2_2;
            if (new_val) {
                lv_obj_add_flag(objects.lesson_branch_2_2, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.lesson_branch_2_2, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 84, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.lesson_branch_2_3, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.lesson_branch_2_3;
            if (new_val) {
                lv_obj_add_flag(objects.lesson_branch_2_3, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.lesson_branch_2_3, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 88, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.lesson_branch_3_0, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.lesson_branch_3_0;
            if (new_val) {
                lv_obj_add_flag(objects.lesson_branch_3_0, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.lesson_branch_3_0, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 92, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.lesson_branch_3_1, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.lesson_branch_3_1;
            if (new_val) {
                lv_obj_add_flag(objects.lesson_branch_3_1, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.lesson_branch_3_1, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 96, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.lesson_branch_3_2, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.lesson_branch_3_2;
            if (new_val) {
                lv_obj_add_flag(objects.lesson_branch_3_2, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.lesson_branch_3_2, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 100, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.lesson_branch_3_3, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.lesson_branch_3_3;
            if (new_val) {
                lv_obj_add_flag(objects.lesson_branch_3_3, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.lesson_branch_3_3, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    tick_user_widget_complete_level_button(getFlowState(flowState, 104), 101);
    tick_user_widget_nav_bar(getFlowState(flowState, 105), 104);
}

void create_screen_level2() {
    void *flowState = getFlowState(0, 6);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.level2 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 1024, 600);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj0 = obj;
            lv_obj_set_pos(obj, 874, 500);
            lv_obj_set_size(obj, 150, 100);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_complete_level_button(obj, getFlowState(flowState, 0), 117);
        }
    }
    
    tick_screen_level2();
}

void delete_screen_level2() {
    lv_obj_delete(objects.level2);
    objects.level2 = 0;
    objects.obj0 = 0;
    deletePageFlowState(6);
}

void tick_screen_level2() {
    void *flowState = getFlowState(0, 6);
    (void)flowState;
    tick_user_widget_complete_level_button(getFlowState(flowState, 0), 117);
}

void create_screen_testing_sensors() {
    void *flowState = getFlowState(0, 7);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.testing_sensors = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 1024, 600);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            lv_obj_set_pos(obj, 229, 201);
            lv_obj_set_size(obj, 100, 50);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "solar panel");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 170, 151);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text_static(obj, "click here to see how much the \nsolar panel is producing right now!");
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            lv_obj_set_pos(obj, 645, 201);
            lv_obj_set_size(obj, 100, 50);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "solar panel");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 586, 151);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text_static(obj, "click here to see how much the \nsolar panel is producing right now!");
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj1 = obj;
            lv_obj_set_pos(obj, 735, 446);
            lv_obj_set_size(obj, 150, 100);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_complete_level_button(obj, getFlowState(flowState, 7), 120);
        }
    }
    
    tick_screen_testing_sensors();
}

void delete_screen_testing_sensors() {
    lv_obj_delete(objects.testing_sensors);
    objects.testing_sensors = 0;
    objects.obj1 = 0;
    deletePageFlowState(7);
}

void tick_screen_testing_sensors() {
    void *flowState = getFlowState(0, 7);
    (void)flowState;
    tick_user_widget_complete_level_button(getFlowState(flowState, 7), 120);
}

void create_screen_profile_page() {
    void *flowState = getFlowState(0, 8);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.profile_page = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 1024, 600);
    {
        lv_obj_t *parent_obj = obj;
        {
            // profile-background
            lv_obj_t *obj = lv_image_create(parent_obj);
            objects.profile_background = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
        }
        {
            // NavBarProfile
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.nav_bar_profile = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 1024, 66);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_nav_bar(obj, getFlowState(flowState, 2), 123);
        }
        {
            // shop-button
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.shop_button = obj;
            lv_obj_set_pos(obj, 684, 100);
            lv_obj_set_size(obj, 81, 40);
            lv_obj_add_event_cb(obj, event_handler_cb_profile_page_shop_button, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
            lv_obj_set_style_bg_opa(obj, 50, LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
        }
        {
            // user-selection
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.user_selection = obj;
            lv_obj_set_pos(obj, 797, 100);
            lv_obj_set_size(obj, 130, 40);
            lv_obj_add_event_cb(obj, event_handler_cb_profile_page_user_selection, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
            lv_obj_set_style_bg_opa(obj, 50, LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
        }
        {
            // profile_name
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.profile_name = obj;
            lv_obj_set_pos(obj, 97, 100);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x18352a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text_static(obj, "");
        }
        {
            // profile_figure
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.profile_figure = obj;
            lv_obj_set_pos(obj, 165, 238);
            lv_obj_set_size(obj, 200, 300);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // outfit_item_1
            lv_obj_t *obj = lv_image_create(parent_obj);
            objects.outfit_item_1 = obj;
            lv_obj_set_pos(obj, 485, 458);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
        }
        {
            // outfit_item_2
            lv_obj_t *obj = lv_image_create(parent_obj);
            objects.outfit_item_2 = obj;
            lv_obj_set_pos(obj, 557, 458);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
        }
        {
            // outfit_item_3
            lv_obj_t *obj = lv_image_create(parent_obj);
            objects.outfit_item_3 = obj;
            lv_obj_set_pos(obj, 629, 458);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
        }
        {
            // outfit_item_4
            lv_obj_t *obj = lv_image_create(parent_obj);
            objects.outfit_item_4 = obj;
            lv_obj_set_pos(obj, 701, 458);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
        }
        {
            // outfit_item_5
            lv_obj_t *obj = lv_image_create(parent_obj);
            objects.outfit_item_5 = obj;
            lv_obj_set_pos(obj, 773, 458);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
        }
        {
            // outfit_item_6
            lv_obj_t *obj = lv_image_create(parent_obj);
            objects.outfit_item_6 = obj;
            lv_obj_set_pos(obj, 845, 458);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
        }
        {
            // outfit_label_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.outfit_label_1 = obj;
            lv_obj_set_pos(obj, 475, 528);
            lv_obj_set_size(obj, 72, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x68736c), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Hat");
        }
        {
            // outfit_label_2
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.outfit_label_2 = obj;
            lv_obj_set_pos(obj, 547, 528);
            lv_obj_set_size(obj, 72, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x68736c), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Necklace");
        }
        {
            // outfit_label_3
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.outfit_label_3 = obj;
            lv_obj_set_pos(obj, 619, 528);
            lv_obj_set_size(obj, 72, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x68736c), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Bag");
        }
        {
            // outfit_label_4
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.outfit_label_4 = obj;
            lv_obj_set_pos(obj, 691, 528);
            lv_obj_set_size(obj, 72, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x68736c), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Shirt");
        }
        {
            // outfit_label_5
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.outfit_label_5 = obj;
            lv_obj_set_pos(obj, 763, 528);
            lv_obj_set_size(obj, 72, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x68736c), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Scarf");
        }
        {
            // outfit_label_6
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.outfit_label_6 = obj;
            lv_obj_set_pos(obj, 835, 528);
            lv_obj_set_size(obj, 72, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0x68736c), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Shoes");
        }
    }
    
    tick_screen_profile_page();
}

void delete_screen_profile_page() {
    lv_obj_delete(objects.profile_page);
    objects.profile_page = 0;
    objects.profile_background = 0;
    objects.nav_bar_profile = 0;
    objects.shop_button = 0;
    objects.user_selection = 0;
    objects.profile_name = 0;
    objects.profile_figure = 0;
    objects.outfit_item_1 = 0;
    objects.outfit_item_2 = 0;
    objects.outfit_item_3 = 0;
    objects.outfit_item_4 = 0;
    objects.outfit_item_5 = 0;
    objects.outfit_item_6 = 0;
    objects.outfit_label_1 = 0;
    objects.outfit_label_2 = 0;
    objects.outfit_label_3 = 0;
    objects.outfit_label_4 = 0;
    objects.outfit_label_5 = 0;
    objects.outfit_label_6 = 0;
    deletePageFlowState(8);
}

void tick_screen_profile_page() {
    void *flowState = getFlowState(0, 8);
    (void)flowState;
    tick_user_widget_nav_bar(getFlowState(flowState, 2), 123);
}

void create_screen_shop_page() {
    void *flowState = getFlowState(0, 9);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.shop_page = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 1024, 600);
    {
        lv_obj_t *parent_obj = obj;
        {
            // shop-background
            lv_obj_t *obj = lv_image_create(parent_obj);
            objects.shop_background = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
        }
        {
            // NavBarShop
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.nav_bar_shop = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 1024, 66);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_nav_bar(obj, getFlowState(flowState, 2), 136);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 374, 154);
            lv_obj_set_size(obj, 558, 437);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // shop_item_1
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.shop_item_1 = obj;
                    lv_obj_set_pos(obj, -5, -3);
                    lv_obj_set_size(obj, 140, 140);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    create_user_widget_shop_item(obj, getFlowState(flowState, 4), 149);
                }
                {
                    // shop_item_2
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.shop_item_2 = obj;
                    lv_obj_set_pos(obj, 131, -3);
                    lv_obj_set_size(obj, 140, 140);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    create_user_widget_shop_item(obj, getFlowState(flowState, 5), 153);
                }
                {
                    // shop_item_3
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.shop_item_3 = obj;
                    lv_obj_set_pos(obj, 267, -3);
                    lv_obj_set_size(obj, 140, 140);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    create_user_widget_shop_item(obj, getFlowState(flowState, 6), 157);
                }
                {
                    // shop_item_4
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.shop_item_4 = obj;
                    lv_obj_set_pos(obj, 403, -3);
                    lv_obj_set_size(obj, 140, 140);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    create_user_widget_shop_item(obj, getFlowState(flowState, 7), 161);
                }
                {
                    // shop_item_5
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.shop_item_5 = obj;
                    lv_obj_set_pos(obj, -5, 138);
                    lv_obj_set_size(obj, 140, 140);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    create_user_widget_shop_item(obj, getFlowState(flowState, 8), 165);
                }
                {
                    // shop_item_6
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.shop_item_6 = obj;
                    lv_obj_set_pos(obj, 131, 138);
                    lv_obj_set_size(obj, 140, 140);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    create_user_widget_shop_item(obj, getFlowState(flowState, 9), 169);
                }
                {
                    // shop_item_7
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.shop_item_7 = obj;
                    lv_obj_set_pos(obj, 267, 138);
                    lv_obj_set_size(obj, 140, 140);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    create_user_widget_shop_item(obj, getFlowState(flowState, 10), 173);
                }
                {
                    // shop_item_8
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.shop_item_8 = obj;
                    lv_obj_set_pos(obj, 403, 138);
                    lv_obj_set_size(obj, 140, 140);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    create_user_widget_shop_item(obj, getFlowState(flowState, 11), 177);
                }
                {
                    // shop_item_9
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.shop_item_9 = obj;
                    lv_obj_set_pos(obj, -5, 279);
                    lv_obj_set_size(obj, 140, 140);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    create_user_widget_shop_item(obj, getFlowState(flowState, 12), 181);
                }
                {
                    // shop_item_10
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.shop_item_10 = obj;
                    lv_obj_set_pos(obj, 131, 279);
                    lv_obj_set_size(obj, 140, 140);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    create_user_widget_shop_item(obj, getFlowState(flowState, 13), 185);
                }
                {
                    // shop_item_11
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.shop_item_11 = obj;
                    lv_obj_set_pos(obj, 267, 279);
                    lv_obj_set_size(obj, 140, 140);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    create_user_widget_shop_item(obj, getFlowState(flowState, 14), 189);
                }
                {
                    // shop_item_12
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.shop_item_12 = obj;
                    lv_obj_set_pos(obj, 403, 279);
                    lv_obj_set_size(obj, 140, 140);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    create_user_widget_shop_item(obj, getFlowState(flowState, 15), 193);
                }
            }
        }
        {
            // shop_figure
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.shop_figure = obj;
            lv_obj_set_pos(obj, 137, 240);
            lv_obj_set_size(obj, 200, 300);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // shop_overlay
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.shop_overlay = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 1024, 600);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // overlay-buy-wear
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.overlay_buy_wear = obj;
                    lv_obj_set_pos(obj, 230, 18);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // overlay_item
                    lv_obj_t *obj = lv_image_create(parent_obj);
                    objects.overlay_item = obj;
                    lv_obj_set_pos(obj, 458, 175);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                }
                {
                    // overlay_action
                    lv_obj_t *obj = lv_button_create(parent_obj);
                    objects.overlay_action = obj;
                    lv_obj_set_pos(obj, 294, 338);
                    lv_obj_set_size(obj, 436, 72);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xe8efdf), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0x2f6b45), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xd6e3c9), LV_PART_MAIN | LV_STATE_PRESSED);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // overlay_action_icon
                            lv_obj_t *obj = lv_image_create(parent_obj);
                            objects.overlay_action_icon = obj;
                            lv_obj_set_pos(obj, 12, 12);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                        }
                        {
                            // overlay_action_title
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.overlay_action_title = obj;
                            lv_obj_set_pos(obj, 72, 12);
                            lv_obj_set_size(obj, 340, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0x18352a), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "");
                        }
                        {
                            // overlay_action_detail
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.overlay_action_detail = obj;
                            lv_obj_set_pos(obj, 72, 40);
                            lv_obj_set_size(obj, 340, LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0x68736c), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "");
                        }
                    }
                }
                {
                    // close_button
                    lv_obj_t *obj = lv_button_create(parent_obj);
                    objects.close_button = obj;
                    lv_obj_set_pos(obj, 690, 64);
                    lv_obj_set_size(obj, 48, 48);
                    lv_obj_add_event_cb(obj, event_handler_cb_shop_page_close_button, LV_EVENT_ALL, flowState);
                    lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_PRESSED);
                    lv_obj_set_style_bg_opa(obj, 50, LV_PART_MAIN | LV_STATE_PRESSED);
                }
                {
                    // overlay_balance
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.overlay_balance = obj;
                    lv_obj_set_pos(obj, 334, 458);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x18352a), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
                {
                    // overlay_price
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.overlay_price = obj;
                    lv_obj_set_pos(obj, 634, 456);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0x18352a), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
    }
    
    tick_screen_shop_page();
}

void delete_screen_shop_page() {
    lv_obj_delete(objects.shop_page);
    objects.shop_page = 0;
    objects.shop_background = 0;
    objects.nav_bar_shop = 0;
    objects.shop_item_1 = 0;
    objects.shop_item_2 = 0;
    objects.shop_item_3 = 0;
    objects.shop_item_4 = 0;
    objects.shop_item_5 = 0;
    objects.shop_item_6 = 0;
    objects.shop_item_7 = 0;
    objects.shop_item_8 = 0;
    objects.shop_item_9 = 0;
    objects.shop_item_10 = 0;
    objects.shop_item_11 = 0;
    objects.shop_item_12 = 0;
    objects.shop_figure = 0;
    objects.shop_overlay = 0;
    objects.overlay_buy_wear = 0;
    objects.overlay_item = 0;
    objects.overlay_action = 0;
    objects.overlay_action_icon = 0;
    objects.overlay_action_title = 0;
    objects.overlay_action_detail = 0;
    objects.close_button = 0;
    objects.overlay_balance = 0;
    objects.overlay_price = 0;
    deletePageFlowState(9);
}

void tick_screen_shop_page() {
    void *flowState = getFlowState(0, 9);
    (void)flowState;
    tick_user_widget_nav_bar(getFlowState(flowState, 2), 136);
    tick_user_widget_shop_item(getFlowState(flowState, 4), 149);
    tick_user_widget_shop_item(getFlowState(flowState, 5), 153);
    tick_user_widget_shop_item(getFlowState(flowState, 6), 157);
    tick_user_widget_shop_item(getFlowState(flowState, 7), 161);
    tick_user_widget_shop_item(getFlowState(flowState, 8), 165);
    tick_user_widget_shop_item(getFlowState(flowState, 9), 169);
    tick_user_widget_shop_item(getFlowState(flowState, 10), 173);
    tick_user_widget_shop_item(getFlowState(flowState, 11), 177);
    tick_user_widget_shop_item(getFlowState(flowState, 12), 181);
    tick_user_widget_shop_item(getFlowState(flowState, 13), 185);
    tick_user_widget_shop_item(getFlowState(flowState, 14), 189);
    tick_user_widget_shop_item(getFlowState(flowState, 15), 193);
    {
        bool new_val = evalBooleanProperty(flowState, 17, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(objects.shop_overlay, LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = objects.shop_overlay;
            if (new_val) {
                lv_obj_add_flag(objects.shop_overlay, LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(objects.shop_overlay, LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 25, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.overlay_balance);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.overlay_balance;
            lv_label_set_text(objects.overlay_balance, new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 26, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.overlay_price);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.overlay_price;
            lv_label_set_text(objects.overlay_price, new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_user_widget_nav_bar(lv_obj_t *parent_obj, void *flowState, int startWidgetIndex) {
    (void)flowState;
    (void)startWidgetIndex;
    lv_obj_t *obj = parent_obj;
    {
        lv_obj_t *parent_obj = obj;
        {
            // nav-bar
            lv_obj_t *obj = lv_image_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 0] = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 1024, 66);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // back-button
                    lv_obj_t *obj = lv_button_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 1] = obj;
                    lv_obj_set_pos(obj, 48, 13);
                    lv_obj_set_size(obj, 75, 40);
                    lv_obj_add_event_cb(obj, event_handler_cb_nav_bar_back_button, LV_EVENT_ALL, flowState);
                    lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_PRESSED);
                    lv_obj_set_style_bg_opa(obj, 50, LV_PART_MAIN | LV_STATE_PRESSED);
                }
                {
                    // battery-button
                    lv_obj_t *obj = lv_button_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 2] = obj;
                    lv_obj_set_pos(obj, 670, 13);
                    lv_obj_set_size(obj, 80, 40);
                    lv_obj_add_event_cb(obj, event_handler_cb_nav_bar_battery_button, LV_EVENT_ALL, flowState);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xe8efdf), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 50, LV_PART_MAIN | LV_STATE_PRESSED);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_PRESSED);
                }
                {
                    // help-button
                    lv_obj_t *obj = lv_button_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 3] = obj;
                    lv_obj_set_pos(obj, 762, 13);
                    lv_obj_set_size(obj, 105, 40);
                    lv_obj_add_event_cb(obj, event_handler_cb_nav_bar_help_button, LV_EVENT_ALL, flowState);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xe8efdf), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_PRESSED);
                    lv_obj_set_style_bg_opa(obj, 50, LV_PART_MAIN | LV_STATE_PRESSED);
                }
                {
                    // avatar-button
                    lv_obj_t *obj = lv_button_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 4] = obj;
                    lv_obj_set_pos(obj, 879, 9);
                    lv_obj_set_size(obj, 48, 48);
                    lv_obj_add_event_cb(obj, event_handler_cb_nav_bar_avatar_button, LV_EVENT_ALL, flowState);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0x9e9e9e), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_PRESSED);
                    lv_obj_set_style_bg_opa(obj, 50, LV_PART_MAIN | LV_STATE_PRESSED);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // avatar-image
                            lv_obj_t *obj = lv_image_create(parent_obj);
                            ((lv_obj_t **)&objects)[startWidgetIndex + 5] = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                        }
                    }
                }
                {
                    // coins-button
                    lv_obj_t *obj = lv_button_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 6] = obj;
                    lv_obj_set_pos(obj, 939, 13);
                    lv_obj_set_size(obj, 55, 40);
                    lv_obj_add_event_cb(obj, event_handler_cb_nav_bar_coins_button, LV_EVENT_ALL, flowState);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0x9e9e9e), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_PRESSED);
                    lv_obj_set_style_bg_opa(obj, 50, LV_PART_MAIN | LV_STATE_PRESSED);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            ((lv_obj_t **)&objects)[startWidgetIndex + 7] = obj;
                            lv_obj_set_pos(obj, 29, 12);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0x18352a), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "");
                        }
                    }
                }
                {
                    // battery-button-no-coins
                    lv_obj_t *obj = lv_button_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 8] = obj;
                    lv_obj_set_pos(obj, 727, 13);
                    lv_obj_set_size(obj, 80, 40);
                    lv_obj_add_event_cb(obj, event_handler_cb_nav_bar_battery_button_no_coins, LV_EVENT_ALL, flowState);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xe8efdf), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 50, LV_PART_MAIN | LV_STATE_PRESSED);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_PRESSED);
                }
                {
                    // help-button-no-coins
                    lv_obj_t *obj = lv_button_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 9] = obj;
                    lv_obj_set_pos(obj, 825, 13);
                    lv_obj_set_size(obj, 105, 40);
                    lv_obj_add_event_cb(obj, event_handler_cb_nav_bar_help_button_no_coins, LV_EVENT_ALL, flowState);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xe8efdf), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_PRESSED);
                    lv_obj_set_style_bg_opa(obj, 50, LV_PART_MAIN | LV_STATE_PRESSED);
                }
                {
                    // avatar-button-no-coins
                    lv_obj_t *obj = lv_button_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 10] = obj;
                    lv_obj_set_pos(obj, 948, 9);
                    lv_obj_set_size(obj, 48, 48);
                    lv_obj_add_event_cb(obj, event_handler_cb_nav_bar_avatar_button_no_coins, LV_EVENT_ALL, flowState);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0x9e9e9e), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_PRESSED);
                    lv_obj_set_style_bg_opa(obj, 50, LV_PART_MAIN | LV_STATE_PRESSED);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // avatar-image-no-coins
                            lv_obj_t *obj = lv_image_create(parent_obj);
                            ((lv_obj_t **)&objects)[startWidgetIndex + 11] = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                        }
                    }
                }
            }
        }
    }
}

void tick_user_widget_nav_bar(void *flowState, int startWidgetIndex) {
    (void)flowState;
    (void)startWidgetIndex;
    {
        bool new_val = evalBooleanProperty(flowState, 3, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(((lv_obj_t **)&objects)[startWidgetIndex + 2], LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = ((lv_obj_t **)&objects)[startWidgetIndex + 2];
            if (new_val) {
                lv_obj_add_flag(((lv_obj_t **)&objects)[startWidgetIndex + 2], LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(((lv_obj_t **)&objects)[startWidgetIndex + 2], LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 4, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(((lv_obj_t **)&objects)[startWidgetIndex + 3], LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = ((lv_obj_t **)&objects)[startWidgetIndex + 3];
            if (new_val) {
                lv_obj_add_flag(((lv_obj_t **)&objects)[startWidgetIndex + 3], LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(((lv_obj_t **)&objects)[startWidgetIndex + 3], LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 5, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(((lv_obj_t **)&objects)[startWidgetIndex + 4], LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = ((lv_obj_t **)&objects)[startWidgetIndex + 4];
            if (new_val) {
                lv_obj_add_flag(((lv_obj_t **)&objects)[startWidgetIndex + 4], LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(((lv_obj_t **)&objects)[startWidgetIndex + 4], LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 7, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(((lv_obj_t **)&objects)[startWidgetIndex + 6], LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = ((lv_obj_t **)&objects)[startWidgetIndex + 6];
            if (new_val) {
                lv_obj_add_flag(((lv_obj_t **)&objects)[startWidgetIndex + 6], LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(((lv_obj_t **)&objects)[startWidgetIndex + 6], LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 8, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(((lv_obj_t **)&objects)[startWidgetIndex + 7]);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = ((lv_obj_t **)&objects)[startWidgetIndex + 7];
            lv_label_set_text(((lv_obj_t **)&objects)[startWidgetIndex + 7], new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 9, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(((lv_obj_t **)&objects)[startWidgetIndex + 8], LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = ((lv_obj_t **)&objects)[startWidgetIndex + 8];
            if (new_val) {
                lv_obj_add_flag(((lv_obj_t **)&objects)[startWidgetIndex + 8], LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(((lv_obj_t **)&objects)[startWidgetIndex + 8], LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 10, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(((lv_obj_t **)&objects)[startWidgetIndex + 9], LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = ((lv_obj_t **)&objects)[startWidgetIndex + 9];
            if (new_val) {
                lv_obj_add_flag(((lv_obj_t **)&objects)[startWidgetIndex + 9], LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(((lv_obj_t **)&objects)[startWidgetIndex + 9], LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 11, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(((lv_obj_t **)&objects)[startWidgetIndex + 10], LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = ((lv_obj_t **)&objects)[startWidgetIndex + 10];
            if (new_val) {
                lv_obj_add_flag(((lv_obj_t **)&objects)[startWidgetIndex + 10], LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(((lv_obj_t **)&objects)[startWidgetIndex + 10], LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
}

void create_user_widget_level_point(lv_obj_t *parent_obj, void *flowState, int startWidgetIndex) {
    (void)flowState;
    (void)startWidgetIndex;
    lv_obj_t *obj = parent_obj;
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 0] = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 100, 100);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_add_event_cb(obj, event_handler_cb_level_point_obj1, LV_EVENT_ALL, flowState);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // level
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 1] = obj;
                    lv_obj_set_pos(obj, 2, 2);
                    lv_obj_set_size(obj, 96, 96);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_add_event_cb(obj, event_handler_cb_level_point_level, LV_EVENT_ALL, flowState);
                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // level-image
                            lv_obj_t *obj = lv_image_create(parent_obj);
                            ((lv_obj_t **)&objects)[startWidgetIndex + 2] = obj;
                            lv_obj_set_pos(obj, 8, 46);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                        }
                    }
                }
                {
                    // level_done
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 3] = obj;
                    lv_obj_set_pos(obj, 2, 2);
                    lv_obj_set_size(obj, 96, 96);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_add_event_cb(obj, event_handler_cb_level_point_level_done, LV_EVENT_ALL, flowState);
                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // level-done-image
                            lv_obj_t *obj = lv_image_create(parent_obj);
                            ((lv_obj_t **)&objects)[startWidgetIndex + 4] = obj;
                            lv_obj_set_pos(obj, 8, 4);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                        }
                    }
                }
                {
                    // level_ongoing
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 5] = obj;
                    lv_obj_set_pos(obj, 2, 2);
                    lv_obj_set_size(obj, 96, 96);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_add_event_cb(obj, event_handler_cb_level_point_level_ongoing, LV_EVENT_ALL, flowState);
                    lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // level-ongoing-image
                            lv_obj_t *obj = lv_image_create(parent_obj);
                            ((lv_obj_t **)&objects)[startWidgetIndex + 6] = obj;
                            lv_obj_set_pos(obj, 8, 4);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                        }
                    }
                }
            }
        }
    }
}

void tick_user_widget_level_point(void *flowState, int startWidgetIndex) {
    (void)flowState;
    (void)startWidgetIndex;
    {
        bool new_val = evalBooleanProperty(flowState, 1, 3, "Failed to evaluate Clickable flag");
        bool cur_val = lv_obj_has_flag(((lv_obj_t **)&objects)[startWidgetIndex + 0], LV_OBJ_FLAG_CLICKABLE);
        if (new_val != cur_val) {
            tick_value_change_obj = ((lv_obj_t **)&objects)[startWidgetIndex + 0];
            if (new_val) {
                lv_obj_add_flag(((lv_obj_t **)&objects)[startWidgetIndex + 0], LV_OBJ_FLAG_CLICKABLE);
            } else {
                lv_obj_remove_flag(((lv_obj_t **)&objects)[startWidgetIndex + 0], LV_OBJ_FLAG_CLICKABLE);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 3, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(((lv_obj_t **)&objects)[startWidgetIndex + 3], LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = ((lv_obj_t **)&objects)[startWidgetIndex + 3];
            if (new_val) {
                lv_obj_add_flag(((lv_obj_t **)&objects)[startWidgetIndex + 3], LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(((lv_obj_t **)&objects)[startWidgetIndex + 3], LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
    {
        bool new_val = evalBooleanProperty(flowState, 5, 3, "Failed to evaluate Hidden flag");
        bool cur_val = lv_obj_has_flag(((lv_obj_t **)&objects)[startWidgetIndex + 5], LV_OBJ_FLAG_HIDDEN);
        if (new_val != cur_val) {
            tick_value_change_obj = ((lv_obj_t **)&objects)[startWidgetIndex + 5];
            if (new_val) {
                lv_obj_add_flag(((lv_obj_t **)&objects)[startWidgetIndex + 5], LV_OBJ_FLAG_HIDDEN);
            } else {
                lv_obj_remove_flag(((lv_obj_t **)&objects)[startWidgetIndex + 5], LV_OBJ_FLAG_HIDDEN);
            }
            tick_value_change_obj = NULL;
        }
    }
}

void create_user_widget_complete_level_button(lv_obj_t *parent_obj, void *flowState, int startWidgetIndex) {
    (void)flowState;
    (void)startWidgetIndex;
    lv_obj_t *obj = parent_obj;
    {
        lv_obj_t *parent_obj = obj;
        {
            // lvl1_complete_level_button
            lv_obj_t *obj = lv_button_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 0] = obj;
            lv_obj_set_pos(obj, 0, 25);
            lv_obj_set_size(obj, 150, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_complete_level_button_lvl1_complete_level_button, LV_EVENT_ALL, flowState);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x2f6b45), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 1] = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
    }
}

void tick_user_widget_complete_level_button(void *flowState, int startWidgetIndex) {
    (void)flowState;
    (void)startWidgetIndex;
    {
        const char *new_val = evalTextProperty(flowState, 0, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(((lv_obj_t **)&objects)[startWidgetIndex + 1]);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = ((lv_obj_t **)&objects)[startWidgetIndex + 1];
            lv_label_set_text(((lv_obj_t **)&objects)[startWidgetIndex + 1], new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void create_user_widget_shop_item(lv_obj_t *parent_obj, void *flowState, int startWidgetIndex) {
    (void)flowState;
    (void)startWidgetIndex;
    lv_obj_t *obj = parent_obj;
    {
        lv_obj_t *parent_obj = obj;
        {
            // card
            lv_obj_t *obj = lv_obj_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 0] = obj;
            lv_obj_set_pos(obj, 8, 7);
            lv_obj_set_size(obj, 124, 126);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_add_event_cb(obj, event_handler_cb_shop_item_card, LV_EVENT_ALL, flowState);
            lv_obj_set_style_radius(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_opa(obj, 50, LV_PART_MAIN | LV_STATE_PRESSED);
        }
        {
            // owned_badge
            lv_obj_t *obj = lv_obj_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 1] = obj;
            lv_obj_set_pos(obj, 53, 96);
            lv_obj_set_size(obj, 72, 33);
            lv_obj_remove_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x2f6b45), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // owned_label
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 2] = obj;
                    lv_obj_set_pos(obj, 0, 8);
                    lv_obj_set_size(obj, 72, LV_SIZE_CONTENT);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfffdf7), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
    }
}

void tick_user_widget_shop_item(void *flowState, int startWidgetIndex) {
    (void)flowState;
    (void)startWidgetIndex;
}

typedef void (*create_screen_func_t)();
create_screen_func_t create_screen_funcs[] = {
    create_screen_home_page,
    create_screen_user_list_view,
    create_screen_user_creation,
    create_screen_chapters,
    create_screen_roadmap,
    create_screen_level1,
    create_screen_level2,
    create_screen_testing_sensors,
    create_screen_profile_page,
    create_screen_shop_page,
};
void create_screen(int screen_index) {
    create_screen_funcs[screen_index]();
}
void create_screen_by_id(enum ScreensEnum screenId) {
    create_screen_funcs[screenId - 1]();
}

typedef void (*delete_screen_func_t)();
delete_screen_func_t delete_screen_funcs[] = {
    delete_screen_home_page,
    delete_screen_user_list_view,
    delete_screen_user_creation,
    delete_screen_chapters,
    delete_screen_roadmap,
    delete_screen_level1,
    delete_screen_level2,
    delete_screen_testing_sensors,
    delete_screen_profile_page,
    delete_screen_shop_page,
};
void delete_screen(int screen_index) {
    delete_screen_funcs[screen_index]();
}
void delete_screen_by_id(enum ScreensEnum screenId) {
    delete_screen_funcs[screenId - 1]();
}

typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_home_page,
    tick_screen_user_list_view,
    tick_screen_user_creation,
    tick_screen_chapters,
    tick_screen_roadmap,
    tick_screen_level1,
    tick_screen_level2,
    tick_screen_testing_sensors,
    tick_screen_profile_page,
    tick_screen_shop_page,
};
void tick_screen(int screen_index) {
    if (screen_index >= 0 && screen_index < 10) {
        tick_screen_funcs[screen_index]();
    }
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen(screenId - 1);
}

//
// Fonts
//

ext_font_desc_t fonts[] = {
#if LV_FONT_MONTSERRAT_8
    { "MONTSERRAT_8", &lv_font_montserrat_8 },
#endif
#if LV_FONT_MONTSERRAT_10
    { "MONTSERRAT_10", &lv_font_montserrat_10 },
#endif
#if LV_FONT_MONTSERRAT_12
    { "MONTSERRAT_12", &lv_font_montserrat_12 },
#endif
#if LV_FONT_MONTSERRAT_14
    { "MONTSERRAT_14", &lv_font_montserrat_14 },
#endif
#if LV_FONT_MONTSERRAT_16
    { "MONTSERRAT_16", &lv_font_montserrat_16 },
#endif
#if LV_FONT_MONTSERRAT_18
    { "MONTSERRAT_18", &lv_font_montserrat_18 },
#endif
#if LV_FONT_MONTSERRAT_20
    { "MONTSERRAT_20", &lv_font_montserrat_20 },
#endif
#if LV_FONT_MONTSERRAT_22
    { "MONTSERRAT_22", &lv_font_montserrat_22 },
#endif
#if LV_FONT_MONTSERRAT_24
    { "MONTSERRAT_24", &lv_font_montserrat_24 },
#endif
#if LV_FONT_MONTSERRAT_26
    { "MONTSERRAT_26", &lv_font_montserrat_26 },
#endif
#if LV_FONT_MONTSERRAT_28
    { "MONTSERRAT_28", &lv_font_montserrat_28 },
#endif
#if LV_FONT_MONTSERRAT_30
    { "MONTSERRAT_30", &lv_font_montserrat_30 },
#endif
#if LV_FONT_MONTSERRAT_32
    { "MONTSERRAT_32", &lv_font_montserrat_32 },
#endif
#if LV_FONT_MONTSERRAT_34
    { "MONTSERRAT_34", &lv_font_montserrat_34 },
#endif
#if LV_FONT_MONTSERRAT_36
    { "MONTSERRAT_36", &lv_font_montserrat_36 },
#endif
#if LV_FONT_MONTSERRAT_38
    { "MONTSERRAT_38", &lv_font_montserrat_38 },
#endif
#if LV_FONT_MONTSERRAT_40
    { "MONTSERRAT_40", &lv_font_montserrat_40 },
#endif
#if LV_FONT_MONTSERRAT_42
    { "MONTSERRAT_42", &lv_font_montserrat_42 },
#endif
#if LV_FONT_MONTSERRAT_44
    { "MONTSERRAT_44", &lv_font_montserrat_44 },
#endif
#if LV_FONT_MONTSERRAT_46
    { "MONTSERRAT_46", &lv_font_montserrat_46 },
#endif
#if LV_FONT_MONTSERRAT_48
    { "MONTSERRAT_48", &lv_font_montserrat_48 },
#endif
};

//
//
//

void create_screens() {
    
    eez_flow_init_fonts(fonts, sizeof(fonts) / sizeof(ext_font_desc_t));

// Set default LVGL theme
    lv_display_t *dispp = lv_display_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_display_set_theme(dispp, theme);
    
    // Initialize screens
    eez_flow_init_screen_names(screen_names, sizeof(screen_names) / sizeof(const char *));
    eez_flow_init_object_names(object_names, sizeof(object_names) / sizeof(const char *));
    
    eez_flow_set_create_screen_func(create_screen);
    eez_flow_set_delete_screen_func(delete_screen);
    
    // Create screens
    create_screen_home_page();
    create_screen_user_list_view();
    create_screen_user_creation();
    create_screen_chapters();
    create_screen_roadmap();
    create_screen_level1();
    create_screen_level2();
    create_screen_testing_sensors();
    create_screen_profile_page();
    create_screen_shop_page();
}