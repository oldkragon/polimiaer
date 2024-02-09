#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "game.h"
#include <SDL2/SDL.h>

#define WIDTH 28
#define HEIGHT 31
#define CELL_SIZE 20
#define CHERRY_POINTS 50
#define BONUS_POINTS 50
#define WALL 'm'
#define EMPTY ' '
#define DOT '.'
#define PACMAN 'p'
#define GHOST 'g'
#define CHERRY 'c'

//colorscheme pacman FFFF00 bg 1919A6 walls 2121DE

/*int main(){
    game Game;

    InitializeGame(Game);

    while (1){
        UpdateGame(Game);
        if (Game.lives == 0)
            break;
    }
    return 0;
}*/
void updateInkyPosition(game *game);
void updatePinkyPosition(game *game);
void updateBlinkyPosition(game *game);
void resetPacManPosition(game *Game);
void resetPinkyPosition(game *Game);
void resetInkyPosition(game *Game);
void resetBlinkyPosition(game *Game);
void resetClydePosition(game *Game);

void InitializeGame(game Game){
    char InitialMaze[HEIGHT][WIDTH] = {{'m', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm'},
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
            Game.maze[i][j] = InitialMaze[i][j];
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
    int cherryActive = 0;
    int cherrySpawnTime;
//aggiorna la posizione di pacman in base all'input
    switch (input){
        case 'w': {
            if(Game.maze[Game.PacMan.y-1][Game.PacMan.x] != 'm') {
                Game.PacMan.y--;
                break;
            }
        }
        case 's': {
            if(Game.maze[Game.PacMan.y+1][Game.PacMan.x] != 'm') {
                Game.PacMan.y++;
                break;
            }
        }
        case 'a': {
            if(Game.maze[Game.PacMan.y][Game.PacMan.x-1] != 'm') {
                Game.PacMan.x--;
                break;
            }
        }
        case 'd': {
            if(Game.maze[Game.PacMan.y][Game.PacMan.x+1] != 'm') {
                Game.PacMan.x++;
                break;
            }
        }
        case (GetAsyncKeyState(VK_UP)): {
            if(Game.maze[Game.PacMan.y-1][Game.PacMan.x] != 'm') {
                Game.PacMan.y--;
                break;
            }
        }
        case (GetAsyncKeyState(VK_DOWN)): {
            if(Game.maze[Game.PacMan.y+1][Game.PacMan.x] != 'm') {
                Game.PacMan.y++;
                break;
            }
        }
        case (GetAsyncKeyState(VK_LEFT)): {
            if(Game.maze[Game.PacMan.y][Game.PacMan.x-1] != 'm') {
                Game.PacMan.x--;
                break;
            }
        }
        case (GetAsyncKeyState(VK_RIGHT)): {
            if(Game.maze[Game.PacMan.y][Game.PacMan.x+1] != 'm') {
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
        targetPosition.x = 2 * predictedPacManPos.x - Game.Blinky.x;
        targetPosition.y = 2 * predictedPacManPos.y - Game.Blinky.y;

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
        //Clyde si muove a caso se si trova a una distanza <= di 8 celle da Pacman, altrimenti fa come Blinky
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
                        Game.maze[i][j] = '.';
                }
            }
        }
    }
    //ciliegia
    if(Game.score == 70 || Game.score == 170) {
        spawnCherry(&Game, cherryActive, cherrySpawnTime);
    }

    if(cherryActive == 1){
        int currTime = time(NULL);
        if(difftime(currTime, cherrySpawnTime)>=10){
            cherryActive = 0;
        }
    }

    int pacmanActive = 0;  //stato di Pac-Man (0 = normale, 1 = potenziato)
    time_t powerupStartTime;  //Pac-Man mangia una ciliegia

    if(cherryActive == 1 && Game.maze[Game.PacMan.y][Game.PacMan.x] == CHERRY) {
        pacmanActive = 1;
        Game.score += CHERRY_POINTS;
        powerupStartTime = time(NULL);  //tempo corrente
    }

    if (pacmanActive == 1) {
        time_t currentTime = time(NULL);
        if (difftime(currentTime, powerupStartTime) >= 15) {
            pacmanActive = 0;  //fine stato potenziato
        }
    }

    while (pacmanActive == 1){
        updateClydePosition(&Game);
        updateInkyPosition(&Game);
        updateBlinkyPosition(&Game);
        updatePinkyPosition(&Game);
    }
    // Verifica se Pac-Man è stato catturato da un fantasma
    if (Game.PacMan.x == Game.Clyde.x && Game.PacMan.y == Game.Clyde.y) {
        if (pacmanActive==1) {
            // Pacman mangia il fantasma
            Game.score += BONUS_POINTS;
            resetClydePosition(&Game.Clyde);
        } else {
            // Pacman perde una vita
            Game.lives--;
            if (Game.lives == 0) {
                //endGame();
            } else {
                resetPacManPosition(&Game.PacMan);
                resetClydePosition(&Game.Clyde);
            }
        }
    }

    if (Game.PacMan.x == Game.Pinky.x && Game.PacMan.y == Game.Pinky.y){
        if (pacmanActive==1) {
            Game.score += BONUS_POINTS;
            resetPinkyPosition(&Game.Pinky);
        } else {
            Game.lives--;
            if (Game.lives == 0) {
                //endGame();
            } else {
                resetPacManPosition(&Game.PacMan);
                resetPinkyPosition(&Game.Pinky);
            }
        }
    }

    if (Game.PacMan.x == Game.Inky.x && Game.PacMan.y == Game.Inky.y) {
        if (pacmanActive==1) {
            Game.score += BONUS_POINTS;
            resetInkyPosition(&Game.Inky);
        } else {
            Game.lives--;
            if (Game.lives == 0) {
                //endGame();
            } else {
                resetPacManPosition(&Game.PacMan);
                resetInkyPosition(&Game.Inky);
            }
        }
    }

    if (Game.PacMan.x == Game.Blinky.x && Game.PacMan.y == Game.Blinky.y) {
        if (pacmanActive==1) {
            Game.score += BONUS_POINTS;
            resetBlinkyPosition(&Game.Blinky);
        } else {
            Game.lives--;
            if (Game.lives == 0) {
                //endGame();
            } else {
                resetPacManPosition(&Game.PacMan);
                resetBlinkyPosition(&Game.Blinky);
            }
        }
    }
    //Togliere vite
}


void resetPacManPosition(game *Game){
    Game->PacMan.x = 15;
    Game->PacMan.y = 14;
}
void resetPinkyPosition(game *Game){
    Game->Pinky.x = 14;
    Game->Pinky.y = 14;

}
void resetInkyPosition(game *Game){
    Game->Inky.x = 14;
    Game->Inky.y = 14;

}
void resetBlinkyPosition(game *Game){
    Game->Blinky.x = 14;
    Game->Blinky.y = 14;
}
void resetClydePosition(game *Game){
    Game->Clyde.x = 14;
    Game->Clyde.y = 14;
}

void updateClydePosition(game *game) {
    srand(time(0));
    int direction;
    int validMove = 0;

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

void updateInkyPosition(game *game) {
    srand(time(0));
    int direction;
    int validMove = 0;

    while (!validMove) {
        direction = rand() % 4;

        switch (direction) {
            case 0: // Su
                if (game->maze[game->Inky.y - 1][game->Inky.x] != 'm') {
                    game->Inky.y--;
                    validMove = 1;
                }
                break;
            case 1: // Giù
                if (game->maze[game->Inky.y + 1][game->Inky.x] != 'm') {
                    game->Inky.y++;
                    validMove = 1;
                }
                break;
            case 2: // Sinistra
                if (game->maze[game->Inky.y][game->Inky.x - 1] != 'm') {
                    game->Inky.x--;
                    validMove = 1;
                }
                break;
            case 3: // Destra
                if (game->maze[game->Inky.y][game->Inky.x + 1] != 'm') {
                    game->Inky.x++;
                    validMove = 1;
                }
                break;
        }
    }
}

void updatePinkyPosition(game *game) {
    srand(time(0));
    int direction;
    int validMove = 0;

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
                if (game->maze[game->Pinky.y][game->Pinky.x + 1] != 'm') {
                    game->Pinky.x++;
                    validMove = 1;
                }
                break;
        }
    }
}

void updateBlinkyPosition(game *game) {
    srand(time(0));
    int direction;
    int validMove = 0;

    while (!validMove) {
        direction = rand() % 4;

        switch (direction) {
            case 0: // Su
                if (game->maze[game->Blinky.y - 1][game->Blinky.x] != 'm') {
                    game->Blinky.y--;
                    validMove = 1;
                }
                break;
            case 1: // Giù
                if (game->maze[game->Blinky.y + 1][game->Blinky.x] != 'm') {
                    game->Blinky.y++;
                    validMove = 1;
                }
                break;
            case 2: // Sinistra
                if (game->maze[game->Blinky.y][game->Blinky.x - 1] != 'm') {
                    game->Blinky.x--;
                    validMove = 1;
                }
                break;
            case 3: // Destra
                if (game->maze[game->Blinky.y][game->Blinky.x + 1] != 'm') {
                    game->Blinky.x++;
                    validMove = 1;
                }
                break;
        }
    }
}

void spawnCherry(game *Game, int cherryActive, int cherrySpawnTime) {
    cherryActive = 1;
    cherrySpawnTime = time(NULL);//tempo in cui compare la ciliegia
    Game->Cherry.y = 17;
    Game->Cherry.x = 15;
}



extern char maze[HEIGHT][WIDTH];

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
