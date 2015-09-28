//
//  main.cpp
//  Calculator
//
//  Created by Alexis Benter on 11/6/14.
//  Copyright (c) 2014 Alexis Benter. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

std::stack<double> is;
std::stack<char> cs;
double result;

//defining the stack
double solve(string inputString) {
    for (int i = 0; i < inputString.length(); ++i) {
        if ( inputString[i] == ')' ) {
            
            double b = is.top();
            is.pop();
            
            char op = cs.top();
            cs.pop();
            
//variables for sin, cos, log, sqrt
            double a = 0;
            if (op != 's' && op != 'c' && op != 'l' && op != 'r') {
                a = is.top();
                is.pop();
            }
            
//operations
            if ( op == '+') {
                result = a + b;
            }
            
            else if ( op == ' '){
                
            }
            
            else if ( op == '-') {
                result = a - b;
            }
            
            else if ( op == '*') {
                result = a * b;
            }
            
            else if ( op == '/') {
                result = a / b;
            }
            
            else if ( op == '^') {
                result = pow(a,b);
            }
            
            else if ( op == 's') {
                double rads = (double(b)*M_PI)/180;
                result = sin(rads);
            }
            
            else if ( op == 'c') {
                double rads = (double(b)*M_PI)/180;
                result = cos(rads);
            }
            
            else if ( op == 'l') {
                result = log(b);
            }
            
            else if ( op == 'r') {
                result = sqrt(b);
            }
            
            is.push(result);
        }
        
//stacking and popping double digit numbers
        else if ( inputString[i] != '(' && inputString[i] != ' ') {
            string s = "";
            if ('0' <= inputString[i] && inputString[i] <= '9') {
                s += inputString[i];
                if ('0' <= inputString[i+1] && inputString[i+1] <= '9') {
                    s += inputString[i+1];
                    ++i;
                }
                
                double operand = stod(s);
                is.push(operand);
            }
            else if (inputString[i] == '+'
                     || inputString[i] == '-'
                     || inputString[i] == '*'
                     || inputString[i] == '/'
                     || inputString[i] == '^') {
                
                cs.push(inputString[i]);
            }
            
//variable definitions for sin, sqrt, cos, log
            else if (inputString[i] == 's') {
                if (inputString[i+1] == 'i') {
                    if (inputString[i+2] == 'n') {
                        cs.push(inputString[i]);
                        i += 2;
                    }
                }
                else if (inputString[i+1] == 'q') {
                    if (inputString[i+2] == 'r') {
                        if (inputString[i+3] == 't') {
                            cs.push('r');
                            i += 3;
                        }
                    }
                }
            }
            
            else if (inputString[i] == 'c') {
                if (inputString[i+1] == 'o') {
                    if (inputString[i+2] == 's') {
                        cs.push(inputString[i]);
                        i += 2;
                    }
                }
            }
            
            else if (inputString[i] == 'l') {
                if (inputString[i+1] == 'o') {
                    if (inputString[i+2] == 'g') {
                        cs.push(inputString[i]);
                        i += 2;
                    }
                }
            }
            
            else {
                cout << "Error. Choose a menu option";
            }
        }
    }
    return is.top();
}
        

//menu for the calculator
int main(int argc, const char * argv[])
{
    bool quit = false;
    char choice;
    
    while (!quit) {
        cout << "Make a selection:\n1. Solve an expression.\n2. Quit." << endl;
        cin >> choice;
        
        if (choice == '1') {
            string input;
            cout << "Enter an expression to solve:" << endl;
            
            cin.ignore(1000, '\n');
            std::getline(std::cin, input);
            
            cout << endl << input << " = " << solve(input) << endl << endl;
        }
        
        else if (choice == '2') {
            quit = true;
        }
        
        else {
            cout << "Not an option." << endl;
        }
    }
    
    
    
    return 0;
}

