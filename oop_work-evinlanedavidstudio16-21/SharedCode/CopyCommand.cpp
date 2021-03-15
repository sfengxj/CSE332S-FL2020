#include "../SharedCode/CopyCommand.h"
#include "../SharedCode/AbstractFileFactory.h"
#include <iostream>
#include <sstream>

using namespace std;

CopyCommand::CopyCommand(AbstractFileSystem* afs) : afs(afs) {}

int CopyCommand::execute(std::string s) {
	//set up iss and parse input
	string afilename;
	string newname;
	istringstream iss(s);

	iss >> afilename;
	iss >> newname;

	//check if file dne
	set<string> fileList;
	fileList = afs->getFileNames();
	if (fileList.find(afilename) == fileList.end()) {
		return copyFailed;
	}

	//if file name already exists
	string namewithexten = newname + afilename.substr(afilename.find('.'));
	if (fileList.find(namewithexten) != fileList.end()) {
		return copyFailed;
	}

	//create copy
	AbstractFile* file = afs->openFile(afilename);
	AbstractFile* copy = file->clone(namewithexten);
	afs->closeFile(file);
	return afs->addFile(copy->getName(), copy);
}

void CopyCommand::displayInfo() {
	cout << "cp copies a file and can be invoked with: cp <file_to_copy> <new_name_without_extension>" << endl;
}