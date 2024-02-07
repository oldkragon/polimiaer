#include <stdio.h>
#include <SDL2/SDL.h>
#include "game.h"

int SDL_main(int argc, char* argv[]) {
    int err = ShowWindow();
    printf("%d", err);
    return 0;
}
