Lab 1
By Evin Jaff
===================================================================================================================
Overview of the program:
This program takes in a text file written in basic characters, and parses through all text in the file. All text fragments 
containing any non-numeric characters (defined as 0-9) will be printed out, making a new line for each fragment.
A fragment is denoted by some form of whitespace between characters (ex. a tab, space of new line). If the text fragment is
purely composed of numberic characters (this will exclude negative numbers), then it will instead be interpreted as an integer 
added into a vector of integers that will then print out all the detected integers in the order that they are parsed.

===================================================================================================================
Notes about development:

Errors encountered:
casting strings to char/char*
At one point when writing the isDigit() statement to see if the string was a digit, I initially attempted to scan the substring
and cast it as a char for the function. I quickly reformatted the program such that this wasn't a problem, but it took me around
40 ish minutes to figure it out.

Warnings encountered:

unsigned int and int type mismatch:
When writing a few iterator for loops to loop through a vector, I ran into a compiler warning when making my iterator an integer, since
the terminating statement in the for loop (vector.size()) returned an unsinged int, since no negative indexes should exist. As
a result, I had to make a special precaution to make my iterating variables an unsinged integer, which is actually more efficient
since I wouldn't have needed to use the negative numbers in the field.

Design Choices around writing the lab:

File Open success statement:
While not technically required, I decided to add in a success statement for when the text file was correctly opened. This doesn't
affect the execution of the program, but does make it a little more intuitive for the programmer

Negative Integers:
I chose not to make my parsing inclusive of negative numbers based off of my interpretation of the lab 1 assignment, since
it was written such that only strings with numeric characters should be printed, so this would by logic, exclude negative numbers.

Overflow integers: Depending on architecture, the size of an integer may vary, but within this program integers beyond the limit
value of what an integer can be stored as will be capped at it's maximum value. I decided to handle overflow integers this way for
a few main reasons; one option I thought about was storing the integer as a long instead, but I soon realized that eventually a long
or even a long long or an unsigned long long would also encounter the same problem. Additionally, after reading the assignment, it
specifies using a vector of integers, so I opted to follow the assignment guidelines and stick with a vector of integers since it
seems like the test cases wouldn't need to handle integers.

===================================================================================================================
Sample inputs:

input: 100 Hello
output: Hello 100

since 100 is only composed of numeric digits, it will go after any strings

input: 80 1Hello 
output: 1Hello 80

Even though 1Hello contains a numeric character, the whole string must contain numeric characters to count.

===================================================================================================================
Functions inside lab1.cpp source file:

int main(int argc, char** argv)
Description:
The main function of the program that the executable runs.

Arguments:

int argc: The amount of arguments passed in

char ** argv: An array of character pointers that convey the main arguments

Return values:
0: Success! Returns fine
1: Error inside readfile function associated with opening file. Often implies a misspelled or nonexistent file
2: Error in number of arguments passed in. Most likely due to too few or too many arguments passed in.

-------------------------------------------------------------------------------------------------------------------

int readfile(vector <string>& A, char* filename)
Description: A helper method that handles reading text from a text file and inserting text into a vector of strings.

Arguments:

vector<string>& A
Passes by referene a string of vectors. The vector will be filled with C++-style strings that are pushed in through 
extraction of the text file fed in.

char* filename
A C-style string that is the name of the text-style file in the same directory as the executable. The C-style string should include the file extension.

Return values:
0: Success! Was able to successfully call the file and push strings onto the vector.
1: Failed to get the file.

-------------------------------------------------------------------------------------------------------------------

void errmessage(int err)
Description: A helper method that takes in a non-zero integer that originate from an integer returned from an error 
and then runs a switch statement for the passed in integer and prints a unique helpful error message depending on
the integer passed in.

Arguments:

int err
A integer that represents a non-zero integer representing an error returned in the program.

Return values:
none as the method is void 

===================================================================================================================
How to execute this program

Once an executable has been compiled, open the Windows Command Prompt and change directories until inside the location
of the executable. Once there, type the name of the executable and the filename inside the same directory following this
style of syntax: 'lab1.exe myfile.txt'

===================================================================================================================
Errors/Return Values

0: Successfull execution

1 (Error 1): Error in opening the file. Check your spelling or make sure the file is in the same folder as the executable

2 (Error 2): Error in arguments passed in. The only argument in the execution after 'lab1.exe' should be the filename with
its extension written as 'mytextinput.txt'

===================================================================================================================
Extra Credit (Compiling in Linux!!):

SSH directory:

[evin@shell ~]$ ls
Desktop  Downloads  lab2.m  Music  My Documents  perl5  Pictures  Public  source  Templates  Videos  WINDOWS

No additional errors were tested when compilig the code in Linux.

Test case on Linux:

input:
C++ was originally created in 1985.
Since it is 2020, C++ will turn 35 this year.
A pointer in the Windows registry looks like this 0x000AF0
Pope Urban II called for the first crusade in 1095,


234567889032446212324567897654

A long on x64 is 8 bytes.

1.4

-2.8

  780.32456

output:

File open, success!
C++
was
originally
created
in
1985.
Since
it
is
2020,
C++
will
turn
this
year.
A
pointer
in
the
Windows
registry
looks
like
this
0x000AF0
Pope
Urban
II
called
for
the
first
crusade
in
1095,
A
long
on
x64
is
bytes.
1.4
-2.8
780.32456
35
2147483647
8