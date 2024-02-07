#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define WIDTH 28
#define HEIGHT 31
#define WALL 'm'
#define EMPTY ' '
#define DOT '.'
#define PACMAN 'p'
#define GHOST 'g'
#define CHERRY 'c'

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
    position Cherry
    int lives;
    int score;
    int moveCounter;
    int countDots
}game;

void InitializeGame(game Game);
void UpdateGame(game Game);
void updateClydePosition(game game);
void spawnCherry()

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
    char InitialMaze = {{'m', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm'},
                        {'m', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 'm', 'm', '.', '.', '.' ,'.', '.', '.', '.', '.', '.', '.', '.', '.', 'm'},
                        {'m', '.', 'm', 'm', 'm', 'm', '.', 'm', 'm', 'm', 'm', 'm', '.', 'm', 'm', '.', 'm', 'm', 'm', 'm', 'm', '.', 'm', 'm', 'm', 'm', '.', 'm'},
                        {'m', '.', 'm', 'm', 'm', 'm', '.', 'm', 'm', 'm', 'm', 'm', '.', 'm', 'm', '.', 'm', 'm', 'm', 'm', 'm', '.', 'm', 'm', 'm', 'm', '.', 'm'},
                        {'m', '.', 'm', 'm', 'm', 'm', '.', 'm', 'm', 'm', 'm', 'm', '.', 'm', 'm', '.', 'm', 'm', 'm', 'm', 'm', '.', 'm', 'm', 'm', 'm', '.', 'm'},
                        {'m', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 'm'},
                        {'m', '.', 'm', 'm', 'm', 'm', '.', 'm', 'm', '.', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', '.', 'm', 'm', '.', 'm', 'm', 'm', 'm', '.', 'm'},
                        {'m', '.', 'm', 'm', 'm', 'm', '.', 'm', 'm', '.', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', '.', 'm', 'm', '.', 'm', 'm', 'm', 'm', '.', 'm'},
                        {'m', '.', '.', '.', '.', '.', '.', 'm', 'm', '.', '.', '.', '.', 'm', 'm', '.', '.', '.', '.', 'm', 'm', '.', '.', '.', '.', '.', '.', 'm'},
                        {'m', 'm', 'm', 'm', 'm', 'm', '.', 'm', 'm', 'm', 'm', 'm', '.', 'm', 'm', '.', 'm', 'm', 'm', 'm', 'm', '.', 'm', 'm', 'm', 'm', 'm', 'm'},
                        {'m', 'm', 'm', 'm', 'm', 'm', '.', 'm', 'm', 'm', 'm', 'm', '.', 'm', 'm', '.', 'm', 'm', 'm', 'm', 'm', '.', 'm', 'm', 'm', 'm', 'm', 'm'},
                        {'m', 'm', 'm', 'm', 'm', 'm', '.', 'm', 'm', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 'm', 'm', '.', 'm', 'm', 'm', 'm', 'm', 'm'},
                        {'m', 'm', 'm', 'm', 'm', 'm', '.', 'm', 'm', '.', 'm', 'm', 'm', '.', '.', 'm', 'm', 'm', '.', 'm', 'm', '.', 'm', 'm', 'm', 'm', 'm', 'm'},
                        {'m', 'm', 'm', 'm', 'm', 'm', '.', 'm', 'm', '.', 'm', '.', '.', '.', '.', '.', '.', 'm', '.', 'm', 'm', '.', 'm', 'm', 'm', 'm', 'm', 'm'},
                        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 'm', '.', '.', '.', '.', '.', '.', 'm', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                        {'m', 'm', 'm', 'm', 'm', 'm', '.', 'm', 'm', '.', 'm', '.', '.', '.', '.', '.', '.', 'm', '.', 'm', 'm', '.', 'm', 'm', 'm', 'm', 'm', 'm'},
                        {'m', 'm', 'm', 'm', 'm', 'm', '.', 'm', 'm', '.', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', '.', 'm', 'm', '.', 'm', 'm', 'm', 'm', 'm', 'm'},
                        {'m', 'm', 'm', 'm', 'm', 'm', '.', 'm', 'm', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 'm', 'm', '.', 'm', 'm', 'm', 'm', 'm', 'm'},
                        {'m', 'm', 'm', 'm', 'm', 'm', '.', 'm', 'm', '.', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', '.', 'm', 'm', '.', 'm', 'm', 'm', 'm', 'm', 'm'},
                        {'m', 'm', 'm', 'm', 'm', 'm', '.', 'm', 'm', '.', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', '.', 'm', 'm', '.', 'm', 'm', 'm', 'm', 'm', 'm'},
                        {'m', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 'm', 'm', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 'm'},
                        {'m', '.', 'm', 'm', 'm', 'm', '.', 'm', 'm', 'm', 'm', 'm', '.', 'm', 'm', '.', 'm', 'm', 'm', 'm', 'm', '.', 'm', 'm', 'm', 'm', '.', 'm'},
                        {'m', '.', 'm', 'm', 'm', 'm', '.', 'm', 'm', 'm', 'm', 'm', '.', 'm', 'm', '.', 'm', 'm', 'm', 'm', 'm', '.', 'm', 'm', 'm', 'm', '.', 'm'},
                        {'m', '.', '.', '.', 'm', 'm', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 'm', 'm', '.', '.', '.', 'm'},
                        {'m', 'm', 'm', '.', 'm', 'm', '.', 'm', 'm', '.', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', '.', 'm', 'm', '.', 'm', 'm', '.', 'm', 'm', 'm'},
                        {'m', 'm', 'm', '.', 'm', 'm', '.', 'm', 'm', '.', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', '.', 'm', 'm', '.', 'm', 'm', '.', 'm', 'm', 'm'},
                        {'m', '.', 'm', 'm', 'm', 'm', '.', 'm', 'm', 'm', 'm', 'm', '.', 'm', 'm', '.', 'm', 'm', 'm', 'm', 'm', '.', 'm', 'm', 'm', 'm', '.', 'm'},
                        {'m', '.', 'm', 'm', 'm', 'm', '.', 'm', 'm', 'm', 'm', 'm', '.', 'm', 'm', '.', 'm', 'm', 'm', 'm', 'm', '.', 'm', 'm', 'm', 'm', '.', 'm'},
                        {'m', '.', 'm', 'm', 'm', 'm', '.', 'm', 'm', 'm', 'm', 'm', '.', 'm', 'm', '.', 'm', 'm', 'm', 'm', 'm', '.', 'm', 'm', 'm', 'm', '.', 'm'},
                        {'m', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 'm'},
                        {'m', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm'}

    };
    Game.lives = 3;
    Game.score = 0;

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            Game.maze[i][j] = InitialMaze
        }
    }

    Game.countDots = 0;

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if(InitialMaze[i][j] == '.')
            Game.countDots++;
        }
    }

    Game.Pinky.x = 14;
    Game.Pinky.y = 14;

    Game.Blinky.x = 14;
    Game.Blinky.y = 14;

    Game.Inky.x = 14;
    Game.Inky.y = 14;

    Game.Clyde.x = 14;
    Game.Clyde.y = 14;

    Game.PacMan.x = 15;
    Game.PacMan.y = 14;

    Game.moveCounter = 0;
}

void UpdateGame(game Game){
    char input;
//aggiorna la posizione di pacman in base all'input
    switch (input){
        case 'w': {
            if(maze[Game.PacMan.y-1][Game.PacMan.x] != 'm') {
                Game.PacMan.y--;
                break;
            }
        }
        case 's': {
            if(maze[Game.PacMan.y+1][Game.PacMan.x] != 'm') {
                Game.PacMan.y++;
                break;
            }
        }
        case 'a': {
            if(maze[Game.PacMan.y][Game.PacMan.x-1] != 'm') {
                Game.PacMan.x--;
                break;
            }
        }
        case 'd': {
            if(maze[Game.PacMan.y][Game.PacMan.x+1] != 'm') {
                Game.PacMan.x++;
                break;
            }
        }
        case (GetAsyncKeyState(VK_UP)): {
            if(maze[Game.PacMan.y-1][Game.PacMan.x] != 'm') {
                Game.PacMan.y--;
                break;
            }
        }
        case (GetAsyncKeyState(VK_DOWN)): {
            if(maze[Game.PacMan.y+1][Game.PacMan.x] != 'm') {
                Game.PacMan.y++;
                break;
            }
        }
        case (GetAsyncKeyState(VK_LEFT)): {
            if(maze[Game.PacMan.y][Game.PacMan.x-1] != 'm') {
                Game.PacMan.x--;
                break;
            }
        }
        case (GetAsyncKeyState(VK_RIGHT)): {
            if(maze[Game.PacMan.y][Game.PacMan.x+1] != 'm') {
                Game.PacMan.x++;
                break;
            }
        }
    }

    Game.moveCounter++;

    while (Game.moveCounter > 7){
        //Blinky lo segue diretto - parte 7 mosse dopo
        if(Game.PacMan.x > Game.Blinky.x && Game.PacMan.y >= Game.Blinky.y){
            if(Game.maze[Game.Blinky.y-1][Game.Blinky.x] != 'm')
                Game.Blinky.y--;
            else if(Game.maze[Game.Blinky.y][Game.Blinky.x+1] != 'm')
                Game.Blinky.x++;
            else if(Game.maze[Game.Blinky.y+1][Game.Blinky.x] != 'm')
                Game.Blinky.y++;
            else if(Game.maze[Game.Blinky.y][Game.Blinky.x-1] != 'm')
                Game.Blinky.x--;
        }

        if(Game.PacMan.x >= Game.Blinky.x && Game.PacMan.y < Game.Blinky.y){
            if(Game.maze[Game.Blinky.y][Game.Blinky.x+1] != 'm')
                Game.Blinky.x++;
            else if(Game.maze[Game.Blinky.y+1][Game.Blinky.x] != 'm')
                Game.Blinky.y++;
            else if(Game.maze[Game.Blinky.y][Game.Blinky.x-1] != 'm')
                Game.Blinky.x--;
            else if(Game.maze[Game.Blinky.y-1][Game.Blinky.x] != 'm')
                Game.Blinky.y--;
        }

        if(Game.PacMan.x < Game.Blinky.x && Game.PacMan.y <= Game.Blinky.y){
            if(Game.maze[Game.Blinky.y+1][Game.Blinky.x] != 'm')
                Game.Blinky.y++;
            else if(Game.maze[Game.Blinky.y][Game.Blinky.x-1] != 'm')
                Game.Blinky.x--;
            else if(Game.maze[Game.Blinky.y-1][Game.Blinky.x] != 'm')
                Game.Blinky.y--;
            else if(Game.maze[Game.Blinky.y][Game.Blinky.x+1] != 'm')
                Game.Blinky.x++;
        }

        if(Game.PacMan.x <= Game.Blinky.x && Game.PacMan.y > Game.Blinky.y){
            if(Game.maze[Game.Blinky.y][Game.Blinky.x-1] != 'm')
                Game.Blinky.x--;
            else if(Game.maze[Game.Blinky.y-1][Game.Blinky.x] != 'm')
                Game.Blinky.y--;
            else if(Game.maze[Game.Blinky.y][Game.Blinky.x+1] != 'm')
                Game.Blinky.x++;
            else if(Game.maze[Game.Blinky.y+1][Game.Blinky.x] != 'm')
                Game.Blinky.y++;
        }
        //Pinky tenta di capire dove sarà tra 4 mosse
        position predictedPacManPos = Game.PacMan;

        switch (input) {
            case 'w': {
                predictedPacManPos.y -= 4;
                break;
            }
            case 's': {
                predictedPacManPos.y += 4;
                break;
            }
            case 'a': {
                predictedPacManPos.x -= 4;
                break;
            }
            case 'd': {
                predictedPacManPos.x += 4;
                break;
            }
            case (GetAsyncKeyState(VK_UP)): {
                predictedPacManPos.y -= 4;
                break;
            }
            case (GetAsyncKeyState(VK_DOWN)): {
                predictedPacManPos.y += 4;
                break;
            }
            case (GetAsyncKeyState(VK_LEFT)): {
                predictedPacManPos.x -= 4;
                break;
            }
            case (GetAsyncKeyState(VK_RIGHT)): {
                predictedPacManPos.x += 4;
                break;
            }
        }

        if(predictedPacManPos.x > Game.Pinky.x && predictedPacManPos.y >= Game.Pinky.y){
            if(Game.maze[Game.Pinky.y-1][Game.Pinky.x] != 'm')
                Game.Pinky.y--;
            else if(Game.maze[Game.Pinky.y][Game.Pinky.x+1] != 'm')
                Game.Pinky.x++;
            else if(Game.maze[Game.Pinky.y+1][Game.Pinky.x] != 'm')
                Game.Pinky.y++;
            else if(Game.maze[Game.Pinky.y][Game.Pinky.x-1] != 'm')
                Game.Pinky.x--;
        }

        if(predictedPacManPos.x >= Game.Pinky.x && predictedPacManPos.y < Game.Pinky.y){
            if(Game.maze[Game.Pinky.y][Game.Pinky.x+1] != 'm')
                Game.Pinky.x++;
            else if(Game.maze[Game.Pinky.y+1][Game.Pinky.x] != 'm')
                Game.Pinky.y++;
            else if(Game.maze[Game.Pinky.y][Game.Pinky.x-1] != 'm')
                Game.Pinky.x--;
            else if(Game.maze[Game.Pinky.y-1][Game.Pinky.x] != 'm')
                Game.Pinky.y--;
        }

        if(predictedPacManPos.x < Game.Pinky.x && predictedPacManPos.y <= Game.Pinky.y){
            if(Game.maze[Game.Pinky.y+1][Game.Pinky.x] != 'm')
                Game.Pinky.y++;
            else if(Game.maze[Game.Pinky.y][Game.Pinky.x-1] != 'm')
                Game.Pinky.x--;
            else if(Game.maze[Game.Pinky.y-1][Game.Pinky.x] != 'm')
                Game.Pinky.y--;
            else if(Game.maze[Game.Pinky.y][Game.Pinky.x+1] != 'm')
                Game.Pinky.x++;
        }

        if(predictedPacManPos.x <= Game.Pinky.x && predictedPacManPos.y > Game.Pinky.y){
            if(Game.maze[Game.Pinky.y][Game.Pinky.x-1] != 'm')
                Game.Pinky.x--;
            else if(Game.maze[Game.Pinky.y-1][Game.Pinky.x] != 'm')
                Game.Pinky.y--;
            else if(Game.maze[Game.Pinky.y][Game.Pinky.x+1] != 'm')
                Game.Pinky.x++;
            else if(Game.maze[Game.Pinky.y+1][Game.Pinky.x] != 'm')
                Game.Pinky.y++;
        }
        //Inky mira a una posizione che è due volte la distanza da Blinky alla posizione che sarebbe quattro passi avanti a Pac-Man nella direzione in cui Pac-Man sta attualmente andando
        position targetPosition;
        targetPosition.x = 2 * predictedPacManPosition.x - Game.Blinky.x;
        targetPosition.y = 2 * predictedPacManPosition.y - Game.Blinky.y;

        if(targetPosition.x > Game.Inky.x && targetPosition.y >= Game.Inky.y){
            if(Game.maze[Game.Inky.y-1][Game.Inky.x] != 'm')
                Game.Inky.y--;
            else if(Game.maze[Game.Inky.y][Game.Inky.x+1] != 'm')
                Game.Inky.x++;
            else if(Game.maze[Game.Inky.y+1][Game.Inky.x] != 'm')
                Game.Inky.y++;
            else if(Game.maze[Game.Inky.y][Game.Inky.x-1] != 'm')
                Game.Inky.x--;
        }

        if(targetPosition.x >= Game.Inky.x && targetPosition.y < Game.Inky.y){
            if(Game.maze[Game.Inky.y][Game.Inky.x+1] != 'm')
                Game.Inky.x++;
            else if(Game.maze[Game.Inky.y+1][Game.Inky.x] != 'm')
                Game.Inky.y++;
            else if(Game.maze[Game.Inky.y][Game.Inky.x-1] != 'm')
                Game.Inky.x--;
            else if(Game.maze[Game.Inky.y-1][Game.Inky.x] != 'm')
                Game.Inky.y--;
        }

        if(targetPosition.x < Game.Inky.x && targetPosition.y <= Game.Inky.y){
            if(Game.maze[Game.Inky.y+1][Game.Inky.x] != 'm')
                Game.Inky.y++;
            else if(Game.maze[Game.Inky.y][Game.Inky.x-1] != 'm')
                Game.Inky.x--;
            else if(Game.maze[Game.Inky.y-1][Game.Inky.x] != 'm')
                Game.Inky.y--;
            else if(Game.maze[Game.Inky.y][Game.Inky.x+1] != 'm')
                Game.Inky.x++;
        }

        if(targetPosition.x <= Game.Inky.x && targetPosition.y > Game.Inky.y){
            if(Game.maze[Game.Inky.y][Game.Inky.x-1] != 'm')
                Game.Inky.x--;
            else if(Game.maze[Game.Inky.y-1][Game.Inky.x] != 'm')
                Game.Inky.y--;
            else if(Game.maze[Game.Inky.y][Game.Inky.x+1] != 'm')
                Game.Inky.x++;
            else if(Game.maze[Game.Inky.y+1][Game.Inky.x] != 'm')
                Game.Inky.y++;

        }
        //Clyde si muove a caso se si trova ad una distanza <= di 8 celle da Pacman, altrimenti fa come Blinky
        if(abs(Game.PacMan.x - Game.Clyde.x)>8 && abs(Game.PacMan.y - Game.Clyde.y)>8) {
            if(Game.PacMan.x > Game.Clyde.x && Game.PacMan.y >= Game.Clyde.y){
                if(Game.maze[Game.Clyde.y-1][Game.Clyde.x] != 'm')
                    Game.Clyde.y--;
                else if(Game.maze[Game.Clyde.y][Game.Clyde.x+1] != 'm')
                    Game.Clyde.x++;
                else if(Game.maze[Game.Clyde.y+1][Game.Clyde.x] != 'm')
                    Game.Clyde.y++;
                else if(Game.maze[Game.Clyde.y][Game.Clyde.x-1] != 'm')
                    Game.Clyde.x--;
            }

            if(Game.PacMan.x >= Game.Clyde.x && Game.PacMan.y < Game.Clyde.y){
                if(Game.maze[Game.Clyde.y][Game.Clyde.x+1] != 'm')
                    Game.Clyde.x++;
                else if(Game.maze[Game.Clyde.y+1][Game.Clyde.x] != 'm')
                    Game.Clyde.y++;
                else if(Game.maze[Game.Clyde.y][Game.Clyde.x-1] != 'm')
                    Game.Clyde.x--;
                else if(Game.maze[Game.Clyde.y-1][Game.Clyde.x] != 'm')
                    Game.Clyde.y--;
            }

            if(Game.PacMan.x < Game.Clyde.x && Game.PacMan.y <= Game.Clyde.y){
                if(Game.maze[Game.Clyde.y+1][Game.Clyde.x] != 'm')
                    Game.Clyde.y++;
                else if(Game.maze[Game.Clyde.y][Game.Clyde.x-1] != 'm')
                    Game.Clyde.x--;
                else if(Game.maze[Game.Clyde.y-1][Game.Clyde.x] != 'm')
                    Game.Clyde.y--;
                else if(Game.maze[Game.Clyde.y][Game.Clyde.x+1] != 'm')
                    Game.Clyde.x++;
            }

            if(Game.PacMan.x <= Game.Clyde.x && Game.PacMan.y > Game.Clyde.y){
                if(Game.maze[Game.Clyde.y][Game.Clyde.x-1] != 'm')
                    Game.Clyde.x--;
                else if(Game.maze[Game.Clyde.y-1][Game.Clyde.x] != 'm')
                    Game.Clyde.y--;
                else if(Game.maze[Game.Clyde.y][Game.Clyde.x+1] != 'm')
                    Game.Clyde.x++;
                else if(Game.maze[Game.Clyde.y+1][Game.Clyde.x] != 'm')
                    Game.Clyde.y++;
            }
        }
        else updateClydePosition(&Game);
    }//fine while
    // Verifica se Pac-Man ha raccolto un punto e aggiorna il punteggio + se tutti i puntini sono spariti rimettere i puntini
    if(Game.maze[Game.PacMan.y][Game.PacMan.x] == DOT){
        Game.score++;
        Game.maze[Game.PacMan.y][Game.PacMan.x] = ' ';
        Game.countDots--;
        if(Game.countDots == 0){
            for (int i = 0; i < HEIGHT; i++) {
                for (int j = 0; j < WIDTH; j++) {
                    if(Game.maze[i][j] == ' ')
                        Game.maze[i][j] == '.';
                }
            }
        }
    }
    //ciliegia
    if(Game.score == 70 || Game.score == 170){
        spawnCherry(&Game);
    }

    // Verifica se Pac-Man è stato catturato da un fantasma

    //Togliere vite

}

void updateClydePosition(game *game) {
    srand(time(0));
    int direction;
    bool validMove = 0;

    while (!validMove) {
        direction = rand() % 4;

        switch (direction) {
            case 0: // Su
                if (game->maze[game->Clyde.y - 1][game->Clyde.x] != 'm') {
                    game->Clyde.y--;
                    validMove = 1;
                }
                break;
            case 1: // Giù
                if (game->maze[game->Clyde.y + 1][game->Clyde.x] != 'm') {
                    game->Clyde.y++;
                    validMove = 1;
                }
                break;
            case 2: // Sinistra
                if (game->maze[game->Clyde.y][game->Clyde.x - 1] != 'm') {
                    game->Clyde.x--;
                    validMove = 1;
                }
                break;
            case 3: // Destra
                if (game->maze[game->Clyde.y][game->Clyde.x + 1] != 'm') {
                    game->Clyde.x++;
                    validMove = 1;
                }
                break;
        }
    }
}

void spawnCherry(game *Game) {
    cherryActive = 1;
    cherrySpawnTime = time(NULL);//tempo in cui compare la ciliegia
    Game.Cherry.y = 17;
    Game.Cherry.x = 15;
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