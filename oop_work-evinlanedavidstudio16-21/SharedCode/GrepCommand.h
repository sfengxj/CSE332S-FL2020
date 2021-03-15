#pragma once
#include "../SharedCode/AbstractCommand.h"
#include "../SharedCode/AbstractFileFactory.h"
#include "../SharedCode/AbstractFileSystem.h"

class GrepCommand : public AbstractCommand {
	AbstractFileSystem* afs;

public:
	GrepCommand(AbstractFileSystem * afs);
	virtual int execute(std::string s) override;
	virtual void displayInfo() override;
	virtual ~GrepCommand() = default;
};