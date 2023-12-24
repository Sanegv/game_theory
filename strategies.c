#include "strategies.h"

int totalScore(Score s){
    return s.playerA + s.playerB;
}

int alwaysCooperate(Score** values, int lastOpponentChoice, char player){
    return COOPERATE;
}

int alwaysBetray(Score** values, int lastOpponentChoice, char player){
    return BETRAY;
}

int random(Score** values, int lastOpponentChoice, char player){
    int i;
    (rand()%2) ? (i = COOPERATE) : (i = BETRAY);

    return i;
}

int doOpponentsLast(Score** values, int lastOpponentChoice, char player){
    return lastOpponentChoice;
}

int doOpponentsOpposite(Score** values, int lastOpponentChoice, char player){
    return !lastOpponentChoice;
}

int maximizeOutcome(Score** values, int lastOpponentChoice, char player){
    int maxI;
    int max = INT_MIN;

    switch (player){
        case 'a':
            for(int i = 0; i < 2; i++){
                if (totalScore(values[0][i]) > max){
                    max = totalScore(values[0][i]);
                    maxI = i;
                }
            }
            break;
        case 'b':
            for(int i = 0; i < 2; i++){
                if (totalScore(values[i][0]) > max){
                    max = totalScore(values[i][0]);
                    maxI = i;
                }
            }
            break;
        default:
            printf("Error: wrong player typ\n");
            exit(1);
    }

    return maxI;
}

int minimizeOutcome(Score** values, int lastOpponentChoice, char player){
    int minI;
    int min = INT_MAX;

    switch (player){
        case 'a':
            for(int i = 0; i < 2; i++){
                if (totalScore(values[0][i]) < min){
                    min = totalScore(values[0][i]);
                    minI = i;
                }
            }
            break;
        case 'b':
            for(int i = 0; i < 2; i++){
                if (totalScore(values[i][0]) < min){
                    min = totalScore(values[i][0]);
                    minI = i;
                }
            }
            break;
        default:
            printf("Error: wrong player typ\n");
            exit(1);
    }

    return minI;
}