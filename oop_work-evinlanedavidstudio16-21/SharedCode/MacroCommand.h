#pragma once
#include "../SharedCode/AbstractCommand.h"
#include "../SharedCode/AbstractFileSystem.h"
#include "../SharedCode/AbstractParsingStrategy.h"

class MacroCommand : public AbstractCommand {
	std::vector<AbstractCommand*> commands;
	AbstractParsingStrategy* aps;
	AbstractFileSystem* afs;

public:
	MacroCommand(AbstractFileSystem* afs);
	virtual int execute(std::string s) override;
	virtual void displayInfo() override;
	virtual ~MacroCommand() = default;
	void addCommand(AbstractCommand* command);
	void setParseStrategy(AbstractParsingStrategy* aps);
};