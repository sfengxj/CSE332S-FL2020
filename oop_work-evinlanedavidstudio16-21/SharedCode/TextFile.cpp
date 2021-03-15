//  Define the TextFile class here
#include "TextFile.h"
#include <iostream>

using namespace std;

TextFile::TextFile() : name(""), contents(vector<char>()) {}

TextFile::TextFile(string name) : name(name), contents(vector<char>()) {}

TextFile::TextFile(const TextFile & a): name(a.name), contents(a.contents){}

TextFile::TextFile(TextFile&& a) : name(a.name), contents(a.contents) {
	a.name = "";
	a.contents.resize(0); 
}

unsigned int TextFile::getSize(){
	return static_cast<unsigned int>(contents.size());
}

string TextFile::getName(){
	return name;
}

vector<char> TextFile::read() {
	vector<char> f;
	for (unsigned int i = 0; i < contents.size(); ++i) {
		f.push_back(contents[i]);
	}
	return f;
}

int TextFile::append(vector<char> c) {
	for (unsigned int i = 0; i < c.size(); ++i){
		contents.push_back(c[i]);
	}
	return successlocal;
}

int TextFile::write(vector<char> c) {
	contents.swap(c);
	return returns::successlocal;
}

void TextFile::accept(AbstractFileVisitor* visitor) {
	visitor->visit_TextFile(this);
}

AbstractFile* TextFile::clone(string newname) {
	AbstractFile* cloned = new TextFile(newname);
	cloned->write(this->read());

	return cloned;
}