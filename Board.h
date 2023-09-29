#ifndef _BOARD
#define _BOARD

class Board{
	private:
		int cell [9][9];
			
	public:
		Board();
		void initialization();
		int setCellValue(int x, int y, int value);
		int getCellValue(int x, int y);
		int isValidCell(int x, int y, int value);
		bool isFull();
		bool checkVertical(int index);
		bool checkHorizontal(int index);
		bool checkRegion(int index);
};

#endif