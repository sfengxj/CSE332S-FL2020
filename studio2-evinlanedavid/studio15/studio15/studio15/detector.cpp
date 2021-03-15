#include "detector.h"
#include<iostream>

using namespace std;

unsigned int detector::detector_count = 0;

detector::detector(){
	++detector_count;
	cout << "detector constructor: " << this << "  " << ID << endl;
}

detector::detector(const detector &orig) {
	if (!(*this == orig)) {
		++detector_count;
		this->ID = orig.ID;

		cout << "detector copy constructor: " << this << "  " << ID << endl;
	}
	else {
		cout << "if not triggered" << endl;
	}
}

detector & detector::operator=(const detector &a){
	if(!(this==&a)){
		detector temp(a);
		swap(temp.ID, this->ID);
		cout << "copy assignment operator" << endl;
	}
	return *this;
}

detector::detector(detector&& d) {

	if (!(*this==d)){
		cout << "move constructor" << endl;
		this->ID = d.ID;

		//
		d.ID = 0;
		//d = nullptr;
	}
}

detector& detector::operator=(const detector && a){
	if (!(this == *a)){
		//delete this->ID;
		this->ID = a.ID;
		a.ID = 0;
	}
	return *this;
}


bool detector::operator ==(const detector& a){
	if (this == &a){
		return true;
	}
	return false;
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