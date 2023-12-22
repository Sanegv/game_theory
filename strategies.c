#include "strategies.h"

int alwaysCooperate(Score** values, int lastOpponentChoice){
    return COOPERATE;
}

int alwaysBetray(Score** values, int lastOpponentChoice){
    return BETRAY;
}

int random(Score** values, int lastOpponentChoice){
    int i;
    (rand()%2) ? (i = COOPERATE) : (i = BETRAY);

    return i;
}