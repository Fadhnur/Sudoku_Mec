#ifndef DATA_HPP
#define DATA_HPP

#include <string>

#include "Player.hpp"
#include "Board.hpp"


class Data{
    public :
        Player getPlayerData(std::string file_address);
        Board getBoardData(std::string file_address);

        Data() = default;
        bool operator==(const Data& other) const;
};

#endif