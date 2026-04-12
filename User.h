#pragma once
#include <string>

class User {
protected:
    std::string name;

public:
    //constructor
    User(std::string userName);

    //honestly, I dont get the polyphormism concept, but that`s why the virtual is there
    virtual void displayProfile();

    std::string getName();
};
