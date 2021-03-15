#pragma once
#include "../SharedCode/AbstractFileSystem.h"
#include "../SharedCode/AbstractFileFactory.h"
#include "../SharedCode/AbstractCommand.h"
#include <map>

class CommandPrompt {
	std::map<std::string, AbstractCommand*> commands;
	AbstractFileSystem* fs;
	AbstractFileFactory* ff;
public:
	CommandPrompt();
	void setFileSystem(AbstractFileSystem*);
	void setFileFactory(AbstractFileFactory*);
	int addCommand(std::string, AbstractCommand*);
	int run();
protected:
	void listCommands();
	std::string prompt();
};