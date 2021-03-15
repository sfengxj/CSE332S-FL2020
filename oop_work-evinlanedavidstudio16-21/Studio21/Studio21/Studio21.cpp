// Studio21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "../../SharedCode/SimpleFileSystem.h"
#include "../../SharedCode/SimpleFileFactory.h"
#include "../..//SharedCode/CommandPrompt.h"
#include "../..//SharedCode/AbstractCommand.h"
#include "../..//SharedCode/TouchCommand.h"
#include "../..//SharedCode/MetadataDisplayVisitor.h"
#include "../..//SharedCode/TextFile.h"

int main()
{
	AbstractFileSystem * afs = new SimpleFileSystem();
	AbstractFileFactory* aff = new SimpleFileFactory();

	AbstractCommand* touch = new TouchCommand(afs, aff);
	CommandPrompt* commandprompt = new CommandPrompt();

	commandprompt->setFileFactory(aff);
	commandprompt->setFileSystem(afs);
	commandprompt->addCommand("touch", touch);
	
	int result = 0;
	do {
		result = commandprompt->run();
	} while (result != returns::commandPromptQuit);

	AbstractFileVisitor* visitor = new MetadataDisplayVisitor();

	AbstractFile* file = afs->openFile("one.txt");
	file->accept(visitor);

	return 0;
}

