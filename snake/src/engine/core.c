#include "core.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>


bool Core_Init(Core* core, const char* title, int w, int h) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        printf("SDL_Init error: %s\n", SDL_GetError());
        return false;
    }

    core->window = SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        w, h,
        SDL_WINDOW_SHOWN
    );
    if (!core->window) return false;

    // init render
    core->renderer = SDL_CreateRenderer(
        core->window,
        -1,
        SDL_RENDERER_ACCELERATED
    );
    if (!core->renderer) return false;


    // init SDL_IMG
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        printf("[SDL2_image] initialization error: %s\n", IMG_GetError());
        return false;
    }

    // init SDL_Mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("[SDL2_Mixer] initialization error: %s\n", Mix_GetError());
        return false;
    }


    // init SDL_TTF_
    if (TTF_Init() < 0) {
        printf("[SDL2_TTF] initialization error: %s\n", TTF_GetError());
        return false;
    }

    core->width = w;
    core->height = h;
    return true;
}

void Core_Shutdown() {
    if (core->renderer) SDL_DestroyRenderer(core->renderer);
    if (core->window) SDL_DestroyWindow(core->window);
    Mix_CloseAudio();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}


SDL_Renderer* Core_GetRenderer() {
    return core->renderer;
}
