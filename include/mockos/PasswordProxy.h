/*
header file for the PasswordProxy Class
1) Andrew Hartmann a.r.hartmann@wustl.edu
1. Mario Rodriguez-Montoya m.rodriguez-montoya@wustl.edu
1. Shangwe Nyota s.nyota@wustl.edu

*/
#include "AbstractFile.h"
#include <string>
class AbstractFileVisitor;

//PasswordProxy must implement the same interface as anyfile (TextFile or ImageFile) which is the
//AbstractFile interface
class PasswordProxy : public AbstractFile {
public:
    PasswordProxy(AbstractFile* passwordProtectedFile, std::string password); //constructor for the PasswordProxy
    virtual ~PasswordProxy(); //Destructor that deletes the pointer to the real file
    virtual std::vector<char> read() override;
    virtual int write(std::vector<char>) override;
    virtual int append(std::vector<char>) override;
    virtual unsigned int getSize() override;
    virtual std::string getName() override;
    virtual void accept(AbstractFileVisitor* fileVisitor) override;
    virtual AbstractFile* copy(std::string) override;
private:
    AbstractFile* passwordProtectedFile; //Pointer to an abstract file (that is password protecteD)
    std::string password;
    bool isCorrectPassword(std::string inputtedPassword); //boolean helper that returns true if a password matches
protected:
    std::string passwordPrompt(); //this method shoul prompt the user to input a password and returns the password entered by the user

};

enum passwordResults {
    incorrectPassword = 88
};