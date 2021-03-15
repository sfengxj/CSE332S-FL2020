/* gomoku.cpp: source file that contains the functions and operators to make the Gomoku class run
 * Written by: Evin Jaff (evin@wustl.edu), Lane Bohrer (a.bohrer@wustl.edu), David Moon (davidmoon@wustl.com)
 */

#include "gomoku.h"
using namespace std;

//Gomoku
GomokuGame::GomokuGame() : GameBase(boardconstants::gomokusize, boardconstants::gomokusize), B("B"), W("W"), turncounter(firstturn), Bmoves(""), Wmoves(""), gwin(boardconstants::gwin) {
	longestOut = (to_string(boardconstants::gomokusize)).length();
}

GomokuGame::GomokuGame(unsigned int size) : GameBase(size, size), B("B"), W("W"), turncounter(firstturn), Bmoves(""), Wmoves("") {
	if (size <= 5) {
		gwin = size-1;
	}
	else {
		gwin = 4;
	}
	longestOut = (to_string(boardconstants::gomokusize)).length();
}

GomokuGame::GomokuGame(unsigned int size, unsigned int gwin) : GameBase(size, size), B("B"), W("W"), turncounter(firstturn), Bmoves(""), Wmoves(""), gwin(gwin) {
	longestOut = (to_string(boardconstants::gomokusize)).length();
}

std::ostream& operator<< (std::ostream& ostr, GomokuGame& game) {
	ostr << game.printBoard();
	return ostr;
}

string GomokuGame::printBoard() {
	GomokuGame& game = *this;
	string s;
	string out;
	istringstream iss;

	for (unsigned int i = 0; i < game.gameboard.size(); i++) {
		if (game.gameboard[i].out.length() > game.longestOut) {
			game.longestOut = game.gameboard[i].out.length();
		}
	}


	size_t init = game.gameboard.size() - 1;

	for (size_t i = init; i >= offset; i--) {
		if (i % this->height) {
			//Loop over how much whitespace is needed
			for (int j = 0; j < game.longestOut; j++) {
				s += " ";
			}
			s += game.gameboard[i].out;
			
		}
		else {
			if(game.gameboard[i].out != " "){
				s += game.gameboard[i].out;
			}
			
			size_t indexlength = (to_string(i / this->height)).size() - 1;
			for (size_t j = indexlength; j < game.longestOut; j++) {
				s += " ";
			}
			std::reverse(s.begin(), s.end());
			out += to_string(i / this->width);
			
				out += s + "\n";
			
			

			s = "";
		}
	}

	out += "X";

	for (size_t i = offset; i < init; i++) {
		if (!(i % this->height)) {
			size_t indexlength = (to_string(i / this->height)).size() - 1;
			for (size_t j = indexlength; j < game.longestOut; j++) {
				out += " ";
			}
			out += to_string(i / this->width);

		}
	}

	return out;
}

void::GomokuGame::print(){
	cout << *this << endl;
	return;
}

bool GomokuGame::done() {

	//Vertical Check
	for (unsigned int i = 0; i < height; ++i) {
		std::string token;
		//is the token ever flipped?
		bool tokenflip = false;
		bool declare = true;

		int tokenctr = 0;
		for (unsigned int j = 0; j < width; ++j) {

			if (!(this->gameboard[(i + width * j)].out == token)) {
				//Empty piece
				if (this->gameboard[(i + width * j)].out != W && this->gameboard[(i + width * j)].out != B) {
					tokenctr = 0;
					token = this->gameboard[(i + width * j)].out;
				}
				else {
					tokenctr = 0;
					token = this->gameboard[(i + width * j)].out;
					//Nonempty piece
				}
			}
			else {
				if (this->gameboard[(i + width * j)].out != W && this->gameboard[(i + width * j)].out != B) {
					tokenctr = 0;
					token = this->gameboard[(i + width * j)].out;
				}
				else {
					tokenctr++;
				}

			}
			if (tokenctr == gwin) {
				return true;
			}
		}
	}
	
	//Horizontal
	for (unsigned int i = 0; i < height; ++i) {
		std::string token;
		//is the token ever flipped?
		bool tokenflip = false;
		bool declare = true;

		int tokenctr = 0;

		for (unsigned int j = 0; j < width; ++j) {

			if (!(this->gameboard[(j + width * i)].out == token)) {
				//Empty piece
				if (this->gameboard[(j + width * i)].out != W && this->gameboard[(j + width * i)].out != B) {
					tokenctr = 0;
					token = this->gameboard[(j + width * i)].out;
				}
				else {
					tokenctr = 0;
					token = this->gameboard[(j + width * i)].out;
					//Nonempty piece
				}
			}
			else {
				if (this->gameboard[(j + width * i)].out != W && this->gameboard[(j + width * i)].out != B) {
					tokenctr = 0;
					token = this->gameboard[(j + width * i)].out;
				}
				else {
					tokenctr++;
				}

			}
			if (tokenctr == gwin) {
				return true;
			}
		}
	}

	//Check Right Diagonals
	for (unsigned int i = 0; i < height; ++i) {
		std::string token;
		//is the token ever flipped?
		bool tokenflip = false;
		bool declare = true;

		int tokenctr = 0;
		for (unsigned int j = 0; j < width; ++j) {
			//Overflow guard
			if ((width * i) + (j + width * j) >= width * height) {
				break;
			}


			if (!(this->gameboard[(width * i) + (j + width * j)].out == token)) {
				//Empty piece
				if (this->gameboard[(width * i) + (j + width * j)].out != W && this->gameboard[(width * i) + (j + width * j)].out != B) {
					tokenctr = 0;
					token = this->gameboard[(width * i) + (j + width * j)].out;
				}
				else {
					tokenctr = 0;
					token = this->gameboard[(width * i) + (j + width * j)].out;
					//Nonempty piece
				}
			}
			else {
				if (this->gameboard[(width * i) + (j + width * j)].out != W && this->gameboard[(width * i) + (j + width * j)].out != B) {
					tokenctr = 0;
					token = this->gameboard[(width * i) + (j + width * j)].out;
				}
				else {
					tokenctr++;
				}

			}
			if (tokenctr == gwin) {
				return true;
			}
		}

		for (unsigned int j = 0; j < width; ++j) {
			//Overflow guard
			if (i + (j + width * j) >= width * height) {
				break;
			}

			if (!(this->gameboard[i + (j + width * j)].out == token)) {
				//Empty piece
				if (this->gameboard[i + (j + width * j)].out != W && this->gameboard[i + (j + width * j)].out != B) {
					tokenctr = 0;
					token = this->gameboard[i + (j + width * j)].out;
				}
				else {
					tokenctr = 0;
					token = this->gameboard[i + (j + width * j)].out;
					//Nonempty piece
				}
			}
			else {
				if (this->gameboard[i + (j + width * j)].out != W && this->gameboard[i + (j + width * j)].out != B) {
					tokenctr = 0;
					token = this->gameboard[i + (j + width * j)].out;
				}
				else {
					tokenctr++;
				}

			}
			if (tokenctr == gwin) {
				return true;
			}
		}
	}



	for (size_t j = 0; j < width; ++j) {

		std::string token;
		int tokenctr = 0;
		for (size_t i = width-offset; i >= (j); i--) {

			//is the token ever flipped?
			bool tokenflip = false;
			bool declare = true;

			if (j + (((width - offset)-i) + width * i) >= width * height || j + (((width - offset)-i) + width * i) < 0) {
				break;
			}


			if (!(this->gameboard[j + (((width - offset)-i) + width * i)].out == token)) {
				//Empty piece
				if (this->gameboard[j + (((width - offset)-i) + width * i)].out != B && this->gameboard[j + (((width - offset)-i) + width * i)].out != W) {

					tokenctr = 0;
					token = this->gameboard[j + (((width - offset)-i) + width * i)].out;
				}
				else {

					tokenctr = 0;
					token = this->gameboard[j + (((width - offset)-i) + width * i)].out;

					//Nonempty piece


				}
			}
			else {
				if (this->gameboard[j + (((width - offset)-i) + width * i)].out != B && this->gameboard[j + (((width - offset)-i) + width * i)].out != W) {

					tokenctr = 0;
					token = this->gameboard[j + (((width - offset)-i) + width * i)].out;
				}
				else {

					tokenctr++;
				}

			}

			if (tokenctr == gwin) {

				return true;
			}
		}



		//reset in case any memory carryover
		tokenctr = 0;
		for (size_t i = width - offset; i >= (j); i--) {

			// = gameboard[(((arrwidth) - i) + width * i) - (j * width)].out;
			//is the token ever flipped?
			bool tokenflip = false;
			bool declare = true;

			if ((((width - offset)-i) + width * i) - (j * width) >= width * height || (((width - offset)-i) + width * i) - (j * width) < 0) {
				break;
			}

			if (!(this->gameboard[(((width - offset)-i) + width * i) - (j * width)].out == token)) {
				//Empty piece
				if (this->gameboard[(((width - offset)-i) + width * i) - (j * width)].out != W && this->gameboard[(((width - offset)-i) + width * i) - (j * width)].out != B) {
					tokenctr = 0;
					token = this->gameboard[(((width - offset)-i) + width * i) - (j * width)].out;
				}
				else {
					tokenctr = 0;
					token = this->gameboard[(((width - offset)-i) + width * i) - (j * width)].out;
					//Nonempty piece


				}
			}
			else {
				if (this->gameboard[(((width - offset)-i) + width * i) - (j * width)].out != W && this->gameboard[(((width - offset)-i) + width * i) - (j * width)].out != B) {
					tokenctr = 0;
					token = this->gameboard[(((width - offset)-i) + width * i) - (j * width)].out;
				}
				else {
					tokenctr++;
				}

			}
			if (tokenctr == gwin) {
				return true;
			}
		}

	}
	return false;

}

bool GomokuGame::draw() {
	/*if (done() || turncounter < ((width - offset)*(height - offset))) { //if less turns have been played than the number of spots, it can't be a draw'
		return false;
	}
	for (unsigned int i = 0; i < gameboard.size(); ++i) {
		if (!(gameboard[i].out == W || gameboard[i].out == B)) {
			return false;
		}
	}
	return true;
	*/

	//Vertical Check
	for (unsigned int i = 0; i < height; ++i) {
		std::string token;
		//is the token ever flipped?
		bool tokenflip = false;
		bool declare = true;

		int tokenctr = 0;
		for (unsigned int j = 0; j < width; ++j) {

			if (!(this->gameboard[(i + width * j)].out == token)) {
				//Empty piece
				if (this->gameboard[(i + width * j)].out != W && this->gameboard[(i + width * j)].out != B) {
					tokenctr++;
				}
				else {
					tokenctr = 0;
					token = this->gameboard[(i + width * j)].out;
					//Nonempty piece
				}
			}
			else {
				if (this->gameboard[(i + width * j)].out != W && this->gameboard[(i + width * j)].out != B) {
					tokenctr = 0;
					token = this->gameboard[(i + width * j)].out;
				}
				else {
					tokenctr++;
				}

			}
			if (tokenctr == gwin) {
				return true;
			}
		}
	}
	
	//Horizontal
	for (unsigned int i = 0; i < height; ++i) {
		std::string token;
		//is the token ever flipped?
		bool tokenflip = false;
		bool declare = true;

		int tokenctr = 0;

		for (unsigned int j = 0; j < width; ++j) {

			if (!(this->gameboard[(j + width * i)].out == token)) {
				//Empty piece
				if (this->gameboard[(j + width * i)].out != W && this->gameboard[(j + width * i)].out != B) {
					tokenctr++;
				}
				else {
					tokenctr = 0;
					token = this->gameboard[(j + width * i)].out;
					//Nonempty piece
				}
			}
			else {
				if (this->gameboard[(j + width * i)].out != W && this->gameboard[(j + width * i)].out != B) {
					tokenctr = 0;
					token = this->gameboard[(j + width * i)].out;
				}
				else {
					tokenctr++;
				}

			}
			if (tokenctr == gwin) {
				return true;
			}
		}
	}

	//Check Right Diagonals
	for (unsigned int i = 0; i < height; ++i) {
		std::string token;
		//is the token ever flipped?
		bool tokenflip = false;
		bool declare = true;

		int tokenctr = 0;
		for (unsigned int j = 0; j < width; ++j) {
			//Overflow guard
			if ((width * i) + (j + width * j) >= width * height) {
				break;
			}


			if (!(this->gameboard[(width * i) + (j + width * j)].out == token)) {
				//Empty piece
				if (this->gameboard[(width * i) + (j + width * j)].out != W && this->gameboard[(width * i) + (j + width * j)].out != B) {
					tokenctr++;
				}
				else {
					tokenctr = 0;
					token = this->gameboard[(width * i) + (j + width * j)].out;
					//Nonempty piece
				}
			}
			else {
				if (this->gameboard[(width * i) + (j + width * j)].out != W && this->gameboard[(width * i) + (j + width * j)].out != B) {
					tokenctr = 0;
					token = this->gameboard[(width * i) + (j + width * j)].out;
				}
				else {
					tokenctr++;
				}

			}
			if (tokenctr == gwin) {
				return true;
			}
		}

		for (unsigned int j = 0; j < width; ++j) {
			//Overflow guard
			if (i + (j + width * j) >= width * height) {
				break;
			}

			if (!(this->gameboard[i + (j + width * j)].out == token)) {
				//Empty piece
				if (this->gameboard[i + (j + width * j)].out != W && this->gameboard[i + (j + width * j)].out != B) {
					tokenctr++;
				}
				else {
					tokenctr = 0;
					token = this->gameboard[i + (j + width * j)].out;
					//Nonempty piece
				}
			}
			else {
				if (this->gameboard[i + (j + width * j)].out != W && this->gameboard[i + (j + width * j)].out != B) {
					tokenctr = 0;
					token = this->gameboard[i + (j + width * j)].out;
				}
				else {
					tokenctr++;
				}

			}
			if (tokenctr == gwin) {
				return true;
			}
		}
	}



	for (size_t j = 0; j < width; ++j) {

		std::string token;
		int tokenctr = 0;
		for (size_t i = width-offset; i >= (j); i--) {

			//is the token ever flipped?
			bool tokenflip = false;
			bool declare = true;

			if (j + (((width - offset)-i) + width * i) >= width * height || j + (((width - offset)-i) + width * i) < 0) {
				break;
			}


			if (!(this->gameboard[j + (((width - offset)-i) + width * i)].out == token)) {
				//Empty piece
				if (this->gameboard[j + (((width - offset)-i) + width * i)].out != B && this->gameboard[j + (((width - offset)-i) + width * i)].out != W) {
					tokenctr++;
				}
				else {

					tokenctr = 0;
					token = this->gameboard[j + (((width - offset)-i) + width * i)].out;

					//Nonempty piece


				}
			}
			else {
				if (this->gameboard[j + (((width - offset)-i) + width * i)].out != B && this->gameboard[j + (((width - offset)-i) + width * i)].out != W) {

					tokenctr = 0;
					token = this->gameboard[j + (((width - offset)-i) + width * i)].out;
				}
				else {

					tokenctr++;
				}

			}

			if (tokenctr == gwin) {

				return true;
			}
		}



		//reset in case any memory carryover
		tokenctr = 0;
		for (size_t i = width - offset; i >= (j); i--) {

			// = gameboard[(((arrwidth) - i) + width * i) - (j * width)].out;
			//is the token ever flipped?
			bool tokenflip = false;
			bool declare = true;

			if ((((width - offset)-i) + width * i) - (j * width) >= width * height || (((width - offset)-i) + width * i) - (j * width) < 0) {
				break;
			}

			if (!(this->gameboard[(((width - offset)-i) + width * i) - (j * width)].out == token)) {
				//Empty piece
				if (this->gameboard[(((width - offset)-i) + width * i) - (j * width)].out != W && this->gameboard[(((width - offset)-i) + width * i) - (j * width)].out != B) {
						tokenctr++;
				}
				else {
					tokenctr = 0;
					token = this->gameboard[(((width - offset)-i) + width * i) - (j * width)].out;
					//Nonempty piece


				}
			}
			else {
				if (this->gameboard[(((width - offset)-i) + width * i) - (j * width)].out != W && this->gameboard[(((width - offset)-i) + width * i) - (j * width)].out != B) {
					tokenctr = 0;
					token = this->gameboard[(((width - offset)-i) + width * i) - (j * width)].out;
				}
				else {
					tokenctr++;
				}

			}
			if (tokenctr == gwin) {
				return true;
			}
		}

	}
	return false;

}

void GomokuGame::turn() {

	this->print();

	if (done()) {
		if (turncounter % boardconstants::players) {

			cout << "Winner winner chicken dinner - White wins!" << endl;
			throw win;
		}
		else {
			cout << "Winner winner chicken dinner - Black wins!" << endl;
			throw win;
		}

		return;
	}
	if (turncounter != firstturn) {
		bool catflip = true;
		for (unsigned int i = 0; i < this->gameboard.size(); i++) {

			if (this->gameboard[i].out == " " && !(i <= width) && !(i >= width - offset * height - 1) && !(i % width == 0) && !(((i) % width) == width - offset)) {
				catflip = false;
			}
		}
		if (catflip) {
			cout << "Cat's Game!" << endl;
			cout << turncounter << " turns were played!" << endl;
			throw catsgame;
		}
	}

	bool o1 = false;
	if (turncounter % boardconstants::players) {

		cout << Bmoves << endl;
		cout << "It is Black's turn" << endl;

		o1 = true;
	}
	else {
		cout << Wmoves << endl;
		cout << "It is White's turn" << endl;
	}
	unsigned int x;
	unsigned int y;

	try {
		this->prompt(x, y);
	}
	catch (returncodes e){
		throw e;
	}

	while ((x >= width || y >= height) || (x == 0 || y == 0) || ((this->gameboard[((y * height) + x)].out == "W") || (this->gameboard[(x + (y * height))].out == "B"))) {
		if ((this->gameboard[x + (y * height)].out == "W") || (this->gameboard[x + (y * height)].out == "B")) {
			cout << "Oops! That space is already taken!" << endl;
			this->prompt(x, y);
		} 
		if (x == 0 || y == 0) {
			cout << "Oops! no pieces can be put in the 0th row or column" << endl;
			this->prompt(x, y);
		} 
		if (x >= width || y >= height) {
			cout << "Oops! no pieces can be put outside the 19x19 grid" << endl;
			this->prompt(x, y);
		}
	}

	turncounter++;

	if (o1) {
		// O -> black
		piece p(black, "Black", "B");
		this->gameboard[x + (y * height)] = p;
		Bmoves += "B -> " + to_string(x) + " ,  " + to_string(y) + "| ";
		return;
	}
	else {
		// X -> white
		piece p(white, "White", "W");
		this->gameboard[x + (y * height)] = p;
		Wmoves += "W -> " + to_string(x) + " ,  " + to_string(y) + "| ";
		return;
	}
}
