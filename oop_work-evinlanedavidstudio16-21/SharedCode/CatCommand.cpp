#include "../SharedCode/CatCommand.h"
#include "../SharedCode/AbstractFile.h"
#include "../SharedCode/AbstractFileFactory.h"
#include "../SharedCode/LSCommand.h"
#include "../SharedCode/BasicDisplayVisitor.h"
#include <iostream>
#include <sstream>

using namespace std;

CatCommand::CatCommand(AbstractFileSystem* afs) : afs(afs) {}

int CatCommand::execute(std::string s) {
	//set up iss and parse input
	istringstream iss(s);
	string afilename;
	string suffix;
	iss >> afilename;
	iss >> suffix;

	AbstractFile* file = afs->openFile(afilename);

	//if file couldn't be opened
	if (file == nullptr) {
		afs->closeFile(file);
		return returns::catFailed;
	}

	//check if appending
	if (suffix.compare("-a") == 0) {
		//first, print current contents
		AbstractFileVisitor* visitor = new BasicDisplayVisitor();
		file->accept(visitor);
		cout << endl;

		//instructions for user
		cout << "input data to append to the file, \":wq\" to save and quit, or \":q\" to quit without saving" << endl;

		string userInput;
		string currentLine;
		unsigned int status = successlocal;

		while (status == successlocal) { //will be false at end of input
			//get input
			getline(cin, currentLine);
			
			//check if quitting
			if (currentLine.compare(":wq") == 0) {
				status = catSaveQuit;
			}
			if (currentLine.compare(":q") == 0) {
				status = catQuit;
			}

			//if input is neither
			userInput += currentLine + "\n";
			currentLine = "";
		}

		//if quitting
		if (status == catQuit) {
			afs->closeFile(file);
			return successlocal;
		}

		//if saving and quitting
		if (status == catSaveQuit) {

			//if it's an image file, can't append
			string extension = afilename.substr( afilename.find("."));
			if (extension.compare(".img") == 0) {
				afs->closeFile(file);
				return catFailed;
			}
		
			if (userInput.size() > 5) { //user gave more than nothing
				//make string into vector of chars
				vector<char> vect(userInput.length() - lengthToCut); //lengthToCut is 5, takes off \n:wq\n
				copy(userInput.begin(), userInput.end() - lengthToCut, vect.begin()); //lengthToCut is 5, takes off \n:wq\n
				file->append(vect);
			}
			afs->closeFile(file);

			return successlocal;
		}
	}

	//not appending
	else {

		//instructions for user
		cout << "input data to write to the file, \":wq\" to save and quit, or \":q\" to quit without saving" << endl;

		string userInput;
		string currentLine;
		unsigned int status = successlocal;

		while (status == successlocal) { //will be false at end of input

			getline(cin, currentLine);

			//check if quitting
			if (currentLine.compare(":wq") == 0) {
				status = catSaveQuit;
			}
			if (currentLine.compare(":q") == 0) {
				status = catQuit;
			}

			//if input is neither
			userInput += currentLine + "\n";
			currentLine = "";
		}

		//if just quitting
		if (status == catQuit) {
			afs->closeFile(file);
			return successlocal;
		}

		//if saving and quitting
		if (status == catSaveQuit) {

			if (userInput.size() > 5) { //user gave more than nothing
				//make string into vector of chars
				vector<char> vect(userInput.length() - lengthToCut); //lengthToCut is 5, takes off \n:wq\n
				copy(userInput.begin(), userInput.end() - lengthToCut, vect.begin()); //lengthToCut is 5, takes off \n:wq\n
				file->write(vect);
			}

			afs->closeFile(file);

			return successlocal;
		}
	}

	afs->closeFile(file);
	return catFailed;
}

void CatCommand::displayInfo() {
	cout << "cat writes to a file and can be invoked with: cat <filename> [-a]" << endl;
}