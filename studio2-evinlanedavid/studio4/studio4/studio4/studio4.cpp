// studio4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


int main()
{

    unsigned int arr[2][3][5];
    /*
    cout << sizeof(arr) << endl; //120
    cout << sizeof(arr[0]) << endl; //60
    cout << sizeof(arr[0][0]) << endl; //20
    cout << sizeof(arr[0][0][0]) << endl; // 4
    */

    unsigned int* A = & arr[0][0][0];
    
    for (int i = 0; i <= sizeof(arr); i+=sizeof(arr[i]) ) {
        
        for (int j = 0; j<= sizeof(arr[i]); j+= sizeof(arr[i][j])) {

            for (int k = 0; k <= sizeof(arr[i][j]); k+= 4) {
               
                *A = (i/sizeof(arr[i])) * (j/ sizeof(arr[i][j])) * (k/sizeof(arr[i][j][k]));

                //cout << A << endl; // 4

                cout << *A << endl;

                A++;

                

            }
        } 
    }
 

}

/*arr[0][0][0]
arr[0][0][4]
arr[0][0][8]
arr[0][0][12]
arr[0][0][16]
arr[0][0][20]
arr[0][20][0]
arr[0][20][4]
arr[0][20][8]
arr[0][20][12]
arr[0][20][16]
arr[0][20][20]
arr[0][40][0]
arr[0][40][4]
arr[0][40][8]
arr[0][40][12]
arr[0][40][16]
arr[0][40][20]
arr[0][60][0]
arr[0][60][4]
arr[0][60][8]
arr[0][60][12]
arr[0][60][16]
arr[0][60][20]
arr[60][0][0]
arr[60][0][4]
arr[60][0][8]
arr[60][0][12]
arr[60][0][16]
arr[60][0][20]
arr[60][20][0]
arr[60][20][4]
arr[60][20][8]
arr[60][20][12]
arr[60][20][16]
arr[60][20][20]
arr[60][40][0]
arr[60][40][4]
arr[60][40][8]
arr[60][40][12]
arr[60][40][16]
arr[60][40][20]
arr[60][60][0]
arr[60][60][4]
arr[60][60][8]
arr[60][60][12]
arr[60][60][16]
arr[60][60][20]
arr[120][0][0]
arr[120][0][4]
arr[120][0][8]
arr[120][0][12]
arr[120][0][16]
arr[120][0][20]
arr[120][20][0]
arr[120][20][4]
arr[120][20][8]
arr[120][20][12]
arr[120][20][16]
arr[120][20][20]
arr[120][40][0]
arr[120][40][4]
arr[120][40][8]
arr[120][40][12]
arr[120][40][16]
arr[120][40][20]
arr[120][60][0]
arr[120][60][4]
arr[120][60][8]
arr[120][60][12]
arr[120][60][16]
arr[120][60][20]*/

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
