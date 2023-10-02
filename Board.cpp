#include <iostream>
#include "Board.hpp"
#include "GameManager.hpp"
#include "Data.hpp"
#include <vector>

using namespace std;

Board::Board() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cell[i][j] = 0;
        }
    }
}

void Board::setBoardData(const int data[9][9]) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            setCellValue(i, j, data[i][j]);
        }
    }
}

void Board::initialization() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            int num = getCellValue(i, j);
            if (num != 0) {
                cout << num << " ";
            }
            else {
                cout << ". ";
            }

            if (j == 2 || j == 5) {
                cout << "| ";
            }
        }
        cout << endl;

        if (i == 2 || i == 5) {
            cout << "------+-------+------" << endl;
        }
    }
    cout << endl;
}

void Board::setCellValue(int baris, int kolom, int value) {
    cell[baris][kolom] = value;
}

int Board::getCellValue(int baris, int kolom) {
    return cell[baris][kolom];
}

bool Board::isValidCell(int baris, int kolom, int value) {
    // Memeriksa baris dan kolom
    for (int i = 0; i < 9; ++i) {
        if (cell[baris][i] == value || cell[i][kolom] == value) {
            return false;
        }
    }

    // Memeriksa kotak 3x3
    int startRow = baris / 3 * 3;
    int startCol = kolom / 3 * 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (cell[startRow + i][startCol + j] == value) {
                return false;
            }
        }
    }
    return true;
}

bool Board::checkHorizontal(int baris) {
    bool used[10] = { false };
    for (int i = 0; i < 9; ++i) {
        int num = getCellValue(baris, i);
        if (num != 0) {
            if (used[num]) {
                return false;
            }
            used[num] = true;
        }
    }
    return true;
}

bool Board::checkVertical(int kolom) {
    bool used[10] = { false };
    for (int i = 0; i < 9; ++i) {
        int num = getCellValue(i, kolom);
        if (num != 0) {
            if (used[num]) {
                return false;
            }
            used[num] = true;
        }
    }
    return true;
}

bool Board::checkRegion(int index) {
    int startBaris = (index / 3) * 3;
    int startKolom = (index % 3) * 3;
    bool used[10] = { false };
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int num = getCellValue(startBaris + i, startKolom + j);
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

bool Board::isFull() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (cell[i][j] == 0) {
                return false;
            }
        }

        if (!checkHorizontal(i) || !checkRegion(i) || !checkVertical(i)) {
            return false;
        }
    }
    return true;
}