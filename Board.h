
class Board{
	private:
		int cells [9][9]= {
		{1,2,0,0,0,7,9,5,0},
		{0,5,6,3,0,8,0,1,7},
		{3,4,7,0,0,9,6,8,0},
		{0,0,0,7,0,0,0,0,0},
		{0,0,0,0,8,0,0,0,5},
		{0,3,1,0,0,0,8,9,0},
		{0,0,4,9,5,0,0,0,0},
		{8,9,3,1,0,0,5,0,6},
		{0,0,2,0,3,6,7,0,9}};

		bool IsSudokuValid();
			
	public:
		Board();
		int getCellatCoordinate (int baris, int kolom);	//getNumber
        bool isCellAvailable (int baris, int kolom, int value);	//isMoveValid
		void setCellatCoordinate (int baris, int kolom, int value);	//placeNumber

		bool checkHorizontal (int index);	//
		bool checkVertikal (int index);
		bool checkRegional (int index);

		bool IsSolved();
		
		bool IsValidMove(int baris, int kolom, int value);



		void PrintBoard();
};
