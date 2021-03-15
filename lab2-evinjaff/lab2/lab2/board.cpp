/* board.cpp: cpp source file that holds functions around generating a gameboard from the fed in pieces
 * Written by Evin Jaff
 * email: evin@wustl.edu
 */
#include "pieces.h"
#include "declarations.h"
#include "board.h"
using namespace std;

int readboard(std::ifstream &ifs, unsigned int &width, unsigned int &height) {
	bool succ1 = false;
	bool succ2 = false;
	bool succ3 = false;

	if (ifs.is_open()) {
			string a;
			bool succ1 = (bool)(getline(ifs, a));
			
			istringstream iss;

			iss.str(a);

			succ2 = (bool)(iss >> width);

			succ3 = (bool)(iss >> height);

			if (succ1 && succ2 && succ3) {
				//value is good! Variables have been assigned
				return success;
			}
			else if (succ1 && (!succ2 || !succ3)) {
				return Improper_head_synatx;
			}
			else if (!succ1 && (!succ2 || !succ3)) {
				throw Improper_head_synatx;
			}
			else {
				//Return non-zero number if other error
				return Head_parse_error;
			}
	}
	else {
		return File_failed_to_open;
	}
	
}

int addpieces(std::ifstream& ifstream, vector<piece>& pieces, unsigned int& width, unsigned int& height) {
	string s;

	
	//keeps running so long as there's a new line to extract
	while ((bool)(getline(ifstream, s)) ) {
		istringstream iss;
		iss.str(s);

		string                                  color;
		string                                   name;
		string                                   disp;
		unsigned int                                x;
		unsigned int                                y;
		
		//Casts >> operater as boolean to check success of insertion. Will also check if the piece is out of bounds
		bool succ1 =             (bool)(iss >> color);
		bool succ2 =             (bool)(iss >>  name);
		bool succ3 =             (bool)(iss >>  disp);
		bool succ4 =             (bool)(iss >>     x);
		bool succ5 =             (bool)(iss >>     y);
		bool succ6 =          x > width && y > height;
		
		bool succ7 = stringtoEnum(color) != Piece_type::other;
		//cout << succ7 << endl;
		//cout << stringtoEnum(color) << endl;
		
		if (succ1 && succ2 && succ3 && succ4 && succ5 && !succ6 && succ7) {
			piece p = piece(stringtoEnum(color), name, disp);
			
			unsigned int inx = x + (y * width);
			if (inx < pieces.size()) {
				pieces[inx] = p;
			}
			
		}
	}
	return success;
}

/* printBoard()
Input: A const vector of game pieces(for example of type ​const vector<game_piece>&)​and two unsigned integers by value as its parameters.
Output: Prints out the gameboard
*/
void printBoard(const vector<piece> & vect, unsigned int width, unsigned int length) {
	
	string s;

	//Made an unsigned long long as to avoid data loss since vect.size() is up to 64 bits. Made unsigned because negative indicies aren't needed
	size_t init = vect.size() - 1;
	for (int i = init; i >= 0 ; i--) {
		if (i%length) {
			s += vect[i].out + " ";
		}
		else {
			s += vect[i].out;
			std::reverse(s.begin(), s.end());
		    cout << s;
			cout << endl;
			s = "";
		}
	}
	piece p;
	string blank = p.out;
	bool flip = true;
	for (unsigned int i = 0; i < vect.size(); i++) {
		if (!vect[i].out._Equal(blank)) {
			// a piece exists! no need to keep checking!
			flip = false;
			break;
			
		}
	}
	if (flip == true) {
		//Friendly indcator that the board is empty to avoid confusion
		cout << "(Empty Board)" << endl;
	}
	return;
}

void neighbor(const vector<piece>& vect, unsigned int width, unsigned int length) {
	piece p;
	string blank = p.out;
	for (unsigned int i = 0; i < vect.size(); i++) {
		//cout << i << endl;
		if (vect[i].out != p.out) {
			//Opening data on piece
			cout << "For piece @ (" << i%width << ", " << i/width << ")" << endl;

			

			//All neighboring indexes, size_t is used to avoid warnings related to size
			size_t tl = i   + width - neighbordiff;
			size_t tr = i   + width + neighbordiff;
			size_t r  = i   +         neighbordiff;
			size_t l  = i           - neighbordiff;
			size_t bl = i   - width - neighbordiff;
			size_t br = i   - width + neighbordiff;
			size_t b  = i       -            width;
			size_t t  = i       +            width;


			size_t nums[8] = { tl, tr, r, l, bl, br, b, t };
			//Construct vector of nums with array.
			vector<int> num(nums, nums + sizeof(nums)/sizeof(int));

			bool botl = i + width - 1 < 0;
			bool botr = i + width + 1 < 0;
			bool bor  =         i + 1 < 0;
			bool bol  =         i - 1 < 0;
			bool bobl = i - width - 1 < 0;
			bool bobr = i - width + 1 < 0;
			bool bob  = i     - width < 0;
			bool bot  = i     + width < 0;
			
			if (i % width == invalid::startingindx) {
				num[etl] = invalid::inv;
				num[el]  = invalid::inv;
				num[ebl] = invalid::inv;
			}
			if (i % width == width) {
				num[etr] = invalid::inv;
				num[er]  = invalid::inv;
				num[ebr] = invalid::inv;
			}
			if (i-width < invalid::startingindx) {
				num[eb]  = invalid::inv;
				num[ebr] = invalid::inv;
				num[ebl] = invalid::inv;
			}
			size_t h = i + width;
			if (h > vect.size() ) {
				num[etl] = invalid::inv;
				num[etr] = invalid::inv;
				num[et]  = invalid::inv;
			}

			for (unsigned int k = 0; k < num.size(); k++) {
			
				//Avoids type errors on comparison
				size_t comp = num[k];

				if (!(num[k] < 0) && !(comp > vect.size()-1)) {
					//Valid index

					if (vect[num[k]].type != Piece_type::invalid) {
						cout << (num[k] % width) << " , " << (num[k] / width) << " " << enumtoString(vect[num[k]].type) << " " << vect[num[k]].name << endl;
					}
				}
				else {
				
				}
			}
			cout << "" << endl;
		}
		
	}
	return;
}