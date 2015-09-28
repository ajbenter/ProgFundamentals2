//
//  board.cpp
//  UI
//
//  Created by Alexis Benter on 12/1/14.
//  Copyright (c) 2014 Alexis Benter. All rights reserved.
//

#include "Board.h"

Board::Board()
{
    // Setting the cursor to the default position in the board
    cursor[0] = boardSize / 2;
    cursor[1] = boardSize / 2;
    
    // Setting each piece on the board to a default piece
    for (int x = 0; x < boardSize; x++) {
        for (int y = 0; y < boardSize; y++)
            board[x][y] = new Piece();
    }
    
    /* checkWin related */
    win = false;
    winSize = 5; // Default winSize
    winCount = 0;
    sectorSize = boardSize - winSize;
    numDiags = 2*sectorSize - 1;
    lsf_row = boardSize - (numDiags - sectorSize);
    lsf_col = 0;
    mf_row = boardSize - 1;
    mf_col = 0;
    rsf_row = boardSize - 1;
    rsf_col = 1;
    lsb_row = boardSize - winSize;
    lsb_col = 0;
    mb_row = mb_col = 0;
    rsb_row = 0;
    rsb_col = 1;
    lsf_count = rsf_count = lsb_count = lsb_count = 0;
    
    // The starting position piece on the board is the cursor
    board[cursor[0]][cursor[1]].setCursor();
    
    // What the representation of the cursor is (to be used for later)
    cursorChar = '*';
}

Board::Board(int winSize)
{
    // Setting the cursor to the default position in the board
    cursor[0] = boardSize / 2;
    cursor[1] = boardSize / 2;
    
    // Setting each piece on the board to a default piece
    for (int x = 0; x < boardSize; x++) {
        for (int y = 0; y < boardSize; y++)
            board[x][y] = new Piece();
    }
    
    /* checkWin related */
    win = false;
    this->winSize = winSize;
    winCount = 0;
    sectorSize = boardSize - winSize;
    numDiags = 2*sectorSize - 1;
    lsf_row = boardSize - (numDiags - sectorSize);
    lsf_col = 0;
    mf_row = boardSize - 1;
    mf_col = 0;
    rsf_row = boardSize - 1;
    rsf_col = 1;
    lsb_row = boardSize - winSize;
    lsb_col = 0;
    mb_row = mb_col = 0;
    rsb_row = 0;
    rsb_col = 1;
    lsf_count = rsf_count = lsb_count = lsb_count = 0;
    
    // The starting position piece on the board is the cursor
    board[cursor[0]][cursor[1]].setCursor();
    
    // What the representation of the cursor is (to be used for later)
    cursorChar = '*';
}


void Board::changePiece(int player)
{
    char set; if (player == 1) set = '1'; else if (player == 2) set = '2'; else set = '0';
    
	// If this piece on the board is already taken by a player, don't change it!
	if (board[cursor[0]][cursor[1]].getPlayer() != '0')
        cout << "Piece cannot be changed!" << endl;
	else board[cursor[0]][cursor[1]].setPlayer(set);   // Else, change the piece
}

void Board::checkWin()
{
    char check = board[cursor[0]][cursor[1]].getPlayer();
    
    /* ROWS */
    for (int i = 0; i < boardSize; i++) {
        if (win) break;
        
        for (int j = 0; j < boardSize; j++) {
            if (board[i][j] == check) winCount++;
            else winCount = 0;
            
            if (winCount == winSize) { win = true; break; }
        }
    }
    
    if (win) return true; // Do not continue
    
    /* COLUMNS */
    for (int i = 0; i < boardSize; i++) {
        if (win) break;
        
        for (int j = 0; j < boardSize; j++) {
            if (board[j][i] == check) winCount++;
            else winCount = 0;
            
            if (winCount == winSize) { win = true; break; }
        }
    }
    
    if (win) return true; // Do not continue
    
    /* LEFT SECTOR FORWARD DIAGONALS */
    for (int s = 0; s < sectorSize; s++) {
        if (win) break;
        
        /* Set new starting position */
        if (lsf_count > 0) {
            lsf_row = (boardSize - (numDiags - sectorSize)) + lsf_count;
            lsf_col = 0;
        }
        
        while (lsf_row >= 0) { // all lsf rows move to 0
            if (board[lsf_row][lsf_col] == check) winCount++;
            else winCount = 0;
            
            if (winCount == winSize) { win = true; break; }
            
            lsf_row--;
            lsf_col++;
        } lsf_count++;
    }
    
    if (win) return true; // Do not continue
    
    /* MIDDLE FORWARD DIAGONAL */
    while (mf_row >= 0) {
        if (board[mf_row][mf_col] == check) winCount++;
        else winCount = 0;
        
        if (winCount == winSize) { win = true; break; }
        
        mf_row--;
        mf_col++;
    }
    
    if (win) return true; // Do not continue
    
    /* RIGHT SECTOR FORWARD DIAGONALS */
    for (int s = 0; s < sectorSize; s++) {
        if (win) break;
        
        /* Set new starting position */
        if (rsf_count > 0) {
            rsf_row = boardSize - 1;
            rsf_col = 1 + rsf_count;
        }
        
        while (rsf_col < boardSize) { // all rsf columns move to n-1
            if (board[rsf_row][rsf_col] == check) winCount++;
            else winCount = 0;
            
            if (winCount == winSize) { win = true; break; }
            
            rsf_row--;
            rsf_col++;
        } rsf_count++;
    }
    
    if (win) return true; // Do not continue
    
    /* LEFT SECTOR BACKWARD DIAGONALS */
    for (int s = 0; s < sectorSize; s++) {
        if (win) break;
        
        /* Set new starting position */
        if (lsb_count > 0) {
            lsb_row = (boardSize - winSize) - lsb_count;
            lsb_col = 0;
        }
        
        while (lsb_row < boardSize) { // all lsb rows move to n-1
            if (board[lsb_row][lsb_col] == check) winCount++;
            else winCount = 0;
            
            if (winCount == winSize) { win = true; break; }
            
            lsb_row++;
            lsb_col++;
        } lsb_count++;
    }
    
    if (win) return true; // Do not continue
    
    /* MIDDLE BACKWARD DIAGONAL */
    while (mb_row < boardSize) {
        if (board[mb_row][mb_col] == check) winCount++;
        else winCount = 0;
        
        if (winCount == winSize) { win = true; break; }
        
        mb_row++;
        mb_col++;
    }
    
    if (win) return true; // Do not continue
    
    /* RIGHT SECTOR BACKWARD DIAGONALS */
    for (int s = 0; s < sectorSize; s++) {
        if (win) break;
        
        /* Set new starting position */
        if (rsb_count > 0) {
            rsb_row = 0;
            rsb_col = 1 + rsb_count;
        }
        
        while (rsb_col < boardSize) { // all rsb columns move to n-1
            if (board[rsb_row][rsb_col] == check) winCount++;
            else winCount = 0;
            
            if (winCount == winSize) { win = true; break; }
            
            rsb_row++;
            rsb_col++;
        } rsb_count++;
    }
    
    return win;
}

void Board::printBoard()
{
    for (int x = 0; x < boardSize; x++) {
        for (int y = 0; y < boardSize; y++) {
            if (board[x][y].isCursor())
                cout << cursorChar << " ";
            else
                cout << board[x][y].getPlayer() << " ";
        } cout << endl;
    }
}