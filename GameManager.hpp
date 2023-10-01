#ifndef GameManager_HPP
#define GameManager_HPP

#include "Board.hpp"
#include "Player.hpp"
#include "Data.hpp"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

class GameManager{
    private :
        Player p;    //memanggil class dan memiliki nama objek "p"
        Board brd;   //memanggil class dan memiliki nama objek "brd"
        Data data;
        std::vector < std::vector<int>> papan;

    public :
        GameManager(){
            
        }

        void initialization(){      //mengubah file menjadi array
            brd.initialization();
        }

        void setPlayer(Player& pl){  //player input
            //meminta input data player
            string uname;
            cout << "Masukkan nama = "; cin >> uname;
            cout << endl;
            pl.setUsername(uname);
        }

        Player getPlayer(){ 
            return p;
        }

        void setBoard (){     //menyiapkan papan
            int baris, kolom, angka;
            while(!brd.isFull()){
                initialization();   //memanggil header board dan mengambil fungsi initialization utk print board
                cout <<"Masukkan baris, kolom, dan angka (0 untuk keluar)" <<endl;
                cout <<"Baris : "; cin >> baris;
                cout <<"Kolom : "; cin >> kolom;
                cout <<"Angka : "; cin >> angka;

                if(baris == 0 || kolom == 0){
                    break;  //keluar dari permainan
                }

                if(brd.isValidCell(baris - 1, kolom - 1, angka)){
                    brd.setCellValue(baris -1, kolom - 1, angka);
                }
                else {
                    cout << "Angka sudah ada" << endl;
                }
            }
        }

        Board getBoard(){
            return brd;
        }

        bool checkWin(){
            if(brd.isFull()){
                cout << "Menang!" << endl;
                p.addWinCount();
                return true;
            }
            else {
                cout << "Kalah" << endl;
                return false;
            }
        }

        bool isValidMove(int baris, int kolom, int angka){
            if(angka < 1 || angka > 9){
                return false;   //apabila angka yang dimasukkan kurang dari 1 / lebih dari 9 maka nilainya salah 
            }
            //memeriksa apakah sel tersedia dengan memanggil isCellAvailable
            return brd.isValidCell(baris, kolom, angka);  //keadaan benar dan dimasukkan pada cells
        }

        void savePlayerData(Player p, string fileName){   
            p = data.getPlayerData(fileName);

            ofstream file(fileName);
            if (file.is_open()) {
                // Tulis data pemain ke dalam file
                file << "Nama Pemain: " << p.getUsername() << endl;
                file << "Skor: " << p.getWinCount() << endl;
                // Tambahkan data lainnya sesuai kebutuhan
                file.close();
                cout << "Data pemain telah disimpan ke dalam file " << fileName << endl;
            } else {
                cout << "Gagal membuka file " << fileName << endl;
            } 
        }

        void saveBoardData();

        Board generateChallenge(){
            // Inisialisasi generator angka acak dengan waktu saat ini
            srand(static_cast<unsigned int>(time(nullptr)));

            //random angka 1-9 lalu dari angka yang muncul, mengambil file sesuai angka yang muncul
            int randomFile = rand() % 9 + 1;
            string fileName = to_string(randomFile);
            string fullFileName = fileName + ".txt";
            return data.getBoardData(fullFileName);
        }

        void play(){
            Player pemain;
            setPlayer(pemain);

            GameManager game;
            game.initialization();
            setBoard();
            //checkWin();
        }
};

#endif
