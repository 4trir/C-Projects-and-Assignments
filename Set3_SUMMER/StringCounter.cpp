#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include "StringCounter.h"

using namespace std;

StringCounter::StringCounter(){
    // allWords = std::vector(<std::string> "");
    // letterCounts = 0;
    // totalLetterCount = 0;

}



void StringCounter::readAllWords(std::istream& filein, std::string x) {
    char character;
    string exceptLetters = x;
    string word;
    while (filein.get(character)) {
        if (exceptLetters.find(character) != std::string::npos) {
            if (!word.empty()) {
                allWords.push_back(word);
                word = "";
            }
        } else {
            if (character > 90) {
                character = character - 32;
            }
            word += character;
            if (character == ' ') {
                if (!word.empty() && word != " ") {
                    allWords.push_back(word);
                    word = "";
                }
            }
        }
    }

    if (!word.empty() && word != " ") {
        allWords.push_back(word);
    }
}

void StringCounter::printLetterCounts(std::ostream& outStream) {
    int iterator = allWords.size();
    string word = "";
    char letter = 'A';
    
    
    while(letter <= 'Z'){
        int tempCount(0), count(0);    
        for(int i = 0; i < iterator; i++) {
            word = allWords[i];
            tempCount = 0;
            int j = 0;
            while(word[j] != '\0') {
                char tempchar = word[j];

                if (tempchar == letter) {
                    tempCount++;

                }

                j++;
            }
            count += tempCount;
            
        }
        letterCounts.push_back(count);
        outStream << letter << ": " << count << endl; 
        letter++;
    }



}

void StringCounter::printLetterStats(std::ostream& outStream) {
    int individualCount = 0;
    int iterator = letterCounts.size();

    for(int i = 0; i < iterator; i++ ) {
        individualCount += letterCounts[i];
    }
    totalLetterCount = individualCount;

    int maxLetterCount = letterCounts[0], minLetterCount = letterCounts[0];
    int minPlace(0),maxPlace(0);

    //Max calc
    for(int j = 1; j < iterator; j++) {
        if(maxLetterCount < letterCounts[j]) {
            maxLetterCount = letterCounts[j];
            maxPlace = j - 1;
        }

    } 

    //Min calc
    for(int k = 1; k < iterator; k++) {
        if(minLetterCount > letterCounts[k]) {
            minLetterCount = letterCounts[k];
            minPlace = k - 1;
        }

    }
    
    double maxPercent(0), minPercent(0);

    maxPercent = (static_cast<double>(maxLetterCount) / totalLetterCount) * 100;
    minPercent = (static_cast<double>(minLetterCount) / totalLetterCount) * 100;
    
    vector<char> alphabet{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','W','T', 'U', 'V','W','X','Y','Z'};

        outStream << "Most Frequent Letter: " << alphabet[maxPlace + 1] << " " << maxLetterCount << " " << fixed << setprecision(2) << maxPercent << "%" << endl;
    outStream << "Least Frequent Letter: " << alphabet[minPlace + 1] << " " << minLetterCount << " " << fixed << setprecision(2) << minPercent << "%" << endl;
    


}

std::vector<std::string> StringCounter::getAllWords() {
    return allWords;

}