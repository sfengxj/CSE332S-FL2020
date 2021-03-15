// Studio19.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "../../SharedCode/AbstractFile.h"
#include "../../SharedCode/TextFile.h"
#include <iostream>

using namespace std;

int main()
{
	
	AbstractFile* txt = new TextFile("last testament.txt");
	vector<char> vect = { 'h','e','n','l','o'};
	txt->write(vect);
	vector<char> read = txt->read();

	for (unsigned int i = 0; i < read.size(); ++i) {
		cout << read[i];
	}
	cout << endl;

	return 0;
}
