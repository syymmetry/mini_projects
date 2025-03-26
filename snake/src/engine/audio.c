#include "audio.h"


static Mix_Music* bg_music = NULL;


void Audio_Load() {
    bg_music = Mix_LoadMUS("assets/music/menu.ogg");
    if (!bg_music) {
        printf("[Audio] Не удалось загрузить музыку: %s\n", Mix_GetError());
    } else {
        Mix_PlayMusic(bg_music, -1);
    }
}

void Audio_Free() {
    if (bg_music) Mix_FreeMusic(bg_music);
}

void Audio_PlaySound(const char* path) {
    Mix_Chunk* sound = Mix_LoadWAV(path);
    if (sound) {
        Mix_PlayChannel(-1, sound, 0);
    } else {
        printf("[Audio] Не удалось загрузить звук: %s\n", Mix_GetError());
    }
}