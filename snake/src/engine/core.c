#include <core.h>

static SDL_Window* window = NULL;
static SDL_Renderer* renderer = NULL;

bool Core_Init() {
    if ((SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        printf("[SDL2] Ошибка инициализации: %s\n", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow(
        "Hungry snake",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800, 600,
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
    );
    if (!window) {
        printf("[SDL2] window creation error: %s\n", SDL_GetError());
    }


    renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );
    if(!renderer) {
        printf("[SDL2] render creation error: %s\n", SDL_GetError());
    }

    // init SDL_IMG
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        printf("[SDL2_image] initialization error: s\n", IMG_GetError());
        return false;
    }

    // init SDL_Mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("[SDL2_Mixer] initialization error: s\n", Mix_GetError());
        return false;
    }


    // init SDL_TTF_
    if (TTF_Init() < 0) {
        printf("[SDL2_TTF] initialization error: s\n", TTF_GetError());
        return false;
    }


    return true;
}

void Core_Shotdown() {
    if (renderer) SDL_DestroyRenderer(renderer);
    if (window) SDL_DestroyWindow(window);
    Mix_CloseAudio();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}


SDL_Renderer* Core_GetRenderer() {
    return renderer;
}

void Core_GetWindowSize(int* w, int* h) {
    SDL_GetWindowSize(window, w, h);
}
