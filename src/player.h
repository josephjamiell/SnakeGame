#ifndef PLAYER_H
#define PLAYER_H

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

class Player
{
    public:
    void ShowGreeting();
    void LoadScores();
    void Save();
    void SetScore(int score);
    int GetDifficulty() { return _difficulty;}
    std::string GetName() {return _name;}
    bool saved{false};

    private:
    const std::string saveFile{"../tscrs.txt"};
    std::map<std::string, int> topScores{};
    std::string _name{"NoName"};
    int _score{0};
    int _difficulty{1};
    bool _saved{false};
};

#endif