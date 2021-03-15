// definitions of metadata visitor here

#include "MetadataDisplayVisitor.h"

#include "TextFile.h"
#include "ImageFile.h"
#include <vector>
#include <iostream>
using namespace std;

void MetadataDisplayVisitor::visit_TextFile(TextFile* txt) {
	cout << txt->getName();

	for (unsigned int i = 0; i < 20 - txt->getName().size(); ++i) {
		cout << " ";
	}

	cout << "text " <<  "\t"  << txt->getSize();
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* img) {
	cout << img->getName();

	
	for (unsigned int i = 0; i < 20 - img->getName().size(); ++i) {
		cout << " ";
	}
		
	cout << "image" << "\t" << img->getSize();

}
