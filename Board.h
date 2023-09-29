
class Board{
	private:
		int cells [9][9];
			
	public:
		Board();
		void initialization();
		void setCellValue(int x, int y, int value);
		void getCellValue(int x, int y);
		bool isValidCell();
		bool isFull();
		bool checkVertical(int index);
		bool checkHorizontal(int index);
		bool checkRegion(int index);
};
