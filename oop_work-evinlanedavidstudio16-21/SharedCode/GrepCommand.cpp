#include "../SharedCode/GrepCommand.h"
#include "../SharedCode/AbstractFileFactory.h"
#include "../SharedCode/SearchVisitor.h"
#include <iostream>
#include <sstream>

using namespace std;

GrepCommand::GrepCommand(AbstractFileSystem* afs) : afs(afs) {}

int GrepCommand::execute(std::string s) {

	//iterate through files, pass search visitor to each
	set<string> fileNames = afs->getFileNames();
	set<string>::iterator it;

	for (it = fileNames.begin(); it != fileNames.end(); ++it) {
		AbstractFileVisitor* visitor = new SearchVisitor(s);

		AbstractFile* file = afs->openFile(*it);
		file->accept(visitor);
		afs->closeFile(file);
	}
	return successlocal;
}

void GrepCommand::displayInfo() {
	cout << "grep searches all files and prints out those that include a given string. invoke with grep <string>" << endl;

}