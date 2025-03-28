#pragma once
#include <SDL2/SDL.h>
#include <ft2build.h>
#include FT_FREETYPE_H

typedef struct {
    FT_Face face;
    FT_Library ft;
    SDL_Renderer* renderer;
} Woff2Font;

Woff2Font* Woff2Font_Load(SDL_Renderer* renderer, const char* path);
void Woff2Font_Render(Woff2Font* font, const char* text, int x, int y, SDL_Color color);
void Woff2Font_Free(Woff2Font* font);