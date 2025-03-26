#include "engine/core.h"
#include "engine/audio.h"
#include "game/menu.h"
#include "game/game.h"

int main(void) {
    // init engine
    if (!Core_Init()) {
        printf("Failed to initialize engine!\n");
        return -1;
    }

    // load resource
    Audio_Load();  // sound and music
    Menu menu;
    Menu_Init(&menu, Core_GetRenderer());

    // Игровой цикл
    bool isRunning = true;
    SDL_Event event;

    while (isRunning) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                isRunning = false;
            }
            Menu_HandleEvent(&menu, &event); // Только обработка меню
        }

        SDL_SetRenderDrawColor(Core_GetRenderer(), 0, 0, 0, 255);
        SDL_RenderClear(Core_GetRenderer());
        
        Menu_Render(&menu, Core_GetRenderer()); // Только рендер меню
        
        SDL_RenderPresent(Core_GetRenderer());
        SDL_Delay(16);
    }

    // Resource release
    Core_Shutdown();
    return 0;
}