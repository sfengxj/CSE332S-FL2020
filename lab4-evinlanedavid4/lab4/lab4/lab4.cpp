/* lab4.cpp: main source file where execution starts
 * Ported From Evin Jaff's Lab 3 Code. Refactored by: 
 * Evin Jaff (evin@wustl.edu), Lane Bohrer (a.bohrer@wustl.edu), David Moon (davidmoon@wustl.com)
 */

#pragma once
#include "tictactoe.h"
#include "declarations.h"
#include "GameBase.h"

using namespace std;

int main(int argc, char * argv[])
{
    TicTacToeGame tgame;

    try {
        shared_ptr<GameBase> game_ptr = tgame.choose_game(argc, argv);
        
        if (game_ptr == 0) {
            return usageFunction(argc, argv);
        }
        return game_ptr->play();

    } catch (errors e) {
        return usageFunction(argc, argv);
        return e;
    }
    catch (...) {
        return usageFunction(argc, argv);
        return other_errors;
    }
    
    
}

int usageFunction(int argc, char* argv[]) {

    //npm usage function syntax referenced
    cout << "Usage: "<< argv[arguments::executable_name] << " <gametype>" << endl;

    cout << "Where <gametype> is one of: " << endl << "TicTacToe, Gomoku" << endl;

    cout << "Define Game Board Specifics (Gomoku only)" << endl;
    cout <<  argv[arguments::executable_name] << "<gametype>" << endl;
    cout <<  argv[arguments::executable_name] << "<gametype> <numtowin>" << endl;

    if (argc == arguments::expectedArgs || argc == arguments::withSizeArg || argc == arguments::withWinNumArg) { //expectedArgs, withSize, withWinNum all valid inputs
        return errors::Invalid_Input_Bad_Game;
    }
    return errors::Invalid_Args_Number;
}

int makelowercase(string &s) {
    string newlowercase = "";
    
    for (unsigned int i = 0; i < s.length(); i++) {
        newlowercase += tolower(s[i]);
    }
    s = newlowercase;
	return errors::success;
    
}