#include "mockos/IMParsingStrategy.h"
#include <string>
#include <vector>
#include <iostream>     
#include <sstream>      
using namespace std;
IMParsingStrategy::IMParsingStrategy() {} //Constructor for IM parsing strategy



std::vector<std::string> IMParsingStrategy::parse(std::string existingFileNameAndNewFileName) {
    //could've just made it two method calls but didn't want to declare anything else in header files. Basically, cat command can only
    //have one flag, so if it exists, remove it from the touch commands input, and vice versa, so flags don't interfere. 
    existingFileNameAndNewFileName.erase(parsingBounds::initial, flagLength + parsingBounds::parsingOffset);
    
    string CommandInput = existingFileNameAndNewFileName;
    int pFlagIndex = existingFileNameAndNewFileName.find("-p");
    string catCommand = existingFileNameAndNewFileName;
    
    if (pFlagIndex != string::npos && pFlagIndex < existingFileNameAndNewFileName.size() - parsingBounds::parsingOffset) {
        catCommand = existingFileNameAndNewFileName.substr(parsingBounds::initial, pFlagIndex - parsingBounds::parsingOffset);
    }
    
    vector<string> parsingStrategy = { CommandInput, catCommand };
    return parsingStrategy;

}
