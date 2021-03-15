#pragma once
#include "../SharedCode/AbstractCommand.h"
#include "../SharedCode/AbstractFileSystem.h"

class CatCommand : public AbstractCommand {
	AbstractFileSystem* afs;

public:
	CatCommand(AbstractFileSystem* afs);
	virtual int execute(std::string s) override;
	virtual void displayInfo() override;
	virtual ~CatCommand() = default;

};