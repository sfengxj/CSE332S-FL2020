#pragma once
#include "../SharedCode/AbstractCommand.h"
#include "../SharedCode/AbstractFileFactory.h"
#include "../SharedCode/AbstractFileSystem.h"

class LSCommand : public AbstractCommand {
	AbstractFileSystem* afs;

public:
	LSCommand(AbstractFileSystem * afs);
	virtual int execute(std::string s) override;
	virtual void displayInfo() override;
	virtual ~LSCommand() = default;
};