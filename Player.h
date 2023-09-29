#ifndef _PLAYER
#define _PLAYER
#include <string>

class Player{
    private :
    string username;
    int WinCount;

    public : 
    Player();
    Player(string uname, int WinCounter);
    void setUsername (string uname);
    string getUsername();
    void addWinCount();
    int getWinCount();
};

#endif