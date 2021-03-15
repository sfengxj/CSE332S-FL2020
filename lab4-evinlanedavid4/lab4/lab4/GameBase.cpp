/* GameBase.cpp: source file that contains the functions and operators to make the GameBase class run
 * Written by: Evin Jaff (evin@wustl.edu), Lane Bohrer (a.bohrer@wustl.edu), David Moon (davidmoon@wustl.com)
 */

#pragma once
#include"GameBase.h"
#include "tictactoe.h"
#include "gomoku.h"
#include <vector>

using namespace std;

//GameBase Class
GameBase::GameBase(size_t width, size_t height) : width(width), height(height){
	//Make board with a width and height
	gameboard = std::vector<piece>(width * height);
}

void GameBase::prompt(unsigned int& x, unsigned int& y) {
	size_t arrwidth = width - 1;
	size_t arrheight = height - 1;

	cout << "Enter valid coordinates in the form x,y" << endl;
	string input;
	getline(cin, input);

	unsigned int firstryx;
	unsigned int firstryy;

	if ( input.compare("quit")==0 ) {
		//overflow #'s to flag quitting the game
		throw quitcode;
	}
	//breakup space
	for (unsigned int i = 0; i < input.length(); i++) {
		if (input[i] == ',') {
			input[i] = ' ';
		}
	}

	istringstream iss(input);

	bool succ1 = (bool)(iss >> firstryx);
	bool succ2 = (bool)(iss >> firstryy);
	bool testvalid = (!(firstryx + (firstryy * width) >= width * height)) && (!(firstryx > arrwidth)) && (!(firstryy > arrheight));

	if (testvalid && succ1 && succ2) {

		x = firstryx;
		y = firstryy;
		cout << endl;
		return;
	}

	bool notvalid = (!(x + (y * width) >= width * height)) && (!(x > arrwidth)) && (!(y > arrheight));

	iss.clear();

	while (!notvalid) {
		unsigned int testx;
		unsigned int testy;

		cout << "Invalid input, enter valid coordinates in the form x,y" << endl;
		string input;
		getline(cin, input);

		if (input.compare("quit")==0) {
			throw quitcode;

		}

		//breakup space
		for (unsigned int i = 0; i < input.length(); i++) {
			if (input[i] == ',') {
				input[i] = ' ';
			}
		}


		istringstream iss(input);

		bool succ1 = (bool)(iss >> testx);
		bool succ2 = (bool)(iss >> testy);
		
		iss.clear();

		notvalid = (!(testx + (testy * width) >= width * height)) && (!(testx > arrwidth)) && (!(testy > arrheight));

		if (notvalid && succ1 && succ2) {

			x = testx;
			y = testy;
			break;
		}
	}
	return;
}

int GameBase::play() {
	try {
		while (true) {
			turn();

		}
	}
	catch (returncodes e) {
		if (e == returncodes::quitcode) {
			cout << "Quit Called" << endl;
		}
		return e;
	}
}

string GameBase::printBoard() {
	GameBase& game = *this;
	string s;
	string out;
	istringstream iss;

	for (unsigned int i = 0; i < game.gameboard.size(); i++) {
		if (game.gameboard[i].out.length() > game.longestOut) {
			game.longestOut = game.gameboard[i].out.length();
		}
	}

	size_t init = game.gameboard.size() - 1;

	for (size_t i = init; i != 0; i--) {
		if (i % height) {
			s += game.gameboard[i].out;
			//Loop over how much whitespace is needed
			for (int j = 0; j <= game.longestOut; j++) {
				s += " ";
			}
		}
		else {
			s += game.gameboard[i].out;
			std::reverse(s.begin(), s.end());

			out += to_string(i / width);

			out += s + "\n";
			s = "";
		}
	}
	for (size_t i = 0; i < init; i++) {
		if (!(i % height)) {
			for (int j = 0; j <= game.longestOut; j++) {
				out += " ";
			}
			out += to_string(i / width);


		}

	}


	return out;

};

shared_ptr<GameBase> GameBase::choose_game(int i, char *arr[]) {
	if (i < expectedArgs) {
		shared_ptr<GameBase> zero = 0;
		return zero;
	}

	string gamefilename = arr[arguments::gametype];
	makelowercase(gamefilename);

	if ( !(gamefilename.compare("tictactoe") ) && expectedArgs==i) {
		shared_ptr<GameBase> tictactoegame(new TicTacToeGame());
		return tictactoegame;
	}
	
	if (!(gamefilename.compare("gomoku"))) {
		try {
			if (i == arguments::withSizeArg) {
				unsigned int size = 1+stoi(arr[withSizeInd]); //add one bc 0 row isn't used. cast input to integer, can throw except but is caught and returns zero pointer
			
				if (size < 3) { // if invalid size, return error
					throw errors::Invalid_Input_Bad_Params;
				}

				shared_ptr<GameBase> gomokugame(new GomokuGame(size));
				return gomokugame;
			}
			else if (i == arguments::withWinNumArg) {
				unsigned int size = 1+stoi(arr[withSizeInd]); //add one bc 0 row isn't used
				unsigned int numToWin = stoi(arr[withWinNumInd])-1; //subtract one to adjust user input to relevant code value 

				if (size < 3 || numToWin > size) { // if invalid size or gwin>size, return error
					throw errors::Invalid_Input_Bad_Params;
				}

				shared_ptr<GameBase> gomokugame(new GomokuGame(size, numToWin));
				return gomokugame;
			}
			else if (i == arguments::expectedArgs) {
				shared_ptr<GameBase> gomokugame(new GomokuGame());
				return gomokugame;
			}

			//if none of the specification are met, return a 0 pointer to indicate bad input
			shared_ptr<GameBase> zero = 0;
			return zero;
		}
		catch (...) {
			shared_ptr<GameBase> zero = 0;
			return zero;
		}
	}
	
	else {
		throw errors::Invalid_Input_Bad_Game;
	}	
}

