#include "Data.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

Player Data::getPlayerData(string file_address){
    Player plyr;

    //membuka file 
    ifstream file(file_address);

    if(file.is_open()){
        string uname;
        int WinCounter;
        file >> uname >> WinCounter;
        plyr = Player(uname, WinCounter);
        
        file.close();
    }
    else{
        cout << "Gagal membuka file" << file_address << endl;
    }

    return plyr;
}

Board Data::getBoardData(string file_address){      //membaca soal dari file
    Board board;
    ifstream file(file_address);
    vector < vector<int>> papan;
    if(file.is_open()){
        for (int i = 0; i < 9; ++i) {    //menghitung banyak baris ke bawah
            vector<int>row;   //mencetak baris angka masuk ke dalam vector
            for (int j = 0; j < 9; ++j) {
                int num;
                file >> num;   //membaca angka dari file ke dalam variabel num (inputFile merupakan objek dari kelas ifstream)
                row.push_back(num); //menambah angka ke dalam vektor baris
            }
            papan.push_back(row);   //menambah baris ke dalam vektor papan
        }
        file.close();

        board.setBoardData(papan);
    }
    else{
        cout << "Gagal membuka file" << file_address << endl;
    }
    
    return board;
}

bool Data::operator==(const Data& other) const
{
    return false;
}
