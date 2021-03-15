/* lab2.cpp : This file contains the 'main' function, as well as the helper methods 'makelowercase', 'errmessage', 'usageFunction'. 
 * Program execution begins and ends here.
 * Written by Evin Jaff
 * email: evin@wustl.edu
 */
#include "declarations.h"
#include "pieces.h"
#include "board.h"

using namespace std;

int main(int argc, char** argv)
{
    //Output Usage function if no arguments other thatn program name are provided
    if (argc == usagearguments) {
        usageFunction(argv[arguments::executable_name]);
        return errors::success;
    }

    char* filename = argv[filename_index];

    ifstream ifs;

    ifs.open(filename);

    if (!ifs.is_open()) { errmessage(File_failed_to_open); return File_failed_to_open; }

  
    //dimension ints
    unsigned int x;
    unsigned int y;

    try {
        while (readboard(ifs, x, y) != success) {
           
        }
    }
    catch (errors e) {
        errmessage(e);
        return e;
    }
    
        
    
    
    int maxval = x * y;

    vector<piece> pieces(maxval);

    addpieces(ifs, pieces, x, y);

    printBoard(pieces, x, y);

    neighbor(pieces, x, y);



    return success;
}

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

void errmessage(int e) {
    //Spit out error code
   

    cout << "Return code of " << e << endl;

    cout << "Error " << e << ": " << endl;

    switch (e) {
         return;
    case errors::Improper_head_synatx:
        cout << "Improper heading in text file. Could not read a dimension line from the input file." << endl << "Please make sure you have a dimension declared at the top line  of the file such as '2 2' " << endl;
        return;
    case errors::File_failed_to_open:
         cout << "Failure opening file, check your filename syntax." << endl;
         return;
    default:
         cout << "Unknown error" << endl;
    }

}

void usageFunction(char * exename) {
    
    cout << exename << endl;
    cout << "Usage Function:" << endl;
    cout << "Game board barser program. Use the syntax: lab2.exe yourfilename.txt to import a gameboard with this dimension syntax:" << endl;
    cout << "4 4" << endl;
    cout << "And the syntax 'Color name token xposition yposition' for game pieces (ex. BLACK STONE A 0 7)" << endl;
    return;
}