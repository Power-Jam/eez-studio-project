#ifndef EEZ_LVGL_UI_VARS_H
#define EEZ_LVGL_UI_VARS_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// enum declarations

// Flow global variables

enum FlowGlobalVariables {
    FLOW_GLOBAL_VARIABLE_CURRENT_LEVEL = 0,
    FLOW_GLOBAL_VARIABLE_HIGHEST_UNLOCKED_LEVEL = 1,
    FLOW_GLOBAL_VARIABLE_CURRENT_COINS = 2,
    FLOW_GLOBAL_VARIABLE_ITEM_COST = 3,
    FLOW_GLOBAL_VARIABLE_SHOW_OVERLAY = 4,
    FLOW_GLOBAL_VARIABLE_LEVEL_STEP = 5,
    FLOW_GLOBAL_VARIABLE_RIGHT_TAG = 6,
    FLOW_GLOBAL_VARIABLE_CURRENT_PANEL = 7,
    FLOW_GLOBAL_VARIABLE_LESSON_CHOICE = 8
};

// Native global variables

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_VARS_H*/