
#include "mockos/DisplayCommand.h"
using namespace std;

DisplayCommand::DisplayCommand(AbstractFileSystem* sys) {
    this->fileSystem = sys;
}

void DisplayCommand::displayInfo() {
    cout << "Ds (short for display) is a command that displays a file's contents to the terminal." << endl;
    cout << "Used with 'ds <filename> [-d]'. Without the -d option, ds will display the file formatted." << endl;
    cout << "With the -d option, ds will display the file unformatted." << endl;
}

int DisplayCommand::execute(string fileNameAndPotentialFlag) {
    int indexOfSpaceInFileNameInput = fileNameAndPotentialFlag.find(' ');
    string fileName = "";
    string potentialFlag = "";
    string displayFlag = "-d";
    if (indexOfSpaceInFileNameInput != string::npos && indexOfSpaceInFileNameInput < fileNameAndPotentialFlag.size() - 1){
        //If the indexOfthe space in the fileName input is not -1 (so it's a valid index/ there is a space)
        //and the index of the space is actually in bounds meaning that there is another character in the string
        fileName = fileNameAndPotentialFlag.substr(0, indexOfSpaceInFileNameInput); //extract the fileName
        potentialFlag = fileNameAndPotentialFlag.substr(indexOfSpaceInFileNameInput + 1); // Extract the second word

    } else {
        //no space in the name that is followed by a second word, so set the fileName to the inputted string
        fileName = fileNameAndPotentialFlag;
    }

    if (potentialFlag == displayFlag) {
        //display option
        //open file, read file, close file
        AbstractFile* filePointer = fileSystem->openFile(fileName);
        vector<char> fileContents = filePointer->read();
        for (char fileContent: fileContents) {
            cout<<fileContent;
        }
        cout<<endl;
        return fileSystem->closeFile(filePointer);
    } else if (potentialFlag.empty()) {
        //no option
        AbstractFileVisitor* visitor = new BasicDisplayVisitor;
        AbstractFile* filePointer = fileSystem->openFile(fileName);
        if (filePointer == nullptr) {
            cout << "Invalid file." << endl;
            return commandOutcomes::invalidFile;
        }
        filePointer->accept(visitor);
        fileSystem->closeFile(filePointer);
        cout << endl;
    } else {
        //Invalid arguments
        cout << "Invalid arguments for display command." << endl;
        return commandOutcomes::invalidArguments;
    }
    return success;
}
