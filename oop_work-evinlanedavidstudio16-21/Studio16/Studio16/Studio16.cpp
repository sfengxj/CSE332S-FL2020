// Studio16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\..\\SharedCode\TextFile.h"
#include <iostream>

using namespace std;


int main()
{
	AbstractFile* abstractconfession = new TextFile();

	char confession [] = { 's', 'i', 'm', 'o', 'n', 'y' };
	vector<char> confessionvector(confession, confession + sizeof(confession)/sizeof(char));

	abstractconfession->append(confessionvector);

	abstractconfession->read();

	return 0;
}


