#include "Words.h" 
#include <iostream>
#include <fstream>   
#include <stdexcept> 
#include <cstdlib>   
#include <ctime>     

using namespace std; 

Words::Words() {
    srand(time(0)); //random number generator (I had a doubt about the random number being way bigger than the number of words)**
}



void Words::loadWords(string filename) {

ifstream wordsFile(filename);

//exception 
if (!wordsFile.is_open()) {
throw runtime_error("File could not be opened!");
}

string word; 

//it will get the words from the file and store in the word string (then add ot the vector)
while (getline(wordsFile, word)) {
listOfWords.push_back(word); 
}

wordsFile.close();
}


string Words::getRandomWord() {
    //**up there I was worried the number would be too big, but this one will get the remainder of the file words number, so if I increase, it will update automatically.
    int randomIndex = rand() % listOfWords.size();

    return listOfWords[randomIndex];
}
