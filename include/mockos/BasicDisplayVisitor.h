/*

1) Andrew Hartmann a.r.hartmann@wustl.edu
1. Mario Rodriguez-Montoya m.rodriguez-montoya@wustl.edu
1. Shangwe Nyota s.nyota@wustl.edu

*/
//Step4
//Creating a concreete visitor class called BasicDisplayVisitor
#pragma once
#include "AbstractFileVisitor.h"

class BasicDisplayVisitor: public AbstractFileVisitor{
public:
    virtual void visit_ImageFile(ImageFile* imageFile) override;
    virtual void visit_TextFile(TextFile* textFile) override;
};

enum iteratorValues {
    initalBound = 0,
    offset = 1
};