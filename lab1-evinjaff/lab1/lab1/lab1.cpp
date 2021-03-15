/* lab1.cpp : This file contains the 'main' 'readfile' and 'errmessage' function. Program execution begins and ends here.
 * Written by Evin Jaff
 * email: evin@wustl.edu
 */

#include "Header.h"

int main(int argc, char** argv)
{
    
    

    vector <string> A;
    vector<int> nums;

    //Program should only execute with one other argument
    if (argc != 2) {
        errmessage(Invalid_arguments);
        return Invalid_arguments;
    }
    char* filename = argv[1];



    if (readfile(A, filename) == success) {
        
        for (unsigned int i = 0; i < A.size(); i++) {

            //boolean for a flipped value
            bool hasdigit = true;

            for (unsigned int j = 0; j < A[i].length(); j++) {
                
                
               //Will switch if any digit is not true
                if (!isdigit((A[i][j])) ) {
                    hasdigit = false;
                    cout << A[i] << endl;
                    break;
                }



            }

            if (hasdigit) {
                istringstream abc(A[i]);

                
                int numchar;
                abc >> numchar;
                nums.push_back(numchar);

            }
            

            
        }
        for (unsigned int i = 0; i < nums.size(); i++) {

            cout << nums[i] << endl;

        }
    }
    else {
        errmessage(File_failed_to_open);
        return File_failed_to_open;
    }
    return success;
}


int readfile(vector <string>& A, char* filename) {
    ifstream ifs;
 
    ifs.open(filename);
    string i;

    if (ifs.is_open()) {
        cout << "File open, success!" << endl;
       
       
        //cast as bool. If nothing to feed in -> will return false | if something to feed in. -> returns true
        while ((bool)(ifs >> i)) {

            A.push_back(i);

        }

        

        

        
    }
    else {
        
        return File_failed_to_open;
    }

    
    ifs.close();
    return success;


}

void errmessage(int err) {
    switch (err) {
    case 1:
        cout << "Error " << err<< ": failed to open file. Make sure your file name is spelled correctly and that it is in the same folder as the executable" << endl;
        break;
    case 2:
        cout << "Error " << err << ": invalid arguments. Please see the usage function below:" << endl;
        cout << "Usage: " << endl;
        cout << "Name: Lab1.exe" << endl;
        cout << "Command Line Argument: lab1.exe <filename (including extension)>" << endl;
        break;
    default:
        break;
    }
}
/* From Assignment:

Declare and define a function for parsing an input file(for example input_file.txt)
containing text(character) strings and different forms of whitespace(spaces, tabs, line
    breaks, etc.)., and then extract one string at a time from that file until there are no more strings
    to read(hint: the input file stream >> extraction operator will return false when it cannot
        extract another string from the file). 
    Each time a non - empty string is extracted(any empty strings should be simply ignored),
    the function should push back the string into the vector that was passed as the first
    parameter.If the file cannot be opened or the function encounters any other problems
    during its execution it should print out a helpful error message indicating the problem and
    return the appropriate enumeration label(that has a non - zero integer value) for failing to
    open an input file; otherwise it should return the enumeration label(that has integer value
        0) that indicates success.
        */


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
