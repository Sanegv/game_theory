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
 * @brief returns the sum of the scores
 * @return int
 */
int totalScore(Score);

void printScore(Score s);

/**
 * @brief Always betrays, no matter the input
 * @param values
 * @param lastOpponentChoice
 * @return int
 */
int alwaysBetray(Score** values, int lastOpponentChoice, char player);

/**
 * @brief Always Cooperates, no matter the input
 * @param values
 * @param lastOpponentChoice
 * @return int
 */
int alwaysCooperate(Score** values, int lastOpponentChoice, char player);

/**
 * @brief Will randomly betray or cooperate, no matter the input
 * @param values
 * @param lastOpponentChoice
 * @return int
 */
int random(Score** values, int lastOpponentChoice, char player);

/**
 * @brief does what the opponent did last turn, ie, returns COOPERATE in case of a cooperation, BETRAY in case of betrayal
 * @param values
 * @param lastOpponentChoice
 * @return int
 */
int doOpponentsLast(Score** values, int lastOpponentChoice, char player);

/**
 * @brief returns COOPERATE if the opponent betrayed last turn, returns BETRAY if the opponent cooperated
 * @param values
 * @param lastOpponentChoice
 * @return int
 */
int doOpponentsOpposite(Score** values, int lastOpponentChoice, char player);

/**
 * @brief chooses the action that maximizes the total outcome of the game
 * @param values
 * @param lastOpponentChoice
 * @return int
 */
int maximizeGlobalOutcome(Score** values, int lastOpponentChoice, char player);

/**
 * @brief chooses the action that minimizes the total outcome of the game
 * @param values
 * @param lastOpponentChoice
 * @return int
 */
int minimizeGlobalOutcome(Score** values, int lastOpponentChoice, char player);

/**
 * @brief returns the value that could offer the greatest score for the player
 * @param values
 * @param lastOpponentChoice
 * @param player
 * @return int
 */
int maximizeSelfOutcome(Score** values, int lastOpponentChoice, char player);

/**
 * @brief returns the value that could offer the lowest score for the player
 * @param values
 * @param lastOpponentChoice
 * @param player
 * @return int
 */
int minimizeSelfOutcome(Score** values, int lastOpponentChoice, char player);

/**
 * @brief returns the value that could offer the greatest score for the other player
 * @param values
 * @param lastOpponentChoice
 * @param player
 * @return
 */
int maximizeOpponentOutcome(Score** values, int lastOpponentChoice, char player);

/**
 * @brief returns the value that could offer the lowest score for the other player
 * @param values
 * @param lastOpponentChoice
 * @param player
 * @return
 */
int minimizeOpponentOutcome(Score** values, int lastOpponentChoice, char player);

#endif //GAME_THEORY_STRATEGIES_H
