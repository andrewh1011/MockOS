/*
header file for the AbstractFileVisitor class
1) Andrew Hartmann a.r.hartmann@wustl.edu
1. Mario Rodriguez-Montoya m.rodriguez-montoya@wustl.edu
1. Shangwe Nyota s.nyota@wustl.edu

*/

#pragma once
#include <vector>
#include <string>
class AbstractFileVisitor;
//File interface
class AbstractFile {
    
public:
    virtual std::vector<char> read()= 0;
    virtual int write(std::vector<char>)=0;
    virtual int append(std::vector<char>)=0;
    virtual unsigned int getSize()=0;
    virtual std::string getName()=0;
    virtual ~AbstractFile()=default;
    virtual AbstractFile* copy(std::string) = 0;
    virtual void accept(AbstractFileVisitor* fileVisitor)=0;
};