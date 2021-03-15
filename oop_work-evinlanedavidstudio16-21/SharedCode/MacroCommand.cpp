#include "../SharedCode/AbstractFileFactory.h"
#include "../SharedCode/MacroCommand.h"
#include <iostream>
using namespace std;

MacroCommand::MacroCommand(AbstractFileSystem* afs) : afs(afs), aps(nullptr) {
}

int MacroCommand::execute(std::string s) {
	//ask aps to parse input, return vector<string>
	vector<string> commandArgs = aps->parse(s);

	//for each string, call the command's execute with that as args
	for ( unsigned int i = 0; i < commands.size(); i++) {
		//String Check - will write later
		string input = commandArgs[i];
		//Execute command according to string

		int retstat = commands[i]->execute(input);

		//if a command execute fails, return its error enum
		if(retstat){
			return retstat;
		}
	}

	//if none failed, return success
	return successlocal;
}

void MacroCommand::displayInfo() {
	
	//wrote display info for the parsing strategy to be called here (piazza)
	if (aps != nullptr){
		aps->displayInfo();
	} else {
		cout << "no macro commands exist" << endl;
	}
}

void MacroCommand::addCommand(AbstractCommand* command) {
	commands.push_back(command);
}

void MacroCommand::setParseStrategy(AbstractParsingStrategy* parsingStrategy) {
	this->aps = parsingStrategy;
}