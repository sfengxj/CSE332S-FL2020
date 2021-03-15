/* tictactoe.h: header file that declares tictactoe class and its supporting enums/inclusions/operators
 * Written by Evin Jaff
 * email: evin@wustl.edu
 */
#pragma once
#include <vector>
#include "pieces.h"
#include <string>
#include <iostream>
#include <sstream>

//only acceptable symbols, X and O



enum boardconstants { width = 5, height = 5, arrwidth = width - 1, arrheight = height - 1, firstturn = 1, players = 2 };
enum returncodes { win = 0, quitcode = 1, catsgame = 2, usagemessage = 3 };

class TicTacToeGame {
	
	friend std::ostream& operator <<(std::ostream& ostr,  const TicTacToeGame& game);
	//std::ostream& operator<<(std::ostream& ostr, const TicTacToeGame& game);

	

public:
	TicTacToeGame(); //Default constructor
	bool done();
	bool draw();
	void prompt(unsigned int& a, unsigned int& b);
	void turn();
	int play();

	std::vector<piece> gameboard;

	int turncounter;
	// starts at 1, O goes first so turncounter%2 = 1 -> O, turncounter%2 = 0 -> X

	//String constants for symbols to avoid hardcoding later on
	const std::string X;
	const std::string O;
	std::string Xmoves;
	std::string Omoves;
	
	



};

std::ostream& operator << (std::ostream& ostr, const TicTacToeGame& game);