//
//  Board.h
//  UI
//
//  Created by Alexis Benter on 12/1/14.
//  Copyright (c) 2014 Alexis Benter. All rights reserved.
//

#ifndef UI_Board_h
#define UI_Board_h
#include <iostream>
using namespace std;

class Piece
{
private:
    // Each 'piece' on the board has two components, which player it belongs to,
    // and if that position is where the cursor is.
    char player;
    bool cursor;
    
public:
    Piece() { player = '0'; cursor = false; }
    Piece(char player) { this->player = player; cursor = false; }
    
    // Standard get and mutator methods
    virtual char getPlayer() { return player; }
    virtual void setPlayer(char player) { this->player = player; }
    virtual void setCursor() { cursor = true; }
    virtual bool isCursor() { return cursor; }
};

class Board
{
private:
    static const int boardSize = 19;
    Piece board[boardSize][boardSize];
    int cursor[2];
    char cursorChar;
    
    /* checkWin related */
    bool win;
    int winSize, winCount, sectorSize, numDiags;
    
    int lsf_row, lsf_col; // Start positions for diagonals
    int mf_row, mf_col;
    int rsf_row, rsf_col;
    int lsb_row, lsb_col;
    int mb_row, mb_col;
    int rsb_row, rsb_col;
    
    int lsf_count, rsf_count, lsb_count, rsb_count; // Counters for diagonals
    
public:
    Board();
    Board(int winSize);
    ~Board();
    
    virtual void changePiece(int row, int column, int player);
    virtual void checkWin();
    virtual void printBoard();
};


#endif
