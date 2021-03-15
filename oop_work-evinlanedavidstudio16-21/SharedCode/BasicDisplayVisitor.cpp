// definitions of basic display visitor here
#include "BasicDisplayVisitor.h"
#include "TextFile.h"
#include "ImageFile.h"
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;


void BasicDisplayVisitor::visit_TextFile(TextFile* txt) {
	vector<char> contents = txt->read();
	for (unsigned int i = 0; i < contents.size(); ++i) {
		cout << (contents[i]);
	}
	cout << endl;
	return;
}
 void BasicDisplayVisitor::visit_ImageFile(ImageFile* img) {
	 vector<char> contents = img->read();
	 size_t r = static_cast<size_t> (sqrt(img->getSize())); //cast from double to size_t bc sqrt returns a double
	 for (size_t y = r-1; y < r; --y) { //counts down from minimum is an okay warning to ignore here
		 for (size_t x = 0; x < r; ++x) {
			 cout << (contents[(y * r) + x]);
		 }
		 cout << endl;
	 }
	 return;
}