#include "RemoveCommand.h"
#include <string>
#include <iostream>

using namespace std;

RemoveCommand::RemoveCommand(AbstractFileSystem* afs) : afs(afs) {}

int RemoveCommand::execute(string filename) {

	//get set of file names
	set<string> fileList;
	fileList = afs->getFileNames();

	//check if file dne
	if (fileList.find(filename) == fileList.end()) {
		return doesNotExist;	
	}	
	
	//if file exists, call delete on it
	return afs->deleteFile(filename);

}

void RemoveCommand::displayInfo() {
	cout << "rm removes a file. invoke with: rm <filename>" << endl;
}