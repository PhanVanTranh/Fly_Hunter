#ifndef __AR_GAME_FLY_HUNTER_H__
#define __AR_GAME_FLY_HUNTER_H__

#include <stdio.h>

#include "fsm.h"
#include "port.h"
#include "message.h"
#include "timer.h"

#include "app.h"
#include "app_dbg.h"
#include "task_list.h"
#include "task_display.h"

#include "scr_fly_hunter_game.h"

#define STEP_FLY_HUNTER_AXIS_Y     (10)
#define SIZE_BITMAP_FLY_HUNTER_X   (15)
#define SIZE_BITMAP_FLY_HUNTER_Y   (15)
#define AXIS_X_FLY_HUNTER          (0)
#define AXIS_Y_FLY_HUNTER          (30)

enum {
	AR_GAME_FLY_HUNTER_ACTION_IMAGE_1 = 1,	   // Has arrow
	AR_GAME_FLY_HUNTER_ACTION_IMAGE_2,		   // Empty
	AR_GAME_FLY_HUNTER_ACTION_IMAGE_END
};

typedef struct {
    bool visible;
    uint32_t x, y;
    uint8_t action_image;
} ar_game_fly_hunter_t;

extern ar_game_fly_hunter_t fly_hunter;

#endif //__AR_GAME_FLY_HUNTER_H__
