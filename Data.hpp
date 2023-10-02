#ifndef DATA_HPP
#define DATA_HPP

#include <string>

#include "Player.hpp"
#include "Board.hpp"


class Data {
public:
    Player getPlayerData(string file_address);
    void savePlayerData(Player p, string fileName);
    int getBoardData(string file_address, int data[9][9]);
};

#endif