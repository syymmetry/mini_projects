#include "snake.h"
#include "audio.h"
#include <SDL2/SDL_image.h>

void Snake_Init(Snake* snake, SDL_Renderer* ren) {
    snake->head = IMG_LoadTexture(ren, "assets/sprites/snake_head.png");
    snake->body = IMG_LoadTexture(ren, "assets/sprites/snake_body.png");
    snake->tail = IMG_LoadTexture(ren, "assets/sprites/snake_tail.png");
    snake->move_sound = Mix_LoadWAV("assets/sounds/move.wav");
    snake->length = 3;
    snake->direction = 1;

    for (int i = 0; i < snake->length; i++) {
        snake->segments[i] = (SDL_Rect){100 - i * 20, 100, 20, 20};
    }
}

void Snake_Move(Snake* snake) {
    for (int i = 0; i < snake->length; i++) {
        snake->segments[i] = snake->segments[i - 1];
    }

    switch (snake->direction) {
        case 0: snake->segments[0].y -= 20; break;
        case 1: snake->segments[0].x += 20; break;
        case 2: snake->segments[0].y += 20; break;
        case 3: snake->segments[0].x -= 20; break;
    }

    if (snake->move_sound) {
        Mix_PlayChannel(-1, snake->move_sound, 0);
    }
 }

 void Snake_Render(Snake* snake, SDL_Renderer* ren) {
    // render tail
    SDL_RenderCopy(ren, snake->tail, NULL, &snake->segments[snake->length-1]);

    // render body
    for (int i = 1; i < snake->length-1; i++) {
        SDL_RenderCopy(ren, snake->body, NULL, &snake->segments[i]);
    }

    // render head
    SDL_RenderCopy(ren, snake->head, NULL, &snake->segments[0]);
 }


 void Snake_HandleInput(Snake* snake, SDL_Event* event) {
    if (event->type == SDL_KEYDOWN) {
        switch (event->key.keysym.sym) {
            case SDLK_UP: if (snake->direction != 2) snake->direction = 0; break;
            case SDLK_RIGHT: if (snake->direction != 3) snake->direction = 1; break;
            case SDLK_DOWN: if (snake->direction != 0) snake->direction = 2; break;
            case SDLK_LEFT: if (snake->direction != 1) snake->direction = 3; break;
        }
    }
 }