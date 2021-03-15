/* pieces.h: header file that declares gamepiece struct and functions 
 * Written by Evin Jaff
 * email: evin@wustl.edu
 */

//Default header guard
#pragma once
#include <string>

int stringtoEnum(std::string s);

std::string enumtoString(int e);

enum Piece_type { invalid = 0, red = 1, black = 2, white = 3, blue= 4, other = 5 };

//Piece structure
struct piece {
	//Constructors
	piece(int type, std::string name, std::string out);
	piece();
	//member variables
	int          type;
	std::string  name;
	std::string   out;
};