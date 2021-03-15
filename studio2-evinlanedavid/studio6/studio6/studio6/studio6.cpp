// studio6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "def.h"

int main()
{
   // cout << "Hello World!\n" << endl;
    vector<int> vector;
    
    vector.push_back(7);
    vector.push_back(-2);
    vector.push_back(10);
    
    try {
        cout << squareElement(8, vector) << endl;
    }
    catch(enum::errors & i) {
        cout << "outer catch block " << i << endl;
        return errors::out_of_range;
    }
   
        
    return 0;
}

int squareElement(unsigned int g, vector<int> k) {
    //try {
        if (g >= k.size()) {
            cout << "get to the if block" << endl;
            throw errors::out_of_range;
        }

        return k[g] * k[g];

    //}

    return success;
}



/*squareElement(), which takes a vector<int> and an unsigned int as
parameters and returns the square of the element of the provided vector at the index
given by the second parameter. Create a vector in main() and push a few values to it.
Call squareElement() with this vector and some different index values to make sure it
behaves as expected. What happens when you call this function and provide an index
that is bigger than the size of the vector?*/


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
