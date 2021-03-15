// Studio17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "../../SharedCode/ImageFile.h"
#include <iostream>

using namespace std;

int main()
{
	AbstractFile* abstractfile = new ImageFile("rock");

	cout << "Name: " << abstractfile->getName() << endl;
	cout << "Size: " << abstractfile->getSize() << endl;

	vector<char> v = {'X',' ','X',' ','X',' ','X',' ', 'X', '3'};
	abstractfile->write(v);
	abstractfile->read();

	return 0;
}