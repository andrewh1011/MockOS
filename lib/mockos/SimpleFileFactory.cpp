#include "mockos/SimpleFileFactory.h"
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
using namespace std;
//Step 3i of Studio 18
//Creates a new file of AbstractFile Type (text, image, etc...) and returns a pointer to the AbstractFile
//Single Responsibility principle says that the SimpleFileFactory is NOT responsible for knowing
//If the newly created file is already in the FileSystem as that is not the responsiblity of this class
//SimpleFileFactory class has one responsibility and that is to create AbstractFiles!
AbstractFile * SimpleFileFactory::createFile(std::string fileNameToCreate) {
    AbstractFile * newlyCreatedFile = nullptr;

    //If the file extension is .txt
    if (fileNameToCreate.find(".txt") != string::npos) {
        newlyCreatedFile = new TextFile(fileNameToCreate);

    } else if (fileNameToCreate.find(".img") != string::npos) {

        //if the newly created file extension is an image file
        newlyCreatedFile = new ImageFile(fileNameToCreate);
    }

    return newlyCreatedFile;
}


