#include "splash.h"
#include "audio.h"
#include <SDL2/SDL_image.h>

void splash_show(SDL_Renderer* renderer) {
    SDL_Texture* logo = IMG_LoadTexture(renderer, "assets/sprites/logo.png");
    if (!logo) return;

    Audio_PlaySound("assets/sounds/logo_sound.wav");

    SDL_RenderCopy(renderer, logo, NULL, NULL);
    SDL_RendererPresent(renderer);
    SDL_Dealay(3000);

    SDL_DestroyTexture(logo);
}