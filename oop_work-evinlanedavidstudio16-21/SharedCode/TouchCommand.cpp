#include "../SharedCode/TouchCommand.h"
#include "../SharedCode/AbstractFile.h"
#include "../SharedCode/PasswordProxy.h"
#include <iostream>
#include <sstream>

using namespace std;


TouchCommand::TouchCommand(AbstractFileSystem* afs, AbstractFileFactory* aff) : afs(afs), aff(aff) {}


int TouchCommand::execute(std::string s) {

	//don't allow file names over 20 characters. if given one, take first 20 characters
	if (s.length() > 20) {
		s.resize(20);
	}

	//set up iss and parse input
	istringstream iss(s);

	string afilename; 
	string suffix; 

	iss >> afilename;
	iss >> suffix;


	//if creating with password
	if (suffix.compare("-p") == 0) {

		//get password
		string password;
		cout << "What is the password?" << endl;
		getline(cin, password);
//		cin.ignore();
		//create file and proxy
		AbstractFile* file = this->aff->createFile(afilename);
		PasswordProxy* pp = new PasswordProxy(file, password);

		//if file creation failed
		if (file == nullptr) {
			delete file;
			return addfileFailed;
		}

		else {
			//add file to afs
			if (this->afs->addFile(afilename, pp) == 0) {
				return successlocal;
			}
			else {
				return addfileFailed;
			}
		}
	}

	//create without password
	else {
		AbstractFile* file = this->aff->createFile(s);

		//if file creation failed
		if (file == nullptr) {
			delete file;
			return addfileFailed;
		}

		else {
			//add file to afs
			if (this->afs->addFile(s,file) == 0) {
				return successlocal;
			}
			else {
				return addfileFailed;
			}
		}
	}
}

void TouchCommand::displayInfo() {
	cout << "touch creates a file, touch can be invoked with the command: touch <filename>" << endl;
}