/*

1) Andrew Hartmann a.r.hartmann@wustl.edu
1. Mario Rodriguez-Montoya m.rodriguez-montoya@wustl.edu
1. Shangwe Nyota s.nyota@wustl.edu

*/
//Simple file system (no directories or folders)
#include "AbstractFileSystem.h"
#include <map>
#include <set>

class SimpleFileSystem : public AbstractFileSystem {
protected: //steps 3a,b
    //key = string
    //value = pointer to an Abstract File (can be a texFile, imageFile, etc.)
    std::map<std::string, AbstractFile *> allFilesInTheFileSystem;
    //set containing all of the currently open files
    //Contains pointers to AbstractFile(can be a textFile, imageFile, etc.)
    std::set<AbstractFile *> openFiles;
public:
    //Steps 3c+
    //No need for constructor declaration + definition, as the compiler defined constructor will work
    virtual int addFile(std::string fileName, AbstractFile * abstractFile) override;
    virtual int deleteFile(std::string fileName) override;
    virtual AbstractFile * openFile(std::string fileName) override;
    virtual int closeFile(AbstractFile * abstractFile) override;
    virtual std::set<std::string> getFileNames() override;
    virtual std::set<AbstractFile*> getFilePointers() override;

private:
    /*
        (Not part of any directions just for helping write cleaner code)
         Private helper methods (Why private?, Abstraction-
         prevent a minimal interface to the client, without worrying about implementation details!)
     */
    bool fileSystemAlreadyContainsName(std::string newFileNameToAdd);
    bool fileIsCurrentlyOpen(std::string fileNameToCheck);

};

