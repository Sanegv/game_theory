#ifndef GAME_THEORY_STRATEGIES_H
#define GAME_THEORY_STRATEGIES_H

#include <stdio.h>
#include <stdlib.h>

#define COOPERATE 0
#define  BETRAY 1

/**
 * @brief Contains two ints:
 * @param playerA the score of the first player
 * @param playerB the score of the second player
 */
typedef struct score{
    int playerA;
    int playerB;
} Score;

/**
 * @brief Always Cooperates, no matter the input
 * @param values
 * @param lastOpponentChoice
 * @return
 */
int alwaysCooperate(Score** values, int lastOpponentChoice);

/**
 * @brief Always betrays, no matter the input
 * @param values
 * @param lastOpponentChoice
 * @return
 */
int alwaysBetray(Score** values, int lastOpponentChoice);

/**
 * @brief Will randomly betray or cooperate, no matter the input
 * @param values
 * @param lastOpponentChoice
 * @return
 */
int random(Score** values, int lastOpponentChoice);

#endif //GAME_THEORY_STRATEGIES_H