/* lab2.cpp : This is legacy lab2 code to allow for the pieces and board files to still run
 * Program execution begins and ends here.
 * Written by Evin Jaff
 * email: evin@wustl.edu
 */
#include "declarations.h"
#include "tictactoe.h"

using namespace std;



//Passes a string by reference and makes it lowercase.
//Chose to make it int to denote success, if any failure arise in testing, will make try/catch block
int makelowercase(string &s) {
    string newlowercase = "";
    
    for (unsigned int i = 0; i < s.length(); i++) {
        newlowercase += tolower(s[i]);
    }
    s = newlowercase;
    return success;
    
}

