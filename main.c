#include "strategies.h"
#include "game.h"
#include <time.h>

int main(){
    time_t t;
    srand((unsigned) time(&t));

    Score** game = init_game(
            (Score){5,5},
            (Score){1, 10},
            (Score){10, 1},
            (Score){3, 3});

    printGame(game);

    Score s = playGames(game, doOpponentsLast, alwaysBetray, COOPERATE, COOPERATE, 3);
    printScore(s);

    freeGame(game);

    return 0;
}