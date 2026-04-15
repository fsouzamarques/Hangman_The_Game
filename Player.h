#pragma once
#include "User.h" //this will connect to the leaderboard so its a base class

class Player : public User { //inheritance
private:
    int score; 

public:
    //constructor
    Player(std::string userName);

    void addPoints(int points);
    int getScore();

    void displayProfile() override; //this is POLYMORPHISM
};
