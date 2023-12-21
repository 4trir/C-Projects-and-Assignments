/* CSCI 200: Assignment 1: A1 - Rock Paper Scissor Throw Down!
 *
 * Author: Gabe Berta
 * Resources used: zybooks and class slides
 *
 *
 * This program has the player play rock paper scissors against a computer, the play choses one of the three options and the computer will generate a random response. 
 * The player can chose to replay and total number of wins, loses and ties are tracked and displayed at the end.
 */

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
/*Includes necassary libraries*/
using namespace std;

int main() {
    
    int compChoice, wins(0), losses(0), ties(0);
    /*declares computer choice, wins loses and ties as integers*/
    string userChoice, replay;

    do{
    /*Starts the do while loop*/
    srand(time(0));
    rand();
    /*Seeds the random number with the time and clears the first value (Should be seeded outside the loop but breaks my program?)*/
    cout << "Enter rock paper or scissors (r, p or s)" << endl;
    cin >> userChoice;
    if (userChoice == "r" || userChoice == "R"){
        cout << "Player picks Rock!" << endl;
        userChoice = "r";
        /*sets userchoice to lowercase value only*/
    } else if (userChoice == "p" || userChoice == "P") {
        cout << "Player picks Paper!" << endl;
        userChoice = "p";
    } else if (userChoice == "s" || userChoice == "S") {
        cout << "Player picks Scissors!" << endl;
        userChoice = "s";
    } else {
        cout << "That is not a valid repsonse." << endl;
        break;
    }
    /*Repeats what the player chose as a word*/
    compChoice = rand() % (2 - 0 + 1) + 0;
    /*Generates randome number, 1, 2 or 3*/

    if (compChoice == 0) {
        cout << "Computer picks Rock!" << endl;
        if (userChoice == "r"){
            cout << "Rock ties with Rock!" << endl;
            ties++;
            /*Prints result and increments ties*/
        } else if (userChoice == "p") {
            cout << "Paper beats Rock!" << endl;
            wins++;
        } else if (userChoice == "s") {
            cout << "Paper loses to Scissors!" << endl;
            losses++;
        }
        /*Logic for if computer picks rock*/
    } else if (compChoice == 1) {
        cout << "Computer picks Paper!" << endl;
        if (userChoice == "r"){
            cout << "Rock loses to Paper!" << endl;
            losses++;
        } else if (userChoice == "p") {
            cout << "Paper ties with Paper!" << endl;
            ties++;
        } else if (userChoice == "s") {
            cout << "Scissors beat Paper!" << endl;
            wins++;
        }
        /*Logic for if computer picks paper*/
    } else if ( compChoice == 2) {
        cout << "Computer picks Scissors!" << endl;
        if (userChoice == "r"){
            cout << "Rock beats Scissors!" << endl;
            wins++;
        } else if (userChoice == "p") {
            cout << "Paper loses to Scissors!" << endl;
            losses++;
        } else if (userChoice == "s") {
            cout << "Scissors ties with Scissors!" << endl;
            losses++;
        }
        /*Logic for if computer picks scissors*/
    } cout << "Would you like to play again? (Y/N)" << endl;
    cin >> replay;
    } while (replay == "y" || replay == "Y");
    cout << "Thanks for Playing!" << endl << "You won " << wins << " time(s), " << "Lost " << losses << " time(s), " << "and tied " << ties << " time(s)." << endl;
    return 0;
}