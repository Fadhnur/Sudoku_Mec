#include <iostream>
#include "Board.hpp"
#include "Data.hpp"
#include <vector>

using namespace std;

Board::Board() {
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            cell[i][j] = 0;
        }
    }
}

void setBoardData(const std::vector<std::vector<int>>& data) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cell[i][j] = data[i][j];
        }
    }
}

void Board :: initialization(){     //print 
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            int num = getCellValue(i,j);      //koordinat disimpan pada variabel num
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

void Board :: setCellValue(int baris, int kolom, int value){
    cell[baris][kolom] = value;    //menaruh angka pada koordinat
}

int Board :: getCellValue(int baris, int kolom){
    return cell[baris][kolom];
}

bool Board :: isValidCell(int baris, int kolom, int value){
    Board brd;
    //memeriksa baris dan kolom
    for(int i = 0; i < 9; ++i){
        if(cell[baris][i] == value || cell[i][kolom] == value){
            return false;   //ada angka yang sama di baris atau kolom
        }
    }
   
    //periksa kotak 3x3
    int startRow = baris / 3 * 3;   //mencari koordinat x (baris)
    int startCol = kolom / 3 * 3;   //mencari koordinat y (kolom)
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (cell [startRow + i][startCol + j] == value) {     //array multidimensi [][] (koordinat pada satu kotak angka) memiliki nilai angka sama dengan "num"
                return false; // Ada angka yang sama di kotak 3x3 bernilai salah
            }
        }
    }
    return true; // Tidak ada angka yang sama di baris, kolom, atau kotak 3x3

}


bool Board :: checkHorizontal(int baris){   //cek baris
    Board brd;
    vector<bool> used(10, false);
    //bool used[10] = {false};    //untuk angka 0-9, menggunakan elemen 0 untuk 0, elemen 1 untuk 1 dan seterusnya 
    for (int i = 0; i < 9; ++i){
        int num = brd.getCellValue(baris, i);
        if(num != 0){
            if(used[num]){
                return false;
            }
            used[num] = true;
        }
    }
    return true;
}

bool Board :: checkVertical(int kolom){     //cek kolom
    Board brd;
    vector<bool> used(10, false);
    //bool used[10] = {false};    //untuk angka 0-9, menggunakan elemen 0 untuk 0, elemen 1 untuk 1 dan seterusnya 
    for (int i = 0; i < 9; ++i){
        int num = brd.getCellValue(i, kolom);
        if(num != 0){
            if(used[num]){
                return false;
            }
            used[num] = true;
        }
    }
    return true;
}

bool Board :: checkRegion(int index){
    Board brd;

    int startBaris = (index / 3) * 3;
    int startKolom = (index % 3) * 3;

    vector<bool> used(10, false);
    for (int i = 0; i < 3; ++i) {
        //bool used[10] = {false};
        for (int j = 0; j < 3; ++j) {
            int num = brd.getCellValue(startBaris + i, startKolom + j);
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

bool Board :: isFull(){     //sudoku selesai
    for(int i = 0; i < 9; ++i){ //menghitung baris
        for(int j = 0; j < 9; ++j){ //menghitung kolom
            if(cell[i][j] == 0){
                return false; //ada sel yang kosong, papan belum selesai
            }
        }

        if(!checkHorizontal(i) || !checkRegion(i) || !checkVertical(i)){   //mengecek baris, kolom, dan region 
            return false;
        }
    }
    return true; //sel terisi semua, papan selesai
}

