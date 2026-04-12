#pragma once
#include <string>
#include <vector>

//I just learned that using namespace std in a .h file can cause name conflicts in bigger files

class Words {
private:
    //the list will be hidden so its private
    std::vector<std::string> listOfWords;

public:
    //random words will be public to play the game itself
    Words();
    void loadWords(std::string filename);
    std::string getRandomWord();


};
