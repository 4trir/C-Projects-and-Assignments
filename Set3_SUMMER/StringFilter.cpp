#include "StringFilter.h"
#include<iomanip>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

StringFilter::StringFilter(){
    

}

void StringFilter::addWords(vector<string> input) {
    uniqueWords.clear();
    int iterator = input.size();
    bool isUnique;
   

    for(int i = 0; i < iterator; i++)  {
        int uniqueIterator = uniqueWords.size();

        isUnique = false;
        for(int j = 0; j < uniqueIterator;) {
            if(input[i] == uniqueWords[j]) {
                isUnique = false;
                break;
                
                
            }else {
                isUnique = true;
            }
        
        }if(isUnique == true) {
            uniqueWords.push_back(input[i]);
            
        }
        totalWordCount++;
    }
    
    for(int i = 0; i < iterator; i++)  {
        int uniqueIterator = uniqueWords.size();
        int count = 0;
    for(int j = 0; j < uniqueIterator;) {
        if(input[i] == uniqueWords[j]) {
            count++;
        }
        wordCounts.push_back(count);
    }
    }
}

    








void StringFilter::printUniqueWordCounts(ostream& outStream) {
    int iterator = wordCounts.size();

    for(int i = 0; i < iterator; i++) {
        outStream << uniqueWords[i] << ": " << wordCounts[i] << endl;
        
    }

}
void StringFilter::printUniqueWordStats(ostream& outStream) {
    int iterator = wordCounts.size();
    for(int k = 0; k < iterator; k++) {
        outStream << wordCounts[k] << endl;
    }
}
vector<string> StringFilter::getUniqueWords() {
    return uniqueWords;

}