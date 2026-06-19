#include "ar_game_fly_hunter.h"

ar_game_fly_hunter_t fly_hunter;
static uint32_t fly_hunter_y;

#define AXIS_Y_FLY_HUNTER_MIN (10)
#define AXIS_Y_FLY_HUNTER_MAX (50)

void ar_game_fly_hunter_handle(ak_msg_t *msg) {
	switch (msg->sig) {
	case AR_GAME_FLY_HUNTER_SETUP: {
		APP_DBG_SIG("AR_GAME_FLY_HUNTER_SETUP\n");
		fly_hunter.x			 = AXIS_X_FLY_HUNTER;
		fly_hunter.y			 = AXIS_Y_FLY_HUNTER;
		fly_hunter.visible		 = WHITE;
		fly_hunter.action_image = (settingsetup.num_arrow > 0 ? \
                                AR_GAME_FLY_HUNTER_ACTION_IMAGE_1 : \
                                AR_GAME_FLY_HUNTER_ACTION_IMAGE_2);
		fly_hunter_y			 = AXIS_Y_FLY_HUNTER;
	} break;

	case AR_GAME_FLY_HUNTER_UPDATE: {
		APP_DBG_SIG("AR_GAME_FLY_HUNTER_UPDATE\n");
		fly_hunter.y = fly_hunter_y;
	} break;

	case AR_GAME_FLY_HUNTER_UP: {
		APP_DBG_SIG("AR_GAME_FLY_HUNTER_UP\n");
		if (fly_hunter_y <= STEP_FLY_HUNTER_AXIS_Y || \
           (fly_hunter_y - STEP_FLY_HUNTER_AXIS_Y) < AXIS_Y_FLY_HUNTER_MIN) \
        {
			fly_hunter_y = AXIS_Y_FLY_HUNTER_MIN;
		}
		else {
			fly_hunter_y -= STEP_FLY_HUNTER_AXIS_Y;
		}
	} break;

	case AR_GAME_FLY_HUNTER_DOWN: {
		APP_DBG_SIG("AR_GAME_FLY_HUNTER_DOWN\n");
		fly_hunter_y += STEP_FLY_HUNTER_AXIS_Y;
		if (fly_hunter_y > AXIS_Y_FLY_HUNTER_MAX) {
			fly_hunter_y = AXIS_Y_FLY_HUNTER_MAX;
		}
	} break;

	case AR_GAME_FLY_HUNTER_RESET: {
		APP_DBG_SIG("AR_GAME_FLY_HUNTER_RESET\n");
		fly_hunter.visible = BLACK;
	} break;

	default:
		break;
	}
}
