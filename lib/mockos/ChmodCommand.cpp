
#include "mockos/ChmodCommand.h"
using namespace std;
//Constructor for the ChmodCommand
ChmodCommand::ChmodCommand(AbstractFileSystem *fileSystem)
:fileSystem(fileSystem){}

//Displays the ChmodCommand Information
void ChmodCommand::displayInfo() {
    cout<<"Chmod is a command that adjusts a files permissions."<<endl;
    cout<<"Used with 'chmod <filename> <+> or chmod <filename> <-> will make the given file writable (with + flag) or readonly (with - flag)."<<endl;
}

int ChmodCommand::execute(std::string fileNameAndPotentialFlag) {
    int indexOfSpaceInFileNameInput = fileNameAndPotentialFlag.find(' ');
    string fileName = "";
    string potentialFlag = "";
    string writableFlag = "+";
    string readOnlyFlag = "-";
    if (indexOfSpaceInFileNameInput != string::npos && indexOfSpaceInFileNameInput < fileNameAndPotentialFlag.size() - 1){
        //If the indexOfthe space in the fileName input is not -1 (so it's a valid index/ there is a space)
        //and the index of the space is actually in bounds meaning that there is another character in the string
        fileName = fileNameAndPotentialFlag.substr(0, indexOfSpaceInFileNameInput); //extract the fileName
        potentialFlag = fileNameAndPotentialFlag.substr(indexOfSpaceInFileNameInput + 1); // Extract the second word

    } else {
        //no space in the name that is followed by a second word, so set the fileName to the inputted string
        fileName = fileNameAndPotentialFlag;
    }

    //If the flag is not equal to the + or -, then in this case we cannot execute the chmod command and can return early
    if (potentialFlag != writableFlag && potentialFlag!= readOnlyFlag) {
        cout << "Invalid arguments. You must enter + or - as the flag" << endl;
        return commandOutcomes::invalidFlagInput;
    }

    AbstractFile* inputtedFilePointer = this->fileSystem->openFile(fileName);
    if (inputtedFilePointer == nullptr) {
        cout << "File does not exist in the filesystem, please try again!" << endl;
        return commandOutcomes::invalidFile;
    }

    bool isWritableFlag = (potentialFlag == writableFlag);
    //Create a new chmodFile that is either writable(true) or readonly(false)
    AbstractFile* chmodFile = new ChmodProxy(inputtedFilePointer->copy(fileName), isWritableFlag);

    //Close the original file (that the chmod command was called on)
    this->fileSystem->closeFile(inputtedFilePointer);
    //Delete the original file (that the chmod command was called on)
    this->fileSystem->deleteFile(fileName);

    //Add the newly created chmodFile to the filesystem and return
    return this->fileSystem->addFile(fileName, chmodFile);
}
