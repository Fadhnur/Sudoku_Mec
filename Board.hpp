#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include "GameManager.hpp"

class Board{
	private:
		int cell[9][9];
		std::vector < std::vector<int>> papan;

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
		void setBoardData(const std::vector<std::vector<int>>& data);
};

#endif