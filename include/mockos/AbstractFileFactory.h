/*
header file for the AbstractFile class
1) Andrew Hartmann a.r.hartmann@wustl.edu
1. Mario Rodriguez-Montoya m.rodriguez-montoya@wustl.edu
1. Shangwe Nyota s.nyota@wustl.edu

*/

#pragma once
#include "AbstractFile.h"
#include <iostream>
#include <string>
#include <vector>
//Interface of an abstract file factory includes methods for creating different types of objects
//that are opened by the client
//This allows maintaining of the single responsibility principle
class AbstractFileFactory {
public: 
    virtual AbstractFile * createFile(std::string fileName) =0;
};