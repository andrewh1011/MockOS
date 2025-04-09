/*
header file for the CatCommand Class
1) Andrew Hartmann a.r.hartmann@wustl.edu
1. Mario Rodriguez-Montoya m.rodriguez-montoya@wustl.edu
1. Shangwe Nyota s.nyota@wustl.edu

*/
#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"


//Lab 5: CatCommand
class CatCommand: public AbstractCommand {
    AbstractFileSystem* fileSystem; //pointer to the abstractFileSystem
public:
    explicit CatCommand(AbstractFileSystem*);
    void displayInfo() override;
    int execute(std::string) override;

};