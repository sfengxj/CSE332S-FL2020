// studio12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include"header.h"
using namespace std;

int main()
{
    A a;
    B b;

    A& c = a;
    A& d = b;
    B& e = b;

    A* f = &a;
    A* g = &b;
    B* h = &b;

    cout << "a" << endl;
    a.grass();
    cout << "b" << endl;
    b.grass();
    cout << "c" << endl;
    c.grass();
    cout << "d" << endl;
    d.grass();
    cout << "e" << endl;
    e.grass();

    cout << "f" << endl;
    f->grass();
    cout << "g" << endl;
    g->grass();
    cout << "h" << endl;
    h->grass();

    


    cout << "Hello World!\n";

    return 0;
}

