// Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "../../SharedCode/TextFile.h"
#include "../../SharedCode/AbstractFile.h "
#include "../../SharedCode/SimpleFileSystem.h"
#include "../../SharedCode/SimpleFileFactory.h"
#include "../../SharedCode/CommandPrompt.h"

#include "../../SharedCode/LSCommand.h"
#include "../../SharedCode/RemoveCommand.h"
#include "../../SharedCode/TouchCommand.h"
#include "../../SharedCode/CatCommand.h"
#include "../../SharedCode/DisplayCommand.h"
#include "../../SharedCode/CopyCommand.h"
#include "../../SharedCode/MacroCommand.h"
#include "../../SharedCode/RenameParsingStrategy.h"
#include "../../SharedCode/GrepCommand.h"

#include <sstream>
#include <iostream>
#include <string>

using namespace std;

int main(){
	//set up afs, aff
	AbstractFileSystem* sfs = new SimpleFileSystem();
	AbstractFileFactory* sff = new SimpleFileFactory();

	//set up command prompt
	CommandPrompt cp;
	cp.setFileSystem(sfs);
	cp.setFileFactory(sff);

	//add commands
	AbstractCommand* ls = new LSCommand(sfs);
	cp.addCommand("ls", ls);
	AbstractCommand* remove = new RemoveCommand(sfs);
	cp.addCommand("rm", remove);
	AbstractCommand* touch = new TouchCommand(sfs,sff);
	cp.addCommand("touch", touch);
	AbstractCommand* cat = new CatCommand(sfs);
	cp.addCommand("cat", cat);
	AbstractCommand* display = new DisplayCommand(sfs);
	cp.addCommand("ds", display);
	AbstractCommand* copy = new CopyCommand(sfs);
	cp.addCommand("cp", copy);
	MacroCommand* mc = new MacroCommand(sfs);
	RenameParsingStrategy* rps = new RenameParsingStrategy;
	AbstractCommand* cpc = new CopyCommand(sfs);
	AbstractCommand* rmc = new RemoveCommand(sfs);
	mc->setParseStrategy(rps);
	mc->addCommand(cpc);
	mc->addCommand(rmc);
	cp.addCommand("rn", mc);
	AbstractCommand* grep = new GrepCommand(sfs);
	cp.addCommand("grep", grep);

	//run
	int result = 0;
	do {
		result = cp.run();
	} while (result != returns::commandPromptQuit);

	return 0;
}


