// definition of ImageFile class here

#include "ImageFile.h"
#include <iostream>

using namespace std;

ImageFile::ImageFile(string name) : name(name),size(0) {}

unsigned int ImageFile::getSize(){
	return static_cast<unsigned int>(contents.size());
}

string ImageFile::getName(){
	return name;
}

int ImageFile::write(std::vector<char> vect){
	unsigned int size = static_cast<unsigned int>(vect.size()); // declare size of input vector
	char charsize = vect[size - 1]; // identify the last element of the vector
	size_t chartoint = static_cast<size_t>(charsize)  - '0'; // convert the last element of the vector from char to int. warning here is ignored bc a character to size_t int cast is sufficient
	vector<char> contentvect(contents); // declare a new vector which will retain contents of the file
	contentvect.resize((chartoint * chartoint), 0); // resize the content vector to the size of the file declared in the input file
	if (size-1 != contentvect.size()) {
		vect.clear();
		vect.resize(0,0);
		// return non zero value for error
		return returns::writeFailed;
	}
	else {

		for (unsigned int i = 0; i < vect.size()-1; i++) {
			if (vect[i] != 'X' && vect[i] != ' '){
				vect.clear();
				vect.resize(0, 0);
				return returns::writeFailed;
			}
		}

		for (int i = 0; i < contentvect.size(); i++) {
			if (contentvect[i] != ' ' || contentvect[i] != 'X') {
				contentvect[i] = vect[i];
			}
			else {
				vect.clear();
				vect.resize(0, 0);
				return returns::writeFailed;
			}
		}
	}
	contents = contentvect;
	this->size = chartoint;
	return returns::successlocal; 

}

int ImageFile::append(std::vector<char> vect){
	return returns::No_Append; 
}

vector<char> ImageFile::read(){
	vector<char> f;
	for (size_t y = size-1; y < size; --y){ //ignore warning about counting down from minimum because of unsigned iterator
		for (size_t x = 0; x < size; ++x) {
			f.push_back ( contents[coorToIndex(x, y)]);
		}
	}
	return f;
}

size_t ImageFile::coorToIndex(size_t x, size_t y){
	return (y*size + x);
}

void ImageFile::accept(AbstractFileVisitor* visitor) {
	visitor->visit_ImageFile(this);
}

AbstractFile* ImageFile::clone(string newname) {
	AbstractFile* cloned = new ImageFile(newname);
	cloned->write(this->read());

	return cloned;
}