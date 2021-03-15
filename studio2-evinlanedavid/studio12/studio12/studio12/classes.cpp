#include "header.h"
using namespace std;
A::A() {
	cout << "A() Construct" << endl;
}

A::~A() {
	cout << "~A() Destruct" << endl;
}

void A::grass() {
	cout << "A$() Method" << endl;
}

B::B() {
	cout << "B() Construct" << endl;
}

B::~B() {
	cout << "~B() Destruct" << endl;
}

void B::grass() {
	cout << "B$() Method" << endl;
}