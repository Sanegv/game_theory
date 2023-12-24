#include "game.h"

Score** init_game(Score coopCoop, Score coopBet, Score betCoop, Score betBet){
    Score ** game = malloc(2*sizeof(Score*));

    for(int i = 0; i < 2; i++)
        game[i] = malloc(2*sizeof(Score));

    game[COOPERATE][COOPERATE] = coopCoop;
    game[COOPERATE][BETRAY] = coopBet;
    game[BETRAY][COOPERATE] = betCoop;
    game[BETRAY][BETRAY] = betBet;

    return game;
}

void printGame(Score** game){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            printf("| %d, %d |", game[i][j].playerA, game[i][j].playerB);
        }
        printf("\n");
    }
}

void freeGame(Score** game){
    for(int i = 0; i < 2; i++)
        free(game[i]);
    free(game);
}

Score playGame(Score** game, int (*strategyA) (Score**, int), int (*strategyB) (Score**, int), int* lastTurnA, int* lastTurnB){
    int a = strategyA(game, *lastTurnB);
    int b = strategyB(game, *lastTurnA);

    *lastTurnA = a;
    *lastTurnB = b;

    return game[a][b];
}

Score playGames(Score** game, int (*strategyA) (Score**, int), int (*strategyB) (Score**, int), int lastTurnA, int lastTurnB, int iterations){
    Score s = {0};
    Score tmp;

    int lastA = lastTurnA;
    int lastB = lastTurnB;

    for(int i = 0; i < iterations; i++){
        tmp = playGame(game, strategyA, strategyB, &lastTurnA, &lastTurnB);
        s.playerA += tmp.playerA;
        s.playerB += tmp.playerB;
    }

    return s;
}

void printScore(Score s){
    printf("Player A: %d\nPlayer B: %d\n", s.playerA, s.playerB);
}