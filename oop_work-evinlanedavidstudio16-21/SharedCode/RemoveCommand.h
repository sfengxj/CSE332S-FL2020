#pragma once
#include "../SharedCode/AbstractCommand.h"
#include "../SharedCode/AbstractFileSystem.h"

class RemoveCommand : public AbstractCommand {
	AbstractFileSystem* afs;

public:
	RemoveCommand(AbstractFileSystem* afs);
	virtual int execute(std::string s) override;
	virtual void displayInfo() override;
	virtual ~RemoveCommand() = default;

};