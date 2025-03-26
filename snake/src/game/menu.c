#include <menu.h>
#include <core.h>
#include "engine/audio.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void Menu_Init(Menu* menu, SDL_Renderer* renderer) {
    //upload background
    menu->background = IMG_LoadTexture(renderer, "assets/sprites/background.png");
    if (!menu->background) {
        printf("[Menu] Не удалось загрузить фон: %s\n", IMG_GetError());
    }

    // load buttons texture
    const char* btn_files[3] = {
        "assets/sprites/btn_play.png",
        "assets/sprites/btn_settings.png",
        "assets/sprites/btn_exit.png"
    };

    for (int i = 0; i < 3; i++) {
        menu->btn_texture[i] = IMG_LoadTexture(renderer, btn_files[i]);
        if (!menu->btn_texture[i]) {
            printf("[Menu] Не удалось загрузить текстуру кнопки %d: %s\n", i, IMG_GetError());
        }
        menu->btn_rects[i] = (SDL_Rect){300, 200 + i * 100, 200, 50};
    }
}