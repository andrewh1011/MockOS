//
// Created by Shangwe Nyota on 5/4/24.
//

#pragma once
#include "AbstractFile.h"
#include <iostream>

class ChmodProxy: public AbstractFile{
public:
    ChmodProxy(AbstractFile* chmodProxyFile, bool  isWritable); //constructor for the ChmodProxy
    virtual ~ChmodProxy(); //Destructor that deletes the pointer to the real file
    virtual std::vector<char> read() override;
    virtual int write(std::vector<char> fileContents) override;
    virtual int append(std::vector<char>) override;
    virtual unsigned int getSize() override;
    virtual std::string getName() override;
    virtual void accept(AbstractFileVisitor* fileVisitor) override;
    virtual AbstractFile* copy(std::string) override;
    bool isWritable();
private:
    AbstractFile* abstractFile; //Pointer to an abstract file (that will be affected by the chmod command)
    bool isModifable; //if isWritable is true, then the AbstractFile is writable, else the file is read only (false case)
};

enum chmodResults {
    invalidPermissionsToModifyFile = 147
};



