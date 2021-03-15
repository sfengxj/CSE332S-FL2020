/* board.h: header file that declares board.cpp functions and enums
 * Written by Evin Jaff
 * email : evin@wustl.edu
*/
#pragma once
#include "pieces.h"

int readboard(std::ifstream &istream, unsigned int & x, unsigned int & y);

int addpieces(std::ifstream& ifstream, std::vector<piece>& pieces, unsigned int& width, unsigned int& height);

void printBoard(const std::vector<piece>&, unsigned int width, unsigned int length);

void neighbor(const std::vector<piece>& vect, unsigned int width, unsigned int length);

//indexes of c-style array
enum {etl = 0, etr=1, er=2, el=3, ebl=4, ebr=5, eb=6, et=7};

//Constant for invalid index, plus other utility constants.
enum invalid {inv=-1, startingindx = 0, neighbordiff=1};