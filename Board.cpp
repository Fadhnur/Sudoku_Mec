#include <iostream>
#include "Board.h"

using namespace std;

int Board :: getCellatCoordinate(int baris, int kolom){
    return cells[baris][kolom];
}

bool Board :: isCellAvailable(int baris, int kolom, int value){
    //memeriksa baris dan kolom
    for(int i = 0; i < 9; ++i){
        if(cells[baris][i] == value || cells[i][kolom] == value){
            return false;   //ada angka yang sama di baris atau kolom
        }
    }

    //periksa kotak 3x3
    int startRow = baris / 3 * 3;   //mencari koordinat x (baris)
    int startCol = kolom / 3 * 3;   //mencari koordinat y (kolom)
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (cells[startRow + i][startCol + j] == value) {     //array multidimensi [][] (koordinat pada satu kotak angka) memiliki nilai angka sama dengan "num"
                return false; // Ada angka yang sama di kotak 3x3 bernilai salah
            }
        }
    }

    return true; // Tidak ada angka yang sama di baris, kolom, atau kotak 3x3
}

void Board :: setCellatCoordinate(int baris, int kolom, int value){
    cells[baris][kolom] = value;    //menaruh angka pada koordinat
}

bool Board :: checkHorizontal(int baris){   //cek baris
    bool used[10] = {false};    //untuk angka 0-9, menggunakan elemen 0 untuk 0, elemen 1 untuk 1 dan seterusnya 
    for (int i = 0; i < 9; ++i){
        int num = Board::getCellatCoordinate(baris, i);
        if(num != 0){
            if(used[num]){
                return false;
            }
            used[num] = true;
        }
    }
    return true;
}

bool Board :: checkVertikal(int kolom){     //cek kolom
    bool used[10] = {false};    //untuk angka 0-9, menggunakan elemen 0 untuk 0, elemen 1 untuk 1 dan seterusnya 
    for (int i = 0; i < 9; ++i){
        int num = Board::getCellatCoordinate(i, kolom);
        if(num != 0){
            if(used[num]){
                return false;
            }
            used[num] = true;
        }
    }
    return true;
}

bool Board :: checkRegional(int index){
    int startBaris = (index / 3) * 3;
    int startKolom = (index % 3) * 3;

    for (int i = 0; i < 3; ++i) {
        bool used[10] = {false};
        for (int j = 0; j < 3; ++j) {
            int num = Board::getCellatCoordinate(startBaris + i, startKolom + j);
            if (num != 0) {
                if (used[num]) {
                    return false;
                }
                used[num] = true;
            }
        }
    }
    return true;
}

bool Board :: IsSolved(){
    for(int i = 0; i < 9; ++i){ //menghitung baris
        for(int j = 0; j < 9; ++j){ //menghitung kolom
            if(cells[i][j] == 0){
                return false; //ada sel yang kosong, papan belum selesai
            }
        }
    }
    return true; //sel terisi semua, papan selesai
}

void Board :: PrintBoard(){
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            int num = getCellatCoordinate(i,j);      //koordinat disimpan pada variabel num
            if (num != 0) {             
                cout << num << " ";    //mencetak angka dan spasi 
            }
            else {
                cout << ". ";          //mencetak dot(.) apabila angka bernilai 0
            }

            if (j == 2 || j == 5) {     //mencetak pembatas setelah index ke 2 atau 5 (secara kolom, agar menjadi kotak)
                cout << "| ";
            }
        }
        cout << endl;

        if (i == 2 || i == 5) {         //mencetak pembatas setelah index ke 2 atau 5 (secara baris, agar menjadi kotak)
            std::cout << "------+-------+------" << std::endl;
        }
    }
    cout << endl;
}

bool Board :: IsSudokuValid(){
    for(int i = 0; i < 9; ++i){
        if(!checkHorizontal(i) || !checkRegional(i) || !checkVertikal(i)){   //mengecek baris, kolom, dan region 
            return false;
        }
    }
    return true;
}

bool Board :: IsValidMove(int baris, int kolom, int value){
    if(value < 1 || value > 9){
        return false;   //apabila angka yang dimasukkan kurang dari 1 / lebih dari 9 maka nilainya salah 
    }
    //memeriksa apakah sel tersedia dengan memanggil isCellAvailable
    return Board::isCellAvailable(baris, kolom, value);  //keadaan benar dan dimasukkan pada cells
}
