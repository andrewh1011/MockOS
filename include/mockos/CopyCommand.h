/*
header file for the copyCommand class
1) Andrew Hartmann a.r.hartmann@wustl.edu
1. Mario Rodriguez-Montoya m.rodriguez-montoya@wustl.edu
1. Shangwe Nyota s.nyota@wustl.edu

*/
#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "mockos/ChmodProxy.h"


enum { noSecondArgument = -2, FileNotFound = -3};
//Lab 5: CopyCommand
class CopyCommand : public AbstractCommand {
    AbstractFileSystem* fileSystem; //pointer to the abstractFileSystem
public:
     CopyCommand(AbstractFileSystem*);
    void displayInfo() override;
    int execute(std::string) override;

};