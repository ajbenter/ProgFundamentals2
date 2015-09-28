#include <iostream>
using namespace std;

class Piece
{
private:
	//Each 'piece' on the board has two components, which player it belongs to
	//(0 = no player, 1 = main player, 2 = second player/AI), and if that position
	//is where the cursor is.
	char player;
	bool isCursor;
    
public:
	//Constructors
	Piece(){this->player = '0'; this->isCursor = false;};
	Piece(char playerType){this->player = playerType; this->isCursor = false;};
    
	//Standard get and mutator methods
	virtual char getPlayer(){return this->player;};
	virtual void changePlayer(char newPlayer){this->player = newPlayer;};
	virtual bool cursor(){return isCursor;};
	virtual void changeCursor(bool arg){this->isCursor = arg;};
};

class Board
{
private:
    
	int cursor[2];
	int boardSize;
	Piece board[19][19];
	char cursorChar;
    
public:
	Board(int size);
	//~Board();
    
	virtual bool change(int row, int column, char player);
	virtual void changeCur(int row, int column);
	virtual bool checkWin(int rowStart, int columnStart, int winSize);
	virtual void printBoard();
};