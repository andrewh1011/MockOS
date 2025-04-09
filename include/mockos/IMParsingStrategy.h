/*
header file for the Instant Modification Parsing Strategy class
1) Andrew Hartmann a.r.hartmann@wustl.edu
1. Mario Rodriguez-Montoya m.rodriguez-montoya@wustl.edu
1. Shangwe Nyota s.nyota@wustl.edu

*/
#pragma once
#include "mockos/AbstractParsingStrategy.h"

enum {flagLength = 2};

enum parsingBounds {
    initial = 0,
    parsingOffset = 1

};

class IMParsingStrategy : public AbstractParsingStrategy {
public:
    IMParsingStrategy(); //Constructor for the RenameParsingStrategyClass
    virtual std::vector<std::string> parse(std::string existingFileNameAndNewFileName) override;
};