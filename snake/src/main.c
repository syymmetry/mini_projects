#include "core.h"
#include "game_state.h"
#include "audio.h"
#include "menu.h"

int main() {
    Core core;
    if (!Core_Init(&core, "Hungry Snake", 800, 600)) return 1;

    splash_show(core.renderer);

    Audio_Load();

    Menu menu;
    Menu_Init(&menu, core.renderer);

    while (GameState_Set() != GAME_STATE_EXIT) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_Quit) {
                GameState_Set(GAME_STATE_EXIT);
            }

            switch (GameState_Get()) {
                case GAME_STATE_MENU:
                    Menu_HandleEvent(&menu, &event);
                    break;
                case GAME_STATE_PLAYING:
                break;
            }
        }
        SDL_RenderClear(core.renderer);
        switch (GameState_Get()) {
            case GAME_STATE_MENU:
                Menu_Render(&menu, core.renderer);
                break;
            case GAME_STATE_PLAYING:
            break;
        }
        SDL_RenderPresent(core.renderer);
    }

    Menu_Free(&menu);
    Audio_Free();
    Core_Shutdown(&core);
    return 0;
}