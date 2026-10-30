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
    FLOW_GLOBAL_VARIABLE_CURRENT_COINS = 1,
    FLOW_GLOBAL_VARIABLE_ITEM_COST = 2,
    FLOW_GLOBAL_VARIABLE_SHOW_OVERLAY = 3,
    FLOW_GLOBAL_VARIABLE_LEVEL_STEP = 4,
    FLOW_GLOBAL_VARIABLE_RIGHT_TAG = 5
};

// Native global variables

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_VARS_H*/