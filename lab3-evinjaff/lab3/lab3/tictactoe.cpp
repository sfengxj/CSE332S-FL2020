/* tictactoe.cpp: source file that contains the functions and operators to make the TicTacToeGame class run
 * Written by Evin Jaff
 * email: evin@wustl.edu
 */
#include "tictactoe.h"
#include "board.h"


using namespace std;


TicTacToeGame::TicTacToeGame() : X("X"), O("O"),turncounter(firstturn),Xmoves(""),Omoves("") {
	gameboard = std::vector<piece>(width * height);
	//String constants for symbols to avoid hardcoding later on

}

//std::ostream& operator <<(const TicTacToeGame& game, std::ostream&) {
std::ostream& operator<< (std::ostream& ostr, const TicTacToeGame& game){
	ostr << printBoard(game.gameboard, width, height);
	
	return ostr;
}

int TicTacToeGame::play() {
	try {
		while (true) {
			turn();

		}
	}
	catch (returncodes e) {
		return e;
	}
}

void TicTacToeGame::turn() {

	cout << *this << endl;

	if (done()) {
		if (turncounter % 2) {

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
			
			if (this->gameboard[i].out == " " && !(i<=width) && !(i >= arrwidth*height - 1) && !(i%5 == 0) && !(((i) % 5) == arrwidth) ){
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
	if (turncounter % 2) {
		
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

	this->prompt(x, y);

	while( (x >= 4 || y >= 4 )|| (x == 0 || y == 0) || ((this->gameboard[x + (y * height)].out == "X") || (this->gameboard[x + (y * height)].out == "O")) ){
		if ((this->gameboard[x + (y * height)].out == "X") || (this->gameboard[x + (y * height)].out == "O")) {
			//while ((this->gameboard[x + (y * height)].out == "X") || (this->gameboard[x + (y * height)].out == "O")) {
				cout << "Oops! That space is already taken!" << endl;
				this->prompt(x, y);
			//}
		}

		if (x == 0 || y == 0) {
			//while (x == 0 || y == 0) {
				cout << "Oops! no pieces can be put in the 0th row or column" << endl;
				this->prompt(x, y);
			//}
		}

		if (x >= 4 || y >= 4) {
			//while (x >= 4 || y >= 4) {
				cout << "Oops! no pieces can be put outside the 3x3 grid" << endl;
				this->prompt(x, y);
			//}
		}
	}

	//Catches overflow if quit is called
	if (x >= width && y >= height) {
		cout << "User quit the game - Rage Quit!" << endl;
		cout << turncounter << " turns were played." << endl;
		throw quitcode;
	}
	else {
		turncounter++;
		if (o1) {
			// O -> black
			piece p(black, "Team O", "O");
			this->gameboard[x + (y * height)] = p;
			Omoves += "X -> " + to_string(x)+ " ,  " + to_string(y) + "| ";
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

	
	

}

void TicTacToeGame::prompt(unsigned int& x, unsigned int& y) {
	cout << "Enter valid coordinates in the form x,y" << endl;
	string input;
	cin >> input;

	
	unsigned int firstryx;
	unsigned int firstryy;

	if (input == "quit") {
		//overflow #'s to flag quitting the game
		x = 0;
		y = 0;
		--x;
		--y;
		return;

	}
	//breakup space
	for (unsigned int i = 0; i < input.length(); i++) {
		if (input[i] == ',') {
			input[i] = ' ';
		}
	}



	
	istringstream iss(input);


	bool succ1 = (bool)(iss >> firstryx);
	bool succ2 = (bool)(iss >> firstryy);




	bool testvalid = (!(firstryx + (firstryy * width) >= width * height)) && (!(firstryx > arrwidth)) && (!(firstryy > arrheight));
	
	
	if (testvalid && succ1 && succ2) {

			x = firstryx;
			y = firstryy;
			cout << endl;
			return;
	}


	bool notvalid = (!(x + (y * width) >= width * height)) && (!(x > arrwidth)) && (!(y > arrheight));


	while (!notvalid) {
		unsigned int testx;
		unsigned int testy;

		cout << "Invalid input, enter valid coordinates in the form x,y" << endl;
		string input;
		cin >> input;

		if (input == "quit") {
			//overflow #'s to flag quitting the game
			x = 0;
			y = 0;
			x--;
			y--;
			return;

		}
		

		//breakup space
		for (unsigned int i = 0; i < input.length(); i++) {
			if (input[i] == ',') {
				input[i] = ' ';
			}
		}

		


		istringstream iss(input);


		bool succ1 = (bool)(iss >> testx);
		bool succ2 = (bool)(iss >> testy);
		

		notvalid = (!(testx + (testy * width) >= width * height)) && (!(testx > arrwidth)) && (!(testy > arrheight));

		if (notvalid && succ1 && succ2) {
		
				x = testx;
				y = testy;
				break;
		}
	}
	
	return;

}

bool TicTacToeGame::draw() {
	if (done()) {
		return false;
	}
	for (unsigned int i = 0; i < gameboard.size();++i) {
		if (!(gameboard[i].out == X || gameboard[i].out == O)) {
			return false;
		}
	}
	return true;
}

bool TicTacToeGame::done() {

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
			if (tokenctr == 2) {
				return true;
			}
		}
	}


	for (unsigned int i = 0; i < height; ++i) {
		std::string token;
		//is the token ever flipped?
		bool tokenflip = false;
		bool declare = true;

		int tokenctr = 0;

		for (unsigned int j = 0; j < width; ++j) {

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

		for (unsigned int j = 0; j < width; ++j) {
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



	for (int j = 0; j < width; ++j) {
	
		std::string token;
		int tokenctr = 0;
		for (int i = arrwidth; i >= (j); i--) {


			//is the token ever flipped?
			bool tokenflip = false;
			bool declare = true;

			if (j + (((arrwidth)-i) + width * i) >= width * height || j + (((arrwidth)-i) + width * i) < 0) {
				break;
			}


			if (!(this->gameboard[j + (((arrwidth)-i) + width * i)].out == token)) {
				//Empty piece
				if (this->gameboard[j + (((arrwidth)-i) + width * i)].out != X && this->gameboard[j + (((arrwidth)-i) + width * i)].out != O) {

					tokenctr = 0;
					token = this->gameboard[j + (((arrwidth)-i) + width * i)].out;
				}
				else {
		
					tokenctr = 0;
					token = this->gameboard[j + (((arrwidth)-i) + width * i)].out;
			
					//Nonempty piece


				}
			}
			else {
				if (this->gameboard[j + (((arrwidth)-i) + width * i)].out != X && this->gameboard[j + (((arrwidth)-i) + width * i)].out != O) {
			
					tokenctr = 0;
					token = this->gameboard[j + (((arrwidth)-i) + width * i)].out;
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
		for (int i = arrwidth; i >= (j); i--) {

			// = gameboard[(((arrwidth) - i) + width * i) - (j * width)].out;
			//is the token ever flipped?
			bool tokenflip = false;
			bool declare = true;
			
			if ((((arrwidth) - i) + width * i) - (j * width) >= width * height || (((arrwidth) - i) + width * i) - (j * width) < 0) {
				break;
			}

			if (!(this->gameboard[(((arrwidth) - i) + width * i) - (j * width)].out == token)) {
				//Empty piece
				if (this->gameboard[(((arrwidth) - i) + width * i) - (j * width)].out != X && this->gameboard[(((arrwidth) - i) + width * i) - (j * width)].out != O) {
					tokenctr = 0;
					token = this->gameboard[(((arrwidth) - i) + width * i) - (j * width)].out;
				}
				else {
					tokenctr = 0;
					token = this->gameboard[(((arrwidth) - i) + width * i) - (j * width)].out;
					//Nonempty piece


				}
			}
			else {
				if (this->gameboard[(((arrwidth) - i) + width * i) - (j * width)].out != X && this->gameboard[(((arrwidth) - i) + width * i) - (j * width)].out != O) {
					tokenctr = 0;
					token = this->gameboard[(((arrwidth) - i) + width * i) - (j * width)].out;
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



	return false;
	

}