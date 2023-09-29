#include <iostream>
#include <string>
using namespace std;

class Player{
    private :
    string username;
    int WinCount;

    public : 
    //Player();
    //Player(string uname, int WinCounter);
    void setUsername (string uname);
    string getUsername();
    void addWinCount();
    int getWinCount();
};
