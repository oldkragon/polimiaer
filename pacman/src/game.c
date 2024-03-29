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


void InitializeGame(game *Game) {
    char InitialMaze[HEIGHT][WIDTH] = {{'m', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm', 'm'},
                                       {'m', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 'm', 'm', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 'm'},
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
    Game->lives = 3;
    Game->score = 0;

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            Game->maze[i][j] = InitialMaze[i][j];
        }
    }

    Game->countDots = 0;

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (InitialMaze[i][j] == '.')
                Game->countDots++;
        }
    }

    Game->Pinky.x = 12;
    Game->Pinky.y = 14;

    Game->Blinky.x = 13;
    Game->Blinky.y = 14;

    Game->Inky.x = 14;
    Game->Inky.y = 14;

    Game->Clyde.x = 15;
    Game->Clyde.y = 14;

    Game->PacMan.x = 13;
    Game->PacMan.y = 13;

    Game->moveCounter = 0;
    Game->cherryActive = 0;
}

void UpdateGame(game *Game, const bool keys[SDL_NUM_SCANCODES]) {

//aggiorna la posizione di pacman in base all'input
    if (keys[SDL_SCANCODE_W]) {
        if (Game->maze[Game->PacMan.y - 1][Game->PacMan.x] != 'm') {
            Game->PacMan.y--;
        }
    }
    if (keys[SDL_SCANCODE_S]) {
        if (Game->maze[Game->PacMan.y + 1][Game->PacMan.x] != 'm') {
            Game->PacMan.y++;
        }
    }
    if (keys[SDL_SCANCODE_A]) {
        if (Game->maze[Game->PacMan.y][Game->PacMan.x - 1] != 'm') {
            Game->PacMan.x--;
        }
    }
    if (keys[SDL_SCANCODE_D]) {
        if (Game->maze[Game->PacMan.y][Game->PacMan.x + 1] != 'm') {
            Game->PacMan.x++;
        }
    }

    Game->moveCounter++;

    while (Game->moveCounter > 7) {
        //Blinky lo segue diretto - parte 7 mosse dopo
        if (Game->PacMan.x > Game->Blinky.x && Game->PacMan.y >= Game->Blinky.y) {
            if (Game->maze[Game->Blinky.y - 1][Game->Blinky.x] != 'm')
                Game->Blinky.y--;
            else if (Game->maze[Game->Blinky.y][Game->Blinky.x + 1] != 'm')
                Game->Blinky.x++;
            else if (Game->maze[Game->Blinky.y + 1][Game->Blinky.x] != 'm')
                Game->Blinky.y++;
            else if (Game->maze[Game->Blinky.y][Game->Blinky.x - 1] != 'm')
                Game->Blinky.x--;
        }

        if (Game->PacMan.x >= Game->Blinky.x && Game->PacMan.y < Game->Blinky.y) {
            if (Game->maze[Game->Blinky.y][Game->Blinky.x + 1] != 'm')
                Game->Blinky.x++;
            else if (Game->maze[Game->Blinky.y + 1][Game->Blinky.x] != 'm')
                Game->Blinky.y++;
            else if (Game->maze[Game->Blinky.y][Game->Blinky.x - 1] != 'm')
                Game->Blinky.x--;
            else if (Game->maze[Game->Blinky.y - 1][Game->Blinky.x] != 'm')
                Game->Blinky.y--;
        }

        if (Game->PacMan.x < Game->Blinky.x && Game->PacMan.y <= Game->Blinky.y) {
            if (Game->maze[Game->Blinky.y + 1][Game->Blinky.x] != 'm')
                Game->Blinky.y++;
            else if (Game->maze[Game->Blinky.y][Game->Blinky.x - 1] != 'm')
                Game->Blinky.x--;
            else if (Game->maze[Game->Blinky.y - 1][Game->Blinky.x] != 'm')
                Game->Blinky.y--;
            else if (Game->maze[Game->Blinky.y][Game->Blinky.x + 1] != 'm')
                Game->Blinky.x++;
        }

        if (Game->PacMan.x <= Game->Blinky.x && Game->PacMan.y > Game->Blinky.y) {
            if (Game->maze[Game->Blinky.y][Game->Blinky.x - 1] != 'm')
                Game->Blinky.x--;
            else if (Game->maze[Game->Blinky.y - 1][Game->Blinky.x] != 'm')
                Game->Blinky.y--;
            else if (Game->maze[Game->Blinky.y][Game->Blinky.x + 1] != 'm')
                Game->Blinky.x++;
            else if (Game->maze[Game->Blinky.y + 1][Game->Blinky.x] != 'm')
                Game->Blinky.y++;
        }
        //Pinky tenta di capire dove sarà tra 4 mosse
        position predictedPacManPos = Game->PacMan;

        if (keys[SDL_SCANCODE_W]) {
            predictedPacManPos.y -= 4;
        }
        if (keys[SDL_SCANCODE_S]) {
            predictedPacManPos.y += 4;
        }
        if (keys[SDL_SCANCODE_A]) {
            predictedPacManPos.x -= 4;
            break;
        }
        if (keys[SDL_SCANCODE_D]) {
            predictedPacManPos.x += 4;
            break;
        }

        if (predictedPacManPos.x > Game->Pinky.x && predictedPacManPos.y >= Game->Pinky.y) {
            if (Game->maze[Game->Pinky.y - 1][Game->Pinky.x] != 'm')
                Game->Pinky.y--;
            else if (Game->maze[Game->Pinky.y][Game->Pinky.x + 1] != 'm')
                Game->Pinky.x++;
            else if (Game->maze[Game->Pinky.y + 1][Game->Pinky.x] != 'm')
                Game->Pinky.y++;
            else if (Game->maze[Game->Pinky.y][Game->Pinky.x - 1] != 'm')
                Game->Pinky.x--;
        }

        if (predictedPacManPos.x >= Game->Pinky.x && predictedPacManPos.y < Game->Pinky.y) {
            if (Game->maze[Game->Pinky.y][Game->Pinky.x + 1] != 'm')
                Game->Pinky.x++;
            else if (Game->maze[Game->Pinky.y + 1][Game->Pinky.x] != 'm')
                Game->Pinky.y++;
            else if (Game->maze[Game->Pinky.y][Game->Pinky.x - 1] != 'm')
                Game->Pinky.x--;
            else if (Game->maze[Game->Pinky.y - 1][Game->Pinky.x] != 'm') {
                Game->Pinky.y--;
            }
        }

        if (predictedPacManPos.x < Game->Pinky.x && predictedPacManPos.y <= Game->Pinky.y) {
            if (Game->maze[Game->Pinky.y + 1][Game->Pinky.x] != 'm')
                Game->Pinky.y++;
            else if (Game->maze[Game->Pinky.y][Game->Pinky.x - 1] != 'm')
                Game->Pinky.x--;
            else if (Game->maze[Game->Pinky.y - 1][Game->Pinky.x] != 'm')
                Game->Pinky.y--;
            else if (Game->maze[Game->Pinky.y][Game->Pinky.x + 1] != 'm')
                Game->Pinky.x++;
        }

        if (predictedPacManPos.x <= Game->Pinky.x && predictedPacManPos.y > Game->Pinky.y) {
            if (Game->maze[Game->Pinky.y][Game->Pinky.x - 1] != 'm')
                Game->Pinky.x--;
            else if (Game->maze[Game->Pinky.y - 1][Game->Pinky.x] != 'm')
                Game->Pinky.y--;
            else if (Game->maze[Game->Pinky.y][Game->Pinky.x + 1] != 'm')
                Game->Pinky.x++;
            else if (Game->maze[Game->Pinky.y + 1][Game->Pinky.x] != 'm')
                Game->Pinky.y++;
        }
        //Inky mira a una posizione che è due volte la distanza da Blinky alla posizione che sarebbe quattro passi avanti a Pac-Man nella direzione in cui Pac-Man sta attualmente andando
        position targetPosition;
        targetPosition.x = 2 * predictedPacManPos.x - Game->Blinky.x;
        targetPosition.y = 2 * predictedPacManPos.y - Game->Blinky.y;

        if (targetPosition.x > Game->Inky.x && targetPosition.y >= Game->Inky.y) {
            if (Game->maze[Game->Inky.y - 1][Game->Inky.x] != 'm')
                Game->Inky.y--;
            else if (Game->maze[Game->Inky.y][Game->Inky.x + 1] != 'm')
                Game->Inky.x++;
            else if (Game->maze[Game->Inky.y + 1][Game->Inky.x] != 'm') {
                Game->Inky.y++;
            } else if (Game->maze[Game->Inky.y][Game->Inky.x - 1] != 'm')
                Game->Inky.x--;
        }

        if (targetPosition.x >= Game->Inky.x && targetPosition.y < Game->Inky.y) {
            if (Game->maze[Game->Inky.y][Game->Inky.x + 1] != 'm')
                Game->Inky.x++;
            else if (Game->maze[Game->Inky.y + 1][Game->Inky.x] != 'm')
                Game->Inky.y++;
            else if (Game->maze[Game->Inky.y][Game->Inky.x - 1] != 'm') {
                Game->Inky.x--;
            } else if (Game->maze[Game->Inky.y - 1][Game->Inky.x] != 'm')
                Game->Inky.y--;
        }

        if (targetPosition.x < Game->Inky.x && targetPosition.y <= Game->Inky.y) {
            if (Game->maze[Game->Inky.y + 1][Game->Inky.x] != 'm')
                Game->Inky.y++;
            else if (Game->maze[Game->Inky.y][Game->Inky.x - 1] != 'm')
                Game->Inky.x--;
            else if (Game->maze[Game->Inky.y - 1][Game->Inky.x] != 'm')
                Game->Inky.y--;
            else if (Game->maze[Game->Inky.y][Game->Inky.x + 1] != 'm')
                Game->Inky.x++;
        }

        if (targetPosition.x <= Game->Inky.x && targetPosition.y > Game->Inky.y) {
            if (Game->maze[Game->Inky.y][Game->Inky.x - 1] != 'm')
                Game->Inky.x--;
            else if (Game->maze[Game->Inky.y - 1][Game->Inky.x] != 'm')
                Game->Inky.y--;
            else if (Game->maze[Game->Inky.y][Game->Inky.x + 1] != 'm')
                Game->Inky.x++;
            else if (Game->maze[Game->Inky.y + 1][Game->Inky.x] != 'm')
                Game->Inky.y++;

        }
        //Clyde si muove a caso se si trova a una distanza <= di 8 celle da Pacman, altrimenti fa come Blinky
        if (abs(Game->PacMan.x - Game->Clyde.x) > 8 && abs(Game->PacMan.y - Game->Clyde.y) > 8) {
            if (Game->PacMan.x > Game->Clyde.x && Game->PacMan.y >= Game->Clyde.y) {
                if (Game->maze[Game->Clyde.y - 1][Game->Clyde.x] != 'm')
                    Game->Clyde.y--;
                else if (Game->maze[Game->Clyde.y][Game->Clyde.x + 1] != 'm')
                    Game->Clyde.x++;
                else if (Game->maze[Game->Clyde.y + 1][Game->Clyde.x] != 'm')
                    Game->Clyde.y++;
                else if (Game->maze[Game->Clyde.y][Game->Clyde.x - 1] != 'm')
                    Game->Clyde.x--;
            }

            if (Game->PacMan.x >= Game->Clyde.x && Game->PacMan.y < Game->Clyde.y) {
                if (Game->maze[Game->Clyde.y][Game->Clyde.x + 1] != 'm')
                    Game->Clyde.x++;
                else if (Game->maze[Game->Clyde.y + 1][Game->Clyde.x] != 'm') {
                    Game->Clyde.y++;
                } else if (Game->maze[Game->Clyde.y][Game->Clyde.x - 1] != 'm')
                    Game->Clyde.x--;
                else if (Game->maze[Game->Clyde.y - 1][Game->Clyde.x] != 'm')
                    Game->Clyde.y--;
            }

            if (Game->PacMan.x < Game->Clyde.x && Game->PacMan.y <= Game->Clyde.y) {
                if (Game->maze[Game->Clyde.y + 1][Game->Clyde.x] != 'm')
                    Game->Clyde.y++;
                else if (Game->maze[Game->Clyde.y][Game->Clyde.x - 1] != 'm')
                    Game->Clyde.x--;
                else if (Game->maze[Game->Clyde.y - 1][Game->Clyde.x] != 'm')
                    Game->Clyde.y--;
                else if (Game->maze[Game->Clyde.y][Game->Clyde.x + 1] != 'm')
                    Game->Clyde.x++;
            }

            if (Game->PacMan.x <= Game->Clyde.x && Game->PacMan.y > Game->Clyde.y) {
                if (Game->maze[Game->Clyde.y][Game->Clyde.x - 1] != 'm')
                    Game->Clyde.x--;
                else if (Game->maze[Game->Clyde.y - 1][Game->Clyde.x] != 'm')
                    Game->Clyde.y--;
                else if (Game->maze[Game->Clyde.y][Game->Clyde.x + 1] != 'm')
                    Game->Clyde.x++;
                else if (Game->maze[Game->Clyde.y + 1][Game->Clyde.x] != 'm')
                    Game->Clyde.y++;
            }
        } else updateClydePosition(Game);
    }//fine while
    // Verifica se Pac-Man ha raccolto un punto e aggiorna il punteggio + se tutti i puntini sono spariti rimettere i puntini
    if (Game->maze[Game->PacMan.y][Game->PacMan.x] == DOT) {
        Game->score++;
        Game->maze[Game->PacMan.y][Game->PacMan.x] = ' ';
        Game->countDots--;
        if (Game->countDots == 0) {
            for (int i = 0; i < HEIGHT; i++) {
                for (int j = 0; j < WIDTH; j++) {
                    if (Game->maze[i][j] == ' ')
                        Game->maze[i][j] = '.';
                }
            }
        }
    }
    //ciliegia
    if (Game->score == 70 || Game->score == 170) {
        spawnCherry(Game);
    }

    if (Game->cherryActive == 1) {
        int currTime = time(NULL);
        if (difftime(currTime, Game->cherrySpawnTime) >= 10) {
            Game->cherryActive = 0;
        }
    }

    int pacmanActive = 0;  //stato di Pac-Man (0 = normale, 1 = potenziato)
    time_t powerupStartTime;  //Pac-Man mangia una ciliegia

    if (Game->cherryActive == 1 && Game->maze[Game->PacMan.y][Game->PacMan.x] == CHERRY) {
        pacmanActive = 1;
        Game->score += CHERRY_POINTS;
        powerupStartTime = time(NULL);  //tempo corrente
    }

    if (pacmanActive == 1) {
        time_t currentTime = time(NULL);
        if (difftime(currentTime, powerupStartTime) >= 15) {
            pacmanActive = 0;  //fine stato potenziato
        }
    }

    while (pacmanActive == 1) {
        updateClydePosition(Game);
        updateInkyPosition(Game);
        updateBlinkyPosition(Game);
        updatePinkyPosition(Game);
    }
    // Verifica se Pac-Man è stato catturato da un fantasma
    if (Game->PacMan.x == Game->Clyde.x && Game->PacMan.y == Game->Clyde.y) {
        if (pacmanActive == 1) {
            // Pacman mangia il fantasma
            Game->score += BONUS_POINTS;
            resetClydePosition(Game);
        } else {
            // Pacman perde una vita
            Game->lives--;
            if (Game->lives == 0) {
                //endGame();
            } else {
                resetPacManPosition(Game);
                resetClydePosition(Game);
            }
        }
    }

    if (Game->PacMan.x == Game->Pinky.x && Game->PacMan.y == Game->Pinky.y) {
        if (pacmanActive == 1) {
            Game->score += BONUS_POINTS;
            resetPinkyPosition(Game);
        } else {
            Game->lives--;
            if (Game->lives == 0) {
                //endGame();
            } else {
                resetPacManPosition(Game);
                resetPinkyPosition(Game);
            }
        }
    }

    if (Game->PacMan.x == Game->Inky.x && Game->PacMan.y == Game->Inky.y) {
        if (pacmanActive == 1) {
            Game->score += BONUS_POINTS;
            resetInkyPosition(Game);
        } else {
            Game->lives--;
            if (Game->lives == 0) {
                //endGame();
            } else {
                resetPacManPosition(Game);
                resetInkyPosition(Game);
            }
        }
    }

    if (Game->PacMan.x == Game->Blinky.x && Game->PacMan.y == Game->Blinky.y) {
        if (pacmanActive == 1) {
            Game->score += BONUS_POINTS;
            resetBlinkyPosition(Game);
        } else {
            Game->lives--;
            if (Game->lives == 0) {
                //endGame();
            } else {
                resetPacManPosition(Game);
                resetBlinkyPosition(Game);
            }
        }
    }
    //Togliere vite
}


void resetPacManPosition(game *Game) {
    Game->PacMan.x = 13;
    Game->PacMan.y = 13;
}

void resetPinkyPosition(game *Game) {
    Game->Pinky.x = 12;
    Game->Pinky.y = 14;

}

void resetInkyPosition(game *Game) {
    Game->Inky.x = 13;
    Game->Inky.y = 14;

}

void resetBlinkyPosition(game *Game) {
    Game->Blinky.x = 14;
    Game->Blinky.y = 14;
}

void resetClydePosition(game *Game) {
    Game->Clyde.x = 15;
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

void spawnCherry(game *Game) {
    Game->cherryActive = 1;
    Game->cherrySpawnTime = time(NULL);//tempo in cui compare la ciliegia
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
            if (maze[i][j] == 'm') {
                SDL_Rect rect = {j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE};
                SDL_RenderFillRect(renderer, &rect);
            }
        }
    }
    SDL_RenderPresent(renderer);
}

void ShowEntities(SDL_Renderer *renderer, game *Game) {
    SDL_SetRenderDrawColor(renderer, 255, 240, 240, 255);
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (Game->maze[i][j] == '.') {
                SDL_Rect rect = {j * CELL_SIZE, i * CELL_SIZE, 5, 5};
                SDL_RenderFillRect(renderer, &rect);
            }
        }
    }

    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_Rect PacMan = {Game->PacMan.x * CELL_SIZE, Game->PacMan.y * CELL_SIZE, CELL_SIZE, CELL_SIZE};
    SDL_RenderFillRect(renderer, &PacMan);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_Rect Blinky = {Game->Blinky.x * CELL_SIZE, Game->Blinky.y * CELL_SIZE, CELL_SIZE, CELL_SIZE};
    SDL_RenderFillRect(renderer, &Blinky);

    SDL_SetRenderDrawColor(renderer, 255, 184, 255, 255);
    SDL_Rect Pinky = {Game->Pinky.x * CELL_SIZE, Game->Pinky.y * CELL_SIZE, CELL_SIZE, CELL_SIZE};
    SDL_RenderFillRect(renderer, &Pinky);

    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
    SDL_Rect Inky = {Game->Inky.x * CELL_SIZE, Game->Inky.y * CELL_SIZE, CELL_SIZE, CELL_SIZE};
    SDL_RenderFillRect(renderer, &Inky);

    SDL_SetRenderDrawColor(renderer, 255, 184, 82, 255);
    SDL_Rect Clyde = {Game->Clyde.x * CELL_SIZE, Game->Clyde.y * CELL_SIZE, CELL_SIZE, CELL_SIZE};
    SDL_RenderFillRect(renderer, &Clyde);

    if (Game->cherryActive) {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_Rect Cherry = {Game->Cherry.x * CELL_SIZE, Game->Cherry.y * CELL_SIZE, CELL_SIZE, CELL_SIZE};
        SDL_RenderFillRect(renderer, &Cherry);
    }

    SDL_RenderPresent(renderer);
}
