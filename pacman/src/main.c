#include <SDL2/SDL.h>
#include "game.h"

int SDL_main(int argc, char* argv[]) {
    int running = 1;
    if(SDL_Init(SDL_INIT_VIDEO)!=0) {
        return -1;
    }
    SDL_Window *window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900, 600, SDL_WINDOW_SHOWN);
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
            if (event.type == SDL_QUIT) {
                running = 0;
            }
            UpdateGame(&Game);
            ShowMaze(renderer);
        }
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
