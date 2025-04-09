/*
header file for the MacroCommandClass
1) Andrew Hartmann a.r.hartmann@wustl.edu
1. Mario Rodriguez-Montoya m.rodriguez-montoya@wustl.edu
1. Shangwe Nyota s.nyota@wustl.edu

*/
#pragma once
#include "mockos/AbstractFileSystem.h"
#include "mockos/AbstractCommand.h"
#include "mockos/AbstractParsingStrategy.h"
#include <vector>
#include <string>
class AbstractParsingStrategy;
class MacroCommand : public AbstractCommand {
public:
    MacroCommand(AbstractFileSystem *abstractFileSystem); //Constructor for the macro command
    virtual int execute(std::string) override; //the parameter will hold any information that is passed to the command
    virtual void displayInfo() override; //this is essentially a usage message for the command, it will display to the user how the command should be invoked
    void addCommand(AbstractCommand* command); //adds an Abstract Command to the abstract object
    void setParseStrategy(AbstractParsingStrategy* parsingStrategy); //sets the specific parsing strategy ex: RenameParsingStategy
private:
    AbstractFileSystem* abstractFileSystem; //Reference to the filesystem
    std::vector<AbstractCommand* > abstractCommandVector; //vector of abstract commnads that primitive and macro commands will use
    AbstractParsingStrategy* parsingStrategy; //the concrete parsing strategy the MacroCommand will use, ex: renameparsing
};