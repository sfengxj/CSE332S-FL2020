// Studio18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "../../SharedCode/AbstractFileSystem.h"
#include "../../SharedCode/SimpleFileFactory.h"
#include "../../SharedCode/SimpleFileSystem.h"
#include "../../SharedCode/AbstractFileFactory.h"
#include "../../SharedCode/ImageFile.h"
#include "../../SharedCode/TextFile.h"
#include <iostream>

using namespace std;

int main()
{
	AbstractFileSystem* fs = new SimpleFileSystem();
	AbstractFileFactory* ff = new SimpleFileFactory();

	AbstractFile* imgFile = ff->createFile("Christmas2008.img");
	fs->addFile(imgFile->getName(), imgFile);
	
	AbstractFile* absFile = fs->openFile(imgFile->getName());
	absFile->read();

	AbstractFile* txtFile = ff->createFile("mywill.txt");
	vector<char> words = { 'f', 'u', 'n', ' ', 'w','o','r','d','s' };
	txtFile->write(words);
	fs->addFile(txtFile->getName(), txtFile);

	AbstractFile* ourFile = fs->openFile(txtFile->getName());
	ourFile->read();


	return 0;
}
