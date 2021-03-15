 // deque_assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <deque>
#include "my_deque.h"
#include "my_deque_iterator.h"

using namespace std;

void AreEqual(int* a, int* b) {
    cout << &a << " = " << &b << endl;
    return;
}
void AreEqual1(int a, int b) {
    cout << a << " = " << b << endl;
    return;
}




int main()
{
    int verbose = 0;
    int init_size = 32;
    int n = 32;
    // Jon Shidal: Feel free to use this file to test your program via the command line with tests you create.
  

    my_deque d = my_deque(init_size);
    for (int i = 0; i < n; i++) {
        d.push_back(i);
    }

    for (int i = 0; i < n; i++) {
        AreEqual1((n - (i + 1)), d.pop_back());
    }

    d.~d();

    /*
        //my_deque d = my_deque(init_size);
        for (int i = 1; i <= n / 2 + 1; ++i) {
            d.push_back(i);
        }s
        for (int i = 1; i <= n / 4 + 2; ++i) {
            d.pop_back();
        }
        AreEqual(init_size / 2 - n / 8 - 1, int(d.get_lIndex()));
        AreEqual(init_size / 2 + n / 8 - 1, int(d.get_rIndex()));
        AreEqual(init_size, int(d.get_size()));
        AreEqual(n / 4 - 1, int(d.get_used()));
    */


    int noexitgarbage = 0;
    /*
    my_deque d = my_deque(init_size);
    int* init_mem = d.get_mem();
    for (int i = 1; i <= n / 2; ++i) {
        d.push_back(i);
    }
   AreEqual(d.pop_front(), 1);

    d.push_back(1);
    int* after_mem = d.get_mem();
    AreEqual(init_size / 2 - n / 4 - 1, int(d.get_lIndex()));
    AreEqual(init_size / 2 + n / 4, int(d.get_rIndex()));
 AreEqual(init_size, int(d.get_size()));
 AreEqual(init_size / 2, int(d.get_used()));
 cout << init_mem << " = " << after_mem << endl;
 */
    /*
    my_deque d = my_deque(init_size);
    
    
    for (int i = 1; i <= n / 2 + 1; ++i) {
        d.push_front(i);
    }
    AreEqual(init_size - n / 4 - 2, int(d.get_lIndex()));
    AreEqual(init_size + n / 4, int(d.get_rIndex()));
   AreEqual(init_size * 2, int(d.get_size()));
    AreEqual(n / 2 + 1, int(d.get_used()));

    //

    my_deque d1 = my_deque(init_size);
    
    int* init_mem = d1.get_mem();
    for (int i = 1; i <= n / 2; ++i) {
        d1.push_front(i);
    }
    AreEqual(1, d1.pop_back() );
    d1.push_front(1);
    int* after_mem = d1.get_mem();
    AreEqual(init_size / 2 - n / 4 - 1, int(d1.get_lIndex()));
    AreEqual(init_size / 2 + n / 4, int(d1.get_rIndex()));
    AreEqual(init_size, int(d1.get_size()));
    AreEqual(init_size / 2, int(d1.get_used()));
    */

    /*
    for (int i = 1; i <= n / 2; ++i) {
        d.push_back(i);
    }
    cout << "Push: " << endl << endl;
    cout << d.queue[d.get_lIndex()+1] << endl;
    cout << "Pop" << endl;
    cout << d.pop_front() << endl;
   */


    /*
        my_deque d = my_deque(init_size);
        for (int i = 1; i <= n / 2 + 1; ++i) {
            d.push_front(i);
        }
        for (int i = 1; i <= n / 4 + 2; ++i) {
            d.pop_front();
        }
        AreEqual(init_size / 2 - n / 8 - 1, int(d.get_lIndex()));
        AreEqual(init_size / 2 + n / 8 - 1, int(d.get_rIndex()));
        AreEqual(init_size, int(d.get_size()));
        AreEqual(n / 4 - 1, int(d.get_used()));
    */

    /*
    int* init_mem = d.get_mem();
    int ticker = 0;
    for (int i = 1; i <= n / 2 + 1; ++i) {
        d.push_front(i);
    }
    cout << 1 << " = " << d.pop_front() << endl;
    d.push_back(1);
    int* after_mem = d.get_mem();

    cout << "tests: " << endl << endl;
    cout << init_size - n / 4 - 2 << " = " << int(d.get_lIndex()) << endl;

    cout << init_size + n / 4 << " = " << int(d.get_rIndex()) << endl;
    cout << init_size << " = " << int(d.get_size()) << endl;
    cout << init_size / 2 << " = " << int(d.get_used()) << endl;
    cout << init_mem << " = " << after_mem << endl;
    */
    

    /*
    cout << init_size / 2 - n / 4 - 1 << " = " << int(d.get_lIndex()) << endl;
    cout << init_size / 2 +  n / 4 << " = " << int(d.get_rIndex()) << endl;
    cout << init_size << " = " << d.get_size() << endl;
    cout << n / 4 - 1 << " = " << int(d.get_used()) << endl;
    */
    
    
    return 0;

    /*
    Assert::AreEqual(init_size, int(d.get_size()));
    Assert::AreEqual(init_size / 2, int(d.get_used()));
    Assert::AreEqual(init_mem, after_mem);

    cout << "Expected " << 1 << " = " << d.pop_front() << endl;
    cout << "Expected " << (init_size / 2 - 1) << " = " << int(d.get_lIndex()) << endl;
    cout << "Expected " << (init_size / 2) << " = " << int(d.get_rIndex()) << endl;
    cout << "Expected " << (init_size) << " = " << int(d.get_size()) << endl;
    cout << "Expected " << 0 << " = " << int(d.get_used()) << endl;
    */


  

    //my_deque d(8<< endl;

    //cout << "queue:     " << d.queue << endl;

   // cout << "get_mem(): " << d.get_mem() << endl;

    /*
    d.push_back(8);
    d.push_back(4);
    d.push_back(2);
    d.push_back(10);

    cout << "mem " << endl << endl;

    for (int i = 0; i <= d.get_size(); i++) {
        cout << "d[" << i << "]: " << d[i] << endl;
    }

    d.push_back(12);

    cout << "used: " << d.get_used() << endl;
    cout << "mem " << endl << endl;

    for (int i = 0; i <= d.get_size(); i++) {
        cout << "d[" << i << "]: " << d[i] << endl;

    }
    */
    //cout << endl << "Pop_Back ops" << endl;


    /*
    cout << d.pop_back() << endl;
    cout << d.pop_back() << endl;

    cout << "Mem" << endl;


    for(int i=0;i<10;i++){
        cout << d[i] << endl;
    }

    */






}

/*
deque <int> d; //Make empty deque

d.push_back(3); //push a 3

deque <int> newd(d); //Construct a new deque

d.push_back(5); //push a 5 onto the original

//List Both addresses
cout << &d << endl;
cout << &newd << endl;

//Call the destructor on d
//d.~deque();

cout << newd[0] << endl; //Will output 3 if deep

//cout << newd[1] << endl; //This will throw an error if it is a deep copy
 */
