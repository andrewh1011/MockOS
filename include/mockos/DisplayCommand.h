/*
header file for the Display Command Class
1) Andrew Hartmann a.r.hartmann@wustl.edu
1. Mario Rodriguez-Montoya m.rodriguez-montoya@wustl.edu
1. Shangwe Nyota s.nyota@wustl.edu

*/
#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileVisitor.h"
#include "BasicDisplayVisitor.h"



class DisplayCommand : public AbstractCommand{
    AbstractFileSystem* fileSystem;
public:
    explicit DisplayCommand(AbstractFileSystem*);
    void displayInfo() override;
    int execute(std::string) override;


};