/*
header file for the MetaDisplayVisitor Class
1) Andrew Hartmann a.r.hartmann@wustl.edu
1. Mario Rodriguez-Montoya m.rodriguez-montoya@wustl.edu
1. Shangwe Nyota s.nyota@wustl.edu

*/
class ImageFile;
class TextFile;
#include "mockos/AbstractFileVisitor.h"
//Step 5
//Concrete visitor class for Displaying metadata for a textfile (filename, contents, size)
class MetadataDisplayVisitor : public AbstractFileVisitor{
public:
    virtual void visit_ImageFile(ImageFile* imageFile) override;
    virtual void visit_TextFile(TextFile* textFile) override;
};