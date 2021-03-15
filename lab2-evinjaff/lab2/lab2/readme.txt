Lab 1
By Evin Jaff
===================================================================================================================
Overview of the program:
This program takes in a text file that stores game pieces and the dimensions for a game board, and parses through 
all the text line-by-line to read and generate a gameboard from it.

===================================================================================================================
Notes about development:

Errors encountered:
casting strings to char/char*
At one point when writing the isDigit() statement to see if the string was a digit, I initially attempted to scan the substring
and cast it as a char for the function. I quickly reformatted the program such that this wasn't a problem, but it took me around
40 ish minutes to figure it out.

Warnings encountered:

unsigned int vs size_t:
When writing a few comparrisons and lines where unsigned ints and vector.size() interacted, I initially ran into no errors about 
doing addition or subtraction with the two elements. However, I had accidentally put my debug configuration in x64 early on, and
when I changed my debug back to x86, I started encountering compiler warning about int sizes. Luckily I was able to quickly resolve
these warning by use size_t to reduce data loss

scoped and unscoped enums:
I used enums that were not class enums in my lab that had names so that I could handle exceptions and add a layer of abstraction
to my code. Unfortunately, the way in which I had combined my enums resulted in me recieving compiler warnings that advised me to 
use a class enum. Using a class enum interfered with my ability to catch exception enums, so I opted to instead keep the warning, as
professor Shidal noted that points would not be taken off for scoped vs unscoped errors.

===================================================================================================================
Design Choices around writing the lab:

Blank Board statement:
While not technically required, I decided to make the program output "(Empty board)" when no game pieces are on the board. This
was not something required of the lab, but I thought fro the user perspective that they might want to know that the program
detected no pieces 

Blue Pieces:
The blue pices in the example tic tac board were invalid colors, and as a result not displayed on the board. So, I opted to add
a blue piece in my enumeration of colors, so that this test case gave an output as expected.

Overwrite vs Ignore:
When given a gamepiece further down in the text document with the same location as another gamepiece, I decided to overwrite the location
on the board with the new gamepiece instead of instead of the alternative option of ignoring the piece. However, both options seemed
valid.

Whitespace
When deciding how to handle printing out extra whitespace for blank game pieces, I chose to create the whitespace by generating the
blank space in the default constructor, as I thought that this made the code more generic, because if someone ever wanted to change
the icon of a blank piece to something other than a space such as a ? or ! to name a few ideas, all they would have to do is modify
the default constructor which would be a lot simpler than changing the for loop that prints.

===================================================================================================================
Sample Execution/Test Cases:

Standard Input:

command line argument: lab2.exe in.txt

file in.txt:
8 8
black stone X 0 0
black stone X 0 2
black stone X 1 1
black stone X 2 0
black stone X 2 2
black stone X 3 1
black stone X 4 0
black stone X 4 2
black stone X 5 1
black stone X 6 0
black stone X 6 2
black stone X 7 1
white stone O 0 6
white stone O 1 5
white stone O 1 7
white stone O 2 6
white stone O 3 5
white stone O 3 7
white stone O 4 6
white stone O 5 5
white stone O 5 7
white stone O 6 6
white stone O 7 5
white stone O 7 7

output:
  O   O   O   O
O   O   O   O
  O   O   O   O


X   X   X   X
  X   X   X   X
X   X   X   X

Empty Text file:

command line argument: lab2.exe empty.txt

empty.txt:

output:
Return code of 4
Error 4:
Improper heading in text file. Could not read a dimension line from the input file.
Please make sure you have a dimension declared at the top line  of the file such as '2 2'

Empty Pieces:

command line argument: lab2.exe emptypieces.txt

emptypieces.txt:
2 2

output:


(Empty Board)


===================================================================================================================

Allowed arguments that will run in Windows Command Prompt:

No arguments:
lab2.exe 
Will generate a usage function detailing how to run the program

One argument:
lab2.exe filename.txt
First argument is the filename of the gamepieces and board dimensions. Runs main program

===================================================================================================================

Enumerated Error/Return Values:

0: Successfull execution

1 (Error 1): Invalid Arguments. More than one argument was specified. The only argument in the execution after 'lab2.exe' 
should be the filename with its extension written as 'mytextinput.txt'

2 (Error 2): File Failed to Open. This means that the program was unable to open the file. This most likely means there was a typo
in the file name or extension.

3 (Error 3): Header Parse Error. This error will never return during execution, this error code is used internally to handle situations
where the starting dimensions of a board may be on lower lines.

4 (Error 4): Improper Header Syntax. This error will occur if the file can't find the a line in the text file that specifices the 
dimensions of the text file in the format 'int int'


===================================================================================================================
Extra Credit (Finding Neighbors):

I implemented the neighbor extra credit by executing a for loop that ran through every index of the board and checked if the output
of the gamepiece was not a blank space (i.e there was a piece there). Then, once I did that, I cycled through all of the possible indexes
that could be around the non-blank piece. However, as a safeguard to prevent indexing out-of-bounds areas, I instead performed checks
to make sure that none of the indexes were out of bounds, then printed out the values. Here is an example of a test case:

command: lab2.exe in.txt

in.txt:
8 8
black stone X 0 0
black stone X 0 2
black stone X 1 1
black stone X 2 0
black stone X 2 2
black stone X 3 1
black stone X 4 0
black stone X 4 2
black stone X 5 1
black stone X 6 0
black stone X 6 2
black stone X 7 1
white stone O 0 6
white stone O 1 5
white stone O 1 7
white stone O 2 6
white stone O 3 5
white stone O 3 7
white stone O 4 6
white stone O 5 5
white stone O 5 7
white stone O 6 6
white stone O 7 5
white stone O 7 7

output:
  O   O   O   O
O   O   O   O
  O   O   O   O


X   X   X   X
  X   X   X   X
X   X   X   X
For piece @ (0, 0)
1 , 1 black stone

For piece @ (2, 0)
1 , 1 black stone
3 , 1 black stone

For piece @ (4, 0)
3 , 1 black stone
5 , 1 black stone

For piece @ (6, 0)
5 , 1 black stone
7 , 1 black stone

For piece @ (1, 1)
0 , 2 black stone
2 , 2 black stone
0 , 0 black stone
2 , 0 black stone

For piece @ (3, 1)
2 , 2 black stone
4 , 2 black stone
2 , 0 black stone
4 , 0 black stone

For piece @ (5, 1)
4 , 2 black stone
6 , 2 black stone
4 , 0 black stone
6 , 0 black stone

For piece @ (7, 1)
6 , 2 black stone
0 , 2 black stone
6 , 0 black stone

For piece @ (0, 2)
1 , 1 black stone

For piece @ (2, 2)
1 , 1 black stone
3 , 1 black stone

For piece @ (4, 2)
3 , 1 black stone
5 , 1 black stone

For piece @ (6, 2)
5 , 1 black stone
7 , 1 black stone

For piece @ (1, 5)
0 , 6 white stone
2 , 6 white stone

For piece @ (3, 5)
2 , 6 white stone
4 , 6 white stone

For piece @ (5, 5)
4 , 6 white stone
6 , 6 white stone

For piece @ (7, 5)
6 , 6 white stone
0 , 6 white stone

For piece @ (0, 6)
1 , 7 white stone
1 , 5 white stone

For piece @ (2, 6)
1 , 7 white stone
3 , 7 white stone
1 , 5 white stone
3 , 5 white stone

For piece @ (4, 6)
3 , 7 white stone
5 , 7 white stone
3 , 5 white stone
5 , 5 white stone

For piece @ (6, 6)
5 , 7 white stone
7 , 7 white stone
5 , 5 white stone
7 , 5 white stone

For piece @ (1, 7)
0 , 6 white stone
2 , 6 white stone

For piece @ (3, 7)
2 , 6 white stone
4 , 6 white stone

For piece @ (5, 7)
4 , 6 white stone
6 , 6 white stone

For piece @ (7, 7)
6 , 6 white stone