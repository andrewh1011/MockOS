/*
header file for the TestFile Class
1) Andrew Hartmann a.r.hartmann@wustl.edu
1. Mario Rodriguez-Montoya m.rodriguez-montoya@wustl.edu
1. Shangwe Nyota s.nyota@wustl.edu

*/
#include "AbstractFile.h"
class AbstractFileVisitor;
//TextFile publically inherits from AbstractFile
class TextFile: public AbstractFile {

protected:
    std::vector<char> fileContents;
    std::string fileName;
public:
    explicit TextFile(std::string fileName); //constructor for the TextFile
     unsigned int getSize() override;
     virtual AbstractFile* copy(std::string Name) override ;
    std::vector<char> read() override;
    int write(std::vector<char>) override;
    int append(std::vector<char>) override;
    std::string getName() override;
    void accept(AbstractFileVisitor* fileVisitor) override;
};