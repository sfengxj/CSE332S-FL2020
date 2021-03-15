Lab 3

By Evin Jaff

Overview of the program:
This program builds off of the code writte in lab 3, and implements a playable tic tac toe game

===================================================================================================================
Notes about development:

Errors encountered:

Old Code Woes:

Since a lot of code from Lab 2 was refactored as a template for this lab, a lot of old dependencies as well as uneccessary headers inclusions meant that I had to spend a decent amount of time fixing up header and function definitions.

Don't Run and Compile:

I frequently enounctered a pretty easy error that just said that it couldn't compile the executable while it was running, since using cin meant that sometimes it was easy to forget to terminate. Luckily, that's something a quick ^c can fix!

Warnings encountered:

unsigned int vs size_t:
When writing a few comparrisons and lines where unsigned ints and vector.size() interacted, I initially ran into no errors about 
doing addition or subtraction with the two elements. I had this same error last lab  and was luckily able to use size_t to work it out if it came up. 

scoped and unscoped enums:
I used enums that were not class enums in my lab. Unfortunately, the way in which I had combined my enums resulted in me recieving compiler warnings that advised me to  use a class enum whever I tried to catch exceptions with the class enum. Using a class enum interfered with my ability to catch exceptions, so I opted to instead keep the warning, as professor Shidal noted that points would not be taken off for scoped vs unscoped errors.

===================================================================================================================
Design Choices around writing the lab:

Prompt:
I opted to "split the bill" in terms of when to repeat prompt. While most of the repeating was done in the turn() method, I opted to handle some things, such as illegal indexes, inside the prompt() method since it seemed easier at the time. 

Turn counts:

It was a little vague in the instructions for who's turn counts to print out when, so I chose to design the turncount printing such that the opposing player's turn counts were printed out on the gameboard. It wasn't explicity listed which one to output, so I tried to do my best to print out the board. I could easily flip it, but I kinda thought that it might be better for the player to see the opponent's moves since that would have been updated more recently.

===================================================================================================================
Sample Execution/Test Cases:

Standard Game:

command line argument: lab3.exe TicTacToe

Output:

4
3
2
1
0
 0 1 2 3 4

It is Player O's turn
Enter valid coordinates in the form x,y

(Accepting input)



Test Case Snippets:

Feeding in an invalid index:

It is Player O's turn
Enter valid coordinates in the form x,y
4,4

Oops! no pieces can be put in the last row or column
Enter valid coordinates in the form x,y

Feeding in a zero index:



Consecutive incorrect inputs:

4
3
2    O
1
0
 0 1 2 3 4
X -> 2 ,  2|
It is Player X's turn
Enter valid coordinates in the form x,y
4,4

Oops! no pieces can be put outside the 3x3 grid
Enter valid coordinates in the form x,y
0,0

Oops! no pieces can be put in the 0th row or column
Enter valid coordinates in the form x,y
2,2

Oops! That space is already taken!
Enter valid coordinates in the form x,y



Allowed arguments that will run in Windows Command Prompt:

One argument:
lab2.exe gametype
gametype: name of the type of game, for this lab it is just TicTacToe

Any other Argument:

Will output a usage message. The usage function is this:

Usage Function:
lab3.exe.exe
Command Line Argument: lab3.exe <gametype>



===================================================================================================================

Enumerated Error/Return Values:

0: Full Game execution: The game was fully played until someone won

1 Quit Game: A user-prompted game quit was triggered by typing quit when asking for a piece. While this is a non-zero return, this isn't really an error, however it's important to denote the different return type.

2 Cats Game: I'm sure everyone's played at least one game of Tic-Tac-Toe that's ended in a cat's game. Like Quit game, this isn't a hard error, just a non-standard return.

===================================================================================================================