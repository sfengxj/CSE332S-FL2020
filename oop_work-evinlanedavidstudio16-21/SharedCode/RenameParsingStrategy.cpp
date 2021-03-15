#include "../SharedCode/RenameParsingStrategy.h"
#include <sstream>
#include <iostream>
using namespace std;

vector<string> RenameParsingStrategy::parse(string param) {

	//set up iss and parse input
	string first;
	string second;
	istringstream iss(param);

	iss >> first; //name of existing file with extension
	iss >> second; //new name, no extension

	//create vector and push back contents
	vector<string> newParams;
	newParams.push_back(first + " " + second); //copy takes first and second args
	newParams.push_back(first); //remove takes just first arg

	return newParams;
}

void RenameParsingStrategy::displayInfo(){
	cout << "rn renames a file and can be invoked with: rn <old_file_name> <new_name_no_extension> " << endl;

}