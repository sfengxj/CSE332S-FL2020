#pragma once
// declaration of SimpleFileSystem class goes here

#include "../SharedCode/AbstractFileSystem.h"
#include <map>
#include <set>

class SimpleFileSystem : public AbstractFileSystem {
	std::map<std::string, AbstractFile*> allFiles;
	std::set<AbstractFile*> openFiles;

public:
	virtual int addFile(std::string name, AbstractFile* file) override;
	virtual int deleteFile(std::string name) override;
	virtual AbstractFile* openFile(std::string name) override;
	virtual int closeFile(AbstractFile* file) override;
	virtual set<string> getFileNames() override;
};