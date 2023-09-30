#ifndef _DATA
#define _DATA

#include <string>

#include "Player.hpp"
#include "Board.hpp"

class Data{
    public :
        Player getPlayerData(std::string file_address);
        Board getBoardData(std::string file_address);
};

#endif