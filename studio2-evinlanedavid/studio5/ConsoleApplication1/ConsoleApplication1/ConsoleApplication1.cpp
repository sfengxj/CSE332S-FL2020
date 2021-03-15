// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Header.h"

int main()
{
    cout << "Hello World!\n";

    int one = 7;
    int two = 16;

    int* pone = &one;
    int* ptwo = &two;

    int * const cpone = &one;
    int * const cptwo = &two;

    mySwap(cpone, cptwo);

    cout << one << endl;
    cout << two << endl;
    cout << cpone << endl;
    cout << cptwo << endl;
    cout << *cpone << endl;
    cout << *cptwo << endl;
}

void mySwap(int &one, int &two) {
    cout << "mySwap version 1" << endl;
    int temp = one;
    one = two;
    two = temp;
    return;
}

void mySwap(int * & a, int * & b){
    cout << "mySwap version 2" << endl;
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void mySwap(int * const & a, int * const & b){
    cout << "mySwap version 3" << endl;
    int temp = *a;
    *a = *b;
    *b = temp;
    
    return;

}

void reduce(int& a, int& b) {
     

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
