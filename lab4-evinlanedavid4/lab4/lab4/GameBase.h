/* GameBase.h: header file that declares GameBase class and its supporting enums/inclusions/operators
 * Written by: Evin Jaff (evin@wustl.edu), Lane Bohrer (a.bohrer@wustl.edu), David Moon (davidmoon@wustl.com)
 */

#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

#include "declarations.h"
#include "pieces.h"

class GameBase {

protected:
	std::vector<piece> gameboard;
	size_t width;
	size_t height;
	size_t longestOut;

public:
	GameBase(size_t width, size_t height);
	virtual ~GameBase() = default;
	virtual void print() = 0;
	virtual bool done() = 0;
	virtual bool draw() = 0;
	virtual void turn() = 0;
	virtual std::string printBoard() = 0;

	void prompt(unsigned int& a, unsigned int& b);
	int play();

	static std::shared_ptr<GameBase> choose_game(int i, char* arr[]);
};