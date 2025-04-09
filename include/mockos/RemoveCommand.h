/*
header file for the RemoveCommand Class
1) Andrew Hartmann a.r.hartmann@wustl.edu
1. Mario Rodriguez-Montoya m.rodriguez-montoya@wustl.edu
1. Shangwe Nyota s.nyota@wustl.edu

*/
#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"


class RemoveCommand : public AbstractCommand{
    AbstractFileSystem* fileSystem;
public:
    explicit RemoveCommand(AbstractFileSystem*);
    void displayInfo() override;
    int execute(std::string) override;


};