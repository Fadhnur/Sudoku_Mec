#include "Data.h"
#include <fstream>
#include <string>
#include <iostream>

Player Data :: getPlayerData(std::string file_address){
    Player player;

    //membuka file 
    std::ifstream file(file_address);

    if(file.is_open()){
        std::string uname;
        int WinCounter;
        file >> uname >> WinCounter;
        player = Player(uname,WinCounter);
        
        file.close();
    }
    else{
        std::cout<<"Gagal membuka file" << file_address << std::endl;
    }

    return player;
}

Board Data :: getBoardData(std::string file_address){
    Board board;

    std::ifstream file(file_address);
    
    if(file.is_open()){
        std::string filename;
        file >> filename;
        board = Board();

        file.close();
    }
    else{
        std::cout<<"Gagal membuka file" << file_address << std::endl;
    }
    
    return board;
}