#pragma once
// declaration of the file visitor interface here

class TextFile;
class ImageFile;

class AbstractFileVisitor {
public:
	virtual void visit_TextFile(TextFile* txt) = 0;
	virtual void visit_ImageFile(ImageFile* img) = 0;
};