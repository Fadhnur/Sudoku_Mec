#include "Board.h"
#include "Player.h"
#include <iostream>

using namespace std;

class GameManager{
    private :
        Player p;
        Board brd;

    public :
        GameManager(Player plyr, Board brd);
        void setPlayer(Player player);
        Player getPlayer();
        void setBoard (Board brd);
        Board getBoard();

        void play(){
            int baris, kolom, angka;
            while(!brd.IsSolved()){
                brd.PrintBoard();   //memanggil header board dan mengambil fungsi PrintBoard
                cout <<"Masukkan baris, kolom, dan angka (0 untuk keluar)" <<endl;
                cout <<"Baris : "; cin >> baris;
                cout <<"Kolom : "; cin >> kolom;
                cout <<"Angka : "; cin >> angka;

                if(baris == 0 || kolom == 0){
                    break;  //keluar dari permainan
                }

                if(brd.IsValidMove(baris - 1, kolom - 1, angka)){
                    brd.setCellatCoordinate(baris -1, kolom - 1, angka);
                }
                else {
                    cout << "Angka sudah ada" << endl;
                }
            }
            if(brd.IsSolved()){
                cout << "Menang!" << endl;
            }
            else {
                cout << "Kalah" << endl;
            }
        }
        void save();
        void load();

        bool checkWin();
};

int main(){
    Player p1;
    Board br;

    GameManager game(p1, br);
    game.play();

    return 0;
}
