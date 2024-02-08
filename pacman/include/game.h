
#ifndef POLIMIAER_GAME_H
#define POLIMIAER_GAME_H

#define WIDTH 28
#define HEIGHT 31

#include <SDL.h>

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
    position Cherry;
    int lives;
    int score;
    int moveCounter;
    int countDots;
}game;

void ShowMaze(SDL_Renderer *renderer);
void InitializeGame(game Game);
void UpdateGame(game Game);
void updateClydePosition(game *Game);
void spawnCherry(game *Game);


#endif //POLIMIAER_GAME_H


