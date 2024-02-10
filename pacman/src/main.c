#include <SDL2/SDL.h>
#include <stdbool.h>
#include "game.h"

int SDL_main() {
    int running = 1;
    char key;
    bool keys[SDL_NUM_SCANCODES] = {false};
    if(SDL_Init(SDL_INIT_VIDEO)!=0) {
        return -1;
    }
    SDL_Window *window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
    if(window==NULL) {
        SDL_Quit();
        return -1;
    }
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renderer==NULL) {
        SDL_Quit();
        return -1;
    }
    game Game;
    InitializeGame(&Game);

    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_KEYDOWN:
                    keys[event.key.keysym.scancode] = true; // Set key state to true when pressed
                    break;
                case SDL_KEYUP:
                    keys[event.key.keysym.scancode] = false; // Set key state to false when released
                    break;
                case SDL_QUIT:
                    running = 0;
                    break;
                default:
                    break;
            }
        }
        key = GetPressedKeys(keys);
        UpdateGame(&Game, key);
        ShowMaze(renderer);
        ShowEntities(renderer, &Game);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
