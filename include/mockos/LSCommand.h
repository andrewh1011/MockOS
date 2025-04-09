/*
header file for the LSCommandClass
1) Andrew Hartmann a.r.hartmann@wustl.edu
1. Mario Rodriguez-Montoya m.rodriguez-montoya@wustl.edu
1. Shangwe Nyota s.nyota@wustl.edu

*/
#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileVisitor.h"


class LSCommand : public AbstractCommand{
    AbstractFileSystem* fileSystem;
public:
    explicit LSCommand(AbstractFileSystem*);
    void displayInfo() override;
    int execute(std::string) override;
};

enum lsCommandBounds {
    initialValue = 0,
    mod = 2,
    formatter = 20
};