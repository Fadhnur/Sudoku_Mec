#ifndef GameManager_HPP
#define GameManager_HPP

#include "Board.hpp"
#include "Player.hpp"
#include "Data.hpp"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>        //ambil srand()
#include <sstream>      //ambil to_string

using namespace std;

class GameManager {
private:
    Player p;
    Board brd;
    Data* data;
    int papan[9][9];

public:
    GameManager() {
        data = new Data();
    }

    ~GameManager() {
        delete data;
    }

    void initialization() {
        brd.initialization();
    }

    void setPlayer(Player& pl) {
        string uname;
        cout << "Masukkan nama = "; cin >> uname;
        cout << endl;
        pl.setUsername(uname);
    }

    Player getPlayer() {
        return p;
    }

    void setBoard() {
        int status = generateChallenge();

        if (status == 0) {
            brd.setBoardData(papan);
            int baris, kolom, angka;
            while (!brd.isFull()) {
                brd.initialization();   //memanggil header board dan mengambil fungsi initialization utk print board
                cout << "Masukkan baris, kolom, dan angka (0 untuk keluar)" << endl;
                cout << "Baris : "; cin >> baris;
                cout << "Kolom : "; cin >> kolom;
                cout << "Angka : "; cin >> angka;

                if (baris == 0 || kolom == 0) {
                    break;  //keluar dari permainan
                }

                if (brd.isValidCell(baris - 1, kolom - 1, angka)) {
                    brd.setCellValue(baris - 1, kolom - 1, angka);
                }
                else {
                    cout << "Angka sudah ada" << endl;
                }
            }
        }
        else {
            cout << "Gagal membaca data papan." << endl;
        }
    }

    Board getBoard() {
        return brd;
    }

    bool checkWin() {
        if (brd.isFull()) {
            cout << "Menang!" << endl;
            p.addWinCount();
            return true;
        }
        else {
            cout << "Kalah" << endl;
            return false;
        }
    }

    bool isValidMove(int baris, int kolom, int angka) {
        if (angka < 1 || angka > 9) {
            return false;
        }
        return brd.isValidCell(baris, kolom, angka);
    }

    void savePlayerData(Player p, string fileName) {
        data->savePlayerData(p, fileName);
    }

    void saveBoardData(const std::string& fileName) {
        std::ofstream file(fileName);

        if (file.is_open()) {
            // Menyimpan data papan permainan ke dalam file
            for (int i = 0; i < 9; ++i) {
                for (int j = 0; j < 9; ++j) {
                    int value = brd.getCellValue(i, j);
                    file << value << " ";
                }
                file << std::endl; // Pindah ke baris berikutnya
            }

            file.close();
            std::cout << "Data papan permainan telah disimpan ke dalam file " << fileName << std::endl;
        }
        else {
            std::cout << "Gagal membuka file " << fileName << std::endl;
        }
    }

    int generateChallenge() {
        srand(static_cast<unsigned int>(time(nullptr)));
        int randomFile = rand() % 9 + 1;
        string fileName = to_string(randomFile);
        string fullFileName = fileName + ".txt";
        return data->getBoardData(fullFileName, papan);
    }

    void play() {
        GameManager game;

        Player pemain;
        game.setPlayer(pemain);
        int status = generateChallenge();

        if (status == 0) {
            game.setBoard();
            game.initialization();
            bool winStatus = checkWin();

            if (winStatus) {
                cout << "Selamat, Anda menang!" << endl;
                game.saveBoardData("board.txt");    // Menyimpan papan permainan setelah pemain menang
            }
            else {
                cout << "Maaf, Anda kalah." << endl;
            }

            // Menyimpan data pemain
            string fileName = pemain.getUsername() + ".txt";
            savePlayerData(pemain, fileName);
        }
        else {
            cout << "Gagal menghasilkan tantangan." << endl;
        }


    }

};

#endif
