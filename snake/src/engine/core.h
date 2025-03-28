#ifndef CORE_H
#define CORE_H

#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
    int width;
    int height;
} Core;


bool Core_Init(Core* core, const char* title, int w, int h);
void Core_Shutdown(Core* core);
SDL_Renderer* Core_GetRenderer(Core* core);

#endif