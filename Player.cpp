#include "Player.h"
#include <iostream>

using namespace std;

//constructor - passes from player to user as well
Player::Player(string userName) : User(userName) {
    score = 0; 
}

void Player::addPoints(int points) {
    score += points;
}

int Player::getScore() {
    return score;
}

//POLYMORPHISM = override the base displayProfile to show the score too!
void Player::displayProfile() {
    cout << "Player: " << name << " | Score: " << score << endl;
}
