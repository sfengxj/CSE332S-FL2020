#pragma once
// declaration of BasicDisplayVisitor here
#include "AbstractFileVisitor.h"
#include <string>

class SearchVisitor : public AbstractFileVisitor {
	std::string searchTerm;

public:
	SearchVisitor(std::string searchTerm);
	virtual void visit_TextFile(TextFile* txt) override;
	virtual void visit_ImageFile(ImageFile* img) override;
};