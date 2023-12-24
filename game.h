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
               int (*strategyA) (Score**, int, char),
               int (*strategyB) (Score**, int, char),
               int* lastTurnA,
               int* lastTurnB);

/**
 * @brief plays the specified amount of games using strategy A against strategy B, and returns the total outcome
 * @param game
 * @param strategyA
 * @param strategyB
 * @param lastTurnA
 * @param lastTurnB
 * @param iterations
 * @return
 */
Score playGames(Score** game,
               int (*strategyA) (Score**, int, char),
               int (*strategyB) (Score**, int, char),
               int lastTurnA,
               int lastTurnB,
               int iterations);

#endif //GAME_THEORY_GAME_H
