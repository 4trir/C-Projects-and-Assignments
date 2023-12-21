//Lab  
// 
// 
// 
// 
// 

#include<iostream>
#include "Die.h"
#include "Player.h"
#include<ctime>



using namespace std;

int main() {
    srand(time(0));
    Player Character("Gandolf", 100, true, 3, 4 );
    Player Enemy("Balrog", 100, false, 3, 8);
    
    while(Enemy.isAlive() == true && Character.isAlive() == true){
        cout << Character.getPlayerName() << " attacks " << Enemy.getPlayerName()<< " dealing " << Character.attack(&Enemy) << " damage." << endl;
            if(Enemy.isAlive() == true) {
                cout << Enemy.getPlayerName() << " counterattacks " << Character.getPlayerName() << " dealing " << Enemy.attack(&Character) << " damage." << endl;
        
            }
    }if(Character.isAlive() == true) {
        cout << Character.getPlayerName() << " has vanquised " << Enemy.getPlayerName() << "." << endl;
    }else {
        cout << Enemy.getPlayerName() << " has vanquised " << Character.getPlayerName() << "." << endl;
    }
        
    return 0;
}