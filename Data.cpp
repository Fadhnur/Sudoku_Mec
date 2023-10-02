#include "Data.hpp"
#include "Board.hpp"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

Player Data::getPlayerData(string file_address) {
    Player plyr;
    ifstream file(file_address);

    if (file.is_open()) {
        string uname;
        int WinCounter;
        file >> uname >> WinCounter;
        plyr = Player(uname, WinCounter);
        file.close();
    }
    else {
        cout << "Gagal membuka file" << file_address << endl;
    }

    return plyr;
}

void Data::savePlayerData(Player p, string fileName) {
    ifstream file(fileName);

    if (file.is_open()) {
        string uname;
        int WinCounter;
        file >> uname >> WinCounter;
        file.close();

        ofstream outFile(fileName);

        if (outFile.is_open()) {
            outFile << p.getUsername() << " " << p.getWinCount() << endl;
            outFile.close();
        }
        else {
            cout << "Gagal membuka file " << fileName << endl;
        }
    }
    else {
        cout << "Gagal membuka file " << fileName << endl;
    }
}

int Data::getBoardData(string file_address, int data[9][9]) {
    ifstream file(file_address);

    if (file.is_open()) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                file >> data[i][j];
            }
        }
        file.close();
        return 0;
    }
    else {
        cout << "Gagal membuka file" << file_address << endl;
        return -1;
    }
}