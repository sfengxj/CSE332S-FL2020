// define methods of SimpleFileSystem class here
#include "SimpleFileSystem.h"
#include "TextFile.h"
#include "ImageFile.h"
#include <iostream>

using namespace std;

set<string> SimpleFileSystem::getFileNames() {
	set<string> fileNames;

	//iterate over allFiles, adding names to set
	map<std::string, AbstractFile*>::iterator it;
	for (it = allFiles.begin(); it != allFiles.end(); ++it) {
		fileNames.insert(it->first);
	}

	return fileNames;
}

int SimpleFileSystem::addFile(std::string name, AbstractFile* file){
	//check null ptr
	if (file == nullptr){
		return returns::null_Pointer;
	}
	//check already included
	if (allFiles.find(name) != allFiles.end()){
		return returns::already_Exists;
	}
	//otherwise insert
	allFiles.insert(std::pair<std::string, AbstractFile*>(name,file));
	return returns::successlocal;
}

int SimpleFileSystem::deleteFile(std::string name) {
	//check if exists
	if (allFiles.find(name) == allFiles.end()){
		return returns::doesNotExist;
	}

	//check if open
	auto it = allFiles.find(name);
	AbstractFile* file = it->second;
	if (openFiles.find(file) != openFiles.end()){
		return returns::cantDeleteOpenFile;
	}

	//else remove file from map, delete pointer
	allFiles.erase(name);
	delete file;
	return successlocal;
}

AbstractFile* SimpleFileSystem::openFile(string name) {
	//if file exists
    if (allFiles.find(name) != allFiles.end()){
		auto it = allFiles.find(name);
		AbstractFile* file = it->second;

		//if file is not already open
		if (openFiles.find(file) == openFiles.end()){
			openFiles.insert(file);
			return file;
		}
	}

	//if failed to open, return nullptr
	return nullptr;
}

int SimpleFileSystem::closeFile(AbstractFile* file) {
	//if file is currently open
	if (openFiles.find(file) != openFiles.end()) {
		openFiles.erase(file);
			return successlocal;
	}

	else {
		return cantCloseUnopenedFile;
	}
}
