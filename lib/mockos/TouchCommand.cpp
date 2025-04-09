
#include "mockos/TouchCommand.h"
#include "mockos/PasswordProxy.h"
#include <string>
using namespace std;
TouchCommand::TouchCommand(AbstractFileSystem* sys, AbstractFileFactory* fact) {
	this->fileFactory = fact;
	this->fileSystem = sys;
}

//Tells the user how to invoke the touch command and describes the command
void TouchCommand::displayInfo()  {
	cout << "Touch is a command that creates a file.It will be invoked by the user" << endl;
	cout << "inputting �touch <filename>�.Touch will then create a file called �filename� and add it to" << endl;
	cout << "the file system.";
}

//Asks the file factory to create a file with the provided fileName

int TouchCommand::execute(string fileNameAndPotentialFlag) {
    int indexOfSpaceInFileNameInput = fileNameAndPotentialFlag.find(' ');
    string fileName = "";
    string potentialFlag = "";
    string passwordFlag = "-p";
    if (indexOfSpaceInFileNameInput != string::npos && indexOfSpaceInFileNameInput < fileNameAndPotentialFlag.size() - 1){
        //If the indexOfthe space in the fileName input is not -1 (so it's a valid index/ there is a space)
        //and the index of the space is actually in bounds meaning that there is another character in the string
        fileName = fileNameAndPotentialFlag.substr(0, indexOfSpaceInFileNameInput); //extract the fileName
        potentialFlag = fileNameAndPotentialFlag.substr(indexOfSpaceInFileNameInput + 1); // Extract the second word

    } else {
        //no space in the name that is followed by a second word, so set the fileName to the inputted string
        fileName = fileNameAndPotentialFlag;
    }

    if (fileName.size() >= commandOutcomes::maxFileNameSize) {
        //File names should be less than 20 characters (see Lab 5 problem 1)
        cout << "File name too long (must be less than 20 characters)." << endl;
        return commandOutcomes::fileNameTooLong;
    }
    if (potentialFlag != passwordFlag && !potentialFlag.empty()) {
        //Invalid arguments
        cout << "Invalid arguments." << endl;
        return commandOutcomes::invalidArguments;
    }

    //Creates an Abstract File using the fileFactory
    AbstractFile* file = this->fileFactory->createFile(fileName);
    if (potentialFlag == passwordFlag) {
        //if the "-p" flag is selected we must create a proxy
        string userInputtedPassword;
        cout <<"What is the password?"<<endl;
        string response;
        getline(cin, userInputtedPassword);
        if (file != nullptr) {
            AbstractFile* protectedFile = new PasswordProxy(file, userInputtedPassword); //sets up proxy to protect the file
            //Add the password protected file to the filesystem if the file is not null
            return fileSystem->addFile(fileName, protectedFile);
        } else {
            delete file;
            return commandOutcomes::invalidFile; //need to refactor this
        }

    }

	 if (file != nullptr) {
         //if the file is succesfully created, we add the file to the file system object calling addfile
		 if (fileSystem->addFile(fileName, file) != 0) {
			 delete file; //calling delete if the file was created succesfully but not correctly added to the filesystem
			 return commandOutcomes::couldNotAddToSystem;
		 }
		 return success;

	 }

	 return commandOutcomes::fileCouldNotBeCreated;
}




