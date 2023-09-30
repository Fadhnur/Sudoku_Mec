#ifndef _PLAYER
#define _PLAYER
#include <string>

using namespace std;

class Player{
    private :
        string username;
        int WinCount;

    public : 
        player();
        player(string uname, int WinCounter);
        
        void setUsername(string name);
        string getUsername();
        void addWinCount();
        int getWinCount();
};

#endif