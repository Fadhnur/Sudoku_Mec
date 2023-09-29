#include <iostream>
#include <string>
using namespace std;

class Player{
    private :
    string username;
    int WinCount;

    public : 
    Player();
    Player(string username, int WinCount);
    void setUsername (string uname);
    string getUsername();
    void addWinCount();
    int getWinCount();
};
