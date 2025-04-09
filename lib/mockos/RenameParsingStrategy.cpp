#include "mockos/RenameParsingStrategy.h"
#include <string>
#include <vector>
using namespace std;
RenameParsingStrategy::RenameParsingStrategy() {} //Constructor for rename parsing strategy

std::vector<std::string> RenameParsingStrategy::parse(std::string existingFileNameAndNewFileName) {
    int indexOfSpaceInFileNameInput = existingFileNameAndNewFileName.find(' ');
    string existingFileName = "";
    string newFileName = "";
    if (indexOfSpaceInFileNameInput != string::npos && indexOfSpaceInFileNameInput < existingFileNameAndNewFileName.size() - 1){
        //If the indexOfthe space in the fileName input is not -1 (so it's a valid index/ there is a space)
        //and the index of the space is actually in bounds meaning that there is another character in the string
        existingFileName = existingFileNameAndNewFileName.substr(0, indexOfSpaceInFileNameInput); //extract the fileName
        newFileName = existingFileNameAndNewFileName.substr(indexOfSpaceInFileNameInput + 1); // Extract the second word

    } else {
        //no space in the name that is followed by a second word, so the new filename is set to the original one
        newFileName = existingFileName;
    }

    //Return the "strategy"aka order of execute function call for a particular abstract command
    vector<string> parsingStrategy = {existingFileNameAndNewFileName, existingFileName};
    return parsingStrategy;

}
