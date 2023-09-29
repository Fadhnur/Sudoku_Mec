#include <iostream>
#include "Player.h" //memanggil header
using namespace std;

Player :: Player(){     //tidak perlu menambahkan void
    username = " ";
    WinCount = 0;
}

Player :: Player(string uname, int WinCounter){
    username = uname;
    WinCount = WinCounter;
}

void Player :: setName(string name){
    username = name;
}

string Player ::getName(){
    return username;
}

void Player :: addWinCount(){
    WinCount++;
}

int Player :: getWinCount(){
    return WinCount;
}
