/* tictactoe.cpp: source file that contains the functions and operators to make the TicTacToeGame class run
 * Ported From Evin Jaff's Lab 3 Code. Refactored by: 
 * Evin Jaff (evin@wustl.edu), Lane Bohrer (a.bohrer@wustl.edu), David Moon (davidmoon@wustl.com)
 */
#pragma once

#include "tictactoe.h"

using namespace std;

TicTacToeGame::TicTacToeGame() : GameBase(boardconstants::tttsize, boardconstants::tttsize), X("X"), O("O"), Xmoves(""), Omoves(""), turncounter(firstturn), twin(boardconstants::twin)  {

	gameboard = vector<piece>(boardconstants::tttsize * boardconstants::tttsize);
}

void TicTacToeGame::print() {
	cout << this->printBoard() << endl;
}

std::ostream& operator<< (std::ostream& ostr, TicTacToeGame& game) {
	ostr << game.printBoard();

	return ostr;
}

void TicTacToeGame::turn() {

	this->print();

	if (done()) {
		if (turncounter % boardconstants::players) {

			cout << "Winner winner chicken dinner - Player X wins!" << endl;
			throw win;
		}
		else {
			cout << "Winner winner chicken dinner - Player O wins!" << endl;
			throw win;
		}

		return;
	}
	if (turncounter != firstturn) {
		bool catflip = true;
		for (unsigned int i = 0; i < this->gameboard.size(); i++) {

			if (this->gameboard[i].out == " " && !(i <= width) && !(i >= width - offset * height - 1) && !(i % 5 == 0) && !(((i) % 5) == width - offset)) {
				catflip = false;
			}
			else {

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

		cout << Xmoves << endl;
		cout << "It is Player O's turn" << endl;

		o1 = true;
	}
	else {
		cout << Omoves << endl;
		cout << "It is Player X's turn" << endl;

	}
	unsigned int x;
	unsigned int y;

	try {
		this->prompt(x, y);
	}
	catch (returncodes e){
		throw e;
	}

	while ((x >= 4 || y >= 4) || (x == 0 || y == 0) || ((this->gameboard[(long long)((y * height) + x)].out == "X") || (this->gameboard[(long long)(x + (y * height))].out == "O"))) {
		if ((this->gameboard[x + (y * height)].out == "X") || (this->gameboard[x + (y * height)].out == "O")) {
			//while ((this->gameboard[x + (y * height)].out == "X") || (this->gameboard[x + (y * height)].out == "O")) {
			cout << "Oops! That space is already taken!" << endl;
			try {
				this->prompt(x, y);
			}
			catch (returncodes e) {
				throw e;
			}

			//}
		}

		if (x == 0 || y == 0) {
			//while (x == 0 || y == 0) {
			cout << "Oops! no pieces can be put in the 0th row or column" << endl;
			try {
				this->prompt(x, y);
			}
			catch (returncodes e) {
				throw e;
			}

			//}
		}

		if (x >= 4 || y >= 4) {
			//while (x >= 4 || y >= 4) {
			cout << "Oops! no pieces can be put outside the 3x3 grid" << endl;
			try {
				this->prompt(x, y);
			}
			catch (returncodes e) {
				throw e;
			}

			//}
		}
	}


	turncounter++;
	if (o1) {
		// O -> black
		piece p(black, "Team O", "O");
		this->gameboard[x + (y * height)] = p;
		Omoves += "X -> " + to_string(x) + " ,  " + to_string(y) + "| ";
		return;
	}
	else {
		// X -> white
		piece p(white, "Team X", "X");
		this->gameboard[x + (y * height)] = p;
		Xmoves += "Y -> " + to_string(x) + " ,  " + to_string(y) + "| ";
		return;
	}

}

bool TicTacToeGame::draw() {
	if (done()) {
		return false;
	}
	for (unsigned int i = 0; i < gameboard.size(); ++i) {
		if (!(gameboard[i].out == X || gameboard[i].out == O)) {
			return false;
		}
	}
	return true;
}

bool TicTacToeGame::done() {

	//Vertical Check
	for (size_t i = 0; i < height; ++i) {
		std::string token;
		//is the token ever flipped?
		bool tokenflip = false;
		bool declare = true;

		int tokenctr = 0;
		for (size_t j = 0; j < width; ++j) {

			if (!(this->gameboard[(i + width * j)].out == token)) {
				//Empty piece
				if (this->gameboard[(i + width * j)].out != X && this->gameboard[(i + width * j)].out != O) {
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
				if (this->gameboard[(i + width * j)].out != X && this->gameboard[(i + width * j)].out != O) {
					tokenctr = 0;
					token = this->gameboard[(i + width * j)].out;
				}
				else {
					tokenctr++;
				}

			}
			if (tokenctr == twin) {
				return true;
			}
		}
	}


	for (size_t i = 0; i < height; ++i) {
		std::string token;
		//is the token ever flipped?
		bool tokenflip = false;
		bool declare = true;

		int tokenctr = 0;

		for (size_t j = 0; j < width; ++j) {

			if (!(this->gameboard[(j + width * i)].out == token)) {
				//Empty piece
				if (this->gameboard[(j + width * i)].out != X && this->gameboard[(j + width * i)].out != O) {
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
				if (this->gameboard[(j + width * i)].out != X && this->gameboard[(j + width * i)].out != O) {
					tokenctr = 0;
					token = this->gameboard[(j + width * i)].out;
				}
				else {
					tokenctr++;
				}

			}
			if (tokenctr == 2) {
				return true;
			}
		}
	}

	//Check Right Diagonals

	for (size_t i = 0; i < height; ++i) {
		std::string token;
		//is the token ever flipped?
		bool tokenflip = false;
		bool declare = true;

		int tokenctr = 0;
		for (size_t j = 0; j < width; ++j) {
			//Overflow guard
			if ((width * i) + (j + width * j) >= width * height) {
				break;
			}


			if (!(this->gameboard[(width * i) + (j + width * j)].out == token)) {
				//Empty piece
				if (this->gameboard[(width * i) + (j + width * j)].out != X && this->gameboard[(width * i) + (j + width * j)].out != O) {
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
				if (this->gameboard[(width * i) + (j + width * j)].out != X && this->gameboard[(width * i) + (j + width * j)].out != O) {
					tokenctr = 0;
					token = this->gameboard[(width * i) + (j + width * j)].out;
				}
				else {
					tokenctr++;
				}

			}
			if (tokenctr == 2) {
				return true;
			}
		}

		for (size_t j = 0; j < width; ++j) {
			//Overflow guard
			if (i + (j + width * j) >= width * height) {
				break;
			}


			if (!(this->gameboard[i + (j + width * j)].out == token)) {
				//Empty piece
				if (this->gameboard[i + (j + width * j)].out != X && this->gameboard[i + (j + width * j)].out != O) {
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
				if (this->gameboard[i + (j + width * j)].out != X && this->gameboard[i + (j + width * j)].out != O) {
					tokenctr = 0;
					token = this->gameboard[i + (j + width * j)].out;
				}
				else {
					tokenctr++;
				}

			}
			if (tokenctr == 2) {
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
				if (this->gameboard[j + (((width - offset)-i) + width * i)].out != X && this->gameboard[j + (((width - offset)-i) + width * i)].out != O) {

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
				if (this->gameboard[j + (((width - offset)-i) + width * i)].out != X && this->gameboard[j + (((width - offset)-i) + width * i)].out != O) {

					tokenctr = 0;
					token = this->gameboard[j + (((width - offset)-i) + width * i)].out;
				}
				else {

					tokenctr++;
				}

			}

			if (tokenctr == 2) {

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
				if (this->gameboard[(((width - offset)-i) + width * i) - (j * width)].out != X && this->gameboard[(((width - offset)-i) + width * i) - (j * width)].out != O) {
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
				if (this->gameboard[(((width - offset)-i) + width * i) - (j * width)].out != X && this->gameboard[(((width - offset)-i) + width * i) - (j * width)].out != O) {
					tokenctr = 0;
					token = this->gameboard[(((width - offset)-i) + width * i) - (j * width)].out;
				}
				else {
					tokenctr++;
				}

			}
			if (tokenctr == twin) {
				return true;
			}
		}

	}



	return false;


}

string TicTacToeGame::printBoard() {
	TicTacToeGame& game = *this;
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
			for (int j = 0; j < game.longestOut; j++) {
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
			for (size_t j = 0; j < game.longestOut; j++) {
				out += " ";
			}
			out += to_string(i / width);
		}
	}

	return out;
}