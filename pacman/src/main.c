#include <stdio.h>
#include <SDL2/SDL.h>

int SDL_main(int argc, char* argv[]) {
    if(SDL_Init(SDL_INIT_VIDEO)<0) {
        printf("Failed to initialize the SDL2 library\n");
        return -1;
    }
    SDL_Window *window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 680, 480, 0);
    if(!window) {
        printf("Failed to create window\n");
        return -1;
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}