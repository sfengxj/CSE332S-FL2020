#pragma once
#include "../SharedCode/AbstractParsingStrategy.h"

class RenameParsingStrategy : public AbstractParsingStrategy {
public: 
	virtual std::vector<std::string> parse(std::string param) override;
	virtual void displayInfo() override;
};