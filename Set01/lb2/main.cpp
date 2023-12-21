/*CSCI 200: Set 1: Lab 2 - Number classification
*
* Author Gabe Berta
* Resources used; Class slides
*
* This program prompts for a random set of max and min values then generates a random value in that range, which it then defines its location in the range.
*/

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main(){

    
    int userChoiceMinimum, userChoiceMaximum, temp;
    float randomNum, quar1, quar2, quar3;
    char text[1] = "";
    char test[2] = "y";
    
    cout << "Choose a maximum value." << endl;
    cin >> userChoiceMaximum;
    cout << "Choose a minimum value" << endl;
    cin >> userChoiceMinimum;
    temp = userChoiceMaximum;
    quar2 = (userChoiceMaximum + userChoiceMinimum)/2;
    quar1 = (userChoiceMinimum + quar2)/2;
    quar3 = (userChoiceMaximum + quar2)/2;

        srand( time(0) );
        rand();
        randomNum = rand() / (double)RAND_MAX * (userChoiceMaximum - userChoiceMinimum) + userChoiceMinimum;          
    do {


        cout << randomNum << endl;

    

        if (randomNum <= quar1) {
            cout << "Value is in the first quartile." << endl;
        } else if (randomNum > quar1 && randomNum <= quar2) {
            cout << "Value is in the second quartile" << endl;
        } else if (randomNum > quar2 && randomNum <= quar3) {
            cout << "Value is in the third quartile" << endl;
        } else if (randomNum > quar3) {
            cout << "Value is in the fourth quartile" << endl;
        } cout << "Would you like a new number? (Y/N)" << endl;
        cin >> text;
        randomNum = rand() / (double)RAND_MAX * (temp - userChoiceMinimum) + userChoiceMinimum;         
    }while (strcmp(text, test) == 0);
}