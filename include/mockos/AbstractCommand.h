/*
header file for the AbstractCommandClass
1) Andrew Hartmann a.r.hartmann@wustl.edu
1. Mario Rodriguez-Montoya m.rodriguez-montoya@wustl.edu
1. Shangwe Nyota s.nyota@wustl.edu

*/

#pragma once
#include <iostream>
#include <string>

class AbstractCommand {
public:
    virtual int execute(std::string) = 0; //the parameter will hold any information that is passed to the command
    virtual void displayInfo() = 0; //this is essentially a usage message for the command, it will display to the user how the command should be invoked
    virtual ~AbstractCommand() = default; //destructor for the command object
};

enum commandOutcomes {
    maxFileNameSize = 20,
    invalidFlagInput = 84,
    invalidFile = 85,
    fileNameTooLong = 86,
    invalidArguments = 87,
    couldNotAddToSystem = 88,
    fileCouldNotBeCreated = 89,
    appendToImageError = 90
};

