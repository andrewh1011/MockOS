/*
header file for the ImageFile Class
1) Andrew Hartmann a.r.hartmann@wustl.edu
1. Mario Rodriguez-Montoya m.rodriguez-montoya@wustl.edu
1. Shangwe Nyota s.nyota@wustl.edu

*/
#include "AbstractFile.h"
class AbstractFileVisitor;
//ImageFile class publically inherits from the AbstractFile class
class ImageFile: public AbstractFile {
protected:
    std::string fileName;
    std::vector<char> fileContents; //(for studio17) an image is an nxn board of pixels, each pixel is an X or ' '
    char fileSize;
public:
    ImageFile(std::string fileName); //constructor for the ImageFile, initializes the fileName
    virtual std::vector<char> read() override;
    virtual int write(std::vector<char>) override;
    virtual int append(std::vector<char>) override;
    virtual unsigned int getSize() override;
    virtual std::string getName() override;
//    static bool isValidFileElement(char newFileElement);
    void accept(AbstractFileVisitor* fileVisitor) override;
    virtual AbstractFile* copy(std::string Name) override;


private:
    static bool isValidFileElement(char newFileElement);
    };

enum imageFileBounds {
    initialSize = 0,
    min=1,
    max = 9
};