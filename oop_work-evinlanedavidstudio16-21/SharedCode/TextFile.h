#pragma once
// TextFile declaration goes here
#include "AbstractFile.h"

class TextFile : public AbstractFile {
	std::vector<char> contents;
	std::string name;

public:
	virtual unsigned int getSize() override;
	virtual std::vector<char> read() override;
	virtual int write(std::vector<char>) override;
	virtual int append(std::vector<char>) override;
	virtual std::string getName() override;

	virtual void accept(AbstractFileVisitor*) override;
	virtual AbstractFile* clone(std::string newname) override;

	TextFile();
	TextFile(std::string);
	TextFile(const TextFile &);
	TextFile(TextFile&&);
	~TextFile() = default;
};