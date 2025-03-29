#ifndef SNAKE_H
#define SNAKE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

typedef struct {
    SDL_Texture* head;
    SDL_Texture* body;
    SDL_Texture* tail;
    Mix_Chunk* move_sound;
    SDL_Rect segments[100];
    int length;
    int direction; // 0=up, 1=right, 2=down, 3=left
} Snake;

void Snake_Init(Snake* snake, SDL_Renderer* ren);
void Snake_Move(Snake* snake);
void Snake_Render(Snake* snake, SDL_Renderer* ren);
void Snake_HandleInput(Snake* snake, SDL_Event* event);


#endif