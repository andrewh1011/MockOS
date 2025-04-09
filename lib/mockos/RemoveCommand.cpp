
#include "mockos/RemoveCommand.h"

using namespace std;

//Constructor for the rm command initializes the fileSystem member variables
RemoveCommand::RemoveCommand(AbstractFileSystem* sys) {
    this->fileSystem = sys;
}

//Display information on the rm command
void RemoveCommand::displayInfo() {
    cout << "rm (short for remove) is a command that deletes the name of the file given." << endl;
}

//Deletes the file given as a parameter
int RemoveCommand::execute(string name) {
    return fileSystem->deleteFile(name);
}

