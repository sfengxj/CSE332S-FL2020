#pragma once
// Image file class declaration here

#include "AbstractFile.h"

class ImageFile : public AbstractFile {
	std::string name;
	std::vector<char> contents;
	size_t size;

	size_t coorToIndex(size_t x, size_t y);

public:
	virtual unsigned int getSize() override;
	virtual std::string getName() override;
	virtual int write(std::vector<char>) override;
	virtual int append(std::vector<char>) override;
	virtual std::vector <char> read() override;

	ImageFile(std::string name);

	virtual void accept(AbstractFileVisitor*) override;
	virtual AbstractFile* clone(std::string newname) override;

};