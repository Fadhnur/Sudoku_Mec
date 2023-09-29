#include "Board.h"
#include "Player.h"
#include "Data.h"
#include <iostream>

using namespace std;

class GameManager{
    private :
        Player p;    //memanggil class dan memiliki nama objek "p"
        Board brd;   //memanggil class dan memiliki nama objek "brd"
        Data data;

    public :
        GameManager(Player player, Board board);
        void initialization(){
            int baris, kolom, angka;
            while(!brd.IsFull()){
                brd.initialization();   //memanggil header board dan mengambil fungsi initialization utk print board
                cout <<"Masukkan baris, kolom, dan angka (0 untuk keluar)" <<endl;
                cout <<"Baris : "; cin >> baris;
                cout <<"Kolom : "; cin >> kolom;
                cout <<"Angka : "; cin >> angka;

                if(baris == 0 || kolom == 0){
                    break;  //keluar dari permainan
                }

                if(brd.IsValidCell(baris - 1, kolom - 1, angka)){
                    brd.setCellValue(baris -1, kolom - 1, angka);
                }
                else {
                    cout << "Angka sudah ada" << endl;
                }
            }
        }
        void setPlayer(Player player);
        Player getPlayer(){
            return getPlayerData();
        }
        void setBoard (Board board);
        Board getBoard(){
            return getBoardData();
        }
        bool checkWin(){
            if(brd.IsFull()){
                cout << "Menang!" << endl;
                p.getWinCount();
            }
            else {
                cout << "Kalah" << endl;
            }
        }
        void play(){
            getPlayer();
            getBoard();
            initialization();
            checkWin();
        }
        void savePlayerData();
        void saveBoardData();
        Board generateChallenge(){
            //random angka 1-9 lalu dari angka yang muncul, mengambil file sesuai angka yang muncul
            string fileName = rand() % 9;
            return getBoardData(filename);
        }
};

int main(){
    Player p1;
    Board br;

    GameManager game(p1, br);
    game.play();

    return 0;
}
