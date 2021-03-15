/* piece.cpp: cpp source file that holds gamepiece utility functions
 * Written by Evin Jaff
 * email: evin@wustl.edu
 */
#include "pieces.h"
#include "declarations.h"
using namespace std;

piece::piece(int type, std::string name, std::string out) : type(type), name(name), out(out) {};

piece::piece() : type(invalid), name(), out(" ") {};

int stringtoEnum(string s) {

	makelowercase(s);

	if (s._Equal("red")) { return Piece_type::red; }

	else if (s._Equal("black")) { return Piece_type::black; }

	else if (s._Equal("white")) { return Piece_type::white; }

	else if (s._Equal("blue")) { return Piece_type::blue; }

	else { return Piece_type::other; }


}

std::string enumtoString(int val) {

	switch (val)
	{
	case 0:
		return "invalid";
	case 1:
		return "red";
	case 2:
		return "black";
	case 3:
		return "white";
	case 4:
		return "blue";
	default:
		return "invalid";
	}


}



