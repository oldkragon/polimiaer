#include "game.h"
#include <stdio.h>
#include <SDL2/SDL.h>

#define WIDTH 31
#define HEIGHT 28
#define CELL_SIZE 20
//colorscheme pacman FFFF00 bg 1919A6 walls 2121DE

extern char maze[WIDTH][HEIGHT];

void ShowMaze(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 25, 25, 166, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 33, 33, 222, 255);
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if(maze[i][j] == 'm') {
                SDL_Rect rect = {j* CELL_SIZE, i*CELL_SIZE, CELL_SIZE, CELL_SIZE};
                SDL_RenderFillRect(renderer, &rect);
            }
        }
    }
    SDL_RenderPresent(renderer);
}
int ShowWindow(){
    if(SDL_Init(SDL_INIT_VIDEO)!=0) {
        printf("Failed to initialize the SDL2 library\n");
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return -1;
    }
    SDL_Window *window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900, 600, SDL_WINDOW_SHOWN);
    if(window==NULL) {
        printf("Failed to create window\n");
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return -1;
    }
    SDL_Delay(3000);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}