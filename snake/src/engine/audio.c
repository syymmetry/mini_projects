#include "audio.h"
#include <SDL2/SDL_mixer.h>

typedef struct audio {
    Mix_Music* bg_music;
} AuidioSystem;

static AuidioSystem audio;

void Audio_Load() {
    audio.bg_music = Mix_LoadMUS("assets/music/menu.ogg");
    if (!audio.bg_music) {
        printf("[Audio] Ошибка загрузки музыки: %s\n", Mix_GetError());
        return;
    }
    Mix_PlayMusic(audio.bg_music, -1);
}

void Audio_Free() {
    if (audio.bg_music) {
        Mix_FreeMusic(audio.bg_music);
        audio.bg_music = NULL;
    }
}

void audio_PlaySound(const char* path) {
    Mix_Chunk* sound = Mix_LoadWAV(path);
    if (!sound) {
        printf("[Audio] Ошибка загрузки звука: %s\n", Mix_GetError());
        return;
    }
    Mix_PlayChanel(-1, sound, 0);
    Mix_FreeChunk(sound);
}