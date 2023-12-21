
#include "Die.h"

#include<ctime>
#include <cstdlib>

Die::Die()  {
    numSides = 6;
    
}

Die::Die(int sides) {
    
    if(sides > 1) {
        numSides = sides;
    }else {
        numSides = 6;
    }

}

int Die::getNumSides() {
    return numSides;
}

int Die::roll() {
    int numRoll = 0;
    numRoll = (rand() % (numSides) + 1);
    return numRoll;
}