#include "mockos/CopyCommand.h"
using namespace std;

CopyCommand::CopyCommand(AbstractFileSystem* sys) {
    this->fileSystem = sys;
}


void CopyCommand::displayInfo() {
    cout << "Copy is a command that copies a file's contents." << endl;
    cout << "Used with 'cp <fileToCopy> <newFileName>'. cp will copy the first file in the argument to a new file with the second" << endl;
    cout << "argument's name." << endl;
}

int CopyCommand::execute(string fileNames) {
    int indexOfSpaceInFileNameInput = fileNames.find(' ');
    string originalName = "";
    string copyName = "";
    
    if (indexOfSpaceInFileNameInput != string::npos && indexOfSpaceInFileNameInput < fileNames.size() - 1) {
       
        originalName = fileNames.substr(0, indexOfSpaceInFileNameInput); //extract the first fileName
        copyName = fileNames.substr(indexOfSpaceInFileNameInput + 1); // Extract the second fileName

    }
    else {
        //no fileName given to copy onto, failure
        return noSecondArgument;
    }

    if (copyName.empty() || originalName.empty()) {
        return noSecondArgument;
    }
    
    AbstractFile* filePointer = fileSystem->openFile(originalName);
     
    //if openFile failed
    if (filePointer == nullptr) {
        cout << "Invalid file." << endl;
        return FileNotFound;
    }
     
    //2 cases for copycommand, 1--> it is a chmod proxy 2--> it is nota chmodproxy

    //Case 1--> it is a chmodproxy
    ChmodProxy* placeHolderProxy = dynamic_cast<ChmodProxy*>(filePointer);
   
    if(placeHolderProxy == nullptr) {
        //Not a chmodproxy object
        //find extension for the purpose of making a new file name for the copy (not determining the file type)
        int IndexOfExtension = originalName.find('.');
        string extension = originalName.substr(IndexOfExtension);

        AbstractFile* ptr = filePointer->copy(copyName + extension);

        

        this->fileSystem->closeFile(filePointer);

        //return if addFile was successful or not
        return this->fileSystem->addFile(copyName + extension, ptr);

    } else {
        //Is a chmodproxy object
        //find extension for the purpose of making a new file name for the copy (not determining the file type)
        int indexOfExtension = originalName.find('.');
        string extension = originalName.substr(indexOfExtension);

        AbstractFile* ptr = filePointer->copy(copyName + extension);
        ChmodProxy* chmodProxy = new ChmodProxy(ptr, placeHolderProxy->isWritable());

        this->fileSystem->closeFile(filePointer);

        //return if addFile was successful or not
        return this->fileSystem->addFile(copyName + extension, chmodProxy);
    }

}