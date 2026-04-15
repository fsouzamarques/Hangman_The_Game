#include "Scoreboard.h"
#include <iostream>
#include <fstream> 
#include <stdexcept>

using namespace std;

Scoreboard::Scoreboard() {
}

void Scoreboard::addPlayer(Player p) {
    players.push_back(p);
}

void Scoreboard::saveToFile(string filename) {

    ofstream outFile(filename, ios::app);

    if (!outFile.is_open()) {
        throw runtime_error("Could not open leaderboard file to save scores!");
    }

    //writing the name to the scoreboard
    for (int i = 0; i < players.size(); i++) {
        outFile << players[i].getName() << "," << players[i].getScore() << endl;
    }

    outFile.close();
}

//print the vector to the console
void Scoreboard::displayLeaderboard() {
    cout << "\n--- LEADERBOARD ---" << endl;

    if (players.empty()) {
        cout << "No scores yet!" << endl;
        return;
    }

    //loop to print in order of score
    for (int i = 0; i < players.size(); i++) {
        players[i].displayProfile();
    }
    cout << "-------------------\n" << endl;
}
