#ifndef GAME_THEORY_GAME_H
#define GAME_THEORY_GAME_H

#include <stdio.h>
#include <stdlib.h>
#include "strategies.h"

/**
 * @brief Returns a 2*2 array containing the values of all the outcomes
 * @param coopCoop both players cooperate
 * @param coopBet one player betrays the other
 * @param betCoop one player betrays the other
 * @param betBet both players betray
 * @return int**
 */
Score** init_game(Score coopCoop, Score coopBet, Score betCoop, Score betBet);

/**
 * @brief prints the grid of the outcomes
 * @param game
 */
void printGame(Score** game);

/**
 * @brief frees the necessary memory
 * @param game
 */
void freeGame(Score** game);

/**
 * @brief plays a game using strategy A against strategy B, and returns the outcome
 * @param game
 * @param strategyA
 * @param strategyB
 * @return
 */
Score playGame(Score** game,
               int (*strategyA) (Score**, int),
               int (*strategyB) (Score**, int),
               int lastTurnA,
               int lastTurnB);

void printScore(Score s);

#endif //GAME_THEORY_GAME_H