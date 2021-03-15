// studio8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "header.h"

using namespace std;

int main()
{
    Socks n = Socks();

    n.setY(8);

    cout << n.retsocks().getY() << endl;

    cout << n.getX() << "  " << n.getY() << endl;


    return 0;
}

Socks::Socks(): x(0), y(0), fixed(0){
   
}

int Socks::getX() const {
    return Socks::x;
}

int Socks::getY() const {
    return Socks::y;
}

int Socks::getFixed() const {
    return Socks::fixed;
}

Socks Socks::retsocks() {
    return *this;
}

/*
void Socks::setFixed(int a) {
    fixed = a;
    return;
}
*/

void Socks::setY(int a) {
    y = a;
    return;
}

void Socks::setX(int a) {
    x = a;
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
