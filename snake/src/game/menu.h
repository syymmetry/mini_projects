#ifndef MENU_H
#define MENU_H 

#include <SDL2/SDL.h>


typedef struct {
    SDL_Texture* background;
    SDL_Texture* btn_texture[3];
    SDL_Rect btn_rects[3];
    Mix_Chunk* click_sound;
} Menu;

void Menu_Init(Menu* menu, SDL_Renderer* renderer);
void Menu_Render(Menu* menu, SDL_Renderer* renderer);
void Menu_HandleEvent(Menu* menu, SDL_Event* event);
void Menu_Free(Menu* menu);



#endif