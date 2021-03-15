#pragma once
#include <string>
#include <vector>

class AbstractParsingStrategy {

public:
	virtual std::vector<std::string> parse(std::string param) = 0;
	virtual void displayInfo() = 0;
};