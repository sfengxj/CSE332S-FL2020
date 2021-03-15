Lab 4 - Evin Jaff, Lane Bohrer, David Moon

Overview of the program:
	Our Lab 4 program takes a user input for game name (and potentially more parameters from Extra Credit) and game moves to play a game of either TicTacToe or Gomoku.
	Both TicTacToe and Gomoku classes derive from a common base class where their methods and many of their member variables are defined. 
	
Notes about specific choices:
	We used getline to take in our user input so that it could accept a wider set of input (space separated values) and cleaned up the input more efficiently.
	We allow input in the format <x,y> or <x y> where x and y are integers within the valid game board.
	We use a shared pointer to the base class to hold the game object so that it can be dynamically chosen at run time. Using a shared pointer also means that the virtual destructor is called when main returns. 
	We moved general member variables to the base class (leaving specific things like output strings in derived classes).
	We chose to leave a couple of the methods in the base class because they were the most general (prompt and play). The rest were refactored into derived classes to be implemented more specifically.
	When working with the longest display string, we added a member variable that tracked the longest string (specifically checking during the constructor to see what the longest index was) and added spaces in the print method accordingly. This meant altering our printBoard function, which was added from the Lab 3 code.
	User input like game names and "quit" are converted to lowercase before being used by our program to accept a wider range of user input without complicating our code and if statements.
	The usage function was modeled off of the Node Package Manager's (npm) command line usage function as a reference format

Work Breakdown:
	Starter code for the lab was pulled from Evin's Lab 2 and Lab 3 code.

	Work Done by Evin:
	-updated printboard()/ostream insertion operator to dynamically adjust spacing to work with C++ style strings and multi-digit gameboards as well as mutli-character pieces
	-Wrote Extra Credit nxn gameboard
	-Updated done() method
	-Wrote new exception handlers to handle errors such as quits
	-Rewrote the usage function

	Work Done by Lane:
	-Wrote Extra Credit nxn gameboard
	-Making play() and prompt() pure virtual functions to be implemented in the derived classes
	-Updated usage function
	-Updated done() method
	-Removed magic numbers

	Work Done by David:
	-Transferred lab 3/lab 2 code for TicTacToe class
	-Transferred lab 3/lab 2 code for Gomoku class
	-Implemented original choose game method, adjusted later due to type errors

	Work done as a group of 3 on Liveshare:
	-Refactored the code to adapt to the framework of a GameBase class.
	-Added the static method that takes in the command line arguments and generates a gameboard using shared pointers
	-Creating the draw() method to check for when to call a draw before all pieces are played
	-Fixed gamequit crashing error

Warnings/Errors:
	Our most frequent warning (over a hundred oof) was an arithmetic overflow error. Along with this we also had some "conversion from 'size_t' to 'int', possible loss of data" errors, and some signed/unsigned mismatched errors.
	These were largely resolved together by changing the types of some of our member variables and iterators to size_t.

	While doing the refactoring, we saw a lot of inaccessible and 'no declaration found' errors, but most were relatively easily resolved.
	While doing the member functions, we ran into an issue with inheritance and the error: ErrorC2247 'GameBase::play' not accessible because 'TicTacToeGame' uses 'protected' to inherit from 'GameBase'. After asking on Piazza, we figured out that it was an issue with the inheritance mode being wrong.

	While making choose_game, we ran into Error C2259 'GameBase': cannot instantiate abstract class. This is because we were trying to create a base class object in main to call choosegame on, but because it's an abstract class, we had to create a derived class object and call choose_game which could change its class

	While entering coordinate input, we ran into Errors where entering non numerical values printed out error messages per string character. We tried to address the issue by using cin.ignore(MAX_INT) but this ended up breaking our quit exit. 

Test Cases:
	When given no game name, the program returns a unique error code, Invalid_Input_Bad_Game and calls the usage function that prints the following:
		Usage: lab4.exe <gametype>
		Where <gametype> is one of:
		TicTacToe, Gomoku
		Define Game Board Specifics (Gomoku only)
		lab4.exe<gametype>
		lab4.exe<gametype> <numtowin>
	When declared coordinates are out of bounds, the program returns an error message asking again for user input.
	When declared coordinates have already been played, the program returns an error message asking for user input on a valid unoccupied coordinate.
	When non numerical input strings are declared, the program returns an error message asking again for a valid numerical coordinate.
	When "quit" is declared by user input, the program sees and returns with a quit return code.
	When n pieces (declared initially by user input or default if not given) are in line, the program sees and returns with a win return code.
	When there is no path to victory left, the program sees this and returns with a draw return code.

Extra Credit:
	The choose_game method was expanded to check how many command line inputs were passed. Depending on that value, it calls the correct constructor. 
	We tested this with different input combinations to verify that invalid input (like a toWin value greater than the size) wouldn't be accepted and an error+usage message would be returned.
	Additionally, when a gameboard dimension that is smaller than 3 is passed in, then it returns a specific error message indicating that a board cannot be smaller than 3
	
	When the gameboard is passed in just a size that is smaller than 5, the amount in a row to win will be equal to the board's size dimenstion (ex. 3x3 -> 3 in a row to win)

	Test:
	Initial output: 
		.... Debug>lab4.exe gomoku 5 4
		5
		4
		3
		2
		1
		X  1  2  3  4  5

		It is Black's turn
		Enter valid coordinates in the form x,y

	After some rounds:
		5              W
		4  B
		3  B     W  W
		2  B
		1  B
		X  1  2  3  4  5
		
		Winner winner chicken dinner - Black wins!



      |\      _,,,---,,_
ZZZzz /,`.-'`'    -.  ;-;;,_
     |,4-  ) )-,_. ,\ (  `'-'
    '---''(_/--'  `-'\_)  