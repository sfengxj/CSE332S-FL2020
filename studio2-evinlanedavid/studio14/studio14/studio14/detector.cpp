#include "detector.h"
#include<iostream>

using namespace std;

unsigned int detector::detector_count = 0;

detector::detector() : ID(detector_count) {
	++detector_count;
	cout << "detector constructor: " << this << "  " << ID << endl;
}

detector::~detector() {
	cout << "detector destructor: " << this << "  " << ID << endl;
}

unsigned int detector::getID() { return ID; }

wrapper::wrapper() : d(0), b(true) {
	cout << "wrapper constructor" << endl;
	detector* d = new detector();
	this->d = d;
}

wrapper::~wrapper(){
	cout << "wrapper destructor: " << this << endl;
	delete d;
} 