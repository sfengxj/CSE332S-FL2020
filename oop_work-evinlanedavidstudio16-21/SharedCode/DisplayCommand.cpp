#include "../SharedCode/DisplayCommand.h"
#include "../SharedCode/AbstractFileFactory.h"
#include "../SharedCode/BasicDisplayVisitor.h"
#include <iostream>
#include <sstream>

using namespace std;

DisplayCommand::DisplayCommand(AbstractFileSystem* afs) : afs(afs) {}

int DisplayCommand::execute(std::string s) {
	//set up iss and parse input
	string afilename;
	string suffix;
	istringstream iss(s);

	iss >> afilename;
	iss >> suffix;

	//check if file dne and opens correctly
	set<string> fileList;
	fileList = afs->getFileNames();
	if (fileList.find(afilename) == fileList.end()) {
		return displayFailed;
	}

	AbstractFile* file = afs->openFile(afilename);
	
	if (file == nullptr){
		return returns::null_Pointer;
	}
	
	//check if -d is present
	if (suffix.compare("-d") == 0) {
		//unformatted file content displayed
		vector<char> contents = file->read();

		for (unsigned int i = 0; i < contents.size(); ++i) {
			if (contents[i] == '\n') {
				cout << endl; 
			}
			else {
				cout << contents[i];
			}
		}
		cout << endl;

		afs->closeFile(file);
		return successlocal;
	}
	//no -d, formatted content displayed (using visitor)
	else {

		AbstractFileVisitor* visitor = new BasicDisplayVisitor();
		file->accept(visitor);

		afs->closeFile(file);
		return successlocal;
	}


}

void DisplayCommand::displayInfo() {
	cout << "ds displays a file and can be invoked with: ds <filename> [-d]" << endl;
}