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
		//cout<<"2: Change settings"<<endl;
		cout<<"2: Exit"<<endl;
        
		int choice;
		cin >>choice;
        
		if(choice == 1)
		{this->playGameTwoPlayer();}
		//if(choice == 2)
		//{this->changeSettings();}
		if(choice == 2)
		{done = true;}
	}
}

void UI::playGameTwoPlayer()
{
	Board basicBoard(this->boardSize);
	winSize = 5;
    char i = 0;
	int x = 0;
	int y = 0;
    bool one = false;
    bool two = false;
    
	while(one == false && two == false){
        do{
            cout << "Player 1 turn: " << endl;
			basicBoard.printBoard();
            cout << "Choose a direction by using the 'wasd' keypad and hitting enter." << endl;
			cout << "If you've decided on your move, hit 1 and hit enter." << endl;
            cin >> i;
            if(i == 'w' && y != 0){
				basicBoard.changeCur(x, y);
                y = y-1;
				basicBoard.changeCur(x, y);
                basicBoard.printBoard();
            }
            else if(i == 'a' && x!=0){
				basicBoard.changeCur(x, y);
                x = x-1;
				basicBoard.changeCur(x, y);
                basicBoard.printBoard();
            }
            else if(i == 's' && y!=19){
				basicBoard.changeCur(x, y);
                y = y+1;
				basicBoard.changeCur(x, y);
                basicBoard.printBoard();
            }
            else if(i == 'd' && x!=19){
				basicBoard.changeCur(x, y);
                x = x+1;
				basicBoard.changeCur(x, y);
                basicBoard.printBoard();
            }
            else if(i == '1'){
				bool check = basicBoard.change(x, y, '1');
				if(check){one = basicBoard.checkWin(x, y, winSize);}
				else{i = '0';}
            }
        }while(i != '1');
        
		if(one == true)
		{
            cout << "Player 1 wins!" << endl; return;
		}
        
        do{
            cout << "Player 2 turn: " << endl;
			basicBoard.printBoard();
            cout << "Choose a direction by using the 'wasd' keypad and hitting enter." << endl;
			cout << "If you've decided on your move, hit 2 and enter." << endl;
            cin >> i;
            if(i == 'w' && y != 0){
				basicBoard.changeCur(x, y);
                y = y-1;
				basicBoard.changeCur(x, y);
                basicBoard.printBoard();
            }
            else if(i == 'a' && x!=0){
				basicBoard.changeCur(x, y);
                x = x-1;
				basicBoard.changeCur(x, y);
                basicBoard.printBoard();
            }
            else if(i == 's' && y!=19){
				basicBoard.changeCur(x, y);
                y = y+1;
				basicBoard.changeCur(x, y);
                basicBoard.printBoard();
            }
            else if(i == 'd' && x!=19){
				basicBoard.changeCur(x, y);
                x = x+1;
				basicBoard.changeCur(x, y);
                basicBoard.printBoard();
            }
            else if(i == '2'){
				bool check = basicBoard.change(x, y, '2');
				if(check){one = basicBoard.checkWin(x, y, winSize);}
				else{i = '0';}
            }
        }while(i != '2');
	}
    
    if(two == true)
	{
        cout << "Player 2 wins!" << endl; return;
    }
    
}

void UI::changeSettings()
{
    
}