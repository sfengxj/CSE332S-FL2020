#pragma once

#include "../SharedCode/AbstractCommand.h"
#include "../SharedCode/AbstractFileFactory.h"
#include "../SharedCode/AbstractFileSystem.h"

/*TouchCommand will have 2 member variables, a pointer to an AbstractFileSystem and a pointer to an AbstractFileFactory. Declare and define aconstructor that takes 2 parameters
(AbstractFileSystem * and AbstractFileFactory *) and uses them to initialize the 2 member variables. The compiler defined destructorworks for this class. Override the methods inherited
from AbstractCommand as follows:*/
class TouchCommand : public AbstractCommand {
	AbstractFileSystem* afs;
	AbstractFileFactory* aff;

	public:
		TouchCommand(AbstractFileSystem * afs, AbstractFileFactory * aff);
		virtual int execute(std::string s) override;
		virtual void displayInfo() override;
		virtual ~TouchCommand() = default;

};