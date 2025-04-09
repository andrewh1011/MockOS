/*

1) Andrew Hartmann a.r.hartmann@wustl.edu
1. Mario Rodriguez-Montoya m.rodriguez-montoya@wustl.edu
1. Shangwe Nyota s.nyota@wustl.edu

*/
#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

//Studio 21 (step 4)
//This is a concrete Command class, inherits from the AbstractCommand class
//Touch is a command that creates a file (ex: imageFile, textFile, etc... anything inheirted from an AbstractFile)
//Invoked by the user by inputted "Touch <fileName>"
//Touch will then create the file and add it to the filesystem
class TouchCommand : public AbstractCommand{
private:
	AbstractFileSystem* fileSystem; //pointer to the abstractFileSystem
	AbstractFileFactory* fileFactory; //pointer to the abstractFileFactory
public:
	TouchCommand(AbstractFileSystem*, AbstractFileFactory*); //Constructor that initializes the 2 pointers to what was passed in
	void displayInfo() override; //Tells the user how to invoke the touch command and describes the command
	int execute(std::string fileNameAndPotentialFlag) override; //executes the touch(creates a file) command on a specific fileNameAndPotentialFlag
	

};