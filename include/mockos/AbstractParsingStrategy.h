/*
header file for the AbstractParsingStrategy Class
1) Andrew Hartmann a.r.hartmann@wustl.edu
1. Mario Rodriguez-Montoya m.rodriguez-montoya@wustl.edu
1. Shangwe Nyota s.nyota@wustl.edu

*/

#pragma once
#include <vector>
#include <string>

class AbstractParsingStrategy {
public:
    //Pure virtual void function for parsing a specific concrete commands input for execution
    virtual std::vector<std::string> parse(std::string command)=0;
};