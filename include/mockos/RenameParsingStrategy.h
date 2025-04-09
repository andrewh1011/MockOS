/*
header file for the RenameParsingStrategy Class
1) Andrew Hartmann a.r.hartmann@wustl.edu
1. Mario Rodriguez-Montoya m.rodriguez-montoya@wustl.edu
1. Shangwe Nyota s.nyota@wustl.edu

*/
#include "mockos/AbstractParsingStrategy.h"

class RenameParsingStrategy: public AbstractParsingStrategy{
public:
    RenameParsingStrategy(); //Constructor for the RenameParsingStrategyClass
    virtual std::vector<std::string> parse(std::string existingFileNameAndNewFileName);
};