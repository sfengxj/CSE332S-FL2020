/* gomoku.h: header file that declares gomokou class and its supporting enums/inclusions/operators
 * Written by: Evin Jaff (evin@wustl.edu), Lane Bohrer (a.bohrer@wustl.edu), David Moon (davidmoon@wustl.com)
 */

#pragma once
#include "declarations.h"
#include "GameBase.h"
#include "pieces.h"


class GomokuGame : public GameBase {
	friend std::ostream& operator << (std::ostream& ostr, GomokuGame& game);

public:
	GomokuGame(); //Default constructor
	GomokuGame(unsigned int size);
	GomokuGame(unsigned int size, unsigned int gwin);
	~GomokuGame() = default;

	virtual void print() override;
	virtual bool done() override;
	virtual bool draw() override;
	virtual void turn() override;
	virtual std::string printBoard() override;


	//String constants for symbols to avoid hardcoding later on
	const std::string B;
	const std::string W;
	unsigned int turncounter; 	// starts at 1, O goes first so turncounter%2 = 1 -> O, turncounter%2 = 0 -> X
	std::string Bmoves;
	std::string Wmoves;
	unsigned int gwin;

};

std::ostream& operator << (std::ostream& ostr, GomokuGame& game);

