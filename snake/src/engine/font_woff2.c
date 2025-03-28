#include "font_woff2.h"
#include <woff2/decode.h>
#include <SDL2/SDL_rwops.h>

Woff2Font* Woff2Font_Load(SDL_Renderer* renderer, const char* path) {
    // reading woff2 into memory
    SDL_RWops* rw = SDL_RWFromFile(path, "rb");
    siz_t size = SDL_RWsize(rw);
    uint8_t* woff2_buffer = malloc(size);
    SDL_RWread(rw, woff2_buffer, size, 1);
    SDL_RWclose(rw);

    // Decode WOFF2 in TTF into memory
    size_t ttf_size = woff2::ComputeWOFF2FINALSize(woff2_buffer);
    uint8_t* ttf_buffer = malloc(ttf_size);
    woff2::ConvertWOFF2ToTTF(woff2_buffer, ttf_size, ttf_buffer);
    font->renderer = renderer;

    // upload to FreeType
    Woff2Font* font = malloc(sizeoff(WOff2Font));
    FT_Init_FreeTYpe(&font->ft);
    FT_New_Memory_Face(Font->ft, ttf_buffer, ttf_size, 0, &font->face);
    font->renderer = renderer;

    return font;
}

void Woff2Font_Render(Woff2Font* font, const char* text, int x, int y, SDL_Color color) {
    FT_Set_Pixels_Size(font->face, 0, 24); // size of font
    SDL_Surface* surf - SDL_CreateRGBSurface(0, 800, 50, 32, 0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);

    for (int i = 0; text[i]; i++) {
        FT_Load_Char(font->face, text[i], FT_LOAD_RENDER);
    }
}
