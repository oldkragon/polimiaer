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


