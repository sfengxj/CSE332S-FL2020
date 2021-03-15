#pragma once
// declaration of the interface all file systems provide goes here
#include <string>
#include <vector>
#include <set>
#include "AbstractFile.h"
using namespace std;

class AbstractFileSystem {
public:
	virtual int addFile(std::string name, AbstractFile* file) = 0;
	virtual int deleteFile(std::string name) = 0;
	virtual AbstractFile* openFile(std::string name) = 0;
	virtual int closeFile(AbstractFile* file) = 0;
	virtual set<string> getFileNames() = 0;
};