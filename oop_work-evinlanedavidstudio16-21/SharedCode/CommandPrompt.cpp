#include "CommandPrompt.h"

#include <iostream>
#include <sstream> 

using namespace std;

CommandPrompt::CommandPrompt(): fs(nullptr), ff(nullptr) {}

void CommandPrompt::setFileSystem(AbstractFileSystem * filesystem){
	this->fs = filesystem;
}

void CommandPrompt::setFileFactory(AbstractFileFactory * filefactory){
	this->ff = filefactory;
}

int CommandPrompt::addCommand(std::string str, AbstractCommand * command){
	auto ret = commands.insert(pair<string, AbstractCommand*>(str, command));
	
	if (ret.second){
		return returns::successlocal;
	} else {
		return returns::addCommandFailed;
	}
}

void CommandPrompt::listCommands(){
	map<string, AbstractCommand*>::iterator it;
	for (it = commands.begin(); it != commands.end(); it++){
		cout << it->first << " ";
	}
	cout << endl;
}

std::string CommandPrompt::prompt(){
	cout << "Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command." << endl;
	cout << "$   " << flush;
	string input;
	getline (cin, input);

	return input;
}

int CommandPrompt::run(){
	string input = prompt();

	if (input.compare("q") == 0){
		return returns::commandPromptQuit; 
	}
	if (input.compare("help") == 0){
		cout << "Commands include: ";
		listCommands();
		return returns::commandPromptHelp; 
	}
	
	//check to see if one word
	bool oneWord = true;
	for (unsigned int i = 0; i < input.size(); ++i){
		if (input[i] == ' '){
			oneWord = false;
		}
	}

	if (oneWord){
		auto mapCommand = commands.find(input);
		if (mapCommand != commands.end()){
			int executeReturn= mapCommand->second->execute(""); //return execute's success or fail
			if (executeReturn==successlocal){
				return returns::sucessfulCommand;
			} else{
				cout << "Executing that command gave an error!" << endl;
			}
		} 
		cout << "Oops! That command doesn't exist" <<endl;
		return returns::commandPromptDNE;
	}

	//more than one word

	//set up iss to parse input
	istringstream iss;
	iss.str(input);

	string first;
	iss >> first;

	//if first word is help
	if (first.compare("help") == 0){
		string second;
		iss >> second;

		auto mapCommand = commands.find(second);
		if (mapCommand != commands.end()){
			mapCommand->second->displayInfo(); 
			return returns::sucessfulCommand;
		}
		cout << "Oops! That command doesn't exist" <<endl;
		return returns::commandPromptDNE;
	}

	//first word is not help
	//get from space to the end
	string commandBody = input.substr(input.find(' ')+1); 

	auto mapCommand = commands.find(first);
	if (mapCommand != commands.end()){
		int executeReturn= mapCommand->second->execute(commandBody); //return execute's success or fail
		if (executeReturn==successlocal){
			return returns::sucessfulCommand;
		} else {
			cout << "Executing that command gave an error!" << endl;
		}
	}
	cout << "Oops! That command doesn't exist" <<endl;
	return returns::commandPromptDNE;

}