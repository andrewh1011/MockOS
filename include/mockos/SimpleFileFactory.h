/*
header file for the SimpleFileFactory Class
1) Andrew Hartmann a.r.hartmann@wustl.edu
1. Mario Rodriguez-Montoya m.rodriguez-montoya@wustl.edu
1. Shangwe Nyota s.nyota@wustl.edu

*/
#include "AbstractFileFactory.h"

class SimpleFileFactory : public AbstractFileFactory {
public:
    virtual AbstractFile * createFile(std::string fileName) override;
};