//
//  main.cpp
//  UI
//
//  Created by Alexis Benter on 12/1/14.
//  Copyright (c) 2014 Alexis Benter. All rights reserved.
//

#include "UI.h"
#include "Board.cpp"
#include "Board.h"

int main()
{
	UI gomoku;
	gomoku.run();
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
    char i = 0;
	int x = 0;
	int y = 0;
    bool one = false;
    bool two = false;
    
	while(one == false && two == false){
        while(i != '1'){
            cout << "Player 1 turn: " << endl;
            cout << "Choose a direction by using the 'wasd' keypad" << endl;
            cin >> i;
            if(i == 'w' && y != 0){
                y = y+1;
                Board.printBoard();
            }
            else if(i == 'a' && x!=0){
                x = x-1;
                Board.printBoard();
            }
            else if(i == 's' && y!=19){
                y = y-1;
                Board.printBoard();
            }
            else if(i == 'd' && x!=19){
                x = x+1;
                Board.printBoard();
            }
            else if(i == 1){
                Board.changePiece(1);
                one = Board.checkWin();
            }
        }
        while(i != '2'){
            cout << "Player 2 turn: " << endl;
            cout << "Choose a direction by using the 'wasd' keypad" << endl;
            cin >> i;
            if(i == 'w' && y != 0){
                y = y+1;
                Board.printBoard();
            }
            else if(i == 'a' && x!=0){
                x = x-1;
                Board.printBoard();
            }
            else if(i == 's' && y!=19){
                y = y-1;
                Board.printBoard();
            }
            else if(i == 'd' && x!=19){
                x = x+1;
                Board.printBoard();
            }
            else if(i == 2){
                Board.changePiece(2);
                two = Board.checkWin();
            }
        }
	}
    
    if(one == true){
        cout << "Player 1 wins" << endl;
    }
    
    else if(two == true){
        cout << "Player 2 wins" << endl;
    }
    
}

void UI::changeSettings()
{
    
}