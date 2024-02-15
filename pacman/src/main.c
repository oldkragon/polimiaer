#include <SDL2/SDL.h>
#include "game.h"
#include <stdbool.h>

int SDL_main() {
  int running = 1;
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
    // Handle initialization error
    return -1;
  }
  SDL_Window *window = SDL_CreateWindow(
      "SDL2 Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720,
      SDL_WINDOW_RESIZABLE | SDL_WINDOW_INPUT_FOCUS);
  if (window == NULL) {
    SDL_Quit();
    return -1;
  }
  SDL_Renderer *renderer = SDL_CreateRenderer(
      window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (renderer == NULL) {
    SDL_Quit();
    return -1;
  }
  game Game;
  InitializeGame(&Game);

  while (running) {
    SDL_Event event;
    bool keys[SDL_NUM_SCANCODES] = {false};
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_KEYDOWN:
        keys[event.key.keysym.scancode] =
            true; // Set key state to true when pressed
        break;
      case SDL_KEYUP:
        keys[event.key.keysym.scancode] =
            false; // Set key state to false when released
        break;
      case SDL_QUIT:
        running = 0;
        break;
      default:
        break;
      }
    }
    UpdateGame(&Game, keys);
    ShowMaze(renderer);
    ShowEntities(renderer, &Game);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
