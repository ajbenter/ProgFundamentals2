#include "Board.h"
//#define "Board.h"

Board::Board(int boardSize)
{
	boardSize = 19;
	//Setting the cursor to the default position in the board
	this->cursor[0] = 0;
	this->cursor[1] = 0;
    
	//Setting each piece on the board to a default piece
	for(int x = 0; x < this->boardSize; x++)
	{
		for(int y = 0; y < this->boardSize; y++)
		{this->board[x][y] = Piece(); }
	}
    
	//The piece (zero, zero) on the board is the cursor
	this->board[cursor[0]][cursor[1]].changeCursor(true);
    
	//What the representation of the cursor is (to be used for later)
	this->cursorChar = '*';
}

bool Board::change(int row, int column, char player)
{
	//Convert the int value into a character
	char Player = player;
    
	//If this piece on the board is already taken by a player, don't change it!
	if(this->board[row][column].getPlayer() != '0')
	{cout << "Piece cannot be changed!" << endl; return false;}
    
	//Else, change the piece
	else{this->board[row][column].changePlayer(Player); return true;}
}

void Board::changeCur(int row, int column)
{
	if(this->board[row][column].cursor()){this->board[row][column].changeCursor(false);}
	else{this->board[row][column].changeCursor(true); this->cursor[0] = row; this->cursor[1] = column;}
}

bool Board::checkWin(int columnStart, int rowStart, int winSize)
{
	/*This method is a bit tricky. Essentially, it needs to check each cardinal direction for exacly 5 pieces consecutively owned
     by player who placed the piece at rowStart, columnStart. I believe the best format is as follows:
     2    3   4				These are the 4 'routes' you can win in. Go through 1 through 4, one after another.
     \  |  /				Use a while loop, end looping through the while loop once you hit a piece not owned by the owner of start.
     1-(start)-1				Keep in mind, the amount wins must be EXACTLY winSize. By default, winSize is 5.
     /  |  \
     4	 3   2
     */
    
	bool done = false;
	char thePlayer = this->board[columnStart][rowStart].getPlayer();
    
	while(!done)
	{
		//Travels west and east
		int west = columnStart;
		int east = columnStart + 1;
		int winCount = 0;
		while(this->board[west][rowStart].getPlayer() == thePlayer)
		{
			winCount++;
			if((west - 1) >= 0){west--;}
			else{break;}
		}
        
		if(winCount == winSize){return true;}
        
		if(east < 19){
            while(this->board[east][rowStart].getPlayer() == thePlayer)
            {
                winCount++;
                if((east + 1) < this->boardSize){east++;}
                else{break;}
            }}
        
		if(winCount == winSize){return true;}
        
		//Travels NorthWest and SouthEast
		winCount = 0;
		int NWcolumn = columnStart;
		int NWrow = rowStart;
		int SEcolumn = columnStart + 1;
		int SErow = rowStart + 1;
		while(this->board[NWcolumn][NWrow].getPlayer() == thePlayer)
		{
			winCount++;
			if((NWcolumn - 1) >= 0){NWcolumn--;}
			else{break;}
			if((NWrow - 1) >= 0){NWrow--;}
			else{break;}
		}
        
		if(winCount == winSize){return true;}
        
		if((SEcolumn < 19) && (SErow < 19)){
            while(this->board[SEcolumn][SErow].getPlayer() == thePlayer)
            {
                winCount++;
                if((SEcolumn + 1) < this->boardSize){SEcolumn++;}
                else{break;}
                if((SErow + 1) < this->boardSize){SErow++;}
                else{break;}
            }}
        
		if(winCount == winSize){return true;}
        
		//Travels north and south
		int north = rowStart;
		int south = rowStart + 1;
		winCount = 0;
		while(this->board[columnStart][north].getPlayer() == thePlayer)
		{
			winCount++;
			if((north - 1) >= 0){north--;}
			else{break;}
		}
        
		if(winCount == winSize){return true;}
        
		if(south < 19){
            while(this->board[columnStart][south].getPlayer() == thePlayer)
            {
                winCount++;
                if((south + 1) < this->boardSize){south++;}
                else{break;}
            }}
        
		if(winCount == winSize){return true;}
        
		//Travels north-east and south-west
		winCount = 0;
		int NEcolumn = columnStart;
		int NErow = rowStart;
		int SWcolumn = columnStart - 1;
		int SWrow = rowStart + 1;
		while(this->board[NEcolumn][NErow].getPlayer() == thePlayer)
		{
			winCount++;
			if((NEcolumn + 1) < this->boardSize){NEcolumn++;}
			else{break;}
			if((NErow - 1) >= 0){NErow--;}
			else{break;}
		}
        
		if(winCount == winSize){done = true; return true;}
        
		if((SWcolumn > -1) && (SWrow < 19)){
            while(this->board[SWcolumn][SWrow].getPlayer() == thePlayer)
            {
                winCount++;
                if((SWcolumn - 1) >= 0){SWcolumn--;}
                else{break;}
                if((SWrow + 1) < this->boardSize){SWrow++;}
                else{break;}
            }}
        
		if(winCount == winSize){return true;}
        
		return false;
	}
	return false;
}

void Board::printBoard()
{
	/*This function, on the otherhand, is very simple. All that's neccessary is to print out the board by iterating
     through the matrix. Keep checking whether a piece is the cursor, and if it is, print out cursorChar instead. */
	this->boardSize = 19; 
    for (int y = 0; y < boardSize; y++) 
    {
	    for (int x = 0; x < boardSize; x++)
		{
            if (board[x][y].cursor())
            {cout << cursorChar << " ";}
            else
            {cout << board[x][y].getPlayer() << " ";}
            
	    }
        
        
               
		cout << endl;
    }
    
   
}