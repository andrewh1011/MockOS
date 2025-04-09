#include "mockos/MetadataDisplayVisitor.h"
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include <iostream>

void MetadataDisplayVisitor::visit_TextFile(TextFile *textFile) {
    std::cout << textFile->getName() << " text " <<  textFile->getSize() << std::endl ;
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile *imageFile) {
    std::cout << imageFile->getName() << " image " << imageFile->getSize() << std::endl;
}