#include "mockos/ImageFile.h"
#include "mockos/AbstractFileVisitor.h"
#include "mockos/AbstractCommand.h"
#include "mockos/AbstractFileSystem.h"
#include <unordered_set>
#include <iostream>
using namespace std;
typedef unsigned int UINT;
//Constructor for the ImageFile class
ImageFile::ImageFile(std::string fileName)
    :fileName(fileName), fileSize(imageFileBounds::initialSize) {}

//Returns the size of the ImageFile
UINT ImageFile::getSize() {
    return this->fileContents.size();
}
//returns the ImageFile's name
std::string ImageFile::getName() {
    return this->fileName;
}

//(for studio17) an image is an nxn board of pixels, each pixel is an X or ' ' (space)
//last char in the vector is the size
int ImageFile::write(std::vector<char> newFileContents) {
    int sizeOfNewFileContents = imageFileBounds::initialSize;
    //First, set the size member variable (using the last char in the vector)
    if (!newFileContents.empty()) {
        //if the new file contents is not an empty vector, we can simply access the last element
        char lastElementAsChar = newFileContents.back();
        
        sizeOfNewFileContents = lastElementAsChar - '0';
        int expectedFileSize = newFileContents.size()-imageFileBounds::min;

        //check for invalid size
        if (sizeOfNewFileContents < imageFileBounds::min || sizeOfNewFileContents > imageFileBounds::max || expectedFileSize != sizeOfNewFileContents*sizeOfNewFileContents) {
            this->fileSize = imageFileBounds::initialSize;
            cout << sizeOfNewFileContents << endl;
            cout << expectedFileSize << endl;
            return fileOutcomes::invalidBoardSize; // invalid board size
        }
    } else {
        //newFileContents is empty
        this->fileSize = imageFileBounds::initialSize;
        return fileOutcomes::fileIsNull; //nonzero value representing an error occured
    }

    this->fileSize = sizeOfNewFileContents; //update the member variable
    int totalFileContents = sizeOfNewFileContents * sizeOfNewFileContents; //the image is represented as an nxn vector

    for (int i = imageFileBounds::initialSize; i < totalFileContents; ++i) {
        char currentChar = newFileContents[i];
        if (currentChar == 'X' || currentChar == ' ') {
            this->fileContents.push_back(currentChar);
        } else {
            fileContents.clear();
            this->fileSize = imageFileBounds::initialSize;
            return fileOutcomes::fileIsNull;
        }
    }

    return programOutcomes::success;

}

vector<char> ImageFile::read() {
    return this->fileContents;
}

int ImageFile::append(std::vector<char>) {
    return commandOutcomes::appendToImageError; //returns nonzero value indicating an imageFile is not supported (2d)
}

void ImageFile::accept(AbstractFileVisitor *fileVisitor) {
    fileVisitor->visit_ImageFile(this);
}

AbstractFile* ImageFile::copy(string name) {
    ImageFile* copied = new ImageFile(name);

    copied->fileContents = this->fileContents;
    copied->fileSize = this->fileSize;

    return copied;

}
