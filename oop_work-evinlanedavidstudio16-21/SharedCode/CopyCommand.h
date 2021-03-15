#pragma once
#include "../SharedCode/AbstractCommand.h"
#include "../SharedCode/AbstractFileSystem.h"

class CopyCommand : public AbstractCommand {
	AbstractFileSystem* afs;

public:
	CopyCommand(AbstractFileSystem* afs);
	virtual int execute(std::string s) override;
	virtual void displayInfo() override;
	virtual ~CopyCommand() = default;
};