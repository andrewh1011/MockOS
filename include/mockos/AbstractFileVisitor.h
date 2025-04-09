/*

1) Andrew Hartmann a.r.hartmann@wustl.edu
1. Mario Rodriguez-Montoya m.rodriguez-montoya@wustl.edu
1. Shangwe Nyota s.nyota@wustl.edu

*/
//Step 3a creating an interface for a Visitor
//#include "mockos/ImageFile.h"
//#include "mockos/TextFile.h"
#pragma once
class ImageFile;
class TextFile;

class AbstractFileVisitor {
public:
    virtual void visit_ImageFile(ImageFile* imageFile) = 0;
    virtual void visit_TextFile(TextFile* textFile) = 0;

};