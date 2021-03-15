#include "../SharedCode/TouchCommand.h"
#include "../SharedCode/AbstractFile.h"
#include "../SharedCode/AbstractFileFactory.h"
#include "../SharedCode/LSCommand.h"
#include "../SharedCode/MetadataDisplayVisitor.h"
#include <set>
#include <iostream>


using namespace std;



LSCommand::LSCommand(AbstractFileSystem* afs) : afs(afs) {}

int LSCommand::execute(std::string s) {

	//get set of file names
	set<string> fileNames = afs->getFileNames();
	set<string>::iterator it;

	//if printing metadata
	if (s.compare("-m") == 0) {
		for (it = fileNames.begin(); it != fileNames.end(); ++it) {
			AbstractFileVisitor* visitor = new MetadataDisplayVisitor();

			AbstractFile* file = afs->openFile(*it);
			file->accept(visitor);
			afs->closeFile(file);
			cout << endl;
		}
	}
	//not printing metadata
	else if (s.compare("") == 0) {

		int count = 0; //used to add either space or new line to format output correctly

		for (it = fileNames.begin(); it != fileNames.end(); ++it) {
			//print name
			cout << *it;

			//add spaces or new line (putting two file names to a line)
			if (count % 2 == 0) {
				for (unsigned int i = 0; i < 20 - it->size(); i++) {
					cout << " ";
				}
			}
			else {
				cout << endl;
			}
			++count;
		}
	}
	else {
		return returns::commandPromptDNE;
	}

	cout << endl;
	return successlocal;
}

void LSCommand::displayInfo() {
	cout << "ls lists files in the current directory" << endl;
}