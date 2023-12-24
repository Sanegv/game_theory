#include "strategies.h"
#include "game.h"
#include <time.h>

int main(){
    time_t t;
    srand((unsigned) time(&t));

    Score** game = init_game(
            (Score){7,7},
            (Score){1, 10},
            (Score){10, 1},
            (Score){3, 3});

    printGame(game);

    int lastA = COOPERATE;
    int lastB = COOPERATE;

    Score s = playGame(game, minimizeOpponentOutcome, maximizeOpponentOutcome, &lastA, &lastB);
    printScore(s);

    freeGame(game);

    return 0;
}