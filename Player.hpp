#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>

using namespace std;

class Player {
private:
    string username;
    int WinCount;

public:
    Player();
    Player(string uname, int WinCounter);

    void setUsername(string name);
    string getUsername();
    void addWinCount();
    int getWinCount();
};

#endif