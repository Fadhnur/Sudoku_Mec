#include <iostream>
#include "Player.h" //memanggil header
using namespace std;

void Player :: Player(string uname, int WinCounter){
    username = uname;
    WinCount = WinCounter;
}

void Player :: setUsername(string name){
    username = name;
}

string Player :: getUsername(){
    return username;
}

void Player :: addWinCount(){
    WinCount++;
}

int Player :: getWinCount(){
    return WinCount;
}
