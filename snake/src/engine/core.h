#ifndef CORE_H
#define CORE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include <stdio.h>

bool Core_Init();
void Core_Shutdown();
SDL_Renderer* Core_GetRenderer();
void Core_GetWindowSize(int* w, int* h);



#endif