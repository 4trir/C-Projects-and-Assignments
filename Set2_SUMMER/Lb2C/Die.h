#ifndef DIE_H
#define DIE_H

class Die {
public:
    Die(); //Constructor

    Die(int sides); // Parameterized Constructor
    
    int getNumSides(); //Returns the number of sides on the die

    int roll(); //Simulates the the roll of the die

private:
    int numSides;
};

#endif