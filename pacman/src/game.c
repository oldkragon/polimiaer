#include <stdio.h>
#define WIDTH 28
#define HEIGHT 31
#define WALL 'm'
#define EMPTY ' '
#define DOT '.'
#define PACMAN 'p'
#define GHOST 'g'

typedef struct {
    int x;
    int y;
} position;

typedef struct{
    char maze[HEIGHT][WIDTH];
    position Pinky;
    position Blinky;
    position Inky;
    position Clyde;
    position PacMan;
    int lives;
    int score;
}game;

void InitializeGame(game Game);
void UpdateGame(game Game);

int main(){
    game Game;

    InitializeGame(Game);

    while (1){
        UpdateGame(Game);
        if (game.lives == 0)
            break;
    }
    return 0;

}

void InitializeGame(game Game){
    char InitialMaze = {{m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m}
                        {m, ., ., ., ., ., ., ., ., ., ., ., ., m, m, ., ., ., ., ., ., ., ., ., ., ., ., m}
                        {m, ., m, m, m, m, ., m, m, m, m, m, ., m, m, ., m, m, m, m, m, ., m, m, m, m, ., m}
                        {m, ., m, m, m, m, ., m, m, m, m, m, ., m, m, ., m, m, m, m, m, ., m, m, m, m, ., m}
                        {m, ., m, m, m, m, ., m, m, m, m, m, ., m, m, ., m, m, m, m, m, ., m, m, m, m, ., m}
                        {m, ., ., ., ., ., ., ., ., ., ., ., ., ., ., ., ., ., ., ., ., ., ., ., ., ., ., m}
                        {m, ., m, m, m, m, ., m, m, ., m, m, m, m, m, m, m, m, ., m, m, ., m, m, m, m, ., m}
                        {m, ., m, m, m, m, ., m, m, ., m, m, m, m, m, m, m, m, ., m, m, ., m, m, m, m, ., m}
                        {m, ., ., ., ., ., ., m, m, ., ., ., ., m, m, ., ., ., ., m, m, ., ., ., ., ., ., m}
                        {m, m, m, m, m, m, ., m, m, m, m, m, ., m, m, ., m, m, m, m, m, ., m, m, m, m, m, m}
                        {m, m, m, m, m, m, ., m, m, m, m, m, ., m, m, ., m, m, m, m, m, ., m, m, m, m, m, m}
                        {m, m, m, m, m, m, ., m, m, ., ., ., ., ., ., ., ., ., ., m, m, ., m, m, m, m, m, m}
                        {m, m, m, m, m, m, ., m, m, ., m, m, m, ., ., m, m, m, ., m, m, ., m, m, m, m, m, m}
                        {m, m, m, m, m, m, ., m, m, ., m, ., ., ., ., ., ., m, ., m, m, ., m, m, m, m, m, m}
                        {., ., ., ., ., ., ., ., ., ., m, ., ., ., ., ., ., m, ., ., ., ., ., ., ., ., ., .}
                        {m, m, m, m, m, m, ., m, m, ., m, ., ., ., ., ., ., m, ., m, m, ., m, m, m, m, m, m}
                        {m, m, m, m, m, m, ., m, m, ., m, m, m, m, m, m, m, m, ., m, m, ., m, m, m, m, m, m}
                        {m, m, m, m, m, m, ., m, m, ., ., ., ., ., ., ., ., ., ., m, m, ., m, m, m, m, m, m}
                        {m, m, m, m, m, m, ., m, m, ., m, m, m, m, m, m, m, m, ., m, m, ., m, m, m, m, m, m}
                        {m, m, m, m, m, m, ., m, m, ., m, m, m, m, m, m, m, m, ., m, m, ., m, m, m, m, m, m}
                        {m, ., ., ., ., ., ., ., ., ., ., ., ., m, m, ., ., ., ., ., ., ., ., ., ., ., ., m}
                        {m, ., m, m, m, m, ., m, m, m, m, m, ., m, m, ., m, m, m, m, m, ., m, m, m, m, ., m}
                        {m, ., m, m, m, m, ., m, m, m, m, m, ., m, m, ., m, m, m, m, m, ., m, m, m, m, ., m}
                        {m, ., ., ., m, m, ., ., ., ., ., ., ., ., ., ., ., ., ., ., ., ., m, m, ., ., ., m}
                        {m, m, m, ., m, m, ., m, m, ., m, m, m, m, m, m, m, m, ., m, m, ., m, m, ., m, m, m}
                        {m, m, m, ., m, m, ., m, m, ., m, m, m, m, m, m, m, m, ., m, m, ., m, m, ., m, m, m}
                        {m, ., ., ., ., ., ., ., ., ., ., ., ., ., ., ., ., ., ., ., ., ., ., ., ., ., ., m}
                        {m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m}

    };
    Game.lives = 3;
    Game.score = 0;

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            Game.maze[i][j] = InitialMaze
        }
    }

    Game.Pinky.x == 14;
    Game.Pinky.y == 16;

    Game.Blinky.x == 14;
    Game.Blinky.y == 16;

    Game.Inky.x == 15;
    Game.Inky.y == 16;

    Game.Clyde.x == 15;
    Game.Clyde.y == 16;

    Game.PacMan.x == 15;
    Game.PacMan.y == 16;
}


#include "game.h"
#include <stdio.h>
#include <SDL2/SDL.h>

int ShowWindow();

int ShowWindow(){
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