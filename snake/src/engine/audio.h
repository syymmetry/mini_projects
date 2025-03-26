#ifndef AUDIO_H
#define AUDIO_H

#include <SDL2/SDL_mixer.h>

void Audio_Load();
void Audio_Free();
void Audio_PlaySound(const char* path);


#endif