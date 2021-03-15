// definitions of basic display visitor here
#include "SearchVisitor.h"
#include "TextFile.h"
#include "ImageFile.h"
#include <vector>
#include <iostream>
using namespace std;

SearchVisitor::SearchVisitor(string word) : searchTerm(word) {}

void SearchVisitor::visit_TextFile(TextFile* txt) {

	//get contents and convert to string
	vector<char> chars = txt->read();
	string contents(chars.begin(), chars.end());

	//if search term string is within file contents, print file name
	if (contents.find(searchTerm) != string::npos){
		cout << txt->getName() << endl;
	}

	return;
}
void SearchVisitor::visit_ImageFile(ImageFile* img) {
	//images are excluded from this search, will never print file name
	return;
}