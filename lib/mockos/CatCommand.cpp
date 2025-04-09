
#include "mockos/CatCommand.h"
using namespace std;

CatCommand::CatCommand(AbstractFileSystem* sys) {
    this->fileSystem = sys;
}

void CatCommand::displayInfo() {
    cout << "Cat (short for concatenate) is a command that changes a file's contents." << endl;
    cout << "Used with 'cat <filename> [-a]'. Without the -a option, cat with overwrite the file with the given input" << endl;
    cout << "With the -a option, the cat command will concatenate the given input to the end of the file." << endl;
    cout << "After giving input to the command, type ':wq' to save and quit, or to input ':q' to quit without saving" << endl;
}

int CatCommand::execute(string fileNameAndPotentialFlag) {
    int indexOfSpaceInFileNameInput = fileNameAndPotentialFlag.find(' ');
    string fileName = "";
    string potentialFlag = "";
    string appendFlag = "-a";
    if (indexOfSpaceInFileNameInput != string::npos && indexOfSpaceInFileNameInput < fileNameAndPotentialFlag.size() - 1){
        //If the indexOfthe space in the fileName input is not -1 (so it's a valid index/ there is a space)
        //and the index of the space is actually in bounds meaning that there is another character in the string
        fileName = fileNameAndPotentialFlag.substr(0, indexOfSpaceInFileNameInput); //extract the fileName
        potentialFlag = fileNameAndPotentialFlag.substr(indexOfSpaceInFileNameInput + 1); // Extract the second word

    } else {
        //no space in the name that is followed by a second word, so set the fileName to the inputted string
        fileName = fileNameAndPotentialFlag;
    }

    if (potentialFlag != appendFlag && !potentialFlag.empty()) {
        //Invalid arguments
        cout << "Invalid arguments." << endl;
        return commandOutcomes::invalidArguments;
    }

    AbstractFile* filePointer = fileSystem->openFile(fileName);
    if (filePointer == nullptr) {
        cout << "Invalid file." << endl;
        return commandOutcomes::invalidFile;
    }
    if (potentialFlag == appendFlag) {
        //append option
        //Display current file unformatted
        cout << "Current contents: " << endl;
        vector<char> bytes = filePointer->read();
        for (int i = 0; i < bytes.size(); ++i) {
            char currentFileContent = bytes[i];
            cout << currentFileContent;
        }
        cout << endl;

    }
    cout << "Type what you would like to add to the file. Enter :wq to save the file and exit, or :q to exit without saving:" << endl;
    string userInput;
    vector<char> newFileContents;
    while (getline(cin, userInput)) {

        if (userInput == ":wq") {
            newFileContents.pop_back(); // Remove the last newline character
            if (potentialFlag.empty()) {
                filePointer->write(newFileContents);
            } else {
                if (filePointer->append(newFileContents) == commandOutcomes::appendToImageError) {
                    cout << "Cannot append to images." << endl;
                    return commandOutcomes::appendToImageError;
                }
            }
            fileSystem->closeFile(filePointer);
            break;
        } else if (userInput == ":q") {
            fileSystem->closeFile(filePointer);
            break;
        } else {

            char* char_array = new char[userInput.size() + 1];

            // copying the contents of the
            // string to char array
            strcpy(char_array, userInput.c_str());
            for (int i = 0; i < userInput.size(); ++i)
            {
                newFileContents.push_back(char_array[i]);
            }
            delete[] char_array;
            newFileContents.push_back('\n'); // Add a newline character after each line

        }
    }
    return success;
}
