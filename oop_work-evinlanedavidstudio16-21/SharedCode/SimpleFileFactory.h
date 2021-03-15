#pragma once
// Studio 18 - simplefilefactory class declaration goes here


#include "../SharedCode/AbstractFileFactory.h"

class SimpleFileFactory : public AbstractFileFactory {
public:
	virtual AbstractFile* createFile(std::string argument) override;
};