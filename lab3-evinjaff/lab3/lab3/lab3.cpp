/* lab3.cpp: main source file where execution starts
 * Written by Evin Jaff
 * email: evin@wustl.edu
 */

#include "declarations.h"
#include "tictactoe.h"
using namespace std;

/*Check that exactly one argument (or two if you did the extra credit portion) has
been passed to the program (in addition to the program's name), and if so that the passed argument is "TicTacToe".
If not, your program should pass the program name and a second string showing the format of the command line arguments
that need to be given, into a call to the usage function you implemented in the previous lab, and then return the (unique
non-zero) value that was returned by that function.*/

int main(int argc, char** argv)
{ 
    string arg1(argv[gametype]);

    if (argc == arguments && arg1 == "TicTacToe") {
        TicTacToeGame s;
        return s.play();
    }
    else {
        usageFunction(argv[0]);
        return usagemessage;
    }
}

void usageFunction(char* exename) {
    cout << "Usage Function:" << endl;
    cout << exename << ".exe" << endl;
    cout << "Command Line Argument: lab3.exe <gametype>" << endl;
    return;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
