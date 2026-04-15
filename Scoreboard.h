#pragma once
#include <vector>
#include <string>
#include "Player.h" 

class Scoreboard {
private:
    std::vector<Player> players;

public:
    Scoreboard();

    void addPlayer(Player p);

    void saveToFile(std::string filename);

    void displayLeaderboard();
};

