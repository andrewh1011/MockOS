/*
header file for the AbstractFileSystem class
1) Andrew Hartmann a.r.hartmann@wustl.edu
1. Mario Rodriguez-Montoya m.rodriguez-montoya@wustl.edu
1. Shangwe Nyota s.nyota@wustl.edu

*/

#pragma once
#include "AbstractFile.h"
#include <iostream>
#include <string>
#include <vector>
#include <set>

//Step 3, Studio 17
//We are programming to the AbstractFileSystem interface instead of the implementation!
//Recall, an AbstractFile can be a textFile or an imageFile
//All methods are purely virtual (with no member variables) thus creating an interface
class AbstractFileSystem {
public:
    virtual int addFile(std::string fileName, AbstractFile * abstractFile) = 0;
    virtual int deleteFile(std::string fileName) = 0;
    virtual AbstractFile * openFile(std::string fileName) = 0;
    virtual int closeFile(AbstractFile * abstractFile) = 0;
    virtual std::set<std::string> getFileNames() = 0;
    virtual std::set<AbstractFile*> getFilePointers() = 0;
   // virtual AbstractFile* copy(std::string) = 0;
};


enum fileOutcomes {
    invalidBoardSize = 100,
    fileAlreadyExists = 99,
    fileIsNull = 98,
    fileIsAlreadyOpened = 97,
    fileDoesNotHaveAnEnding = 96,
    fileIsNotOpen = 95,
    fileDoesNotExist = 94
};

enum programOutcomes {
    success = 0
};