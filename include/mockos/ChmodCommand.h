//
// Created by Shangwe Nyota on 5/4/24.
//
#pragma once
#include "mockos/ChmodProxy.h"
#include "AbstractFileSystem.h"
#include "AbstractCommand.h"
#include <string>

class ChmodCommand : public AbstractCommand {
private:
    AbstractFileSystem* fileSystem;
public:
    ChmodCommand(AbstractFileSystem* fileSystem); //Constructor that initializes the 2 pointers to what was passed in
    virtual int execute(std::string fileNameAndPotentialFlag) override; //the parameter will hold any information that is passed to the command
    virtual void displayInfo() override; //this is essentially a usage message for the command, it will display to the user how the command should be invoked
};

