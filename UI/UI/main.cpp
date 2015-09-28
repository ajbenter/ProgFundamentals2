//
//  main.cpp
//  UI
//
//  Created by Alexis Benter on 12/1/14.
//  Copyright (c) 2014 Alexis Benter. All rights reserved.
//

#include "UI.h"

int main()
{
	UI blah;
	blah.run();
}

void UI::run()
{
	bool done = false;
	while(!done)
	{
		cout<<"GOMOKU"<<endl;
		cout<<"Choose one."<<endl;
		cout<<"1: Play a local game (two players)"<<endl;
		cout<<"2: Change settings"<<endl;
		cout<<"3: Exit"<<endl;
        
		int choice;
		cin >>choice;
        
		if(choice == 1)
		{this->playGameTwoPlayer();}
		if(choice == 2)
		{this->changeSettings();}
		if(choice == 3)
		{done = true;}
	}
}

void UI::playGameTwoPlayer()
{
	Board basicBoard(this->boardSize);
	//Says whose turn it is
	//Should move the cursor by pressing *enter* using wasd
	//Will print out the board after every cursor movement. The bool quality of whether a piece is a cursor
    //will change to false for the old cursor location, and true for the new one.
	//Once the cursor is where the player wants to put their piece, the player will hit their player number
    //to add their piece to the board
	//Once a move is made, checkWin() will run, and the next player will go
}

void UI::changeSettings()
{
    
}