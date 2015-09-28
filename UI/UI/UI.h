//
//  UI.h
//  UI
//
//  Created by Alexis Benter on 12/1/14.
//  Copyright (c) 2014 Alexis Benter. All rights reserved.
//

#ifndef UI_UI_h
#define UI_UI_h
#include <iostream>
#include "Board.h"
using namespace std;

class UI

{
    protected:
        int winSize;
        int boardSize;
    
    public:
        virtual void run();
        virtual void playGameTwoPlayer();
        virtual void changeSettings();
    };



#endif
