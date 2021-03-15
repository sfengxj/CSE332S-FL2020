#pragma once
#include "../SharedCode/AbstractCommand.h"
#include "../SharedCode/AbstractFileFactory.h"
#include "../SharedCode/AbstractFileSystem.h"

class DisplayCommand : public AbstractCommand {
	AbstractFileSystem* afs;

public:
	DisplayCommand(AbstractFileSystem* afs);
	virtual int execute(std::string s) override;
	virtual void displayInfo() override;
	virtual ~DisplayCommand() = default;

};