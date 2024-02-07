#include <stdio.h>
#include <SDL2/SDL.h>

int SDL_main(int argc, char* argv[]) {
    if(SDL_Init(SDL_INIT_VIDEO)!=0) {
        printf("Failed to initialize the SDL2 library\n");
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return -1;
    }
    SDL_Window *window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 680, 480, SDL_WINDOW_SHOWN);
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