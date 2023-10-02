#ifndef BOARD_HPP
#define BOARD_HPP


class Board {
private:
    int cell[9][9];

public:
    Board();
    void initialization();
    void setCellValue(int x, int y, int value);
    int getCellValue(int x, int y);
    bool isValidCell(int baris, int kolom, int value);
    bool isFull();
    bool checkVertical(int kolom);
    bool checkHorizontal(int baris);
    bool checkRegion(int index);
    void setBoardData(const int data[9][9]);
};

#endif