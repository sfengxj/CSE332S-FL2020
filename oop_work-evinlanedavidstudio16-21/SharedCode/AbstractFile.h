#pragma once
// declare AbstractFile here. As all methods are virtual and will not be defined, no .cpp file is necessary
#include <vector>
#include <string>
#include "AbstractFileVisitor.h"

enum returns {successlocal, No_Append, null_Pointer, already_Exists, doesNotExist, cantDeleteOpenFile, badPassword, 
				addCommandFailed, commandPromptQuit, commandPromptDNE, commandPromptHelp, addfileFailed, sucessfulCommand,
				catSaveQuit, catQuit, catFailed, displayFailed, copyFailed, lengthToCut = 5, writeFailed, cantCloseUnopenedFile};

class AbstractFile {
public:
	virtual std::vector<char> read() = 0;
	virtual int write(std::vector<char>) = 0;
	virtual int append(std::vector<char>) = 0;
	virtual unsigned int getSize() = 0;
	virtual std::string getName() = 0;

	virtual void accept(AbstractFileVisitor*) = 0;
	virtual AbstractFile* clone(std::string newname) = 0;
};
