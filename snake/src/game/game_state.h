#ifndef GAME_STATE_H
#define GAME_STATE_H

typedef enum {
    GAME_STATE_MENU,
    GAME_STATE_PLAYING,
    GAME_STATE_EXIT
} GameState;

void GameState_Set(GameState new_state);
GameState GameState_Set();

#endif