#include "menu.h"
#include "engine/core.h"
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

    menu->click_sound = Mix_LoadWAV("assets/sounds/click.wav");
    if (!menu->click_sound) {
        printf("[Menu] Не удалось загрузить звук клика: %s\n", Mix_GetError());
    }   
}

void Menu_Render(Menu* menu, SDL_Renderer* renderer) {
    // drowing background
    if (menu->background) {
        SDL_RenderCopy(renderer, menu->background, NULL, NULL);
    } else {
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderClear(renderer);
    }

    // drawing buttons
    for (int i = 0; i < 3; i++) {
        if (menu->btn_texture[i]) {
            SDL_RenderCopy(renderer, menu->btn_texture[i], NULL, &menu->btn_rects[i]);
        } else {
            SDL_SetRenderDrawColor(renderer, 70, 70, 70, 255);
            SDL_RenderFillRect(renderer, &menu->btn_rects[i]);
        }
    }
}

void Menu_HandleEvent(Menu* menu, SDL_Event* event) {
    if (event->type == SDL_MOUSEBUTTONDOWN) {
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);

        // Checking the click on buttons
        for (int i = 0; i < 3; i++) {
            SDL_Rect btn = menu->btn_rects[i];
            if (mouseX >= btn.x && mouseX <= btn.x + btn.w && mouseY >= btn.y && mouseY <= btn.y + btn.h) {
                if (menu->click_sound) {
                    Mix_PlayChannel(-1, menu->click_sound, 0);
                }
                switch (i) {
                    case 0: printf("Запуск игры!\n"); break;
                    case 1: printf("Настройки!\n"); break;
                    case 2: printf("Выход!\n");
                }
            }
        }
    }
}


void Menu_Free(Menu* menu) {
    if (menu->background) SDL_DestroyTexture(menu->background);
    for (int i = 0; i < 3; i++) {
        if (menu->btn_texture[i]) SDL_DestroyTexture(menu->btn_texture[i]);
    }
    if (menu->click_sound) Mix_FreeChunk(menu->click_sound);
}