#include "game_state.h"

static GameState current_state = GAME_STATE_MENU;



void GameState_Set(GameState new_state) {
    current_state = new_state;
}
GameState GameState_Set() {
    return current_state;
}
