//
// Created by Shangwe Nyota on 5/4/24.
//
#include "mockos/ChmodProxy.h"
using namespace std;

//Constructor to initialize the abstractFile and isWritable boolean member variable
ChmodProxy::ChmodProxy(AbstractFile *chmodProxyFile, bool isWritable)
    : abstractFile(chmodProxyFile), isModifable(isWritable){}

//Destructor for deleting the abstract file pointer
ChmodProxy::~ChmodProxy()  {
delete this->abstractFile;
}

//All files irregardless of it's isWritable status can be read!
std::vector<char> ChmodProxy::read() {
    return this->abstractFile->read();
}

//Only files with a true isWritable member variable can be written to
int ChmodProxy::write(std::vector<char> fileContents) {
    if(this->isWritable()) {
        return this->abstractFile->write(fileContents);
    } else {
        //Unable to write to file (readonly)
        cout << "This file is read only, so you cannot modify the file!"<<endl;
        return chmodResults::invalidPermissionsToModifyFile;
    }
}

//Same as write, only files that have a true isWritable member variable can be appended to
int ChmodProxy::append(std::vector<char> fileContentToAdd) {
    if (this->isWritable()) {
        return this->abstractFile->append(fileContentToAdd);
    } else {
        cout << "This file is read only, so you cannot modify the file!"<<endl;
        return chmodResults::invalidPermissionsToModifyFile;
    }
}

unsigned int ChmodProxy::getSize() {
    return this->abstractFile->getSize();
}

std::string ChmodProxy::getName() {
    return this->abstractFile->getName();
}

void ChmodProxy::accept(AbstractFileVisitor *fileVisitor) {
    return this->abstractFile->accept(fileVisitor);
}

//Creates a copy of the chmod proxy
// by 1) getting a copy of the abstract file, then creating a new chmodproxy and returning it
AbstractFile *ChmodProxy::copy(std::string name) {
    return this->abstractFile->copy(name); //avoids stacking multiple chmodproxy's in the abstractFile pointer member variable
}

//Returns bool representing if the file is writable
bool ChmodProxy::isWritable() {
    return this->isModifable;
}






