/* board.cpp: cpp source file that holds functions around generating a gameboard from the fed in pieces. Has been pruned
 * since only printing functionality is needed
 * Written by Evin Jaff
 * email: evin@wustl.edu
 */
#include "pieces.h"
#include "declarations.h"
#include "board.h"
#include "pieces.h"
using namespace std;

/* printBoard()
Input: A const vector of game pieces(for example of type ​const vector<game_piece>&)​and two unsigned integers by value as its parameters.
Output: Prints out the gameboard
*/
std::string printBoard(const vector<piece>& vect, unsigned int width, unsigned int length) {

	string s;
	string out;
	istringstream iss;
	//Made an unsigned long long as to avoid data loss since vect.size() is up to 64 bits. Made unsigned because negative indicies aren't needed
	size_t init = vect.size() - 1;

	for (int i = init; i >= 0; i--) {
		if (i % length) {
			s += vect[i].out + " ";
		}
		else {
			s += vect[i].out;
			std::reverse(s.begin(), s.end());

			out += to_string(i / width);

			out += s + "\n";
			s = "";
		}
	}
	for (size_t i = 0; i < init; i++) {
		if (!(i % length)) {
			out += " ";
			out += to_string(i / width);


		}

	}


	return out;
}
