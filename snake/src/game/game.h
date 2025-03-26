#ifndef Game_H
#define GAME_H

#include <stdbool.h>
#include <SDL2/SDL.h>

bool Game_isRunning();
void Game_HandleEvent(SDL_Event* event);
void Game_Render();


#endif