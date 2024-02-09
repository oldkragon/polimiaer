
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
    int cherryActive;
    int cherrySpawnTime;
}game;

void ShowMaze(SDL_Renderer *renderer);
void InitializeGame(game *Game);
void UpdateGame(game *Game);
void updateClydePosition(game *Game);
void spawnCherry(game *Game);
void updateInkyPosition(game *game);
void updatePinkyPosition(game *game);
void updateBlinkyPosition(game *game);
void resetPacManPosition(game *Game);
void resetPinkyPosition(game *Game);
void resetInkyPosition(game *Game);
void resetBlinkyPosition(game *Game);
void resetClydePosition(game *Game);


#endif //POLIMIAER_GAME_H


