#include "menu.h"
#include "game_state.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

void Menu_Init(Menu* menu, SDL_Renderer* renderer) {
    menu->background = IMG_LoadTexture(renderer, "assets/sprites/background.png");
    const char* btn_files[3] = {
        "assets/sprites/btn_play.png",
        "assets/sprites/btn_settings.png",
        "assets/sprites/btn_exit.png"
    };

    for (int i = 0; i < 3; i++) {
        menu->btn_texture[i] = IMG_LoadTexture(renderer, btn_files[i]);
        menu->btn_rects[i] = (SDL_Rect){300, 200 + i * 100, 200, 50};
    }

    menu->click_sound = Mix_LoadWAV("assets/sounds/click.wav");
}

void Menu_HandleEvent(Menu* menu, SDL_Event* event) {
    if (event->type == SDL_MOUSEBUTTONDOWN) {
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);

        for (int i = 0; i < 3; i++) {
            SDL_Rect btn = menu->btn_rects[i];
            if (mouseX >= btn.x && mouseX <= btn.x + btn.w && 
                mouseY >= btn.y && mouseY <= btn.y + btn.h) {
                
                if (menu->click_sound) Mix_PlayChannel(-1, menu->click_sound, 0);
                
                switch (i) {
                    case 0: GameState_Set(GAME_STATE_PLAYING); break; // Play
                    case 2: GameState_Set(GAME_STATE_EXIT); break;    // Exit
                }
            }
        }
    }
}