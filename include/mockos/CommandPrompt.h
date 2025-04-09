/*

1) Andrew Hartmann a.r.hartmann@wustl.edu
1. Mario Rodriguez-Montoya m.rodriguez-montoya@wustl.edu
1. Shangwe Nyota s.nyota@wustl.edu

*/
#pragma once
#include <map>
#include <string>
#include "mockos/AbstractCommand.h"
#include "mockos/AbstractFileSystem.h"
#include "mockos/AbstractFileFactory.h"

enum commandOutputs { successVal, mapInsertionFailure, quitter};
/*
 (Studio 21, part 3)
 The commandPrompt class handles user input/output. This is the user interface for our file system. (The invoker in the command pattern.)
 The commandPrompt is configured with concrete commands and will invoke them when requested by the user.
 */
class CommandPrompt {
public:
    std::map<std::string, AbstractCommand*> collectionOfCommands;  //maps a string to a pointer (name of command) to an abstract command
    AbstractFileSystem* fileSystem; //stores the fileSystem object the command prompt is configured with
    AbstractFileFactory* fileFactory; //stores the fileFactory object the command prompt is configured with

    CommandPrompt(); //default constructor to initialize to a nullptr
    ~CommandPrompt() = default; //compiler defined destructor
    void setFileSystem(AbstractFileSystem*); //setter for the filesystem
    void setFileFactory(AbstractFileFactory*);
    int addCommand(std::string, AbstractCommand*); //adds a command
    int run();
protected:
    void listCommands();
    std::string prompt();
};
