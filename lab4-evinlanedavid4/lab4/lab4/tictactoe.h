/* tictactoe.h: header file that declares tictactoe class and its supporting enums/inclusions/operators
 * Ported From Evin Jaff's Lab 3 Code. Refactored by: 
 * Evin Jaff (evin@wustl.edu), Lane Bohrer (a.bohrer@wustl.edu), David Moon (davidmoon@wustl.com)
 */

#pragma once
#include "GameBase.h"
#include "pieces.h"
//#include "declarations.h"

#include <vector>
#include <string>
#include <iostream>
#include <sstream>


class TicTacToeGame : public GameBase {
	friend std::ostream& operator << (std::ostream& ostr, TicTacToeGame& game);

public:
	TicTacToeGame(); //Default constructor
	~TicTacToeGame() = default;

	virtual void print() override;
	virtual bool done() override;
	virtual bool draw() override;
	virtual void turn() override;
	virtual std::string printBoard() override;

	//String constants for symbols to avoid hardcoding later on
	const std::string X;
	const std::string O;
	std::string Xmoves;
	std::string Omoves; 

	unsigned int turncounter;
	// starts at 1, O goes first so turncounter%2 = 1 -> O, turncounter%2 = 0 -> X
	const unsigned int twin;

};

std::ostream& operator << (std::ostream& ostr, TicTacToeGame& game);
