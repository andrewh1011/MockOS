#include "mockos/PasswordProxy.h"
#include "mockos/AbstractFileVisitor.h"
#include <iostream>
using namespace std;

//Constructor initializes the 2 member variables
PasswordProxy::PasswordProxy(AbstractFile *passwordProtectedFile, std::string password)
    :passwordProtectedFile(passwordProtectedFile), password(password){}

    //Destructor that deletes the abstract file ( clion formatting is being annoying here)
    PasswordProxy::~PasswordProxy() {
        delete this->passwordProtectedFile;
}


//Studio 20 2e
//this method should prompt the user to input a password and returns the password entered by the user
string PasswordProxy::passwordPrompt() {
    string password;
    cout<< "What is the password?"<<endl;
    getline(cin, password);
    return password;
}

//Helper function that checks if the inputted password matches the "password" member variable
bool PasswordProxy::isCorrectPassword(string inputtedPassword) {
    return this->password == inputtedPassword;
}

//Steps 3 the methods inherited from AbstractFile class

//Step3a
vector<char> PasswordProxy::read() {
    string userInputedPassword = this->passwordPrompt();
    if (isCorrectPassword(userInputedPassword)) {
        //If the inputted password is correct, we simply return the result of calling read on the password protected file
        return this->passwordProtectedFile->read();
    } else {
        return vector<char>{}; //If the inputted password is incorrect, we just return an empty vector
    }
}

//Step 3b
//If the inputted password is correct, we simply return the result of calling
//write on the password protected Abstract File (passing in the fileContents to write of course!)🫡
int PasswordProxy::write(vector<char> fileContents) {
    string userInputedPassword = this->passwordPrompt();
    if (isCorrectPassword(userInputedPassword)) {
        return this->passwordProtectedFile->write(fileContents);
    } else {
        //If the password is incorrect we do not write to the file and return a nonzero enum!
        return passwordResults::incorrectPassword;
    }
}

//Step 3c
//If the user inputted password is correct we append to the abstract file object and return the result of that
//Else we just return an enum representing an incorrect password!
int PasswordProxy::append(vector<char> fileContents) {
    string userInputedPassword = this->passwordPrompt();
    if (isCorrectPassword(userInputedPassword)) {
        return this->passwordProtectedFile->append(fileContents);
    } else {
        //If the password is incorrect we do not write to the file and return a nonzero enum!
        return passwordResults::incorrectPassword;
    }
}

//Step 3d
//the function should return the results of calling getSize on the private member variable
//(Of course calling the private member variable on the abstract file object)
unsigned int PasswordProxy::getSize() {
    return this->passwordProtectedFile->getSize();
}

//Step 3d
//the function should return the results of calling getName on the private member variable
//(Of course calling the private member variable on the abstract file object)
std::string PasswordProxy::getName() {
    return this->passwordProtectedFile->getName();
}

//If the inputted password is correct we call accept on the Abstract filevisiotor (3e)
void PasswordProxy::accept(AbstractFileVisitor *fileVisitor) {
    string userInputtedPassword = this->passwordPrompt();
    if(isCorrectPassword(userInputtedPassword)) {
        this->passwordProtectedFile->accept(fileVisitor);
    }
}

AbstractFile* PasswordProxy::copy(string Name) {
    AbstractFile* copied = this->passwordProtectedFile->copy(Name);
    return new PasswordProxy(copied, this->password);
}

