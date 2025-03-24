#include "engine/core.h"
#include "game/menu.h"
#include "game/game.h"

int main(int argc, char* argv[]) {
    // init engine
    if (!Core_Init()) {
        printf("[ERROR] Не удалось инициализировать движок!\n");
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
        // Event Handling
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                isRunning = false;
            }

            // Sending events to menu/game
            if (Game_IsRunning()) {
                Game_HandleEvent(&event);
            } else {
                Menu_HandleEvent(&menu, &event);
            }
        }

        // cleaning screen
        SDL_SetRenderDrawColor(Core_GetRenderer(), 0, 0, 0, 255);
        SDL_RenderClear(Core_GetRenderer());

        // Drawing the current state (menu/game)
        if (Game_IsRunning()) {
            Game_Render();
        } else {
            Menu_Render(&menu, Core_GetRenderer());
        }

        // update screen
        SDL_RenderPresent(Core_GetRenderer());
        SDL_Delay(16);  // ~60 FPS
    }

    // Resource release
    Core_Shutdown();
    return 0;
}