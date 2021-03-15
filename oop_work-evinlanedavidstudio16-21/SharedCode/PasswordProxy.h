#pragma once
#include "AbstractFile.h"

class PasswordProxy : public AbstractFile {

private:
	AbstractFile* file;
	std::string password;

protected:
	std::string passwordPrompt();
	bool passwordMatch(std::string);

public:
	PasswordProxy(AbstractFile* file, std::string password);
	~PasswordProxy();

	
	int write(std::vector<char>) override;
	virtual std::vector<char> read() override;
	int append(std::vector<char>) override;
	unsigned int getSize() override;
	std::string getName() override;
	void accept(AbstractFileVisitor*) override;
	virtual AbstractFile* clone(std::string newname) override;

};