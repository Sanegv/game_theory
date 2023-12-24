#include "strategies.h"

int totalScore(Score s){
    return s.playerA + s.playerB;
}

void printScore(Score s){
    printf("Player A: %d\nPlayer B: %d\n", s.playerA, s.playerB);
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

int maximizeGlobalOutcome(Score** values, int lastOpponentChoice, char player){
    int maxI;
    int max = INT_MIN;

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            if(totalScore(values[i][j]) > max){
                max = totalScore(values[i][j]);
                switch (player) {
                    case 'a':
                        maxI = i;
                        break;
                    case 'b':
                        maxI = j;
                        break;
                    default:
                        printf("Error: wrong player type\n");
                        exit(1);
                }
            }
        }
    }
    return maxI;
}

int minimizeGlobalOutcome(Score** values, int lastOpponentChoice, char player){
    int minI;
    int min = INT_MAX;

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            if(totalScore(values[i][j]) < min){
                min = totalScore(values[i][j]);
                switch (player) {
                    case 'a':
                        minI = i;
                        break;
                    case 'b':
                        minI = j;
                        break;
                    default:
                        printf("Error: wrong player type\n");
                        exit(1);
                }
            }
        }
    }
    return minI;
}

int maximizeSelfOutcome(Score** values, int lastOpponentChoice, char player){
    int maxI;
    int max = INT_MIN;

    for(int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            switch (player) {
                case 'a':
                    if (values[i][j].playerA > max) {
                        max = values[i][j].playerA;
                        maxI = i;
                    }
                    break;
                case 'b':
                    if (values[i][j].playerB > max) {
                        max = values[i][j].playerB;
                        maxI = j;
                    }
                    break;
                default:
                    printf("Error: wrong player type\n");
                    exit(1);
            }
        }
    }

    return maxI;
}

int minimizeSelfOutcome(Score** values, int lastOpponentChoice, char player){
    int minI;
    int min = INT_MAX;

    for(int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            switch (player) {
                case 'a':
                    if (values[i][j].playerA < min) {
                        min = values[i][j].playerA;
                        minI = i;
                    }
                    break;
                case 'b':
                    if (values[i][j].playerB < min) {
                        min = values[i][j].playerB;
                        minI = j;
                    }
                    break;
                default:
                    printf("Error: wrong player type\n");
                    exit(1);
            }
        }
    }

    return minI;
}

int maximizeOpponentOutcome(Score** values, int lastOpponentChoice, char player){
    int maxI;
    int max = INT_MIN;

    for(int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            switch (player) {
                case 'a':
                    if (values[i][j].playerB > max) {
                        max = values[i][j].playerB;
                        maxI = i;
                    }
                    break;
                case 'b':
                    if (values[i][j].playerA > max) {
                        max = values[i][j].playerA;
                        maxI = j;
                    }
                    break;
                default:
                    printf("Error: wrong player type\n");
                    exit(1);
            }
        }
    }

    return maxI;
}

int minimizeOpponentOutcome(Score** values, int lastOpponentChoice, char player){
    int minI;
    int min = INT_MAX;

    for(int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            switch (player) {
                case 'a':
                    if (values[i][j].playerB < min) {
                        min = values[i][j].playerB;
                        minI = i;
                    }
                    break;
                case 'b':
                    if (values[i][j].playerA < min) {
                        min = values[i][j].playerA;
                        minI = j;
                    }
                    break;
                default:
                    printf("Error: wrong player type\n");
                    exit(1);
            }
        }
    }

    return minI;
}