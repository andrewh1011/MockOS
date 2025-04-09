#include "mockos/TextFile.h"
#include "mockos/AbstractFileVisitor.h"
#include "mockos/AbstractFileSystem.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

//constructor simply sets the fileName of the TextFile
TextFile::TextFile(std::string fileName)
    :fileName(fileName){
};


//returns the size of a TextFile
unsigned int TextFile::getSize() {
    return this->fileContents.size();
}

//returns the name of a TextFile
std::string TextFile::getName() {
    return this->fileName;
}

//Writes to a textfile (overriting anything that was initially there)
//Likely used for the initial write
int TextFile::write(std::vector<char> newFileContents) {
    this->fileContents = newFileContents;
    return success;
}

//Adds new file content (text) to our file vector (overall text file)
int TextFile::append(std::vector<char> newFileContent) {
    for(int i = 0; i < newFileContent.size(); ++i) {
        this->fileContents.push_back(newFileContent[i]);
    }
    return success;
}

//Prints out each element of the file to the output stream
std::vector<char> TextFile::read() {
    vector<char> textFileContents;
    for (int i = 0; i < this->fileContents.size(); ++i) {
        char currentFileContent = this->fileContents[i];
        //cout <<currentFileContent;  //printing out each value from studio 18 (commented out in studio 19)
        textFileContents.push_back(currentFileContent);
    }
    return textFileContents;
}

void TextFile::accept(AbstractFileVisitor *fileVisitor) {
    fileVisitor->visit_TextFile(this);
}

AbstractFile* TextFile::copy(string name) {
    AbstractFile* copied = new TextFile(name);
    copied->write(this->read());
    
    return copied;

}
