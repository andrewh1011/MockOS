#include "mockos/SimpleFileSystem.h"
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
 using namespace std;

 //step 4c of studio 17
 //first, check the collectionOfCommands of files to ensure the file does not already exist (if it
 //does, return an appropriate non-zero value), then ensure the AbstractFile pointer
 //passed to the function is not a nullptr (return a non-zero value if it is). Now insert
 //a std::pair containing the name of the file and the pointer to the file into the collectionOfCommands
 //member variable of the class.

 int SimpleFileSystem::addFile(std::string fileNameToAdd, AbstractFile* abstractFileToAdd) {
     //first check the collectionOfCommands of files to ensure the file does not already exist
     if (this->fileSystemAlreadyContainsName(fileNameToAdd)) {
         //in the case that the file already exists, we can simply return an appropriate nonzero value indicating error
         return fileOutcomes::fileAlreadyExists;
     }
    //If the pointer to the file we want to add is null, we can simply return early
     if (abstractFileToAdd == nullptr) {
         return fileOutcomes::fileIsNull;
     }

     //Now that we have ensured the fileName is unique and have ensured that the file is not null,
     // we may safely add it to our simple file system (as a key value pair), key=fileName, value=pointer to AbstractFile
     this->allFilesInTheFileSystem.insert({fileNameToAdd, abstractFileToAdd});
     return programOutcomes::success; //returns 0 for success
}


//step 4e of Studio 17
AbstractFile *SimpleFileSystem::openFile(std::string fileName) {

    if (!fileSystemAlreadyContainsName(fileName) || fileIsCurrentlyOpen(fileName)) {
        return nullptr;
    }

    //Gets the pointer to the file according to the inputted fileName
    AbstractFile * file = this->allFilesInTheFileSystem[fileName];
     this->openFiles.insert(file);
     return file;

}


int SimpleFileSystem::closeFile(AbstractFile * p) {

    if (fileIsCurrentlyOpen(p->getName())) {

        this->openFiles.erase(p);

        return success;
    }

    return fileIsNotOpen;

}

int SimpleFileSystem::deleteFile(std::string fileName) {
     //if the file is not in the system we cannot delete it so return early
     if(!fileSystemAlreadyContainsName(fileName)) {
         return fileOutcomes::fileDoesNotExist;
     }
     if (fileIsCurrentlyOpen(fileName)) {
         return fileOutcomes::fileIsAlreadyOpened;
     }
     AbstractFile* ptr = allFilesInTheFileSystem[fileName];
    delete ptr;
    ptr = nullptr;
     allFilesInTheFileSystem.erase(fileName);
     return success;
 }



//returns true if name IS already in the file system,
// false it is NOT already in the file system (that is, you may add it)
bool SimpleFileSystem::fileSystemAlreadyContainsName(std::string newFileNameToAdd) {
    bool fileSystemMapAlreadyContainsName = this->allFilesInTheFileSystem.find(newFileNameToAdd) != this->allFilesInTheFileSystem.end();
    return fileSystemMapAlreadyContainsName;
}
//See this stackoverflow post for further clarification for the above method:
//https://stackoverflow.com/questions/1939953/how-to-find-if-a-given-key-exists-in-a-stdmap
//What prompted this question?---> I was frustrated that c++ maps didn't have a .containsKey() method
//like Java or an "in" operator like python so why not create a function under the hood to
//avoid having to redefine this functionality over and over



bool SimpleFileSystem::fileIsCurrentlyOpen(std::string fileNameToCheck) {
    //Iterate through each value (AbstractFile pointer) in the "openFiles" set.
    // At each value check to see if the name of the abstract file pointer is equal to
    // the fileName we want to check(passed into the function). If this is the case
    //we simply return true, if we fail to find a matching file, then the file is not already opened, thus return false
    for (auto it = this->openFiles.begin(); it != this->openFiles.end(); ++it) {
        AbstractFile* currentOpenFile = *it;  //Get the current openFile in the openFiles set
        string currentOpenFileName = currentOpenFile->getName();
        if (currentOpenFileName == fileNameToCheck) {
            return true;
        }
    }

    return false; //The file we are checking is not already in the openFile set, thus we can return false
}

set<string> SimpleFileSystem::getFileNames() {
    set<string> names;
    for (const auto& pair : allFilesInTheFileSystem) {
        names.insert(pair.first);
    }
    return names;
}

std::set<AbstractFile *> SimpleFileSystem::getFilePointers() {
     set<AbstractFile*> pointers;
    for (const auto& pair : allFilesInTheFileSystem) {
        pointers.insert(pair.second);
    }
    return pointers;
}


