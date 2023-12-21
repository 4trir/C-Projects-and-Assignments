/* CSCI 200: Assignment 2:Lab 2A  - The Secret Moosage
 *
 * Author: Gabe Berta
 * Resources used: class slides
 *
 *
 * This program deciphers a secret message and writes the result to a text file.
 *
 */

#include <iostream>
#include <fstream>

using namespace std;

int main(){
    char inputCharacter;
    ifstream secretMessage( "secretMessage.txt" );
    if (secretMessage.fail() ) {
        cerr << "Could not open \"secretMessage.txt\"" << endl;
        return -1;
    }
    
    ofstream deciphered( "decipheredMessage.txt" );
    while (secretMessage.get(inputCharacter)) {
      
        if (inputCharacter == '~') {
            deciphered << ' '; 
        }else if (inputCharacter == '\n') {
            deciphered << inputCharacter;
        }else {
            deciphered << (char)(inputCharacter + 1);
        }
    }
    secretMessage.close();
    deciphered.close();
    return 0;  
}
