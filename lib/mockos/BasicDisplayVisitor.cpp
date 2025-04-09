#include "mockos/BasicDisplayVisitor.h"
#include "mockos/ImageFile.h"
#include "mockos/TextFile.h"
#include <iostream>
#include <cmath>
using namespace std;

void BasicDisplayVisitor::visit_ImageFile(ImageFile *imageFile) {
    vector<char> imageFileContents = imageFile->read();
    int imageFileSize = imageFileContents.size();
    int numColumns = sqrt(imageFileSize);

    //Note: (X, Y) = (Col, Row)
    for (int row = iteratorValues::initalBound; row < imageFileSize; ++row) {
        for (int col = iteratorValues::initalBound; col < numColumns; ++col) {
            //Note: index = Y*size + X
            int index = row*numColumns+col;
            int lastValidIndex = imageFileSize-iteratorValues::offset;
            //Ensures the index is in bounds
            if (index >=iteratorValues::initalBound && index <= lastValidIndex) {
                char currentFileContent = imageFileContents[index];
                cout<<currentFileContent;
            }
        }
        cout<<endl;
    }
}

//As defined in studio 16, read for a TextFile loops through the file contents
//and prints it to the output stream
void BasicDisplayVisitor::visit_TextFile(TextFile *textFile) {
   vector<char> fileContents = textFile->read();
   for (int i = 0; i <fileContents.size(); ++i) {
       char currentFileContent = fileContents[i];
       cout<<currentFileContent;
   }

}