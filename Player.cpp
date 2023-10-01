#include <iostream>
#include <string>
#include "Player.hpp" //memanggil header
using namespace std;

Player::Player() : username(""), WinCount(0) {
    
}

Player::Player(string uname, int WinCounter) : username(uname), WinCount(WinCounter){
    
}

void Player::setUsername(string name){
    username = name;
}

string Player::getUsername(){
    return username;
}

void Player::addWinCount(){
    WinCount++;
}
 
int Player::getWinCount(){
    return WinCount;
}