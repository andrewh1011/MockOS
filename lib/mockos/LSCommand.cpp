#include "mockos/LSCommand.h"
#include "mockos/MetadataDisplayVisitor.h"
using namespace std;

//Lab 5 (part 1)
//Constructor for the ls command initializes the fileSystem member variables
LSCommand::LSCommand(AbstractFileSystem* sys) {
    this->fileSystem = sys;
}

//Display information on the ls command
void LSCommand::displayInfo() {
    cout << "Ls is a command that lists the names of all the files in the file system." << endl;
}

//Executes the ls command
int LSCommand::execute(string arguments) {
    if (arguments.empty()) {
        //If no filename was provided we print out the filenames
        set<string> names = fileSystem->getFileNames();
        int count = lsCommandBounds::initialValue;
        for (const auto& filename : names) {
            std::cout << filename;
            if (++count % lsCommandBounds::mod == lsCommandBounds::initialValue || count == names.size()) {
                std::cout << std::endl;
            }
            else {
                int padding = lsCommandBounds::formatter - filename.size();
                std::cout << std::string(padding, ' ');
            }
        }
        return success;
    }
    else if (arguments == "-m") {
        //-m option
        AbstractFileVisitor* lsFileVisitor = new MetadataDisplayVisitor;
        //Loops through pointers in reverse order of set because that is what the tests wanted
        set<string> strings = fileSystem->getFileNames();

        for (auto iterator = strings.begin(); iterator != strings.end(); iterator++) {
            AbstractFile* ptr = fileSystem->openFile(*iterator);
            (ptr)->accept(lsFileVisitor);
            fileSystem->closeFile(ptr);
        }
        return success;
    }
    else {
        //Invalid arguments
        std::cout << "Invalid arguments for ls command." << std::endl;
        return commandOutcomes::invalidArguments;
    }
}
