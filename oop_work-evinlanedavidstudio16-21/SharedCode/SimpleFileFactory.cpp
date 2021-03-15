// studio 18 - simple file factory definitions

#include "SimpleFileFactory.h"
#include "TextFile.h"
#include "ImageFile.h"
using namespace std;

AbstractFile* SimpleFileFactory::createFile(string name) {
	string extension = name.substr(name.find('.'));

	//if txt file
	if (extension.compare(".txt") == 0) {
		// create new text file
		AbstractFile* tf = (new TextFile(name));
		return tf;
	}

	//if img file
	else if (extension.compare(".img") == 0) {
		//create new image file
		AbstractFile* imf = (new ImageFile(name));
		return imf;
	}

	//if file extension isn't found, return nullptr
	return nullptr;
}


	/*
	string file_extension = " ";
	for (int i = 0; i < name.size(); i++) {
		if (name[i] == '.') {
			while (i < name.size()) {
				file_extension = file_extension + name[i];
				i++;
			}
			if (file_extension != " ") {
				if (file_extension.compare(" .txt") == 0) {
					// create new text file
					AbstractFile* tf = (new TextFile(name));
					return tf;
				}

				else if (file_extension.compare(" .img") == 0) {
					//create new image file
					AbstractFile* imf = (new ImageFile(name));
					return imf;
				}
			}
		}
	}
	//if file extension isn't found, return nullptr
	return nullptr;
	*/
